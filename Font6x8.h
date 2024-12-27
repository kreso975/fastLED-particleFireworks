
const uint8_t FontHeight=8;
const uint8_t FontWidth=6;

const static uint8_t PROGMEM Font[256][6]={
{0x00,0x00,0x00,0x00,0x00,0x00},	// 0x00
{0x00,0x3E,0x45,0x51,0x45,0x3E},	// 0x01
{0x00,0x3E,0x6B,0x6F,0x6B,0x3E},	// 0x02
{0x00,0x1C,0x3E,0x7C,0x3E,0x1C},	// 0x03
{0x00,0x18,0x3C,0x7E,0x3C,0x18},	// 0x04
{0x00,0x30,0x36,0x7F,0x36,0x30},	// 0x05
{0x00,0x18,0x5C,0x7E,0x5C,0x18},	// 0x06
{0x00,0x00,0x00,0x00,0x00,0x00},	// 0x07
{0x00,0x00,0x00,0x00,0x00,0x00},	// 0x08
{0x00,0x00,0x00,0x00,0x00,0x00},	// 0x09
{0x00,0x00,0x00,0x00,0x00,0x00},	// 0x0A
{0x00,0x30,0x48,0x4A,0x36,0x0E},	// 0x0B
{0x00,0x06,0x29,0x79,0x29,0x06},	// 0x0C
{0x00,0x00,0x00,0x00,0x00,0x00},	// 0x0D
{0x00,0x60,0x7E,0x0A,0x35,0x3F},	// 0x0E
{0x00,0x2A,0x1C,0x36,0x1C,0x2A},	// 0x0F
{0x00,0x00,0x7F,0x3E,0x1C,0x08},	// 0x10
{0x00,0x08,0x1C,0x3E,0x7F,0x00},	// 0x11
{0x00,0x14,0x36,0x7F,0x36,0x14},	// 0x12
{0x00,0x00,0x5F,0x00,0x5F,0x00},	// 0x13
{0x00,0x06,0x09,0x7F,0x01,0x7F},	// 0x14
{0x00,0x22,0x4D,0x55,0x59,0x22},	// 0x15
{0x00,0x60,0x60,0x60,0x60,0x00},	// 0x16
{0x00,0x14,0xB6,0xFF,0xB6,0x14},	// 0x17
{0x00,0x04,0x06,0x7F,0x06,0x04},	// 0x18
{0x00,0x10,0x30,0x7F,0x30,0x10},	// 0x19
{0x00,0x08,0x08,0x3E,0x1C,0x08},	// 0x1A
{0x00,0x08,0x1C,0x3E,0x08,0x08},	// 0x1B
{0x00,0x78,0x40,0x40,0x40,0x40},	// 0x1C
{0x00,0x08,0x3E,0x08,0x3E,0x08},	// 0x1D
{0x00,0x30,0x3C,0x3F,0x3C,0x30},	// 0x1E
{0x00,0x03,0x0F,0x3F,0x0F,0x03},	// 0x1F
{0x00,0x00,0x00,0x00,0x00,0x00},	// 0x20
{0x00,0x00,0x06,0x5F,0x06,0x00},	// 0x21
{0x00,0x07,0x03,0x00,0x07,0x03},	// 0x22
{0x00,0x24,0x7E,0x24,0x7E,0x24},	// 0x23
{0x00,0x24,0x2B,0x6A,0x12,0x00},	// 0x24
{0x00,0x63,0x13,0x08,0x64,0x63},	// 0x25
{0x00,0x36,0x49,0x56,0x20,0x50},	// 0x26
{0x00,0x00,0x07,0x03,0x00,0x00},	// 0x27
{0x00,0x00,0x3E,0x41,0x00,0x00},	// 0x28
{0x00,0x00,0x41,0x3E,0x00,0x00},	// 0x29
{0x00,0x08,0x3E,0x1C,0x3E,0x08},	// 0x2A
{0x00,0x08,0x08,0x3E,0x08,0x08},	// 0x2B
{0x00,0x00,0xE0,0x60,0x00,0x00},	// 0x2C
{0x00,0x08,0x08,0x08,0x08,0x08},	// 0x2D
{0x00,0x00,0x60,0x60,0x00,0x00},	// 0x2E
{0x00,0x20,0x10,0x08,0x04,0x02},	// 0x2F
{0x7E,0xFF,0x81,0x81,0xFF,0x7E},    // 0x30  0
{0x00,0x82,0xFF,0xFF,0x80,0x00},    // 0x31  1
{0xC2,0xE3,0xB1,0x99,0x8F,0x86},    // 0x32  2
{0x42,0xC3,0x89,0x89,0xFF,0x76},    // 0x33  3
{0x38,0x3C,0x26,0xF3,0xF1,0x20},    // 0x34  4
{0x4F,0xCF,0x89,0x89,0xF9,0x71},    // 0x35  5
{0x7E,0xFF,0x89,0x89,0xFB,0x72},    // 0x36  6
{0x01,0x01,0xF1,0xF9,0x0F,0x07},    // 0x37  7
{0x76,0xFF,0x89,0x89,0xFF,0x76},    // 0x38  8
{0x4E,0xDF,0x91,0x91,0xFF,0x7E},    // 0x39  9
{0x00,0x00,0x6C,0x6C,0x00,0x00},	// 0x3A
{0x00,0x00,0xEC,0x6C,0x00,0x00},	// 0x3B
{0x00,0x08,0x14,0x22,0x41,0x00},	// 0x3C
{0x00,0x24,0x24,0x24,0x24,0x24},	// 0x3D
{0x00,0x00,0x41,0x22,0x14,0x08},	// 0x3E
{0x00,0x02,0x01,0x59,0x09,0x06},	// 0x3F
{0x00,0x3E,0x41,0x5D,0x55,0x1E},	// 0x40
{0x00,0xfc,0x12,0x12,0x12,0xfc},	// 0x41 - A
{0x00,0xfe,0x92,0x92,0x92,0x6c},	// 0x42 - B
{0x00,0x7c,0x82,0x82,0x82,0x44},	// 0x43 - C
{0x00,0xfe,0x82,0x82,0x82,0x7c},	// 0x44 - D
{0x00,0xfe,0x92,0x92,0x92,0x82},	// 0x45 - E
{0x00,0xfe,0x12,0x12,0x12,0x02},	// 0x46 - F
{0x00,0x7c,0x82,0x92,0x92,0x74},	// 0x47 - G
{0x00,0xfe,0x10,0x10,0x10,0xfe},	// 0x48 - H
{0x00,0x00,0x82,0xfe,0x82,0x00},	// 0x49 - I
{0x00,0x60,0x80,0x80,0x80,0x7e},	// 0x4a - J
{0x00,0xfe,0x10,0x28,0x44,0x82},	// 0x4b - K
{0x00,0xfe,0x80,0x80,0x80,0x80},	// 0x4c - L
{0x00,0xfe,0x04,0x08,0x04,0xfe},	// 0x4d - M
{0x00,0xfe,0x04,0x08,0x10,0xfe},	// 0x4e - N
{0x00,0x7c,0x82,0x82,0x82,0x7c},	// 0x4f - O
{0x00,0xfe,0x12,0x12,0x12,0x0c},	// 0x50 - P
{0x00,0x7c,0x82,0xa2,0x42,0xbc},	// 0x51 - Q
{0x00,0xfe,0x12,0x12,0x32,0xcc},	// 0x52 - R
{0x00,0x4c,0x92,0x92,0x92,0x64},	// 0x53 - S
{0x00,0x02,0x02,0xfe,0x02,0x02},	// 0x54 - T
{0x00,0x7e,0x80,0x80,0x80,0x7e},	// 0x55 - U
{0x00,0x3e,0x40,0x80,0x40,0x3e},	// 0x56 - V
{0x00,0x7e,0x80,0x78,0x80,0x7e},	// 0x57 - W
{0x00,0xc6,0x28,0x10,0x28,0xc6},	// 0x58 - X
{0x00,0x0e,0x10,0xe0,0x10,0x0e},	// 0x59 - Y
{0x00,0xe2,0x92,0x8a,0x86,0x00},	// 0x5a - Z
{0x00,0x00,0x7F,0x41,0x41,0x00},	// 0x5B
{0x00,0x02,0x04,0x08,0x10,0x20},	// 0x5C
{0x00,0x00,0x41,0x41,0x7F,0x00},	// 0x5D
{0x00,0x04,0x02,0x01,0x02,0x04},	// 0x5E
{0x80,0x80,0x80,0x80,0x80,0x80},	// 0x5F
{0x00,0x00,0x03,0x07,0x00,0x00},	// 0x60
{0x00,0x20,0x54,0x54,0x54,0x78},	// 0x61
{0x00,0x7F,0x44,0x44,0x44,0x38},	// 0x62
{0x00,0x38,0x44,0x44,0x44,0x28},	// 0x63
{0x00,0x38,0x44,0x44,0x44,0x7F},	// 0x64
{0x00,0x38,0x54,0x54,0x54,0x08},	// 0x65
{0x00,0x08,0x7E,0x09,0x09,0x00},	// 0x66
{0x00,0x18,0xA4,0xA4,0xA4,0x7C},	// 0x67
{0x00,0x7F,0x04,0x04,0x78,0x00},	// 0x68
{0x00,0x00,0x00,0x7D,0x40,0x00},	// 0x69
{0x00,0x40,0x80,0x84,0x7D,0x00},	// 0x6A
{0x00,0x7F,0x10,0x28,0x44,0x00},	// 0x6B
{0x00,0x00,0x00,0x7F,0x40,0x00},	// 0x6C
{0x00,0x7C,0x04,0x18,0x04,0x78},	// 0x6D
{0x00,0x7C,0x04,0x04,0x78,0x00},	// 0x6E
{0x00,0x38,0x44,0x44,0x44,0x38},	// 0x6F
{0x00,0xFC,0x44,0x44,0x44,0x38},	// 0x70
{0x00,0x38,0x44,0x44,0x44,0xFC},	// 0x71
{0x00,0x44,0x78,0x44,0x04,0x08},	// 0x72
{0x00,0x08,0x54,0x54,0x54,0x20},	// 0x73
{0x00,0x04,0x3E,0x44,0x24,0x00},	// 0x74
{0x00,0x3C,0x40,0x20,0x7C,0x00},	// 0x75
{0x00,0x1C,0x20,0x40,0x20,0x1C},	// 0x76
{0x00,0x3C,0x60,0x30,0x60,0x3C},	// 0x77
{0x00,0x6C,0x10,0x10,0x6C,0x00},	// 0x78
{0x00,0x9C,0xA0,0x60,0x3C,0x00},	// 0x79
{0x00,0x64,0x54,0x54,0x4C,0x00},	// 0x7A
{0x00,0x08,0x3E,0x41,0x41,0x00},	// 0x7B
{0x00,0x00,0x00,0x77,0x00,0x00},	// 0x7C
{0x00,0x00,0x41,0x41,0x3E,0x08},	// 0x7D
{0x00,0x02,0x01,0x02,0x01,0x00},	// 0x7E
{0x00,0x3C,0x26,0x23,0x26,0x3C},	// 0x7F
{0x00,0x1E,0xA1,0xE1,0x21,0x12},	// 0x80
{0x00,0x3D,0x40,0x20,0x7D,0x00},	// 0x81
{0x00,0x38,0x54,0x54,0x55,0x09},	// 0x82
{0x00,0x20,0x55,0x55,0x55,0x78},	// 0x83
{0x00,0x20,0x55,0x54,0x55,0x78},	// 0x84
{0x00,0x20,0x55,0x55,0x54,0x78},	// 0x85
{0x00,0x20,0x57,0x55,0x57,0x78},	// 0x86
{0x00,0x1C,0xA2,0xE2,0x22,0x14},	// 0x87
{0x00,0x38,0x55,0x55,0x55,0x08},	// 0x88
{0x00,0x38,0x55,0x54,0x55,0x08},	// 0x89
{0x00,0x4c,0x93,0x92,0x93,0x64},	// 0x8A
{0x00,0x00,0x01,0x7C,0x41,0x00},	// 0x8B
{0x00,0x00,0x01,0x7D,0x41,0x00},	// 0x8C
{0x00,0x00,0x01,0x7C,0x40,0x00},	// 0x8D
{0x00,0xe2,0x93,0x8b,0x86,0x00},	// 0x8E
{0x00,0x78,0x2F,0x25,0x2F,0x78},	// 0x8F
{0x00,0x7C,0x54,0x54,0x55,0x45},	// 0x90
{0x00,0x34,0x54,0x7C,0x54,0x58},	// 0x91
{0x00,0x7E,0x09,0x7F,0x49,0x49},	// 0x92
{0x00,0x38,0x45,0x45,0x39,0x00},	// 0x93
{0x00,0x38,0x45,0x44,0x39,0x00},	// 0x94
{0x00,0x39,0x45,0x44,0x38,0x00},	// 0x95
{0x00,0x3C,0x41,0x21,0x7D,0x00},	// 0x96
{0x00,0x3D,0x41,0x20,0x7C,0x00},	// 0x97
{0x00,0x9C,0xA1,0x60,0x3D,0x00},	// 0x98
{0x00,0x3D,0x42,0x42,0x3D,0x00},	// 0x99
{0x00,0x08,0x55,0x56,0x55,0x20},	// 0x9A
{0x80,0x70,0x68,0x58,0x38,0x04},	// 0x9B
{0x00,0x48,0x3E,0x49,0x49,0x62},	// 0x9C
{0x00,0x7E,0x61,0x5D,0x43,0x3F},	// 0x9D
{0x00,0x65,0x56,0x55,0x4c,0x00},	// 0x9E
{0x00,0x40,0x88,0x7E,0x09,0x02},	// 0x9F
{0x00,0x20,0x54,0x55,0x55,0x78},	// 0xA0
{0x00,0x00,0x00,0x7D,0x41,0x00},	// 0xA1
{0x00,0x38,0x44,0x45,0x39,0x00},	// 0xA2
{0x00,0x3C,0x40,0x21,0x7D,0x00},	// 0xA3
{0x00,0x7A,0x09,0x0A,0x71,0x00},	// 0xA4
{0x00,0x7A,0x11,0x22,0x79,0x00},	// 0xA5
{0x00,0x08,0x55,0x55,0x55,0x5E},	// 0xA6
{0x00,0x4E,0x51,0x51,0x4E,0x00},	// 0xA7
{0x00,0x30,0x48,0x4D,0x40,0x20},	// 0xA8
{0x3E,0x41,0x5D,0x4B,0x55,0x3E},	// 0xA9
{0x04,0x04,0x04,0x04,0x04,0x1C},	// 0xAA
{0x00,0x17,0x08,0x4C,0x6A,0x50},	// 0xAB
{0x00,0x17,0x08,0x34,0x2A,0x78},	// 0xAC
{0x00,0x00,0x30,0x7D,0x30,0x00},	// 0xAD
{0x00,0x08,0x14,0x00,0x08,0x14},	// 0xAE
{0x00,0x14,0x08,0x00,0x14,0x08},	// 0xAF
{0x44,0x11,0x44,0x11,0x44,0x11},	// 0xB0
{0xAA,0x55,0xAA,0x55,0xAA,0x55},	// 0xB1
{0xBB,0xEE,0xBB,0xEE,0xBB,0xEE},	// 0xB2
{0x00,0x00,0x00,0xFF,0x00,0x00},	// 0xB3
{0x08,0x08,0x08,0xFF,0x00,0x00},	// 0xB4
{0x00,0x70,0x28,0x25,0x29,0x70},	// 0xB5
{0x00,0x70,0x29,0x25,0x29,0x70},	// 0xB6
{0x00,0x70,0x29,0x25,0x28,0x70},	// 0xB7
{0x3E,0x41,0x5D,0x55,0x41,0x3E},	// 0xB8
{0x0A,0xFB,0x00,0xFF,0x00,0x00},	// 0xB9
{0x00,0xFF,0x00,0xFF,0x00,0x00},	// 0xBA
{0x0A,0xFA,0x02,0xFE,0x00,0x00},	// 0xBB
{0x0A,0x0B,0x08,0x0F,0x00,0x00},	// 0xBC
{0x00,0x18,0x24,0x66,0x24,0x00},	// 0xBD
{0x00,0x29,0x2A,0x7C,0x2A,0x29},	// 0xBE
{0x08,0x08,0x08,0xF8,0x00,0x00},	// 0xBF
{0x00,0x00,0x00,0x0F,0x08,0x08},	// 0xC0
{0x08,0x08,0x08,0x0F,0x08,0x08},	// 0xC1
{0x08,0x08,0x08,0xF8,0x08,0x08},	// 0xC2
{0x00,0x00,0x00,0xFF,0x08,0x08},	// 0xC3
{0x08,0x08,0x08,0x08,0x08,0x08},	// 0xC4
{0x08,0x08,0x08,0xFF,0x08,0x08},	// 0xC5
{0x00,0x7c,0x82,0x82,0x83,0x44},	// 0xC6
{0x00,0x70,0x2A,0x25,0x2A,0x71},	// 0xC7
{0x00,0x7c,0x83,0x82,0x83,0x44},	// 0xC8
{0x00,0xFE,0x02,0xFA,0x0A,0x0A},	// 0xC9
{0x0A,0x0B,0x08,0x0B,0x0A,0x0A},	// 0xCA
{0x0A,0xFA,0x02,0xFA,0x0A,0x0A},	// 0xCB
{0x00,0xFF,0x00,0xFB,0x0A,0x0A},	// 0xCC
{0x0A,0x0A,0x0A,0x0A,0x0A,0x0A},	// 0xCD
{0x0A,0xFB,0x00,0xFB,0x0A,0x0A},	// 0xCE
{0x00,0x5D,0x22,0x22,0x22,0x5D},	// 0xCF
{0x10,0xfe,0x92,0x82,0x82,0x7c},	// 0xD0
{0x00,0x08,0x7F,0x49,0x41,0x3E},	// 0xD1
{0x00,0x7C,0x55,0x55,0x55,0x44},	// 0xD2
{0x00,0x7C,0x55,0x54,0x55,0x44},	// 0xD3
{0x00,0x7C,0x55,0x55,0x54,0x44},	// 0xD4
{0x00,0x00,0x00,0x07,0x00,0x00},	// 0xD5
{0x00,0x00,0x44,0x7D,0x45,0x00},	// 0xD6
{0x00,0x00,0x45,0x7D,0x45,0x00},	// 0xD7
{0x00,0x00,0x45,0x7C,0x45,0x00},	// 0xD8
{0x08,0x08,0x08,0x0F,0x00,0x00},	// 0xD9
{0x00,0x00,0x00,0xF8,0x08,0x08},	// 0xDA
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},	// 0xDB
{0xF0,0xF0,0xF0,0xF0,0xF0,0xF0},	// 0xDC
{0x00,0x00,0x00,0x77,0x00,0x00},	// 0xDD
{0x00,0x00,0x45,0x7D,0x44,0x00},	// 0xDE
{0x0F,0x0F,0x0F,0x0F,0x0F,0x0F},	// 0xDF
{0x00,0x3C,0x42,0x43,0x3D,0x00},	// 0xE0
{0x00,0xFE,0x4A,0x4A,0x34,0x00},	// 0xE1
{0x00,0x3C,0x43,0x43,0x3D,0x00},	// 0xE2
{0x00,0x3D,0x43,0x42,0x3C,0x00},	// 0xE3
{0x00,0x32,0x49,0x4A,0x31,0x00},	// 0xE4
{0x00,0x3A,0x45,0x46,0x39,0x00},	// 0xE5
{0x00,0x38,0x44,0x46,0x45,0x28},	// 0xE6
{0x00,0xFE,0xAA,0x28,0x10,0x00},	// 0xE7
{0x00,0x38,0x45,0x46,0x45,0x28},	// 0xE8
{0x00,0x3C,0x40,0x41,0x3D,0x00},	// 0xE9
{0x00,0x3C,0x41,0x41,0x3D,0x00},	// 0xEA
{0x00,0x3D,0x41,0x40,0x3C,0x00},	// 0xEB
{0x00,0x9C,0xA0,0x61,0x3D,0x00},	// 0xEC
{0x00,0x04,0x08,0x71,0x09,0x04},	// 0xED
{0x00,0x00,0x02,0x02,0x02,0x00},	// 0xEE
{0x00,0x00,0x07,0x03,0x00,0x00},	// 0xEF
{0x38,0x44,0x44,0x45,0x7f,0x01},	// 0xF0
{0x00,0x00,0x24,0x2E,0x24,0x00},	// 0xF1
{0x00,0x24,0x24,0x24,0x24,0x24},	// 0xF2
{0x05,0x17,0x0A,0x34,0x2A,0x78},	// 0xF3
{0x00,0x06,0x09,0x7F,0x01,0x7F},	// 0xF4
{0x00,0x22,0x4D,0x55,0x59,0x22},	// 0xF5
{0x00,0x08,0x08,0x2A,0x08,0x08},	// 0xF6
{0x00,0x00,0x08,0x18,0x18,0x00},	// 0xF7
{0x00,0x06,0x09,0x09,0x06,0x00},	// 0xF8
{0x00,0x00,0x08,0x00,0x08,0x00},	// 0xF9
{0x00,0x00,0x08,0x00,0x00,0x00},	// 0xFA
{0x00,0x02,0x0F,0x00,0x00,0x00},	// 0xFB
{0x00,0x09,0x0F,0x05,0x00,0x00},	// 0xFC
{0x00,0x09,0x0D,0x0A,0x00,0x00},	// 0xFD
{0x00,0x3C,0x3C,0x3C,0x3C,0x00},	// 0xFE
{0x00,0x00,0x00,0x00,0x00,0x00} 	// 0xFF
};
