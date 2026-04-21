#include <stdio.h>
#include <string.h>

void header();
void try_guess();
void draw();
void choose_word();
int won();
int hanged();
int has_guessed(char character);

// global variables
char secrect_word[20];
char guesses[26];
int guess_number = 0;

void header() {
    printf("***********************\n");
    printf("*   Word Guess Game   *\n");
    printf("***********************\n\n");
}

// Arrays are actual pointers, so there is not need to pass the reference
void try_guess() {
    char guess;
    scanf(" %c", &guess);

    guesses[guess_number] = guess;
    guess_number++;
}

void draw() {
    for (int i = 0; i < strlen(secrect_word); i++) {

        int found = has_guessed(secrect_word[i]);

        if (found) {
            printf("%c ", secrect_word[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");
}

void choose_word() {
    sprintf(secrect_word, "MELANCIA");
}

int won() {
    for (int i = 0; i < strlen(secrect_word); i++) {
        if (!has_guessed(secrect_word[i])) {
            return 0;
        }
    }

    return 1;
}

int hanged() {
    int errors = 0;

    for (int i = 0; i < guess_number; i++) {
        int exists = 0;

        for (int j = 0; j < strlen(secrect_word); j++) {
            if (guesses[i] == secrect_word[j]) {

                exists = 1;
                break;
            }
        }

        if (!exists) errors++;
    }

    return errors >= 5;
}

int has_guessed(char character) {
    int found = 0;

    for (int j = 0; j < guess_number; j++) {
        if (guesses[j] == character) {
            found = 1;
            break;
        }
    }

    return found;
}

int main() {
    choose_word();
    header();

    do {

        draw();
        try_guess();

    } while (!won() && !hanged());
}
