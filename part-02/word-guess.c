#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "word-guess.h"

// global variables
char secrect_word[WORD_LENGTH];
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

void add_word() {
    char response;

    printf("Do you want to add a new word to the game? (Y/N) ");
    scanf(" %c", &response);

    if (response == 'Y') {
        char new_word[WORD_LENGTH];

        printf("What is the new word? ");
        scanf("%s", &new_word);

        FILE* file = fopen("words.txt", "r+");
        if (file == 0) {
            printf("Sorry, database not available\n");
            exit(1);
        }

        // Get the size number from the first line and add one more
        int size;
        fscanf(file, "%d", &size);
        size++;

        // return to first line and update it
        fseek(file, 0, SEEK_SET);
        fprintf(file, "%d", size);

        // Write the new word at the end
        fseek(file, 0, SEEK_END);
        fprintf(file, "%s", new_word);

        fclose(file);
    }
}

void choose_word() {
    FILE* file;
    int words_size;

    // Open file and read the first line, which has a number indicating the words size
    file = fopen("words.txt", "r");
    if (file == 0) {
        printf("Sorry, database not available\n");
        exit(1);
    }
    fscanf(file, "%d", &words_size);

    // Choose a random number from zero to word size
    srand(time(0));
    int random = rand() % words_size;

    // Find the random word
    for (int i = 0; i <= random; i++) {
        fscanf(file, "%s", &secrect_word);
    }

    fclose(file);
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

    if (won()) {
        printf("\nCongratulations, you won!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    } else {
        printf("\nYou lost!\n");
        printf("The word was **%s**\n\n", secrect_word);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}
