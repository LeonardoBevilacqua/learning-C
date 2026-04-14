#include <stdio.h>

#define RETRY_NUMBER 5

int main() {
    // print the header of our game
    printf("********************************\n");
    printf("* Welcome to our guessing game *\n");
    printf("********************************\n");

    int secret_number = 42;
    int guess;

    for (int i = 1; i <= RETRY_NUMBER; i++) {
        printf("What is your guess? ");
        printf("Attempt %d of %d\n", i, RETRY_NUMBER);
        scanf("%d", &guess);
        printf("Your guess was %d\n", guess);

        int is_correct = guess == secret_number;
        int is_greater = guess > secret_number;

        if (is_correct) {
            printf("Congratulations! You're correct!\n");
            printf("Play again, you're a good player!\n");

            break;
        } else if (is_greater) {
            printf("Your guess was greater than the secret number\n");
        } else {
            printf("Your guess was less than the secret number\n"); 
        }
    }
    printf("Game over!\n");
}
