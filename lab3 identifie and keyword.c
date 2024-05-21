#include <stdio.h>
#include <string.h>

char keyword[32][10] = {
    "auto", "double", "int", "struct", "break", "else", "long", "switch",
    "case", "enum", "register", "typedef", "char", "extern", "return",
    "union", "const", "float", "short", "unsigned", "continue", "for",
    "signed", "void", "default", "goto", "sizeof", "volatile", "do",
    "if", "static", "while"
};

enum states { q0, qf, qd };
enum states delta(enum states, char);
int iskeyword(char []);

int main() {
    enum states curr_state = q0;
    char string[20], ch;
    int i = 0;

    // Print name and roll number
    printf("Hari Prasad Gyawali, Roll NO: 06\n");

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    // Remove trailing newline character if present
    string[strcspn(string, "\n")] = 0;

    if (iskeyword(string))
        printf("The string %s is a keyword.\n", string);
    else {
        while (string[i] != '\0') {
            curr_state = delta(curr_state, string[i]);
            i++;
        }
        if (curr_state == qf)
            printf("The string %s is a valid identifier.\n", string);
        else
            printf("The string %s is neither a keyword nor a valid identifier.\n", string);
    }
    return 0;
}

// Transition function
enum states delta(enum states s, char ch) {
    enum states curr_state;
    switch (s) {
        case q0:
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_')
                curr_state = qf;
            else
                curr_state = qd;
            break;
        case qf:
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_' || (ch >= '0' && ch <= '9'))
                curr_state = qf;
            else
                curr_state = qd;
            break;
        case qd:
            curr_state = qd;
            break;
        default:
            curr_state = qd;
            break;
    }
    return curr_state;
}

// Function to check if a string is a keyword
int iskeyword(char str[]) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keyword[i]) == 0)
            return 1;
    }
    return 0;
}
