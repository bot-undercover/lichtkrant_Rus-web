#include "font.h"

const unsigned char font[][5] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x3E, 0x5B, 0x4F, 0x5B, 0x3E },
    { 0x3E, 0x6B, 0x4F, 0x6B, 0x3E },
    { 0x1C, 0x3E, 0x7C, 0x3E, 0x1C },
    { 0x18, 0x3C, 0x7E, 0x3C, 0x18 },
    { 0x1C, 0x57, 0x7D, 0x57, 0x1C },
    { 0x1C, 0x5E, 0x7F, 0x5E, 0x1C },
    { 0x00, 0x18, 0x3C, 0x18, 0x00 },
    { 0xFF, 0xE7, 0xC3, 0xE7, 0xFF },
    { 0x00, 0x18, 0x24, 0x18, 0x00 },
    { 0xFF, 0xE7, 0xDB, 0xE7, 0xFF },
    { 0x30, 0x48, 0x3A, 0x06, 0x0E },
    { 0x26, 0x29, 0x79, 0x29, 0x26 },
    { 0x40, 0x7F, 0x05, 0x05, 0x07 },
    { 0x40, 0x7F, 0x05, 0x25, 0x3F },
    { 0x5A, 0x3C, 0xE7, 0x3C, 0x5A },
    { 0x7F, 0x3E, 0x1C, 0x1C, 0x08 },
    { 0x08, 0x1C, 0x1C, 0x3E, 0x7F },
    { 0x14, 0x22, 0x7F, 0x22, 0x14 },
    { 0x5F, 0x5F, 0x00, 0x5F, 0x5F },
    { 0x06, 0x09, 0x7F, 0x01, 0x7F },
    { 0x00, 0x66, 0x89, 0x95, 0x6A },
    { 0x60, 0x60, 0x60, 0x60, 0x60 },
    { 0x94, 0xA2, 0xFF, 0xA2, 0x94 },
    { 0x08, 0x04, 0x7E, 0x04, 0x08 },
    { 0x10, 0x20, 0x7E, 0x20, 0x10 },
    { 0x08, 0x08, 0x2A, 0x1C, 0x08 },
    { 0x08, 0x1C, 0x2A, 0x08, 0x08 },
    { 0x1E, 0x10, 0x10, 0x10, 0x10 },
    { 0x0C, 0x1E, 0x0C, 0x1E, 0x0C },
    { 0x30, 0x38, 0x3E, 0x38, 0x30 },
    { 0x06, 0x0E, 0x3E, 0x0E, 0x06 },
    { 0x00, 0x80, 0x80, 0x00, 0x00 },  // 20
    { 0x00, 0x00, 0x5f, 0x00, 0x00 },  // 21 !
    { 0x00, 0x07, 0x00, 0x07, 0x00 },  // 22 "
    { 0x14, 0x7f, 0x14, 0x7f, 0x14 },  // 23 #
    { 0x24, 0x2a, 0x7f, 0x2a, 0x12 },  // 24 $
    { 0x23, 0x13, 0x08, 0x64, 0x62 },  // 25 %
    { 0x36, 0x49, 0x55, 0x22, 0x50 },  // 26 &
    { 0x00, 0x05, 0x03, 0x00, 0x00 },  // 27 '
    { 0x00, 0x1c, 0x22, 0x41, 0x00 },  // 28 (
    { 0x00, 0x41, 0x22, 0x1c, 0x00 },  // 29 )
    { 0x14, 0x08, 0x3e, 0x08, 0x14 },  // 2a *
    { 0x08, 0x08, 0x3e, 0x08, 0x08 },  // 2b +
    { 0x00, 0x50, 0x30, 0x00, 0x00 },  // 2c ,
    { 0x08, 0x08, 0x08, 0x08, 0x08 },  // 2d -
    { 0x00, 0x60, 0x60, 0x00, 0x00 },  // 2e .
    { 0x20, 0x10, 0x08, 0x04, 0x02 },  // 2f /
    { 0x3e, 0x51, 0x49, 0x45, 0x3e },  // 30 0
    { 0x80, 0x42, 0x7f, 0x40, 0x80 },  // 31 1
    { 0x42, 0x61, 0x51, 0x49, 0x46 },  // 32 2
    { 0x21, 0x41, 0x45, 0x4b, 0x31 },  // 33 3
    { 0x18, 0x14, 0x12, 0x7f, 0x10 },  // 34 4
    { 0x27, 0x45, 0x45, 0x45, 0x39 },  // 35 5
    { 0x3c, 0x4a, 0x49, 0x49, 0x30 },  // 36 6
    { 0x01, 0x71, 0x09, 0x05, 0x03 },  // 37 7
    { 0x36, 0x49, 0x49, 0x49, 0x36 },  // 38 8
    { 0x06, 0x49, 0x49, 0x29, 0x1e },  // 39 9
    { 0x00, 0x36, 0x36, 0x00, 0x00 },  // 3a :
    { 0x00, 0x56, 0x36, 0x00, 0x00 },  // 3b ;
    { 0x08, 0x14, 0x22, 0x41, 0x00 },  // 3c <
    { 0x14, 0x14, 0x14, 0x14, 0x14 },  // 3d =
    { 0x00, 0x41, 0x22, 0x14, 0x08 },  // 3e >
    { 0x02, 0x01, 0x51, 0x09, 0x06 },  // 3f ?
    { 0x32, 0x49, 0x79, 0x41, 0x3e },  // 40 @
    { 0x7e, 0x11, 0x11, 0x11, 0x7e },  // 41 A
    { 0x7f, 0x49, 0x49, 0x49, 0x36 },  // 42 B
    { 0x3e, 0x41, 0x41, 0x41, 0x22 },  // 43 C
    { 0x7f, 0x41, 0x41, 0x22, 0x1c },  // 44 D
    { 0x7f, 0x49, 0x49, 0x49, 0x41 },  // 45 E
    { 0x7f, 0x09, 0x09, 0x09, 0x01 },  // 46 F
    { 0x3e, 0x41, 0x49, 0x49, 0x7a },  // 47 G
    { 0x7f, 0x08, 0x08, 0x08, 0x7f },  // 48 H
    { 0x00, 0x41, 0x7f, 0x41, 0x00 },  // 49 I
    { 0x20, 0x40, 0x41, 0x3f, 0x01 },  // 4a J
    { 0x7f, 0x08, 0x14, 0x22, 0x41 },  // 4b K
    { 0x7f, 0x40, 0x40, 0x40, 0x40 },  // 4c L
    { 0x7f, 0x02, 0x0c, 0x02, 0x7f },  // 4d M
    { 0x7f, 0x04, 0x08, 0x10, 0x7f },  // 4e N
    { 0x3e, 0x41, 0x41, 0x41, 0x3e },  // 4f O
    { 0x7f, 0x09, 0x09, 0x09, 0x06 },  // 50 P
    { 0x3e, 0x41, 0x51, 0x21, 0x5e },  // 51 Q
    { 0x7f, 0x09, 0x19, 0x29, 0x46 },  // 52 R
    { 0x46, 0x49, 0x49, 0x49, 0x31 },  // 53 S
    { 0x01, 0x01, 0x7f, 0x01, 0x01 },  // 54 T
    { 0x3f, 0x40, 0x40, 0x40, 0x3f },  // 55 U
    { 0x1f, 0x20, 0x40, 0x20, 0x1f },  // 56 V
    { 0x3f, 0x40, 0x38, 0x40, 0x3f },  // 57 W
    { 0x63, 0x14, 0x08, 0x14, 0x63 },  // 58 X
    { 0x07, 0x08, 0x70, 0x08, 0x07 },  // 59 Y
    { 0x61, 0x51, 0x49, 0x45, 0x43 },  // 5a Z
    { 0x00, 0x7f, 0x41, 0x41, 0x00 },  // 5b [
    { 0x02, 0x04, 0x08, 0x10, 0x20 },  // 5c ¥
    { 0x00, 0x41, 0x41, 0x7f, 0x00 },  // 5d ]
    { 0x04, 0x02, 0x01, 0x02, 0x04 },  // 5e ^
    { 0x40, 0x40, 0x40, 0x40, 0x40 },  // 5f _
    { 0x00, 0x01, 0x02, 0x04, 0x00 },  // 60 `
    { 0x20, 0x54, 0x54, 0x54, 0x78 },  // 61 a
    { 0x7f, 0x48, 0x44, 0x44, 0x38 },  // 62 b
    { 0x38, 0x44, 0x44, 0x44, 0x20 },  // 63 c
    { 0x38, 0x44, 0x44, 0x48, 0x7f },  // 64 d
    { 0x38, 0x54, 0x54, 0x54, 0x18 },  // 65 e
    { 0x08, 0x7e, 0x09, 0x01, 0x02 },  // 66 f
    { 0x0c, 0x52, 0x52, 0x52, 0x3e },  // 67 g
    { 0x7f, 0x08, 0x04, 0x04, 0x78 },  // 68 h
    { 0x00, 0x44, 0x7d, 0x40, 0x00 },  // 69 i
    { 0x20, 0x40, 0x44, 0x3d, 0x00 },  // 6a j
    { 0x7f, 0x10, 0x28, 0x44, 0x00 },  // 6b k
    { 0x00, 0x41, 0x7f, 0x40, 0x00 },  // 6c l
    { 0x7c, 0x04, 0x18, 0x04, 0x78 },  // 6d m
    { 0x7c, 0x08, 0x04, 0x04, 0x78 },  // 6e n
    { 0x38, 0x44, 0x44, 0x44, 0x38 },  // 6f o
    { 0x7c, 0x14, 0x14, 0x14, 0x08 },  // 70 p
    { 0x08, 0x14, 0x14, 0x18, 0x7c },  // 71 q
    { 0x7c, 0x08, 0x04, 0x04, 0x08 },  // 72 r
    { 0x48, 0x54, 0x54, 0x54, 0x20 },  // 73 s
    { 0x04, 0x3f, 0x44, 0x40, 0x20 },  // 74 t
    { 0x3c, 0x40, 0x40, 0x20, 0x7c },  // 75 u
    { 0x1c, 0x20, 0x40, 0x20, 0x1c },  // 76 v
    { 0x3c, 0x40, 0x30, 0x40, 0x3c },  // 77 w
    { 0x44, 0x28, 0x10, 0x28, 0x44 },  // 78 x
    { 0x0c, 0x50, 0x50, 0x50, 0x3c },  // 79 y
    { 0x44, 0x64, 0x54, 0x4c, 0x44 },  // 7a z
    { 0x00, 0x08, 0x36, 0x41, 0x00 },  // 7b {
    { 0x00, 0x00, 0x7f, 0x00, 0x00 },  // 7c |
    { 0x00, 0x41, 0x36, 0x08, 0x00 },  // 7d }
    { 0x10, 0x08, 0x08, 0x10, 0x08 },  // 7e ←
    { 0x78, 0x46, 0x41, 0x46, 0x78 },  // 7f →

    { 0x7C, 0x14, 0x14, 0x14, 0x08 },  // b0 p
    { 0x38, 0x44, 0x44, 0x44, 0x20 },  // b1 c
    { 0x04, 0x04, 0x7c, 0x04, 0x04 },  // b2 т
    { 0x0C, 0x50, 0x50, 0x50, 0x3C },  // b3 у
    { 0x30, 0x48, 0xfc, 0x48, 0x30 },  // b4 ф
    { 0x44, 0x28, 0x10, 0x28, 0x44 },  // b5 x
    { 0x7c, 0x40, 0x40, 0x40, 0xfc },  // b6 ц
    { 0x0c, 0x10, 0x10, 0x10, 0x7c },  // b7 ч
    { 0x7c, 0x40, 0x7c, 0x40, 0x7c },  // b8 ш
    { 0x7c, 0x40, 0x7c, 0x40, 0xfc },  // b9 щ
    { 0x04, 0x7c, 0x50, 0x50, 0x20 },  // ba ъ
    { 0x7c, 0x50, 0x50, 0x20, 0x7c },  // bb ы
    { 0x7c, 0x50, 0x50, 0x20, 0x00 },  // bc ь
    { 0x28, 0x44, 0x54, 0x54, 0x38 },  // bd э
    { 0x7c, 0x10, 0x38, 0x44, 0x38 },  // be ю
    { 0x08, 0x54, 0x34, 0x14, 0x7c },  // bf я

    { 0x7e, 0x11, 0x11, 0x11, 0x7e },  // 80 A
    { 0x7f, 0x49, 0x49, 0x49, 0x33 },  // 81 Б
    { 0x7f, 0x49, 0x49, 0x49, 0x36 },  // 82 В
    { 0x7f, 0x01, 0x01, 0x01, 0x03 },  // 83 Г
    { 0xe0, 0x51, 0x4f, 0x41, 0xff },  // 84 Д
    { 0x7f, 0x49, 0x49, 0x49, 0x41 },  // 85 E
    { 0x77, 0x08, 0x7f, 0x08, 0x77 },  // 86 Ж
    { 0x41, 0x49, 0x49, 0x49, 0x36 },  // 87 З
    { 0x7f, 0x10, 0x08, 0x04, 0x7f },  // 88 И
    { 0x7c, 0x21, 0x12, 0x09, 0x7c },  // 89 Й
    { 0x7f, 0x08, 0x14, 0x22, 0x41 },  // 8a K
    { 0x20, 0x41, 0x3f, 0x01, 0x7f },  // 8b Л
    { 0x7f, 0x02, 0x0c, 0x02, 0x7f },  // 8c M
    { 0x7f, 0x08, 0x08, 0x08, 0x7f },  // 8d H
    { 0x3e, 0x41, 0x41, 0x41, 0x3e },  // 8e O
    { 0x7f, 0x01, 0x01, 0x01, 0x7f },  // 8f П
    { 0x7f, 0x09, 0x09, 0x09, 0x06 },  // 90 P
    { 0x3e, 0x41, 0x41, 0x41, 0x22 },  // 91 C
    { 0x01, 0x01, 0x7f, 0x01, 0x01 },  // 92 T
    { 0x47, 0x28, 0x10, 0x08, 0x07 },  // 93 У
    { 0x1c, 0x22, 0x7f, 0x22, 0x1c },  // 94 Ф
    { 0x63, 0x14, 0x08, 0x14, 0x63 },  // 95 X
    { 0x7f, 0x40, 0x40, 0x40, 0xff },  // 96 Ц
    { 0x07, 0x08, 0x08, 0x08, 0x7f },  // 97 Ч
    { 0x7f, 0x40, 0x7f, 0x40, 0x7f },  // 98 Ш
    { 0x7f, 0x40, 0x7f, 0x40, 0xff },  // 99 Щ
    { 0x01, 0x7f, 0x48, 0x48, 0x30 },  // 9a Ъ
    { 0x7f, 0x48, 0x30, 0x00, 0x7f },  // 9b Ы
    { 0x00, 0x7f, 0x48, 0x48, 0x30 },  // 9c Э
    { 0x22, 0x41, 0x49, 0x49, 0x3e },  // 9d Ь
    { 0x7f, 0x08, 0x3e, 0x41, 0x3e },  // 9e Ю
    { 0x46, 0x29, 0x19, 0x09, 0x7f },  // 9f Я

    { 0x20, 0x54, 0x54, 0x54, 0x78 },  // a0 a
    { 0x3c, 0x4a, 0x4a, 0x49, 0x31 },  // a1 б
    { 0x7c, 0x54, 0x54, 0x28, 0x00 },  // a2 в
    { 0x7c, 0x04, 0x04, 0x04, 0x0c },  // a3 г
    { 0xe0, 0x54, 0x4c, 0x44, 0xfc },  // a4 д
    { 0x38, 0x54, 0x54, 0x54, 0x18 },  // a5 e
    { 0x6c, 0x10, 0x7c, 0x10, 0x6c },  // a6 ж
    { 0x44, 0x44, 0x54, 0x54, 0x28 },  // a7 з
    { 0x7c, 0x20, 0x10, 0x08, 0x7c },  // a8 и
    { 0x7c, 0x41, 0x22, 0x11, 0x7c },  // a9 й
    { 0x7c, 0x10, 0x28, 0x44, 0x00 },  // aa к
    { 0x20, 0x44, 0x3c, 0x04, 0x7c },  // ab л
    { 0x7c, 0x08, 0x10, 0x08, 0x7c },  // ac м
    { 0x7c, 0x10, 0x10, 0x10, 0x7c },  // ad н
    { 0x38, 0x44, 0x44, 0x44, 0x38 },  // ae o
    { 0x7c, 0x04, 0x04, 0x04, 0x7c },  // af п
};

