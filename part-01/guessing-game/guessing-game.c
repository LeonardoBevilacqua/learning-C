#include <stdio.h>

int main() {
    // print the header of our game
    printf("********************************\n");
    printf("* Welcome to our guessing game *\n");
    printf("********************************\n");

    int secret_number = 42;
    int guess;

    printf("What is your guess? ");
    scanf("%d", &guess);
    printf("Your guess was %d\n", guess);

    int is_correct = guess == secret_number;

    if (is_correct) {
        printf("Congratulations! You're correct!\n");
        printf("Play again, you're a good player!\n");
    } else {

        int is_gretter = guess > secret_number;

        if (is_gretter) {
            printf("Your guess was greater than the secret number\n");
        } else {
            printf("Your guess was less than the secret number\n");
        }
    }
}
