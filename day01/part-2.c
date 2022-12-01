#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 6

int main() {
    unsigned long long int max_calories[3] = { 0, 0, 0 }; 
    unsigned long long int item_calories;
    unsigned int calories_sum = 0;

    char line[MAX_LINE_LENGTH + 1];
    int line_len;


    while (fgets(line, MAX_LINE_LENGTH + 1, stdin)) {
        line_len = strlen(line);

        if (line_len > 1) {
            line[line_len - 1] = '\0';
            item_calories = (unsigned long long) atoi(line);

            calories_sum += item_calories;
        } else {
            for (int i = 2; i > -1; --i) {
                if (calories_sum > max_calories[i]) {

                    for (int j = 0; j < i; ++j) {
                        max_calories[j] = max_calories[j + 1];
                    }

                    max_calories[i] = calories_sum;
                    break;
                }
            }

            calories_sum = 0;
        }
    }

    // Checking for the last input
    for (int i = 2; i > -1; --i) {
        if (calories_sum > max_calories[i]) {

            for (int j = 0; j < i; ++j) {
                max_calories[j] = max_calories[j + 1];
            }

            max_calories[i] = calories_sum;
            break;
        }
    }

    printf("Result: %llu\n",
            max_calories[0] + max_calories[1] + max_calories[2]);

    return 0;
}
