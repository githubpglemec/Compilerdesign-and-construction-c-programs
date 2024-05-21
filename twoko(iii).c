#include <stdio.h>

enum states { q0, q1, q2, qf };
enum states delta(enum states s, char ch);

int main() {
    enum states curr_state = q0;
    char string[20], ch;
    int i = 0;

    // Print name and roll number
    printf("Hari Prasad Gyawali, Roll NO: 06\n");

    printf("Enter a binary string: ");
    gets(string);  // Note: 'gets' is deprecated, consider using 'fgets' for safer input handling

    ch = string[i];
    while(ch != '\0') {
        curr_state = delta(curr_state, ch);
        ch = string[++i];
    }

    if(curr_state == qf)
        printf("The string %s is valid.\n", string);
    else
        printf("The string %s is not valid.\n", string);

    return 0;
}

// Transition Function
enum states delta(enum states s, char ch) {
    enum states curr_state;

    switch(s) {
        case q0:
            if(ch == '0')
                curr_state = q1;
            else
                curr_state = q0;
            break;

        case q1:
            if(ch == '0')
                curr_state = q2;
            else
                curr_state = q0;
            break;

        case q2:
            if(ch == '0')
                curr_state = q2;
            else
                curr_state = qf;
            break;

        case qf:
            curr_state = qf;
            break;

        default:
            curr_state = q0;
            break;
    }

    return curr_state;
}
