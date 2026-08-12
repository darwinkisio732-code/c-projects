#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 10
#define NAME_LEN 50
#define CAT_LEN 30

typedef struct {
    char name[NAME_LEN];
    float price;
    int quantity;
    char category[CAT_LEN];
} Product;

// Helper to safely read strings with newline removal
void read_string(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void inputProducts(Product p[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\n====== PRODUCT %d ======\n", i + 1);

        printf("Product Name: ");
        read_string(p[i].name, sizeof(p[i].name));

        printf("Price: ");
        scanf("%f", &p[i].price);

        printf("Quantity: ");
        scanf("%d", &p[i].quantity);
        getchar(); // Clear buffer newline

        printf("Product Category: ");
        read_string(p[i].category, sizeof(p[i].category));
    }
}

void displayProducts(const Product p[], int count) {
    printf("\n================================ INVENTORY ================================\n");
    printf("%-20s %-12s %-10s %-20s\n", "Name", "Price ($)", "Qty", "Category");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-12.2f %-10d %-20s\n",
               p[i].name, p[i].price, p[i].quantity, p[i].category);
    }
}

float calculateTotalValue(const Product p[], int count) {
    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        total += p[i].price * p[i].quantity;
    }
    return total;
}

int findMostExpensive(const Product p[], int count) {
    int expensiveIndex = 0;
    for (int i = 1; i < count; i++) {
        if (p[i].price > p[expensiveIndex].price) {
            expensiveIndex = i;
        }
    }
    return expensiveIndex;
}

int findLowestStock(const Product p[], int count) {
    int lowestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (p[i].quantity < p[lowestIndex].quantity) {
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

int main(void) {
    Product products[MAX_PRODUCTS];
    int num_of_products;

    printf("How many products? (Max %d): ", MAX_PRODUCTS);
    if (scanf("%d", &num_of_products) != 1 || num_of_products <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    getchar(); // Clear buffer newline

    if (num_of_products > MAX_PRODUCTS) {
        printf("Capping input to maximum capacity (%d).\n", MAX_PRODUCTS);
        num_of_products = MAX_PRODUCTS;
    }

    inputProducts(products, num_of_products);
    displayProducts(products, num_of_products);

    float totalValue = calculateTotalValue(products, num_of_products);
    int mostExpensive = findMostExpensive(products, num_of_products);
    int lowestStock = findLowestStock(products, num_of_products);

    printf("\n-------------------------------- SUMMARY --------------------------------\n");
    printf("Total Inventory Value:    $%.2f\n", totalValue);
    printf("Most Expensive Product:   %s ($%.2f)\n", products[mostExpensive].name, products[mostExpensive].price);
    printf("Lowest Stock Level:       %s (%d units remaining)\n", products[lowestStock].name, products[lowestStock].quantity);
    printf("=========================================================================\n\n");

    return 0;
}
