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
}
