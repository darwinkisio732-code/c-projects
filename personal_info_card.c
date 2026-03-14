#include <stdio.h>

int main() {
    char name[50];
    int age;
    float height;

    printf("\n======PERSONAL INFO CARD======\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your height (meters): ");
    scanf("%f", &height);

    printf("\n======YOUR INFO======\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f m\n", height);

    return 0;
}