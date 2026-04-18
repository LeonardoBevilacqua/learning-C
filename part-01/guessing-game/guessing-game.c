#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // print the header of our game
    printf("********************************\n");
    printf("* Welcome to our guessing game *\n");
    printf("********************************\n");

    int seconds = time(0);
    srand(seconds);

    int big_number = rand();

    int secret_number = big_number % 100;
    int guess;
    int attempt = 1;
    double points = 1000;

    int is_correct = 0;
    int difficult_level = 0;
    printf("What is the difficult level?\n");
    printf("(1) Easy (2) Medium (3) Hard\n\n");
    printf("Choose: ");
    scanf("%d", &difficult_level);

    int retry_number = 0;
    switch (difficult_level) {
        case 1:
            retry_number = 20;
            break;
        case 2:
            retry_number = 15;
            break;
        default:
            retry_number = 6;
            break;
    }

    for (int i = 1; i <= retry_number; i++) {

        printf("Attempt %d\n", attempt);
        printf("What is your guess? ");

        scanf("%d", &guess);
        printf("Your guess was %d\n", guess);

        if (guess < 0) {
            printf("You cannot guess negative numbers!\n");
            continue;
        }

        is_correct = guess == secret_number;
        int is_greater = guess > secret_number;

        if (is_correct) {
            break;
        } else if (is_greater) {
            printf("Your guess was greater than the secret number\n");
        } else {
            printf("Your guess was less than the secret number\n"); 
        }

        attempt++;

        double lost_points = abs(guess - secret_number) / (double) 2;
        points = points - lost_points;
    }

    printf("Game over!\n");

    if (is_correct) {
        printf("Congratulations! You're correct!\n");
        printf("You guessed correcty in %d attempts!\n", attempt);
        printf("Total points: %.1f\n", points);
    } else {
        printf("You have lost. Play again!\n");
    }
}
