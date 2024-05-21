#include <stdio.h>

enum states { q0, q1, qf, qd };
enum states delta(enum states s, char ch);

int main() {
    char input[20];
    enum states curr_state = q0;
    int i = 0;

    // Print name and roll number
    printf("Hari Prasad Gyawali, Roll NO: 06\n");

    printf("Enter a binary string: ");
    gets(input);  // Note: 'gets' is deprecated, consider using 'fgets' for safer input handling

    while (input[i] != '\0') {
        curr_state = delta(curr_state, input[i]);
        i++;
    }

    if (curr_state == qf)
        printf("The string %s is accepted.\n", input);
    else
        printf("The string %s is not accepted.\n", input);

    return 0;
}

// Transition Function
enum states delta(enum states s, char ch) {
    enum states curr_state;

    switch(s) {
        case q0:
            if (ch == '0')
                curr_state = q1;
            else
                curr_state = qd;
            break;

        case q1:
            if (ch == '1')
                curr_state = qf;
            else
                curr_state = qd;
            break;

        case qf:
            if (ch == '0' || ch == '1')
                curr_state = qf;
            break;

        case qd:
            if (ch == '0' || ch == '1')
                curr_state = qd;
            break;

        default:
            curr_state = qd;
            break;
    }

    return curr_state;
}
