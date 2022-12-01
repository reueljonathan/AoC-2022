#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 6

int main() {
    int max_calories = 0; 
    int item_calories;
    int calories_sum = 0;

    char line[MAX_LINE_LENGTH + 1];
    int line_len;


    while (fgets(line, MAX_LINE_LENGTH + 1, stdin)) {
        line_len = strlen(line);

        //printf("line read: %s", line);

        if (line_len > 1) {
            line[line_len - 1] = '\0';
            item_calories = atoi(line);

            calories_sum += item_calories;
        } else {
            if (calories_sum > max_calories) max_calories = calories_sum;

            calories_sum = 0;
        }
    }

    // Checking for the last input
    if (calories_sum > max_calories) max_calories = calories_sum;

    printf("Max calories carried by an Elf: %d\n", max_calories);

    return 0;
}
