#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int roman_to_decimal(char roman[]) {
    int decimal = 0;
    int i;
    for (i = 0; i < strlen(roman); i++) {
        switch (roman[i]) {
            case 'I':
                if (roman[i + 1] == 'V' || roman[i + 1] == 'X') {
                    decimal -= 1;
                } else {
                    decimal += 1;
                }
                break;
            case 'V':
                decimal += 5;
                break;
            case 'X':
                if (roman[i + 1] == 'L' || roman[i + 1] == 'C') {
                    decimal -= 10;
                } else {
                    decimal += 10;
                }
                break;
            case 'L':
                decimal += 50;
                break;
            case 'C':
                if (roman[i + 1] == 'D' || roman[i + 1] == 'M') {
                    decimal -= 100;
                } else {
                    decimal += 100;
                }
                break;
            case 'D':
                decimal += 500;
                break;
            case 'M':
                decimal += 1000;
                break;
        }
    }
    return decimal;
}

void decimal_to_binary(int decimal) {
    int binary[32];
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

void decimal_to_hexadecimal(int decimal) {
    char hexadecimal[32];
    int i = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder + 'A' - 10;
        }
        decimal /= 16;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", tolower(hexadecimal[j]));
    }
    printf("\n");
}

int main() {
    char roman[13];
    
    scanf("%s", roman);
    int decimal = roman_to_decimal(roman);

    printf("%s na base 2: ", roman);
    decimal_to_binary(decimal);

    printf("%s na base 10: %d\n", roman, decimal);

    printf("%s na base 16: ", roman);
    decimal_to_hexadecimal(decimal);
    return 0;
}
