#include <stdio.h>
#include <ctype.h>

void FIRST(char[], char);
void addToResultSet(char[], char);
int numOfProductions;
char productionSet[10][10];

void main() {
    int i;
    char choice;
    char ch;
    char result[20];

    // Print name and roll number
    printf("Hari Prasad Gyawali, Roll NO: 06\n");

    printf("How many number of productions?: ");
    scanf("%d", &numOfProductions);

    for(i = 0; i < numOfProductions; i++) { // read production: E=E+T.
        printf("Enter production number %d: ", i + 1);
        scanf("%s", productionSet[i]);
    }

    do {
        printf("Find the First of: ");
        scanf(" %c", &ch); // note the space before %c to skip any leftover whitespace
        FIRST(result, ch);
        printf("\nFIRST(%c)={", ch);
        for(i = 0; result[i] != '\0'; i++) {
            printf("%c", result[i]); // Display result.
        }
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');
}

// First function, compute the first(c) and write them in result array.
void FIRST(char* Result, char ch) {
    int i, j, k;
    char subResult[20];
    int foundEpsilon;

    subResult[0] = '\0';
    Result[0] = '\0';

    // If X is terminal, First(X)={X}.
    if(!isupper(ch)) {
        addToResultSet(Result, ch);
        return;
    }

    // If X is a variable
    // Read each production.
    for(i = 0; i < numOfProductions; i++) {
        // Find production with X as LHS.
        if(productionSet[i][0] == ch) {
            // If X -> epsilon is a production, then add epsilon to first(X).
            if(productionSet[i][2] == '$') {
                addToResultSet(Result, '$');
            } else {
                // If X is variable, and X -> Y1Y2....YK
                // is a production, then add a to first(X).
                // If for same i, a is in First(Yi).
                // And epsilon is in all of First(Y1),...,First(Yi-1).
                j = 2;
                while(productionSet[i][j] != '\0') {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]);
                    for(k = 0; subResult[k] != '\0'; k++) {
                        addToResultSet(Result, subResult[k]);
                    }

                    for(k = 0; subResult[k] != '\0'; k++) {
                        if(subResult[k] == '$') {
                            foundEpsilon = 1;
                            break;
                        }
                    }

                    // No epsilon, no need to check next element
                    if(!foundEpsilon) {
                        break;
                    }
                    j++;
                }
            }
        }
    }
}

// addToResultSet adds the computed element to result set.
// This code avoids multiple inclusion of elements.
void addToResultSet(char Result[], char val) {
    int k;
    for(k = 0; Result[k] != '\0'; k++) {
        if(Result[k] == val) {
            return;
        }
    }
    Result[k] = val;
    Result[k + 1] = '\0';
}
