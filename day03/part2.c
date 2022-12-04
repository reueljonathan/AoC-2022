#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LINE_SIZE 50
#define NUM_TYPES 52

int hash(char c);
int weight(char c);
void check_presence(int * rucksack, char * line, int line_len);

typedef struct elf {
    char * rucksack;
} elf;

// Incomplete.

int main() {
    char * line;
    int line_len;
    int elf1[NUM_TYPES], elf2[NUM_TYPES], elf3[NUM_TYPES];
    unsigned int sum_weights;

    assert(line = (char *) malloc(sizeof(char) * LINE_SIZE));

    sum_weights = 0;

    while (fgets(line, LINE_SIZE, stdin) != NULL) {
        for (int i = 0; i < NUM_TYPES; i++) {
            elf1[i] = 0;
            elf2[i] = 0;
            elf3[i] = 0;
        }
        

        line_len = strlen(line);

        if (line[line_len - 1] == '\n') {
            line[line_len - 1] == '\0';
            line_len--;
        }

        check_presence(elf1, line, line_len);

        // elf2
        assert(fgets(line, LINE_SIZE, stdin) != NULL);
        line_len = strlen(line);
        if (line[line_len - 1] == '\n') {
            line[line_len - 1] == '\0';
            line_len--;
        }

        check_presence(elf2, line, line_len);

        // elf3
        assert(fgets(line, LINE_SIZE, stdin) != NULL);
        line_len = strlen(line);
        if (line[line_len - 1] == '\n') {
            line[line_len - 1] == '\0';
            line_len--;
        }

        check_presence(elf3, line, line_len);

        for (int i = 0; i < NUM_TYPES; i++) {
            if (elf1[i] && elf1[i] == elf2[i] && elf2[i] == elf3[i]) {
                sum_weights += (i + 1);
            }
        }
    }

    free(line);
    return 0;
}

void check_presence(int * rucksack, char * line, int line_len) {
    for (int i = 0, index = 0; i < line_len; i++) {
        index = hash(line[i]);
        rucksack[index] = 1;
    }
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

