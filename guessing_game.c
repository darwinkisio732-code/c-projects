#include <stdio.h>

int main() {
    int secret = 8;
    int guess;
    int attempts = 0;

    printf("\n🎮 GUESSING GAME 🎮\n");
    printf("Guess the number (1-10): ");

    do {
        scanf("%d", &guess);
        attempts++;

        if(guess > secret) {
            printf("Too high! Try again: ");
        }
        else if(guess < secret) {
            printf("Too low! Try again: ");
        }
        else {
            printf("\n✅ Correct! You got it in %d attempts!\n", attempts);
        }
    } while(guess != secret);

    return 0;
}