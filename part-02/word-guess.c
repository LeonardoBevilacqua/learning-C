#include <stdio.h>
#include <string.h>

int main() {
    char secrect_word[20];

    sprintf(secrect_word, "MELANCIA");

    int is_correct = 0;
    int was_hanged = 1;

    do {
        char guess;
        scanf("%c", &guess);

        for (int i = 0; i < strlen(secrect_word); i++) {
            if (secrect_word[i] == guess) {
                printf("The position %d has this character!\n", i);
            }
        }

    } while (!is_correct && !was_hanged);
}
