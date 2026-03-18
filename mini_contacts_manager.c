#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10

int main()
{
    char names[10][50];
    char phone_numbers[10][15];
    int num_contacts = 0;
    int choice, i, j;
    int running = 1;

    while (running)
    {
        printf("\n\n======MINI CONTACTS MANAGER======\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");

        printf("\n\nChoose an option: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (num_contacts < MAX_CONTACTS)
            {
                printf("\nEnter name: ");
                scanf("%s", names[num_contacts]);
                printf("Enter phone number: ");
                scanf("%s", phone_numbers[num_contacts]);
                num_contacts++;
                printf("Contact added successfully!\n");
            }
            else
            {
                printf("Maximum contact limit reached!\n");
            }
        }
        else if (choice == 2)
        {
            char search_name[50];
            int found = 0;
            printf("\nEnter name to search: ");
            scanf("%s", search_name);
            for (i = 0; i < num_contacts; i++)
            {
                if (strstr(names[i], search_name) != NULL)
                {
                    printf("%d. %s - %s\n", i + 1, names[i], phone_numbers[i]);
                    found = 1;
                }
            }
            if (!found)
            {
                printf("No contact found with that name.\n");
            }
        }

        else if (choice == 3)
        {
            if (num_contacts == 0)
            {
                printf("\nNo contacts Found.\n");
            }
            else
            {
                printf("\n\n======ALL CONTACTS======\n");
                for (i = 0; i < num_contacts; i++)
                {
                    printf("%d. %s - %s\n", i + 1, names[i], phone_numbers[i]);
                }
            }
        }
        else if (choice == 4)
        {
            char delete_name[50];
            printf("\nEnter name to delete: ");
            scanf("%s", delete_name);
            for (i = 0; i < num_contacts; i++)
            {
                if (strcmp(names[i], delete_name) == 0)
                {
                    for (j = i; j < num_contacts - 1; j++)
                    {
                        strcpy(names[j], names[j + 1]);
                        strcpy(phone_numbers[j], phone_numbers[j + 1]);
                    }
                    num_contacts--;
                    printf("Contact deleted successfully!\n");
                    break;
                }
            }
            if (i == num_contacts)
            {
                printf("No contact found with that name.\n");
            }
        }
        else if (choice == 5)
        {
            printf("\nGoodbye!\n");
            running = 0;
        }
    }
    return 0;
}
