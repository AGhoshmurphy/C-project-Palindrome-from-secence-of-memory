#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

// Function to check if a word is a palindrome
int is_palindrome(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char word[MAX_WORD_LEN];
    char *words[MAX_WORD_LEN];
    int freq[MAX_WORD_LEN] = {0};
    int num_words = 0;

    // Open the file
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the file word by word
    while (fscanf(file, "%s", word) == 1) {
        // Remove punctuation marks and convert to lowercase
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            if (ispunct(word[i])) {
                memmove(&word[i], &word[i + 1], len - i);
                len--;
                i--;
            } else {
                word[i] = tolower(word[i]);
            }
        }

        // Check if the word is a palindrome
        int palindrome = is_palindrome(word);

        // Check if the word is already in the list of words
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                freq[i]++;
                break;
            }
        }

        // If the word is not in the list of words, add it
        if (i == num_words) {
            words[num_words] = strdup(word);
            freq[num_words] = 1;
            num_words++;
        }
    }

    // Sort the list of words alphabetically using selection sort
    for (int i = 0; i < num_words - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[j], words[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            char *temp_word = words[i];
            words[i] = words[min_idx];
            words[min_idx] = temp_word;
            int temp_freq = freq[i];
            freq[i] = freq[min_idx];
            freq[min_idx] = temp_freq;
        }
    }

    // Print the list of words with their frequency and palindrome information
    for (int i = 0; i < num_words; i++) {
        printf("%s %d ", words[i], freq[i]);
        if (is_palindrome(words[i])) {
            printf("palindrome\n");
        } else {
            printf("not palindrome\n");
        }
    }

    // Free the memory used by the list of words
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    // Close the file
    fclose(file);

    return 0;
}
