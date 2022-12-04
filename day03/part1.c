#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LINE_SIZE 50
#define NUM_TYPES 52

int hash(char c);
int weight(char c);

int main() {
    char * line;
    int line_len;
    int presence[NUM_TYPES];
    unsigned int sum_weights;

    assert(line = (char *) malloc(sizeof(char) * LINE_SIZE));

    sum_weights = 0;

    while (fgets(line, LINE_SIZE, stdin) != NULL) {
        for (int i = 0; i < NUM_TYPES; i++) {
            presence[i] = 0;
        }

        line_len = strlen(line);     

        for (int i = 0, index = 0; i < line_len / 2; i++) {
            index = hash(line[i]);
            presence[index] = 1;
        }

        for (int i = line_len / 2, index = 0; i < line_len; i++) {
            index = hash(line[i]);

            if (presence[index]) {
                sum_weights += weight(line[i]);
                break;
            }
        }
    }

    printf("sum of weights: %u\n", sum_weights);

    free(line);
    return 0;
}

int hash(char c) {
    if (c >= 'a' && c <= 'z') {
        return (int)(c - 'a');
    } else if (c >= 'A' && c <= 'Z') {
        return 26 + (int)(c - 'A');
    } else {
        return -1;
    }
}

int weight(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1 + (int)(c - 'a');
    } else if (c >= 'A' && c <= 'Z') {
        return 27 + (int)(c - 'A');
    } else {
        return 0;
    }
}
