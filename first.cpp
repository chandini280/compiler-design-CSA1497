#include <stdio.h>
#include <stdbool.h>


bool isTerminal(char symbol) {
    
    return (symbol >= 'a' && symbol <= 'z');
}

void calculateFirst(char nonTerminal, char production[][10], int numProductions, char firstSet[]) {
    int i;
    int j;

    for (i = 0; i < numProductions; i++) {
        if (production[i][0] == nonTerminal) {
            
            if (isTerminal(production[i][2])) {
                firstSet[production[i][2] - 'a'] = 1;
            }
                        else {
                calculateFirst(production[i][2], production, numProductions, firstSet);
            }
        }
    }
}

int main() {
   
    char production[5][10] = {
        "A=cd",
        "A=ef",
        "B=gh",
        "B=ij",
        "C=kl"
    };

    char nonTerminals[] = {'A', 'B', 'C'};
    char firstSet[26] = {0};

    int numNonTerminals = sizeof(nonTerminals) / sizeof(nonTerminals[0]);

    
    for (int i = 0; i < numNonTerminals; i++) {
        calculateFirst(nonTerminals[i], production, 5, firstSet);
    }

    
    printf("First Set:\n");
    for (int i = 0; i < 26; i++) {
        if (firstSet[i]) {
            printf("%c: %c\n", i + 'a', i + 'a');
        }
    }

    return 0;
}
