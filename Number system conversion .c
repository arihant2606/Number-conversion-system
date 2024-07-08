#include <stdio.h>
#include <stdlib.h>

long long convertDecimalToBinary(int decimalNumber);
int convertBinaryToDecimal(long long binaryNumber);
long long convertDecimalToOctal(int decimalNumber);
int convertOctalToDecimal(long long octalNumber);
long long convertDecimalToHexadecimal(int decimalNumber);
int convertHexadecimalToDecimal(char hexNumber[]);

int main() {
    int choice;
    int decimalNumber;
    long long binaryNumber, octalNumber;
    char hexNumber[100];

    printf("Choose the type of conversion:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Decimal to Octal\n");
    printf("4. Octal to Decimal\n");
    printf("5. Decimal to Hexadecimal\n");
    printf("6. Hexadecimal to Decimal\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            printf("Binary equivalent: %lld\n", convertDecimalToBinary(decimalNumber));
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%lld", &binaryNumber);
            printf("Decimal equivalent: %d\n", convertBinaryToDecimal(binaryNumber));
            break;
        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            printf("Octal equivalent: %lld\n", convertDecimalToOctal(decimalNumber));
            break;
        case 4:
            printf("Enter an octal number: ");
            scanf("%lld", &octalNumber);
            printf("Decimal equivalent: %d\n", convertOctalToDecimal(octalNumber));
            break;
        case 5:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            printf("Hexadecimal equivalent: 0x%llx\n", convertDecimalToHexadecimal(decimalNumber));
            break;
        case 6:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNumber);
            printf("Decimal equivalent: %d\n", convertHexadecimalToDecimal(hexNumber));
            break;
        default:
            printf("Invalid choice! Please choose a number between 1 and 6.\n");
    }

    return 0;
}

long long convertDecimalToBinary(int decimalNumber) {
    long long binaryNumber = 0;
    int remainder, base = 1;

    while (decimalNumber > 0) {
        remainder = decimalNumber % 2;
        binaryNumber += remainder * base;
        decimalNumber /= 2;
        base *= 10;
    }

    return binaryNumber;
}

int convertBinaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, remainder, base = 1;

    while (binaryNumber > 0) {
        remainder = binaryNumber % 10;
        decimalNumber += remainder * base;
        binaryNumber /= 10;
        base *= 2;
    }

    return decimalNumber;
}

long long convertDecimalToOctal(int decimalNumber) {
    long long octalNumber = 0;
    int remainder, base = 1;

    while (decimalNumber > 0) {
        remainder = decimalNumber % 8;
        octalNumber += remainder * base;
        decimalNumber /= 8;
        base *= 10;
    }

    return octalNumber;
}

int convertOctalToDecimal(long long octalNumber) {
    int decimalNumber = 0, remainder, base = 1;

    while (octalNumber > 0) {
        remainder = octalNumber % 10;
        decimalNumber += remainder * base;
        octalNumber /= 10;
        base *= 8;
    }

    return decimalNumber;
}

long long convertDecimalToHexadecimal(int decimalNumber) {
    long long hexadecimalNumber = 0;
    int remainder, base = 1;

    while (decimalNumber > 0) {
        remainder = decimalNumber % 16;
        hexadecimalNumber += remainder * base;
        decimalNumber /= 16;
        base *= 10;
    }

    return hexadecimalNumber;
}

int convertHexadecimalToDecimal(char hexNumber[]) {
    int decimalNumber = 0, base = 1, i = 0, value;

    while (hexNumber[i] != '\0') {
        i++;
    }
    i--;

    while (i >= 0) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            value = hexNumber[i] - '0';
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            value = hexNumber[i] - 'A' + 10;
        } else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') {
            value = hexNumber[i] - 'a' + 10;
        } else {
            printf("Invalid hex character: %c\n", hexNumber[i]);
            return 0;
        }

        decimalNumber += value * base;
        base *= 16;
        i--;
    }

    return decimalNumber;
}
