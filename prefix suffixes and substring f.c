#include <stdio.h>
#include <string.h>

void find_prefix(char string[]);
void find_suffix(char string[]);
void find_substring(char string[], int x, int y);

int main() {
    char string[20];
    int i, j;

    printf("Hari Prasad Gyawali, Roll NO: 06\n"); // Added this line
    printf("\nEnter a string: ");
    gets(string);

    printf("\nPrefixes:");
    find_prefix(string);

    printf("\nSuffixes:");
    find_suffix(string);

    printf("\nEnter i and j for substring: ");
    scanf("%d %d", &i, &j);
    find_substring(string, i, j);

    return 0;
}

void find_prefix(char string[]) {
    int i, j;
    char prefix[20];
    for (i = 1; i <= strlen(string); i++) {
        for (j = 0; j < i; j++) {
            prefix[j] = string[j];
        }
        prefix[j] = '\0';
        printf("\n%s", prefix);
    }
}

void find_suffix(char string[]) {
    int i, j, k;
    char suffix[20];
    for (i = 0; i < strlen(string); i++) {
        k = 0;
        for (j = i; j < strlen(string); j++) {
            suffix[k] = string[j];
            k++;
        }
        suffix[k] = '\0';
        printf("\n%s", suffix);
    }
}

void find_substring(char string[], int x, int y) {
    char substr[20];
    int k = 0;
    for (int i = x - 1; i < y; i++) {
        substr[k] = string[i];
        k++;
    }
    substr[k] = '\0';
    printf("\nSubstring: %s", substr);
}
