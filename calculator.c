#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;
    int running = 1;

    while(running == 1) {
        printf("\n\n");
        printf("======SIMPLE CALCULATOR======\n");
        printf("1. ADD\n");
        printf("2. SUBTRACT\n");
        printf("3. MULTIPLY\n");
        printf("4. DIVIDE\n");
        printf("5. EXIT\n");

        printf("\n\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\n\nEnter first number: ");
                scanf("%f", &num1);
                printf("\nEnter second number: ");
                scanf("%f", &num2);
                result = num1 + num2;
                printf("\nResult: %.2f", result);
                break;
            case 2:
                printf("\n\nEnter first number: ");
                scanf("%f", &num1);
                printf("\nEnter second number: ");
                scanf("%f", &num2);
                result = num1 - num2;
                printf("\nResult: %.2f", result);
                break;
            case 3:
                printf("\n\nEnter first number: ");
                scanf("%f", &num1);
                printf("\nEnter second number: ");
                scanf("%f", &num2);
                result = num1 * num2;
                printf("\nResult: %.2f", result);
                break;
            case 4:
                printf("\n\nEnter first number: ");
                scanf("%f", &num1);
                printf("\nEnter second number: ");
                scanf("%f", &num2);
                if(num2 != 0) {
                    result = num1 / num2;
                    printf("\nResult: %.2f", result);
                } else {
                    printf("\nCannot divide by zero!");
                }
                break;
            case 5:
                printf("\n\nGoodbye!\n\n");
                running = 0;
                break;
            default:
                printf("\n\nInvalid Number, try again!");
                break;
        }
    }
    return 0;
}