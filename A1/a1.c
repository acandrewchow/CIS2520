/*
Assignment Name: C Library
Course: CIS 2520
Name: Andrew Chow
Date: September 19th, 2021
Student ID: 1088114
*/
#include <stdio.h>
#include <string.h>
#include "a1.h"
//#include "get_bits.c"
#include "get_bits.h"

// Function checks string input and outputs the checksum value based upon the alphabet's order
// e.g a or A = 1
unsigned char checksum(char * string) {
    
    // Variable Declarations
    int sum = 0;
    int checkSum = 0;
    int i = 0;

    // Iterate the string until it reaches null character
    while (string[i] != '\0') {

        //printf("Character: %c\n", string[i]);
        //printf("%d", sum);

        // Iterate through the alphabet and assign values based on respective locations

         if ((string[i] == 'a') || (string[i] == 'A')) {

                sum+=0;
            }
            else if ((string[i] == 'b') || (string[i] == 'B')) {

                sum+=1;
            }
            else if ((string[i] == 'c') || (string[i] == 'C')) {

                sum+=2;
            }
            else if ((string[i] == 'd') || (string[i] == 'D')) {

                sum+=3;
            }
            else if ((string[i] == 'e') || (string[i] == 'E')) {

               sum+=4;
            }
            else if ((string[i] == 'f') || (string[i] == 'F')) {

                sum+=5;
            }
            else if ((string[i] == 'g') || (string[i] == 'G')) {

                sum+=6;
            }
            else if ((string[i] == 'h') || (string[i] == 'H')) {

                sum+=7;
            }
            else if ((string[i] == 'i') || (string[i] == 'I')) {

                sum+=8;
            }
            else if ((string[i] == 'j') || (string[i] == 'J')) {

                sum+=9;
            }
            else if ((string[i] == 'k') || (string[i] == 'K')) {

                sum+=10;
            }
            else if ((string[i] == 'l') || (string[i] == 'L')) {

                sum+=11;
            }
            else if ((string[i] == 'm') || (string[i] == 'M')) {

                sum+=12;
            }
            else if ((string[i] == 'n') || (string[i] == 'N')) {

                sum+=13;
            }
            else if ((string[i] == 'o') || (string[i] == 'O')) {

                sum+=14;
            }
            else if ((string[i] == 'p') || (string[i] == 'P')) {

                sum+=15;
            }
            else if ((string[i] == 'q') || (string[i] == 'Q')) {

                sum+=16;
            }
            else if ((string[i] == 'r') || (string[i] == 'R')) {

                sum+=17;
            }
            else if ((string[i] == 's') || (string[i] == 'S')) {

               sum+=18;
            }
            else if ((string[i] == 't') || (string[i] == 'T')) {

                sum+=19;
            }
            else if ((string[i] == 'u') || (string[i] == 'U')) {

                sum+=20;
            }
            else if ((string[i] == 'v') || (string[i] == 'V')) {

                sum+=21;
            }
            else if ((string[i] == 'w') || (string[i] == 'W')) {

                sum+=22;
            }
            else if ((string[i] == 'x') || (string[i] == 'X')) {

                sum+=23;
            }
            else if ((string[i] == 'y') || (string[i] == 'Y')) {

                sum+=24;
            }
            else if ((string[i] == 'z') || (string[i] == 'Z')) {

                sum+=25;
            }
        i++;
    }
    // Compute the sum
    printf("Sum = %d\n", sum);
    checkSum = (sum % 26);

    // Check if the checkSum is valid
    if (checkSum > 25) {

        printf("Check sum is greater than 25");
        return -1;
    }
    else {

        return checkSum;
    }
}

void caesar(char * string, int rshift) {
    
    // Variable Declarations
    char message;

    for (int i = 0; string[i] != '\0'; i++) {

       message = string[i];
       
       // Check if message is between uppercase A and Z
       if ((message >= 65) && (message <= 90)) {

           message+= rshift;        
           // wrap alphabet forward if greater than 'Z' or 90
           if (message > 90) {

               message = message - 26;
           }
           // wrap alphabet if less than 'A' or 65
           else if (message < 65) {

               message = message + 26;
           }
           string[i] = message;
       }
    }
}

void char2bits(char c, unsigned char bits[8]) {

    // Gathering 8 bits from index 0 to 7
    for (int i = 0; i < 8; i++) {
        
        // Access one bit at a time, while passing in the memory address of the character
        bits[i] = get_bits8(i, i+1, &c);

    }
}

void bits2str(int bitno, unsigned char * bits, char * bitstr) {

    for (int i = 0; i < bitno; i++) {

        bitstr[i] = bits[i] + '0';
        //printf("%d\n", bitstr[i]);
    }
    // replacing the last index with null character
    bitstr[bitno] = '\0';
}

void ushort2bits(unsigned short s, unsigned char bits[16]) {

    // Gathering 16 bits from index 0 to 15 - unsigned
    for (int i = 0; i < 16; i++) {

        bits[i] = get_bits16(i, i+1, &s);

    }
}

void short2bits(short s, unsigned char bits[16]) {

    // Gathering 16 bits from index 0 to 15 - signed
    for (int i = 0; i < 16; i++) {

        bits[i] = get_bits16(i, i+1, &s);
    }
}

short bits2short(char * bits) {

    // Variable Declarations
    short number = 0;
    short answer = 0;
    int counter = strlen(bits) - 1;
    int flag = 0;

    // printf("Counter before loop: %d", counter);

    for (int i = 0; i < strlen(bits); i++) {
        
        // Convert back
        number = bits[i] - '0';

        if (flag == 0) {

            // - (1 * 2^15) + (0 * 2^14) +..... (x * 2^N)
            answer += number<<counter;
            flag++;
        }
        else {

            answer +=number<<counter;
        }
        counter--;
    }
    //printf("flag value: %d", flag);
    return answer;
}

void spff(char * sign, char * exponent, char * significand, float * src) {

    // Variable Declarations
    unsigned char bits[32];
    char bitstr[32];
    int j = 0;
    int z = 0;
    
    // Get the 32 bits, then convert them to string to use operators on
    for (int i = 0; i < 32; i++) {
 
        bits[i] = get_bits32(i, i+1, src);
        bits2str(32, bits, bitstr);
        //printf("%c", bitstr[i]);
    }  

    // Loop through 32 bits assigning variables
    // 1 for sign, 8 for exponent, and 23 for significand
    for (int i = 0; i < 1; i++) {

        sign[i] = bitstr[i];
    }

    for (int i = 1; i < 9; i++) {

        exponent[j] = bitstr[i];
        j++;
    }

    for (int i = 9; i < 32; i++) {

        significand[z] = bitstr[i];
        z++;
    }
}

