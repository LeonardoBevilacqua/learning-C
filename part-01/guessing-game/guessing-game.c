#include <stdio.h>

int main() {
    // print the header of our game
    printf("********************************\n");
    printf("* Welcome to our guessing game *\n");
    printf("********************************\n");

    int secret_number = 42;

    printf("The number %d is the secret number. Don't tell anyone!", secret_number);
}
