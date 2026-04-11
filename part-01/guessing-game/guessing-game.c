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

    if (guess == secret_number) {
        printf("Congratulations! You're correct!\n");
        printf("Play again, you're a good player!\n");
    } else {
        printf("You're wrong!\n");
        printf("Don't be sad, try again!\n");
    }
}
