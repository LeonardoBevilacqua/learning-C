#include <stdio.h>
#include <string.h>

void header() {
    printf("***********************\n");
    printf("*   Word Guess Game   *\n");
    printf("***********************\n\n");
}

void try_guess(char guesses[26], int attempt) {
    char guess;
    scanf(" %c", &guess);

    guesses[attempt] = guess;
    attempt++;
}

int main() {
    char secrect_word[20];

    sprintf(secrect_word, "MELANCIA");

    int is_correct = 0;
    int was_hanged = 0;

    char guesses[26];
    int attempt = 0;

    header();

    do {

        for (int i = 0; i < strlen(secrect_word); i++) {

            int found = 0;
            for (int j = 0; j < attempt; j++) {
                if (guesses[j] == secrect_word[i]) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                printf("%c ", secrect_word[i]);
            } else {
                printf("_ ");
            }

        }
        printf("\n");

        try_guess(guesses, attempt);
    } while (!is_correct && !was_hanged);
}
