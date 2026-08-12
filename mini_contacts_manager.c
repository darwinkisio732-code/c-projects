#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

// Helper function to safely read strings with spaces
void read_string(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void add_contact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("\nMaximum contact limit reached!\n");
        return;
    }

    printf("\nEnter name: ");
    read_string(contacts[*count].name, NAME_LEN);

    printf("Enter phone number: ");
    read_string(contacts[*count].phone, PHONE_LEN);

    (*count)++;
    printf("Contact added successfully!\n");
}

void search_contact(const Contact contacts[], int count) {
    if (count == 0) {
        printf("\nNo contacts to search.\n");
        return;
    }

    char query[NAME_LEN];
    int found = 0;

    printf("\nEnter name to search: ");
    read_string(query, NAME_LEN);

    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, query) != NULL) {
            printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found matching '%s'.\n", query);
    }
}

void display_contacts(const Contact contacts[], int count) {
    if (count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\n====== ALL CONTACTS ======\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %-20s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void delete_contact(Contact contacts[], int *count) {
    if (*count == 0) {
        printf("\nNo contacts to delete.\n");
        return;
    }

    char delete_name[NAME_LEN];
    printf("\nEnter exact name to delete: ");
    read_string(delete_name, NAME_LEN);

    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, delete_name) == 0) {
            // Shift elements to fill the gap
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("No contact found with that name.\n");
}

void print_menu(void) {
    printf("\n====== MINI CONTACTS MANAGER ======\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display All Contacts\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("\nChoose an option: ");
}

int main(void) {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;

    while (1) {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        getchar(); // Clear trailing newline left by scanf

        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                display_contacts(contacts, num_contacts);
                break;
            case 4:
                delete_contact(contacts, &num_contacts);
                break;
            case 5:
                printf("\nGoodbye!\n\n");
                return 0;
            default:
                printf("\nInvalid option! Try again.\n");
                break;
        }
    }

    return 0;
}
