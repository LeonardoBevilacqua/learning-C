#include <stdio.h>
#include <string.h>

void header() {
    printf("***********************\n");
    printf("*   Word Guess Game   *\n");
    printf("***********************\n\n");
}

// Arrays are actual pointers, so there is not need to pass the reference
void try_guess(char guesses[26], int* attempt) {
    char guess;
    scanf(" %c", &guess);

    guesses[(*attempt)] = guess;
    (*attempt)++;
}

int has_guessed(char character, char guesses[26], int attempt) {
    int found = 0;

    for (int j = 0; j < attempt; j++) {
        if (guesses[j] == character) {
            found = 1;
            break;
        }
    }

    return found;
}

void draw(char secrect_word[20], char guesses[26], int attempt) {
    for (int i = 0; i < strlen(secrect_word); i++) {

        int found = has_guessed(secrect_word[i], guesses, attempt);

        if (found) {
            printf("%c ", secrect_word[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");
}

void choose_word(char secrect_word[20]) {
    sprintf(secrect_word, "MELANCIA");
}

int main() {
    char secrect_word[20];
    char guesses[26];
    int is_correct = 0;
    int was_hanged = 0;
    int attempt = 0;

    choose_word(secrect_word);
    header();

    do {

        draw(secrect_word, guesses, attempt);
        try_guess(guesses, &attempt);

    } while (!is_correct && !was_hanged);
}
