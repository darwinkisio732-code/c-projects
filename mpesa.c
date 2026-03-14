#include <stdio.h>

int main() {
    int choice, sub_choice;
    float balance = 1000.00;
    float amount;
    int pin;
    int correct_pin = 7160;
    char phone_number[15];
    int running = 1;

    while(running == 1) {
        printf("\n======M-PESA MENU======\n");
        printf("1. Send Money\n");
        printf("2. Withdraw Cash\n");
        printf("3. Buy Airtime\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Send Money
                printf("\n------SEND MONEY------\n");
                printf("Enter recipient's phone number: ");
                scanf("%s", phone_number);
                printf("Enter Amount: ");
                scanf("%f", &amount);
                printf("Enter PIN: ");
                scanf("%d", &pin);

                if(pin == correct_pin && amount <= balance && amount > 0) {
                    balance -= amount;
                    printf("Confirmed Kshs. %.2f sent to %s!\n", amount, phone_number);
                    printf("New balance: %.2f\n", balance);
                }
                else if(pin != correct_pin) printf("Invalid PIN.\n");
                else if(amount > balance) printf("Insufficient Balance.\n");
                else if(amount <= 0) printf("Invalid Amount.\n");
                break;

            case 2: // Withdraw Cash
                printf("\n------WITHDRAW CASH------\n");
                printf("1. From Agent\n2. From ATM\nChoose: ");
                scanf("%d", &sub_choice);

                if(sub_choice == 1) {
                    printf("\nEnter Amount: ");
                    scanf("%f", &amount);
                    printf("Enter PIN: ");
                    scanf("%d", &pin);

                    if(pin != correct_pin) printf("Incorrect PIN.\n");
                    else if(amount < 100) printf("Minimum is Kshs. 100\n");
                    else if(amount > 20000) printf("Maximum is Kshs. 20,000\n");
                    else if(amount > balance) printf("Insufficient Balance.\n");
                    else {
                        balance -= amount;
                        printf("Withdrawn Kshs. %.2f from Agent\n", amount);
                    }
                }
                else if(sub_choice == 2) {
                    printf("\nEnter Amount: ");
                    scanf("%f", &amount);
                    printf("Enter PIN: ");
                    scanf("%d", &pin);

                    if(pin != correct_pin) printf("Incorrect PIN.\n");
                    else if(amount < 200) printf("Minimum is Kshs. 200\n");
                    else if(amount > 40000) printf("Maximum is Kshs. 40,000\n");
                    else if(amount > balance) printf("Insufficient Balance.\n");
                    else {
                        balance -= amount;
                        printf("Withdrawn Kshs. %.2f from ATM\n", amount);
                    }
                }
                break;

            case 3: // Buy Airtime
                printf("\n------BUY AIRTIME------\n");
                printf("1. My Phone\n2. Other Phone\nChoose: ");
                scanf("%d", &sub_choice);

                if(sub_choice == 1) {
                    printf("Enter Amount: ");
                    scanf("%f", &amount);
                    printf("Enter PIN: ");
                    scanf("%d", &pin);

                    if(pin == correct_pin && amount > 0 && amount <= balance) {
                        balance -= amount;
                        printf("Airtime purchase of Kshs. %.2f successful!\n", amount);
                    }
                    else printf("Invalid PIN or Amount.\n");
                }
                else if(sub_choice == 2) {
                    printf("Enter phone number: ");
                    scanf("%s", phone_number);
                    printf("Enter Amount: ");
                    scanf("%f", &amount);
                    printf("Enter PIN: ");
                    scanf("%d", &pin);

                    if(pin == correct_pin && amount > 0 && amount <= balance) {
                        balance -= amount;
                        printf("Airtime of Kshs. %.2f sent to %s\n", amount, phone_number);
                    }
                    else printf("Invalid PIN or Amount.\n");
                }
                break;

            case 4: // Check Balance
                printf("\n------CHECK BALANCE------\n");
                printf("Enter PIN: ");
                scanf("%d", &pin);
                if(pin == correct_pin) printf("Balance: Kshs. %.2f\n", balance);
                else printf("Invalid PIN.\n");
                break;

            case 5: // Exit
                printf("\nThank you for using M-Pesa!\n");
                running = 0;
                break;

            default:
                printf("\nInvalid option!\n");
        }
    }
    return 0;
}