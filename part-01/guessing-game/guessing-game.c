#include <stdio.h>

int main() {
    // print the header of our game
    printf("********************************\n");
    printf("* Welcome to our guessing game *\n");
    printf("********************************\n");

    int secret_number = 42;
    int guess;
    int attempt = 1;
    int points = 1000;

    while (1) {

        printf("Attempt %d\n", attempt);
        printf("What is your guess? ");

        scanf("%d", &guess);
        printf("Your guess was %d\n", guess);

        if (guess < 0) {
            printf("You cannot guess negative numbers!\n");
            continue;
        }

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

        attempt++;

        int lost_points = (guess - secret_number) / 2;
        points = points - lost_points;
    }
    printf("Game over!\n");
    printf("You guessed correcty in %d attempts!\n", attempt);
    printf("Total points: %d", points);
}
