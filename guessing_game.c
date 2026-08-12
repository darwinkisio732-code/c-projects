#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VAL 1
#define MAX_VAL 10

// Generate a random number within [min, max]
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Clear leftover characters in the input buffer
void clear_input_buffer(void) {
    while (getchar() != '\n');
}

void play_game(void) {
    int secret = get_random_number(MIN_VAL, MAX_VAL);
    int guess = 0;
    int attempts = 0;

    printf("\n🎮 GUESSING GAME 🎮\n");
    printf("Guess the number (%d-%d): ", MIN_VAL, MAX_VAL);

    do {
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Enter a number (%d-%d): ", MIN_VAL, MAX_VAL);
            clear_input_buffer();
            continue;
        }

        attempts++;

        if (guess > secret) {
            printf("Too high! Try again: ");
        } else if (guess < secret) {
            printf("Too low! Try again: ");
        } else {
            printf("\n✅ Correct! You got it in %d attempt%s!\n\n", 
                   attempts, attempts == 1 ? "" : "s");
        }
    } while (guess != secret);
}

int main(void) {
    // Seed random number generator
    srand((unsigned int)time(NULL));

    play_game();

    return 0;
}
