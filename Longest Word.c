#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is in maximal order
int is_maximal_order(char *s, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (s[i] < s[i + 1]) {
            return 0; // Not in maximal order
        }
    }
    return 1; // In maximal order
}

// Function to find the largest terminal substring in maximal order
int find_maximal_substring(char *s, int n) {
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }
    return i;
}

// Function to find the closest superior letter to the left of i
int find_closest_superior(char *s, int n, int i) {
    int j = n - 1;
    while (s[j] <= s[i]) {
        j--;
    }
    return j;
}

// Function to swap the ith and jth letters
void swap_letters(char *s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

// Function to rearrange the substring to the right of ith letter in minimal order
void rearrange_substring(char *s, int i, int n) {
    for (int k = i + 1; k < n - 1; k++) {
        for (int l = i + 1; l < n - 1; l++) {
            if (s[l] > s[l + 1]) {
                char temp = s[l];
                s[l] = s[l + 1];
                s[l + 1] = temp;
            }
        }
    }
}

// Function to find the largest word
void find_largest_word(char *drawn_letters, int n) {
    while (!is_maximal_order(drawn_letters, n)) {
        int i = find_maximal_substring(drawn_letters, n);
        int j = find_closest_superior(drawn_letters, n, i);
        swap_letters(drawn_letters, i, j);
        rearrange_substring(drawn_letters, i, n);
    }
}

int main() {
    int num_vowels;
    printf("Enter the number of vowels: ");
    scanf("%d", &num_vowels);

    char vowels[] = "AEIOU";
    char drawn_letters[num_vowels + 10];

    // Generate random letters with the specified number of vowels
    for (int i = 0; i < num_vowels; i++) {
        drawn_letters[i] = vowels[rand() % 5];
    }

    // Generate random consonants
    for (int i = num_vowels; i < num_vowels + 10; i++) {
        drawn_letters[i] = 'A' + rand() % 26;
    }

    // Shuffle the letters
    for (int i = num_vowels + 10 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = drawn_letters[i];
        drawn_letters[i] = drawn_letters[j];
        drawn_letters[j] = temp;
    }

    printf("Drawn letters: %s\n", drawn_letters);

    find_largest_word(drawn_letters, num_vowels + 10);

    printf("Largest Word: %s\n", drawn_letters);

    return 0;
}
