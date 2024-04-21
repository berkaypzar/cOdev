#include <stdio.h>
#include <stdlib.h>
#define SIZE 250

float myAtof(char *string, char *error);
void evaluate(char* string, char* error);

int main() {
    char string[SIZE];           
    char errorState = 0;

    printf("Enter arithmetic operation:\n");
    gets(string);

    evaluate(string, &errorState);

    if (errorState == 1) {
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}

#define isDigit(c) (c >= '0' && c <= '9')

float myAtof(char* string, char* error) {
                                  
    int e = 0;                                       
    double num = 0.0; 
       int c;
*error = 0;                                       
    while ((c = *string++) != '\0' && isDigit(c)) { 
        num = num * 10.0 + (c - '0');                     
    }
    if (c == '.') {                               
        while ((c = *string++) != '\0' && isDigit(c)) { 
            num = num * 10.0 + (c - '0');                     
            e = e - 1;                              
        }
    }
    else if (!isDigit(c) && c != '\0') {               
        *error = 1;                                   
    }
    
    while (e > 0) {                                 
        num *= 10.0;
        e--;
    }
    while (e < 0) {
        num *= 0.1;
        e++;
    }
    return (float)num;
}

#define isOperator(c) (c == '+' || c == '-' || c == '*' || c == '/')

void evaluate(char* string, char* error) {
    char s[SIZE];                                             
    int i = 0;
    int c = *string++, operand;
    while (c != '\0' && !isOperator(c)) {                          
        s[i++] = c;
        c = *string++;
    }
    s[i] = '\0';
    float n1 = 0.00;
    if (i > 0) {                                                    
        n1 = myAtof(s, error);                                     
        if (*error == 1)
            return;
    }
    operand = c;
    c = *string++;
    char t[SIZE];                                               
    i = 0;
    while (c != '\0') {                                           
        t[i++] = c;
        c = *string++;
    }
    t[i] = '\0';
    float n2 = 0.00;
    if (i > 0)                                                     
        n2 = myAtof(t, error);                                     
    if (*error == 1)   
        return;
                                                                
    if (operand == '+')
        printf("%.2f %c %.2f = %.2f", n1, operand, n2, n1 + n2);
    else if (operand == '/') {
        if (n2 == 0) {
            printf("Cannot divided into 0.");
            exit(0);
        } else
            printf("%.2f %c %.2f = %.2f", n1, operand, n2, n1 / n2);
    }
    else if (operand == '*')
        printf("%.2f %c %.2f = %.2f", n1, operand, n2, n1 * n2);
    else if (operand == '-')
        printf("%.2f %c %.2f = %.2f", n1, operand, n2, n1 - n2);
    
    else {
        printf("Invalid operator type!\n");  
        *error=2;
}
}
