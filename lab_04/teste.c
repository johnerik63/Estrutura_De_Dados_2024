#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_vowel(char c) {
    char lower_c = tolower(c);
    return lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u';
}

char* process_word(char* word, int* sum) {
    int len = strlen(word);
    char* clean_word = malloc(len + 1);
    int j = 0;
    *sum = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(word[i])) {
            clean_word[j++] = word[i];
        } else if (isdigit(word[i])) {
            *sum += word[i] - '0';
        }
    }
    clean_word[j] = '\0';

    if (j == 0) {
        free(clean_word);
        return NULL;
    }

    char* goat_latin_word = malloc(j + 3 + j + 1);
    
    if (is_vowel(clean_word[0])) {
        sprintf(goat_latin_word, "%sma", clean_word);
    } else {
        sprintf(goat_latin_word, "%s%cma", clean_word + 1, clean_word[0]);
    }

    for (int i = 0; i < j; i++) {
        strcat(goat_latin_word, "a");
    }

    free(clean_word);
    return goat_latin_word;
}

void goat_latin_sentence(char* sentence) {
    int total_sum = 0;
    char* words[100];
    int word_count = 0;
    char* word = strtok(sentence, " ");
    
    while (word) {
        int word_sum = 0;
        char* translated_word = process_word(word, &word_sum);
        total_sum += word_sum;
        if (translated_word) {
            words[word_count++] = translated_word;
        }
        word = strtok(NULL, " ");
    }

    if (word_count == 0) {
        if (total_sum == 1) {
            printf("%d goat says:\n", total_sum);
        } else {
            printf("%d goats say:\n", total_sum);
        }
    } else {
        printf("%d goats say:", total_sum);
        for (int i = 0; i < word_count; i++) {
            printf(" %s", words[i]);
            free(words[i]);
        }
        printf("\n");
    }
}

int main() {
    char sentence[1024];
    while (fgets(sentence, sizeof(sentence), stdin)) {
        sentence[strcspn(sentence, "\n")] = '\0';
        goat_latin_sentence(sentence);
    }
    return 0;
}
