#include <stdio.h>
#include <stdlib.h>

#define OPP_ROCK 'A'
#define OPP_PAPER 'B'
#define OPP_SCISSORS 'C'

#define PLA_ROCK 'X'
#define PLA_PAPER 'Y'
#define PLA_SCISSORS 'Z'

#define SCORE_ROCK 1
#define SCORE_PAPER 2
#define SCORE_SCISSORS 3

#define SCORE_WIN 6
#define SCORE_DRAW 3

int main() {

    char opponent_choice, player_choice;
    unsigned int score;
    
    score = 0;

    while (scanf("%c %c\n", &opponent_choice, &player_choice) != EOF) {
        switch (opponent_choice) {

            case OPP_ROCK:
            {
                switch (player_choice) {
                    case PLA_ROCK:
                        score += SCORE_DRAW + SCORE_ROCK;
                        break;

                    case PLA_PAPER:
                        score += SCORE_WIN + SCORE_PAPER;
                        break;

                    case PLA_SCISSORS:
                        score += SCORE_SCISSORS;
                        break;
                }

                break;
            }

            case OPP_PAPER:
            {
                switch (player_choice) {
                    case PLA_ROCK:
                        score += SCORE_ROCK;
                        break;

                    case PLA_PAPER:
                        score += SCORE_DRAW + SCORE_PAPER;
                        break;

                    case PLA_SCISSORS:
                        score += SCORE_WIN + SCORE_SCISSORS;
                        break;
                }

                break;
            }

            case OPP_SCISSORS:
            {
                switch (player_choice) {
                    case PLA_ROCK:
                        score += SCORE_WIN + SCORE_ROCK;
                        break;

                    case PLA_PAPER:
                        score += SCORE_PAPER;
                        break;

                    case PLA_SCISSORS:
                        score += SCORE_DRAW + SCORE_SCISSORS;
                        break;
                }

                break;
            }
        }
    }

    printf("score: %u\n", score);


    return 0;
}
