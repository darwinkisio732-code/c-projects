#include <stdio.h>

// Arithmetic operation functions
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

// Helper function to prompt user for two numbers
void get_numbers(float *num1, float *num2) {
    printf("\nEnter first number: ");
    scanf("%f", num1);
    printf("Enter second number: ");
    scanf("%f", num2);
}

// Menu display helper
void print_menu(void) {
    printf("\n\n====== SIMPLE CALCULATOR ======\n");
    printf("1. ADD\n");
    printf("2. SUBTRACT\n");
    printf("3. MULTIPLY\n");
    printf("4. DIVIDE\n");
    printf("5. EXIT\n");
    printf("\nChoice: ");
}

int main(void) {
    int choice;
    float num1, num2;

    while (1) {
        print_menu();
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            get_numbers(&num1, &num2);
        }

        switch (choice) {
            case 1:
                printf("\nResult: %.2f", add(num1, num2));
                break;
            case 2:
                printf("\nResult: %.2f", subtract(num1, num2));
                break;
            case 3:
                printf("\nResult: %.2f", multiply(num1, num2));
                break;
            case 4:
                if (num2 != 0) {
                    printf("\nResult: %.2f", divide(num1, num2));
                } else {
                    printf("\nError: Cannot divide by zero!");
                }
                break;
            case 5:
                printf("\nGoodbye!\n\n");
                return 0;
            default:
                printf("\nInvalid choice, try again!");
                break;
        }
    }

    return 0;
}
