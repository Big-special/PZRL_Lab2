#include <string.h>
#include <stdlib.h>
#include "bin.h"
#include "reverse.h"

int bin_to_dec(char *bin) {
    int sign;
    int i = 0;
    if (bin[0] == '-') {
        sign = -1;
        ++i;
    } else {
        sign = 1;
    }

    int dec = 0;

    while (bin[i] != '\0') {
        if (bin[i] == '\n') {
            break;
        }
        dec = dec * 2 + (bin[i] - '0');
        i++;
    }
    return dec * sign;
}

char *dec_to_bin(int dec) {
    char* bin = malloc(128);
    memset(bin, 0, 128);
    if (dec == 0) {
        bin[0] = '0';
        bin[1] = '\0';
        return bin;
    }

    int sign = dec >= 0 ? 1 : -1;
    dec = dec < 0 ? -dec : dec;

    int i = 0;


    while (dec != 0) {
        bin[i] = dec % 2 + '0';
        i++;
        dec = dec / 2;
    }

    bin[i] = '\0';

    if (sign > 0) {
        return strreverse(bin);
    } else {
        char* res = malloc(128);
        memset(res, 0, 128);
        res[0] = '-';
        strcat(res, strreverse(bin));
        return res;
    }
}

char* bnot_bin(char *bin) {
    int dec = bin_to_dec(bin);
    int bnot = ~dec;
    char* res = dec_to_bin(bnot);
    return res;
}
