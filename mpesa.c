#include <stdio.h>
#include <string.h>

#define PIN_LENGTH 4
#define PHONE_LEN 15

// Clear standard input buffer
void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Safely read integer input
int read_int(const char *prompt) {
    int val;
    printf("%s", prompt);
    while (scanf("%d", &val) != 1) {
        clear_buffer();
        printf("Invalid input. Try again: ");
    }
    clear_buffer();
    return val;
}

// Safely read float input
float read_float(const char *prompt) {
    float val;
    printf("%s", prompt);
    while (scanf("%f", &val) != 1) {
        clear_buffer();
        printf("Invalid input. Enter amount: ");
    }
    clear_buffer();
    return val;
}

// Safely read string input
void read_string(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int verify_pin(int correct_pin) {
    int pin = read_int("Enter PIN: ");
    if (pin != correct_pin) {
        printf("Error: Incorrect PIN.\n");
        return 0;
    }
    return 1;
}

int main(void) {
    int choice, sub_choice;
    float balance = 1000.00;
    float amount;
    const int correct_pin = 7160;
    char phone_number[PHONE_LEN];
    int running = 1;

    while (running) {
        printf("\n====== M-PESA MENU ======\n");
        printf("1. Send Money\n");
        printf("2. Withdraw Cash\n");
        printf("3. Buy Airtime\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        
        choice = read_int("Choose an option: ");

        switch (choice) {
            case 1: // Send Money
                printf("\n------ SEND MONEY ------\n");
                read_string("Enter recipient phone number: ", phone_number, PHONE_LEN);
                amount = read_float("Enter Amount: ");

                if (amount <= 0) {
                    printf("Error: Invalid Amount.\n");
                } else if (amount > balance) {
                    printf("Error: Insufficient Balance.\n");
                } else if (verify_pin(correct_pin)) {
                    balance -= amount;
                    printf("Confirmed. Kshs. %.2f sent to %s.\n", amount, phone_number);
                    printf("New Balance: Kshs. %.2f\n", balance);
                }
                break;

            case 2: // Withdraw Cash
                printf("\n------ WITHDRAW CASH ------\n");
                printf("1. From Agent\n2. From ATM\n");
                sub_choice = read_int("Choose option: ");

                if (sub_choice == 1) {
                    amount = read_float("Enter Amount: ");
                    if (amount < 100) printf("Error: Minimum withdrawal is Kshs. 100\n");
                    else if (amount > 20000) printf("Error: Maximum withdrawal is Kshs. 20,000\n");
                    else if (amount > balance) printf("Error: Insufficient Balance.\n");
                    else if (verify_pin(correct_pin)) {
                        balance -= amount;
                        printf("Withdrawn Kshs. %.2f from Agent.\n", amount);
                        printf("New Balance: Kshs. %.2f\n", balance);
                    }
                } else if (sub_choice == 2) {
                    amount = read_float("Enter Amount: ");
                    if (amount < 200) printf("Error: Minimum withdrawal is Kshs. 200\n");
                    else if (amount > 40000) printf("Error: Maximum withdrawal is Kshs. 40,000\n");
                    else if (amount > balance) printf("Error: Insufficient Balance.\n");
                    else if (verify_pin(correct_pin)) {
                        balance -= amount;
                        printf("Withdrawn Kshs. %.2f from ATM.\n", amount);
                        printf("New Balance: Kshs. %.2f\n", balance);
                    }
                } else {
                    printf("Invalid withdrawal option.\n");
                }
                break;

            case 3: // Buy Airtime
                printf("\n------ BUY AIRTIME ------\n");
                printf("1. My Phone\n2. Other Phone\n");
                sub_choice = read_int("Choose option: ");

                if (sub_choice == 1) {
                    amount = read_float("Enter Amount: ");
                    if (amount <= 0) printf("Error: Invalid Amount.\n");
                    else if (amount > balance) printf("Error: Insufficient Balance.\n");
                    else if (verify_pin(correct_pin)) {
                        balance -= amount;
                        printf("Airtime purchase of Kshs. %.2f successful!\n", amount);
                        printf("New Balance: Kshs. %.2f\n", balance);
                    }
                } else if (sub_choice == 2) {
                    read_string("Enter recipient phone number: ", phone_number, PHONE_LEN);
                    amount = read_float("Enter Amount: ");
                    if (amount <= 0) printf("Error: Invalid Amount.\n");
                    else if (amount > balance) printf("Error: Insufficient Balance.\n");
                    else if (verify_pin(correct_pin)) {
                        balance -= amount;
                        printf("Airtime of Kshs. %.2f sent to %s.\n", amount, phone_number);
                        printf("New Balance: Kshs. %.2f\n", balance);
                    }
                } else {
                    printf("Invalid option.\n");
                }
                break;

            case 4: // Check Balance
                printf("\n------ CHECK BALANCE ------\n");
                if (verify_pin(correct_pin)) {
                    printf("Your current balance is Kshs. %.2f\n", balance);
                }
                break;

            case 5: // Exit
                printf("\nThank you for using M-Pesa!\n");
                running = 0;
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}
