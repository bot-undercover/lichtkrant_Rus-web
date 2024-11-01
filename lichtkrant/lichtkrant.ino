#include <stdint.h>

#include "cmdproc.h"
#include "editline.h"
#include "leddriver.h"
#include "draw.h"

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiManager.h>
#include <Arduino.h>
#include <WiFiUdp.h>

#define print Serial.printf

#define RGB565_UDP_PORT    1565

static WiFiManager wifiManager;
static WiFiUDP udpServer;
static uint8_t udpframe[8 * 80 * 2];

static char esp_id[64];
static char editline[120];
static char textline[120];
static pixel_t framebuffer[LED_HEIGHT][LED_WIDTH];
static volatile uint32_t frame_counter = 0;

static int do_fps(int argc, char *argv[])
{
    print("Measuring ...");

    uint32_t count = frame_counter;
    delay(1000);
    int fps = frame_counter - count;

    print("FPS = %d\n", fps);

    return CMD_OK;
}

static pixel_t shade_rasta_vertical(int x, int y)
{
    pixel_t c;
    c.r = map(y, 0, 6, 255, 0);
    c.g = map(y, 0, 6, 0, 255);
    return c;
}

static int do_pat(int argc, char *argv[])
{
    if (argc < 2) {
        return CMD_ARG;
    }
    int pat = atoi(argv[1]);

    switch (pat) {
    case 0:
        print("All clear\n");
        draw_fill({0, 0});
        break;
    case 1:
        print("All red\n");
        draw_fill({255, 0});
        break;
    case 2:
        print("All green\n");
        draw_fill({0, 255});
        break;
    case 3:
        print("All yellow\n");
        draw_fill({255, 255});
        break;
    case 4:
        print("quattro stagioni\n");
        draw_fill_ext([](int x, int y) -> pixel_t {
            pixel_t c;
            c.r = (x < 40) || (y == 3) ? 0 : 255;
            c.g = (y < 4) ? 0 : 255;
            return c;
        });
        break;
    case 5:
        print("rasta vertical\n");
        draw_fill_ext(shade_rasta_vertical);
        break;
    case 6:
        print("rasta horizontal\n");
        for (int x = 0; x < 80; x++) {
            for (int y = 0; y < 7; y++) {
                pixel_t c;
                c.r = map(x, 0, 79, 255, 0);
                c.g = map(x, 0, 79, 0, 255);
                draw_pixel(x, y, c);
            }
        }
        break;
    case 7:
        print("red shades\n");
        draw_fill_ext([](int x, int y) -> pixel_t {
            return {(uint8_t)map(x, 0, 79, 255, 0), 0}; 
        });
        break;
    case 8:
        print("green shades\n");
        draw_fill_ext([](int x, int y) -> pixel_t {
            return {0, (uint8_t)map(x, 0, 79, 255, 0)}; 
        });
        break;
    case 9:
        print("red/green shades\n");
        draw_fill_ext([](int x, int y) -> pixel_t {
            pixel_t c;
            c.r = map(x, 0, 79, 0, 255);
            c.g = map(y, 0, 6, 0, 255);
            return c;
        });
        break;
    case 10:
        print("Bleeding test pattern\n");
        for (int y = 0; y < 7; y++) {
            int x = y * 11;
            draw_pixel(x, y, {255, 0});
            draw_pixel(x + 3 , y, {255, 255});
            draw_pixel(x + 6, y, {0, 255});
        }
        break;
    default:
        print("Unhandled pattern %d\n", pat);
        return CMD_ARG;
    }

    return CMD_OK;
}

static int do_line(int argc, char *argv[])
{
    if (argc < 2) {
        return CMD_ARG;
    }
    int y = atoi(argv[1]);
    if ((y < 0) || (y >= 7)) {
        print("Invalid line %d\n", y);
        return -2;
    }
    uint8_t r = 255;
    if (argc > 2) {
        r = atoi(argv[2]);
    }
    uint8_t g = 255;
    if (argc > 3) {
        g = atoi(argv[3]);
    }
    pixel_t c = { r, g };
    draw_hline(y, c);

    return CMD_OK;
}

static int do_pix(int argc, char *argv[])
{
    if (argc < 4) {
        return CMD_ARG;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    uint32_t c = strtoul(argv[3], NULL, 16);

    pixel_t p;
    p.r = (c >> 16) & 0xFF;
    p.g = (c >> 8) & 0xFF;
    bool result = draw_pixel(x, y, p);

    return result ? CMD_OK : CMD_ARG;
}

static int build_textline(int argc, char *argv[], char *line)
{
    if (argc < 2) {
        return CMD_ARG;
    }
    strcpy(line, argv[1]);
    for (int i = 2; i < argc; i++) {
        strcat(line, " ");
        strcat(line, argv[i]);
    }
    return CMD_OK;
}

static int do_text(int argc, char *argv[])
{
    draw_fill({0, 0});
    int res = build_textline(argc, argv, textline);
    if (res >= 0) {
        draw_text(textline, 0, {255, 0}, {0, 0});
    }
    return res;
}

static int scroll_pos = 0;
static bool scroll_active = false;
static unsigned long scroll_tick = 0;

static int do_scroll(int argc, char *argv[])
{
    draw_fill({0, 0});
    int res = build_textline(argc, argv, textline);
    if (res >= 0) {
        scroll_pos = 80;
        scroll_active = true;
    }
    return CMD_OK;
}

static int do_enable(int argc, char *argv[])
{
    bool enable = true;
    if (argc > 1) {
        enable = atoi(argv[1]) != 0;
    }
    if (enable) {
        led_enable();
    } else {
        led_disable();
    }
    return CMD_OK;
}

static int do_reboot(int argc, char *argv[])
{
    led_disable();
    ESP.restart();
    return CMD_OK;
}

static int do_hang(int argc, char *argv[])
{
    print("Hanging");
    unsigned long start = millis();
    while (true) {
        if ((millis() - start) > 100) {
            start += 100;
            printf(".");
        }
    }
    return 0;
}

static int do_help(int argc, char *argv[]);
const cmd_t commands[] = {
    { "fps", do_fps, "Show FPS" },
    { "pat", do_pat, "[pattern] display a specific pattern" },
    { "line", do_line, "<line> [r] [g] fill one row colour {r.g}" },
    { "pix", do_pix, "<col> <row> <hexcode> Set pixel with colour" },
    { "text", do_text, "<text> Write text on the display" },
    { "scroll", do_scroll, "<text> Scroll text on the display" },
    { "enable", do_enable, "[0|1] Enable/disable" },
    { "reboot", do_reboot, "Reboot" },
    { "hang", do_hang, "Hang (triggering a watchdog reset)" },
    { "help", do_help, "Show help" },
    { NULL, NULL, NULL }
};

static void show_help(const cmd_t * cmds)
{
    for (const cmd_t * cmd = cmds; cmd->cmd != NULL; cmd++) {
        print("%10s: %s\n", cmd->name, cmd->help);
    }
}

static int do_help(int argc, char *argv[])
{
    show_help(commands);
    return CMD_OK;
}

// vsync callback
static void IRAM_ATTR vsync(int frame_nr)
{
    led_write_framebuffer(framebuffer);
    frame_counter = frame_nr;
}

void setup(void)
{
    led_init(vsync);

    // get ESP id
    snprintf(esp_id, sizeof(esp_id), "esp-ledsign-%06x", ESP.getChipId());
    Serial.begin(115200);
    print("\n%s\n", esp_id);

    EditInit(editline, sizeof(editline));
    draw_init((pixel_t *)framebuffer);

    memset(framebuffer, 0, sizeof(framebuffer));

    wifiManager.autoConnect(esp_id);
    draw_text_ext(WiFi.localIP().toString().c_str(), 0, shade_rasta_vertical, {0, 0});
    udpServer.begin(RGB565_UDP_PORT);
    MDNS.begin(esp_id);
    MDNS.addService("rgb565", "udp", RGB565_UDP_PORT);

    led_enable();
}

void loop(void)
{
    // handle incoming UDP frame
    int udpSize = udpServer.parsePacket();
    if (udpSize > 0) {
        int len = udpServer.read((uint8_t *)udpframe, sizeof(udpframe));
        if (len == sizeof(udpframe)) {
            // convert first 7 lines from RGB565 to RG88
            uint8_t *p = (uint8_t *)udpframe;
            for (int y = 0; y < 7; y++) {
                for (int x = 0; x < 80; x++) {
                    uint16_t rgb565 = (p[0] << 8) | p[1];
                    p += 2;
                    uint8_t r = (rgb565 >> 8) & 0xF8;
                    r += (r >> 5);
                    uint8_t g = (rgb565 >> 3) & 0xFC;
                    g += (g >> 6);
                    draw_pixel(x, y, {r, g});
                }
            }
        }
    }

    // parse command line
    bool haveLine = false;
    if (Serial.available()) {
        char c;
        haveLine = EditLine(Serial.read(), &c);
        Serial.write(c);
    }
    if (haveLine) {
        int result = cmd_process(commands, editline);
        switch (result) {
        case CMD_OK:
            print("OK\n");
            break;
        case CMD_NO_CMD:
            break;
        case CMD_UNKNOWN:
            print("Unknown command, available commands:\n");
            show_help(commands);
            break;
        case CMD_ARG:
            print("Invalid argument(s)\n");
            break;
        default:
            print("%d\n", result);
            break;
        }
        print(">");
    }
    
    // text scrolling
    if (scroll_active) {
        unsigned long tick = millis() / 40;
        if (scroll_tick != tick) {
            scroll_tick = tick;
            int end = draw_text_ext(textline, scroll_pos, shade_rasta_vertical, {0, 0});
            if (end < 0) {
                scroll_active = false;
            }
            scroll_pos--;
        }
    }

    // mDNS update
    MDNS.update();
}

