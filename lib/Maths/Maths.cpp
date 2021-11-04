#include <Arduino.h>
#include "Maths.h"

int totalCoins(byte _total)
{
    switch (_total)
    {
    case 0x00:
        return 0;
        break;
    case 0x01:
        return 1;
        break;
    case 0x02:
        return 2;
        break;
    case 0x03:
        return 3;
        break;
    case 0x04:
        return 4;
        break;
    case 0x05:
        return 5;
        break;
    case 0x06:
        return 6;
        break;
    case 0x07:
        return 7;
        break;
    case 0x08:
        return 8;
        break;
    case 0x09:
        return 9;
        break;
    case 0x10:
        return 10;
        break;
    case 0x11:
        return 11;
        break;
    case 0x12:
        return 12;
        break;
    case 0x13:
        return 13;
        break;
    case 0x14:
        return 14;
        break;
    case 0x15:
        return 15;
        break;
    case 0x16:
        return 16;
        break;
    case 0x17:
        return 17;
        break;
    case 0x18:
        return 18;
        break;
    case 0x19:
        return 19;
        break;
    case 0x20:
        return 20;
        break;
    case 0x21:
        return 21;
        break;
    case 0x22:
        return 22;
        break;
    case 0x23:
        return 23;
        break;
    case 0x24:
        return 24;
        break;
    case 0x25:
        return 25;
        break;
    case 0x26:
        return 26;
        break;
    case 0x27:
        return 27;
        break;
    case 0x28:
        return 28;
        break;
    case 0x29:
        return 29;
        break;
    case 0x30:
        return 30;
        break;
    case 0x31:
        return 31;
        break;
    case 0x32:
        return 32;
        break;
    case 0x33:
        return 33;
        break;
    case 0x34:
        return 34;
        break;
    case 0x35:
        return 35;
        break;
    case 0x36:
        return 36;
        break;
    case 0x37:
        return 37;
        break;
    case 0x38:
        return 38;
        break;
    case 0x39:
        return 39;
        break;
    case 0x40:
        return 40;
        break;
    case 0x41:
        return 41;
        break;
    case 0x42:
        return 42;
        break;
    case 0x43:
        return 43;
        break;
    case 0x44:
        return 44;
        break;
    case 0x45:
        return 45;
        break;
    case 0x46:
        return 46;
        break;
    case 0x47:
        return 47;
        break;
    case 0x48:
        return 48;
        break;
    case 0x49:
        return 49;
        break;
    case 0x50:
        return 50;
        break;
    case 0x51:
        return 51;
        break;
    case 0x52:
        return 52;
        break;
    case 0x53:
        return 53;
        break;
    case 0x54:
        return 54;
        break;
    case 0x55:
        return 55;
        break;
    case 0x56:
        return 56;
        break;
    case 0x57:
        return 57;
        break;
    case 0x58:
        return 58;
        break;
    case 0x59:
        return 59;
        break;
    case 0x60:
        return 60;
        break;
    case 0x61:
        return 61;
        break;
    case 0x62:
        return 62;
        break;
    case 0x63:
        return 63;
        break;
    case 0x64:
        return 64;
        break;
    case 0x65:
        return 65;
        break;
    case 0x66:
        return 66;
        break;
    case 0x67:
        return 67;
        break;
    case 0x68:
        return 68;
        break;
    case 0x69:
        return 69;
        break;
    case 0x70:
        return 70;
        break;
    case 0x71:
        return 71;
        break;
    case 0x72:
        return 72;
        break;
    case 0x73:
        return 73;
        break;
    case 0x74:
        return 74;
        break;
    case 0x75:
        return 75;
        break;
    case 0x76:
        return 76;
        break;
    case 0x77:
        return 77;
        break;
    case 0x78:
        return 78;
        break;
    case 0x79:
        return 79;
        break;
    case 0x80:
        return 80;
        break;
    case 0x81:
        return 81;
        break;
    case 0x82:
        return 82;
        break;
    case 0x83:
        return 83;
        break;
    case 0x84:
        return 84;
        break;
    case 0x85:
        return 85;
        break;
    case 0x86:
        return 86;
        break;
    case 0x87:
        return 87;
        break;
    case 0x88:
        return 88;
        break;
    case 0x89:
        return 89;
        break;
    case 0x90:
        return 90;
        break;
    case 0x91:
        return 91;
        break;
    case 0x92:
        return 92;
        break;
    case 0x93:
        return 93;
        break;
    case 0x94:
        return 94;
        break;
    case 0x95:
        return 95;
        break;
    case 0x96:
        return 96;
        break;
    case 0x97:
        return 97;
        break;
    case 0x98:
        return 98;
        break;
    case 0x99:
        return 99;
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

byte *createTotalBill(byte b0, byte b1, byte b2)
{
    byte *payload = new byte[10];
    payload[0] = b0;
    payload[1] = b1;
    payload[2] = b2;
    return payload;
}

byte *totalBills(byte _total)
{
    switch (_total)
    {
    case 0x00:
        return createTotalBill(0x30, 0x30, 0x30);
        break;
    case 0x01:
        return createTotalBill(0x30, 0x30, 0x31);
        break;
    case 0x02:
        return createTotalBill(0x30, 0x30, 0x32);
        break;
    case 0x03:
        return createTotalBill(0x30, 0x30, 0x33);
        break;
    case 0x04:
        return createTotalBill(0x30, 0x30, 0x34);
        break;
    case 0x05:
        return createTotalBill(0x30, 0x30, 0x35);
        break;
    case 0x06:
        return createTotalBill(0x30, 0x30, 0x36);
        break;
    case 0x07:
        return createTotalBill(0x30, 0x30, 0x37);
        break;
    case 0x08:
        return createTotalBill(0x30, 0x30, 0x38);
        break;
    case 0x09:
        return createTotalBill(0x30, 0x30, 0x39);
        break;
    case 0x10:
        return createTotalBill(0x30, 0x31, 0x30);
        break;
    case 0x11:
        return createTotalBill(0x30, 0x31, 0x31);
        break;
    case 0x12:
        return createTotalBill(0x30, 0x31, 0x32);
        break;
    case 0x13:
        return createTotalBill(0x30, 0x31, 0x33);
        break;
    case 0x14:
        return createTotalBill(0x30, 0x31, 0x34);
        break;
    case 0x15:
        return createTotalBill(0x30, 0x31, 0x35);
        break;
    case 0x16:
        return createTotalBill(0x30, 0x31, 0x36);
        break;
    case 0x17:
        return createTotalBill(0x30, 0x31, 0x37);
        break;
    case 0x18:
        return createTotalBill(0x30, 0x31, 0x38);
        break;
    case 0x19:
        return createTotalBill(0x30, 0x31, 0x39);
        break;
    case 0x20:
        return createTotalBill(0x30, 0x32, 0x30);
        break;
    case 0x21:
        return createTotalBill(0x30, 0x32, 0x31);
        break;
    case 0x22:
        return createTotalBill(0x30, 0x32, 0x32);
        break;
    case 0x23:
        return createTotalBill(0x30, 0x32, 0x33);
        break;
    case 0x24:
        return createTotalBill(0x30, 0x32, 0x34);
        break;
    case 0x25:
        return createTotalBill(0x30, 0x32, 0x35);
        break;
    case 0x26:
        return createTotalBill(0x30, 0x32, 0x36);
        break;
    case 0x27:
        return createTotalBill(0x30, 0x32, 0x37);
        break;
    case 0x28:
        return createTotalBill(0x30, 0x32, 0x38);
        break;
    case 0x29:
        return createTotalBill(0x30, 0x32, 0x39);
        break;
    case 0x30:
        return createTotalBill(0x30, 0x33, 0x30);
        break;
    case 0x31:
        return createTotalBill(0x30, 0x33, 0x31);
        break;
    case 0x32:
        return createTotalBill(0x30, 0x33, 0x32);
        break;
    case 0x33:
        return createTotalBill(0x30, 0x33, 0x33);
        break;
    case 0x34:
        return createTotalBill(0x30, 0x33, 0x34);
        break;
    case 0x35:
        return createTotalBill(0x30, 0x33, 0x35);
        break;
    case 0x36:
        return createTotalBill(0x30, 0x33, 0x36);
        break;
    case 0x37:
        return createTotalBill(0x30, 0x33, 0x37);
        break;
    case 0x38:
        return createTotalBill(0x30, 0x33, 0x38);
        break;
    case 0x39:
        return createTotalBill(0x30, 0x33, 0x39);
        break;
    case 0x40:
        return createTotalBill(0x30, 0x34, 0x30);
        break;
    case 0x41:
        return createTotalBill(0x30, 0x34, 0x31);
        break;
    case 0x42:
        return createTotalBill(0x30, 0x34, 0x32);
        break;
    case 0x43:
        return createTotalBill(0x30, 0x34, 0x33);
        break;
    case 0x44:
        return createTotalBill(0x30, 0x34, 0x34);
        break;
    case 0x45:
        return createTotalBill(0x30, 0x34, 0x35);
        break;
    case 0x46:
        return createTotalBill(0x30, 0x34, 0x36);
        break;
    case 0x47:
        return createTotalBill(0x30, 0x34, 0x37);
        break;
    case 0x48:
        return createTotalBill(0x30, 0x34, 0x38);
        break;
    case 0x49:
        return createTotalBill(0x30, 0x34, 0x39);
        break;
    case 0x50:
        return createTotalBill(0x30, 0x35, 0x30);
        break;
    case 0x51:
        return createTotalBill(0x30, 0x35, 0x31);
        break;
    case 0x52:
        return createTotalBill(0x30, 0x35, 0x32);
        break;
    case 0x53:
        return createTotalBill(0x30, 0x35, 0x33);
        break;
    case 0x54:
        return createTotalBill(0x30, 0x35, 0x34);
        break;
    case 0x55:
        return createTotalBill(0x30, 0x35, 0x35);
        break;
    case 0x56:
        return createTotalBill(0x30, 0x35, 0x36);
        break;
    case 0x57:
        return createTotalBill(0x30, 0x35, 0x37);
        break;
    case 0x58:
        return createTotalBill(0x30, 0x35, 0x38);
        break;
    case 0x59:
        return createTotalBill(0x30, 0x35, 0x39);
        break;
    case 0x60:
        return createTotalBill(0x30, 0x36, 0x30);
        break;
    case 0x61:
        return createTotalBill(0x30, 0x36, 0x31);
        break;
    case 0x62:
        return createTotalBill(0x30, 0x36, 0x32);
        break;
    case 0x63:
        return createTotalBill(0x30, 0x36, 0x33);
        break;
    case 0x64:
        return createTotalBill(0x30, 0x36, 0x34);
        break;
    case 0x65:
        return createTotalBill(0x30, 0x36, 0x35);
        break;
    case 0x66:
        return createTotalBill(0x30, 0x36, 0x36);
        break;
    case 0x67:
        return createTotalBill(0x30, 0x36, 0x37);
        break;
    case 0x68:
        return createTotalBill(0x30, 0x36, 0x38);
        break;
    case 0x69:
        return createTotalBill(0x30, 0x36, 0x39);
        break;
    case 0x70:
        return createTotalBill(0x30, 0x37, 0x30);
        break;
    case 0x71:
        return createTotalBill(0x30, 0x37, 0x31);
        break;
    case 0x72:
        return createTotalBill(0x30, 0x37, 0x32);
        break;
    case 0x73:
        return createTotalBill(0x30, 0x37, 0x33);
        break;
    case 0x74:
        return createTotalBill(0x30, 0x37, 0x34);
        break;
    case 0x75:
        return createTotalBill(0x30, 0x37, 0x35);
        break;
    case 0x76:
        return createTotalBill(0x30, 0x37, 0x36);
        break;
    case 0x77:
        return createTotalBill(0x30, 0x37, 0x37);
        break;
    case 0x78:
        return createTotalBill(0x30, 0x37, 0x38);
        break;
    case 0x79:
        return createTotalBill(0x30, 0x37, 0x39);
        break;
    case 0x80:
        return createTotalBill(0x30, 0x38, 0x30);
        break;
    case 0x81:
        return createTotalBill(0x30, 0x38, 0x31);
        break;
    case 0x82:
        return createTotalBill(0x30, 0x38, 0x32);
        break;
    case 0x83:
        return createTotalBill(0x30, 0x38, 0x33);
        break;
    case 0x84:
        return createTotalBill(0x30, 0x38, 0x34);
        break;
    case 0x85:
        return createTotalBill(0x30, 0x38, 0x35);
        break;
    case 0x86:
        return createTotalBill(0x30, 0x38, 0x36);
        break;
    case 0x87:
        return createTotalBill(0x30, 0x38, 0x37);
        break;
    case 0x88:
        return createTotalBill(0x30, 0x38, 0x38);
        break;
    case 0x89:
        return createTotalBill(0x30, 0x38, 0x39);
        break;
    case 0x90:
        return createTotalBill(0x30, 0x39, 0x30);
        break;
    case 0x91:
        return createTotalBill(0x30, 0x39, 0x31);
        break;
    case 0x92:
        return createTotalBill(0x30, 0x39, 0x32);
        break;
    case 0x93:
        return createTotalBill(0x30, 0x39, 0x33);
        break;
    case 0x94:
        return createTotalBill(0x30, 0x39, 0x34);
        break;
    case 0x95:
        return createTotalBill(0x30, 0x39, 0x35);
        break;
    case 0x96:
        return createTotalBill(0x30, 0x39, 0x36);
        break;
    case 0x97:
        return createTotalBill(0x30, 0x39, 0x37);
        break;
    case 0x98:
        return createTotalBill(0x30, 0x39, 0x38);
        break;
    case 0x99:
        return createTotalBill(0x30, 0x39, 0x39);
        break;
    default:
        return createTotalBill(0x30, 0x30, 0x30);
        break;
    }
    return createTotalBill(0x30, 0x30, 0x30);
}

int checkCoinsDispensed(byte b1, byte b2, byte b3)
{
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x30)
    {
        return 0;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x31)
    {
        return 1;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x32)
    {
        return 2;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x33)
    {
        return 3;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x34)
    {
        return 4;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x35)
    {
        return 5;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x36)
    {
        return 6;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x37)
    {
        return 7;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x38)
    {
        return 8;
    }
    if (b1 == 0x30 && b2 == 0x30 && b3 == 0x39)
    {
        return 9;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x30)
    {
        return 10;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x31)
    {
        return 11;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x32)
    {
        return 12;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x33)
    {
        return 13;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x34)
    {
        return 14;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x35)
    {
        return 15;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x36)
    {
        return 16;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x37)
    {
        return 17;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x38)
    {
        return 18;
    }
    if (b1 == 0x30 && b2 == 0x31 && b3 == 0x39)
    {
        return 19;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x30)
    {
        return 20;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x31)
    {
        return 21;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x32)
    {
        return 22;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x33)
    {
        return 23;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x34)
    {
        return 24;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x35)
    {
        return 25;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x36)
    {
        return 26;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x37)
    {
        return 27;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x38)
    {
        return 28;
    }
    if (b1 == 0x30 && b2 == 0x32 && b3 == 0x39)
    {
        return 29;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x30)
    {
        return 30;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x31)
    {
        return 31;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x32)
    {
        return 32;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x33)
    {
        return 33;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x34)
    {
        return 34;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x35)
    {
        return 35;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x36)
    {
        return 36;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x37)
    {
        return 37;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x38)
    {
        return 38;
    }
    if (b1 == 0x30 && b2 == 0x33 && b3 == 0x39)
    {
        return 39;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x30)
    {
        return 40;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x31)
    {
        return 41;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x32)
    {
        return 42;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x33)
    {
        return 43;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x34)
    {
        return 44;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x35)
    {
        return 45;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x36)
    {
        return 46;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x37)
    {
        return 47;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x38)
    {
        return 48;
    }
    if (b1 == 0x30 && b2 == 0x34 && b3 == 0x39)
    {
        return 49;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x30)
    {
        return 50;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x31)
    {
        return 51;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x32)
    {
        return 52;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x33)
    {
        return 53;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x34)
    {
        return 54;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x35)
    {
        return 55;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x36)
    {
        return 56;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x37)
    {
        return 57;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x38)
    {
        return 58;
    }
    if (b1 == 0x30 && b2 == 0x35 && b3 == 0x39)
    {
        return 59;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x30)
    {
        return 60;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x31)
    {
        return 61;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x32)
    {
        return 62;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x33)
    {
        return 63;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x34)
    {
        return 64;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x35)
    {
        return 65;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x36)
    {
        return 66;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x37)
    {
        return 67;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x38)
    {
        return 68;
    }
    if (b1 == 0x30 && b2 == 0x36 && b3 == 0x39)
    {
        return 69;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x30)
    {
        return 70;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x31)
    {
        return 71;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x32)
    {
        return 72;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x33)
    {
        return 73;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x34)
    {
        return 74;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x35)
    {
        return 75;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x36)
    {
        return 76;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x37)
    {
        return 77;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x38)
    {
        return 78;
    }
    if (b1 == 0x30 && b2 == 0x37 && b3 == 0x39)
    {
        return 79;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x30)
    {
        return 80;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x31)
    {
        return 81;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x32)
    {
        return 82;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x33)
    {
        return 83;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x34)
    {
        return 84;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x35)
    {
        return 85;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x36)
    {
        return 86;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x37)
    {
        return 87;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x38)
    {
        return 88;
    }
    if (b1 == 0x30 && b2 == 0x38 && b3 == 0x39)
    {
        return 89;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x30)
    {
        return 90;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x31)
    {
        return 91;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x32)
    {
        return 92;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x33)
    {
        return 93;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x34)
    {
        return 94;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x35)
    {
        return 95;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x36)
    {
        return 96;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x37)
    {
        return 97;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x38)
    {
        return 98;
    }
    if (b1 == 0x30 && b2 == 0x39 && b3 == 0x39)
    {
        return 99;
    }
    return 0;
}

byte *totalBillsWithError(int _total)
{
    switch (_total)
    {
    case 0:
        return createTotalBill(0x30, 0x30, 0x30);
        break;
    case 1:
        return createTotalBill(0x30, 0x30, 0x31);
        break;
    case 2:
        return createTotalBill(0x30, 0x30, 0x32);
        break;
    case 3:
        return createTotalBill(0x30, 0x30, 0x33);
        break;
    case 4:
        return createTotalBill(0x30, 0x30, 0x34);
        break;
    case 5:
        return createTotalBill(0x30, 0x30, 0x35);
        break;
    case 6:
        return createTotalBill(0x30, 0x30, 0x36);
        break;
    case 7:
        return createTotalBill(0x30, 0x30, 0x37);
        break;
    case 8:
        return createTotalBill(0x30, 0x30, 0x38);
        break;
    case 9:
        return createTotalBill(0x30, 0x30, 0x39);
        break;
    case 10:
        return createTotalBill(0x30, 0x31, 0x30);
        break;
    case 11:
        return createTotalBill(0x30, 0x31, 0x31);
        break;
    case 12:
        return createTotalBill(0x30, 0x31, 0x32);
        break;
    case 13:
        return createTotalBill(0x30, 0x31, 0x33);
        break;
    case 14:
        return createTotalBill(0x30, 0x31, 0x34);
        break;
    case 15:
        return createTotalBill(0x30, 0x31, 0x35);
        break;
    case 16:
        return createTotalBill(0x30, 0x31, 0x36);
        break;
    case 17:
        return createTotalBill(0x30, 0x31, 0x37);
        break;
    case 18:
        return createTotalBill(0x30, 0x31, 0x38);
        break;
    case 19:
        return createTotalBill(0x30, 0x31, 0x39);
        break;
    case 20:
        return createTotalBill(0x30, 0x32, 0x30);
        break;
    case 21:
        return createTotalBill(0x30, 0x32, 0x31);
        break;
    case 22:
        return createTotalBill(0x30, 0x32, 0x32);
        break;
    case 23:
        return createTotalBill(0x30, 0x32, 0x33);
        break;
    case 24:
        return createTotalBill(0x30, 0x32, 0x34);
        break;
    case 25:
        return createTotalBill(0x30, 0x32, 0x35);
        break;
    case 26:
        return createTotalBill(0x30, 0x32, 0x36);
        break;
    case 27:
        return createTotalBill(0x30, 0x32, 0x37);
        break;
    case 28:
        return createTotalBill(0x30, 0x32, 0x38);
        break;
    case 29:
        return createTotalBill(0x30, 0x32, 0x39);
        break;
    case 30:
        return createTotalBill(0x30, 0x33, 0x30);
        break;
    case 31:
        return createTotalBill(0x30, 0x33, 0x31);
        break;
    case 32:
        return createTotalBill(0x30, 0x33, 0x32);
        break;
    case 33:
        return createTotalBill(0x30, 0x33, 0x33);
        break;
    case 34:
        return createTotalBill(0x30, 0x33, 0x34);
        break;
    case 35:
        return createTotalBill(0x30, 0x33, 0x35);
        break;
    case 36:
        return createTotalBill(0x30, 0x33, 0x36);
        break;
    case 37:
        return createTotalBill(0x30, 0x33, 0x37);
        break;
    case 38:
        return createTotalBill(0x30, 0x33, 0x38);
        break;
    case 39:
        return createTotalBill(0x30, 0x33, 0x39);
        break;
    case 40:
        return createTotalBill(0x30, 0x34, 0x30);
        break;
    case 41:
        return createTotalBill(0x30, 0x34, 0x31);
        break;
    case 42:
        return createTotalBill(0x30, 0x34, 0x32);
        break;
    case 43:
        return createTotalBill(0x30, 0x34, 0x33);
        break;
    case 44:
        return createTotalBill(0x30, 0x34, 0x34);
        break;
    case 45:
        return createTotalBill(0x30, 0x34, 0x35);
        break;
    case 46:
        return createTotalBill(0x30, 0x34, 0x36);
        break;
    case 47:
        return createTotalBill(0x30, 0x34, 0x37);
        break;
    case 48:
        return createTotalBill(0x30, 0x34, 0x38);
        break;
    case 49:
        return createTotalBill(0x30, 0x34, 0x39);
        break;
    case 50:
        return createTotalBill(0x30, 0x35, 0x30);
        break;
    case 51:
        return createTotalBill(0x30, 0x35, 0x31);
        break;
    case 52:
        return createTotalBill(0x30, 0x35, 0x32);
        break;
    case 53:
        return createTotalBill(0x30, 0x35, 0x33);
        break;
    case 54:
        return createTotalBill(0x30, 0x35, 0x34);
        break;
    case 55:
        return createTotalBill(0x30, 0x35, 0x35);
        break;
    case 56:
        return createTotalBill(0x30, 0x35, 0x36);
        break;
    case 57:
        return createTotalBill(0x30, 0x35, 0x37);
        break;
    case 58:
        return createTotalBill(0x30, 0x35, 0x38);
        break;
    case 59:
        return createTotalBill(0x30, 0x35, 0x39);
        break;
    case 60:
        return createTotalBill(0x30, 0x36, 0x30);
        break;
    case 61:
        return createTotalBill(0x30, 0x36, 0x31);
        break;
    case 62:
        return createTotalBill(0x30, 0x36, 0x32);
        break;
    case 63:
        return createTotalBill(0x30, 0x36, 0x33);
        break;
    case 64:
        return createTotalBill(0x30, 0x36, 0x34);
        break;
    case 65:
        return createTotalBill(0x30, 0x36, 0x35);
        break;
    case 66:
        return createTotalBill(0x30, 0x36, 0x36);
        break;
    case 67:
        return createTotalBill(0x30, 0x36, 0x37);
        break;
    case 68:
        return createTotalBill(0x30, 0x36, 0x38);
        break;
    case 69:
        return createTotalBill(0x30, 0x36, 0x39);
        break;
    case 70:
        return createTotalBill(0x30, 0x37, 0x30);
        break;
    case 71:
        return createTotalBill(0x30, 0x37, 0x31);
        break;
    case 72:
        return createTotalBill(0x30, 0x37, 0x32);
        break;
    case 73:
        return createTotalBill(0x30, 0x37, 0x33);
        break;
    case 74:
        return createTotalBill(0x30, 0x37, 0x34);
        break;
    case 75:
        return createTotalBill(0x30, 0x37, 0x35);
        break;
    case 76:
        return createTotalBill(0x30, 0x37, 0x36);
        break;
    case 77:
        return createTotalBill(0x30, 0x37, 0x37);
        break;
    case 78:
        return createTotalBill(0x30, 0x37, 0x38);
        break;
    case 79:
        return createTotalBill(0x30, 0x37, 0x39);
        break;
    case 80:
        return createTotalBill(0x30, 0x38, 0x30);
        break;
    case 81:
        return createTotalBill(0x30, 0x38, 0x31);
        break;
    case 82:
        return createTotalBill(0x30, 0x38, 0x32);
        break;
    case 83:
        return createTotalBill(0x30, 0x38, 0x33);
        break;
    case 84:
        return createTotalBill(0x30, 0x38, 0x34);
        break;
    case 85:
        return createTotalBill(0x30, 0x38, 0x35);
        break;
    case 86:
        return createTotalBill(0x30, 0x38, 0x36);
        break;
    case 87:
        return createTotalBill(0x30, 0x38, 0x37);
        break;
    case 88:
        return createTotalBill(0x30, 0x38, 0x38);
        break;
    case 89:
        return createTotalBill(0x30, 0x38, 0x39);
        break;
    case 90:
        return createTotalBill(0x30, 0x39, 0x30);
        break;
    case 91:
        return createTotalBill(0x30, 0x39, 0x31);
        break;
    case 92:
        return createTotalBill(0x30, 0x39, 0x32);
        break;
    case 93:
        return createTotalBill(0x30, 0x39, 0x33);
        break;
    case 94:
        return createTotalBill(0x30, 0x39, 0x34);
        break;
    case 95:
        return createTotalBill(0x30, 0x39, 0x35);
        break;
    case 96:
        return createTotalBill(0x30, 0x39, 0x36);
        break;
    case 97:
        return createTotalBill(0x30, 0x39, 0x37);
        break;
    case 98:
        return createTotalBill(0x30, 0x39, 0x38);
        break;
    case 99:
        return createTotalBill(0x30, 0x39, 0x39);
        break;
    default:
        return createTotalBill(0x30, 0x30, 0x30);
        break;
    }
    return createTotalBill(0x30, 0x30, 0x30);
}

byte totalByteDispensedCheck(int _total)
{
    if (_total == 0)
    {
        return 0x00;
    }
    if (_total == 1)
    {
        return 0x01;
    }
    if (_total == 2)
    {
        return 0x02;
    }
    if (_total == 3)
    {
        return 0x03;
    }
    if (_total == 4)
    {
        return 0x04;
    }
    if (_total == 5)
    {
        return 0x05;
    }
    if (_total == 6)
    {
        return 0x06;
    }
    if (_total == 7)
    {
        return 0x07;
    }
    if (_total == 8)
    {
        return 0x08;
    }
    if (_total == 9)
    {
        return 0x09;
    }
    if (_total == 10)
    {
        return 0x10;
    }
    if (_total == 11)
    {
        return 0x11;
    }
    if (_total == 12)
    {
        return 0x12;
    }
    if (_total == 13)
    {
        return 0x13;
    }
    if (_total == 14)
    {
        return 0x14;
    }
    if (_total == 15)
    {
        return 0x15;
    }
    if (_total == 16)
    {
        return 0x16;
    }
    if (_total == 17)
    {
        return 0x17;
    }
    if (_total == 18)
    {
        return 0x18;
    }
    if (_total == 19)
    {
        return 0x19;
    }
    if (_total == 20)
    {
        return 0x20;
    }
    if (_total == 21)
    {
        return 0x21;
    }
    if (_total == 22)
    {
        return 0x22;
    }
    if (_total == 23)
    {
        return 0x23;
    }
    if (_total == 24)
    {
        return 0x24;
    }
    if (_total == 25)
    {
        return 0x25;
    }
    if (_total == 26)
    {
        return 0x26;
    }
    if (_total == 27)
    {
        return 0x27;
    }
    if (_total == 28)
    {
        return 0x28;
    }
    if (_total == 29)
    {
        return 0x29;
    }
    if (_total == 30)
    {
        return 0x30;
    }
    if (_total == 31)
    {
        return 0x31;
    }
    if (_total == 32)
    {
        return 0x32;
    }
    if (_total == 33)
    {
        return 0x33;
    }
    if (_total == 34)
    {
        return 0x34;
    }
    if (_total == 35)
    {
        return 0x35;
    }
    if (_total == 36)
    {
        return 0x36;
    }
    if (_total == 37)
    {
        return 0x37;
    }
    if (_total == 38)
    {
        return 0x38;
    }
    if (_total == 39)
    {
        return 0x39;
    }
    if (_total == 40)
    {
        return 0x40;
    }
    if (_total == 41)
    {
        return 0x41;
    }
    if (_total == 42)
    {
        return 0x42;
    }
    if (_total == 43)
    {
        return 0x43;
    }
    if (_total == 44)
    {
        return 0x44;
    }
    if (_total == 45)
    {
        return 0x45;
    }
    if (_total == 46)
    {
        return 0x46;
    }
    if (_total == 47)
    {
        return 0x47;
    }
    if (_total == 48)
    {
        return 0x48;
    }
    if (_total == 49)
    {
        return 0x49;
    }
    if (_total == 50)
    {
        return 0x50;
    }
    if (_total == 51)
    {
        return 0x51;
    }
    if (_total == 52)
    {
        return 0x52;
    }
    if (_total == 53)
    {
        return 0x53;
    }
    if (_total == 54)
    {
        return 0x54;
    }
    if (_total == 55)
    {
        return 0x55;
    }
    if (_total == 56)
    {
        return 0x56;
    }
    if (_total == 57)
    {
        return 0x57;
    }
    if (_total == 58)
    {
        return 0x58;
    }
    if (_total == 59)
    {
        return 0x59;
    }
    if (_total == 60)
    {
        return 0x60;
    }
    if (_total == 61)
    {
        return 0x61;
    }
    if (_total == 62)
    {
        return 0x62;
    }
    if (_total == 63)
    {
        return 0x63;
    }
    if (_total == 64)
    {
        return 0x64;
    }
    if (_total == 65)
    {
        return 0x65;
    }
    if (_total == 66)
    {
        return 0x66;
    }
    if (_total == 67)
    {
        return 0x67;
    }
    if (_total == 68)
    {
        return 0x68;
    }
    if (_total == 69)
    {
        return 0x69;
    }
    if (_total == 70)
    {
        return 0x70;
    }
    if (_total == 71)
    {
        return 0x71;
    }
    if (_total == 72)
    {
        return 0x72;
    }
    if (_total == 73)
    {
        return 0x73;
    }
    if (_total == 74)
    {
        return 0x74;
    }
    if (_total == 75)
    {
        return 0x75;
    }
    if (_total == 76)
    {
        return 0x76;
    }
    if (_total == 77)
    {
        return 0x77;
    }
    if (_total == 78)
    {
        return 0x78;
    }
    if (_total == 79)
    {
        return 0x79;
    }
    if (_total == 80)
    {
        return 0x80;
    }
    if (_total == 81)
    {
        return 0x81;
    }
    if (_total == 82)
    {
        return 0x82;
    }
    if (_total == 83)
    {
        return 0x83;
    }
    if (_total == 84)
    {
        return 0x84;
    }
    if (_total == 85)
    {
        return 0x85;
    }
    if (_total == 86)
    {
        return 0x86;
    }
    if (_total == 87)
    {
        return 0x87;
    }
    if (_total == 88)
    {
        return 0x88;
    }
    if (_total == 89)
    {
        return 0x89;
    }
    if (_total == 90)
    {
        return 0x90;
    }
    if (_total == 91)
    {
        return 0x91;
    }
    if (_total == 92)
    {
        return 0x92;
    }
    if (_total == 93)
    {
        return 0x93;
    }
    if (_total == 94)
    {
        return 0x94;
    }
    if (_total == 95)
    {
        return 0x95;
    }
    if (_total == 96)
    {
        return 0x96;
    }
    if (_total == 97)
    {
        return 0x97;
    }
    if (_total == 98)
    {
        return 0x98;
    }
    if (_total == 99)
    {
        return 0x99;
    }
    return 0x00;
}