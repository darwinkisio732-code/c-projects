#include <stdio.h>
#include <string.h>

struct Product
{
    char name[50];
    float price;
    int quantity;
    char category[30];
};

void inputProducts(struct Product s[], int num_of_products)
{
    for (int i = 0; i < num_of_products; i++)
    {
        printf("\n======PRODUCT %d======", i + 1);

        printf("\nProduct Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0;

        printf("\nPrice: ");
        scanf("%f", &s[i].price);

        printf("\nQuantity: ");
        scanf("%d", &s[i].quantity);
        getchar();

        printf("\nProduct Category: ");
        fgets(s[i].category, sizeof(s[i].category), stdin);
        s[i].category[strcspn(s[i].category, "\n")] = 0;
    }
}

void displayProducts(struct Product s[], int num_of_products)
{
    printf("\n\n=================INVENTORY==================");
    printf("\n%-15s %-10s %-10s %-15s", "Name", "Price", "Qty", "Category");
    printf("\n----------------------------------------------");

    for (int i = 0; i < num_of_products; i++)
    {
        printf("\n%-15s %-10.2f %-10d %-15s",
               s[i].name,
               s[i].price,
               s[i].quantity,
               s[i].category);
    }
}

float calculateTotalValue(struct Product s[], int num_of_products)
{
    float total = 0;

    for (int i = 0; i < num_of_products; i++)
    {
        total += s[i].price * s[i].quantity;
    }

    return total;
}

int findMostExpensive(struct Product s[], int num_of_products)
{
    int expensiveIndex = 0;

    for (int i = 0; i < num_of_products; i++)
    {
        if (s[i].price > s[expensiveIndex].price)
        {
            expensiveIndex = i;
        }
    }

    return expensiveIndex;
}

int findLowestStock(struct Product s[], int num_of_products)
{
    int lowestQuantity = 0;

    for (int i = 0; i < num_of_products; i++)
    {
        if (s[i].quantity < s[lowestQuantity].quantity)
        {
            lowestQuantity = i;
        }
    }

    return lowestQuantity;
}

int main()
{
    struct Product products[10];
    int num_of_products;

    printf("\n\nHow many Products? ");
    scanf("%d", &num_of_products);
    getchar();

    inputProducts(products, num_of_products);

    displayProducts(products, num_of_products);

    float totalValue = calculateTotalValue(products, num_of_products);
    printf("\n\nTotal Inventory Value: %.2f\n", totalValue);

    int mostExpensive = findMostExpensive(products, num_of_products);
    printf("\n\nThe most Expensive Product Is %s - %f\n", products[mostExpensive].name, products[mostExpensive].price);

    int least = findLowestStock(products, num_of_products);
    printf("\n\nThe least Product in quantity is %s - %d", products[least].name, products[least].quantity);

    return 0;
}