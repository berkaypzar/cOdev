#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 250


float myAtof(char* string, char* error);

int main() {
    char string[SIZE]; // Maximum size 250
    printf("Enter a number:\n");
    char errorState=0;
    gets(string); // read input from the user

    char error;
    float result = myAtof(string, &error);
    if (error == 0) {
        printf("Your number is: %.2f\n", result);
    } else {
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}

float myAtof(char* string, char* error) {
    // Check if the string is empty
    if (*string == '\0') {
        *error = 1;
        return 0.0f;
    }

    char* endptr;
    float result = strtof(string, &endptr);


    if (endptr == string || (*endptr != '\0' && !isspace(*endptr))) {
        *error = 1;
        return 0.0f;
    }

    *error = 0;
    return result;
}
