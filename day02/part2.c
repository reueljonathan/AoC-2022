#include <stdio.h>
#include <stdlib.h>

#define OPP_ROCK 'A'
#define OPP_PAPER 'B'
#define OPP_SCISSORS 'C'

#define NEED_TO_LOSE 'X'
#define NEED_TO_DRAW 'Y'
#define NEED_TO_WIN 'Z'

#define SCORE_ROCK 1
#define SCORE_PAPER 2
#define SCORE_SCISSORS 3

#define SCORE_WIN 6
#define SCORE_DRAW 3

int main() {

    char opponent_choice, player_strategy;
    unsigned int score;
    
    score = 0;

    while (scanf("%c %c\n", &opponent_choice, &player_strategy) != EOF) {
        switch (opponent_choice) {

            case OPP_ROCK:
            {
                switch (player_strategy) {
                    case NEED_TO_LOSE:
                        score += SCORE_SCISSORS;
                        break;

                    case NEED_TO_DRAW:
                        score += SCORE_DRAW + SCORE_ROCK;
                        break;

                    case NEED_TO_WIN:
                        score += SCORE_WIN + SCORE_PAPER;
                        break;
                }

                break;
            }

            case OPP_PAPER:
            {
                switch (player_strategy) {
                    case NEED_TO_LOSE:
                        score += SCORE_ROCK;
                        break;

                    case NEED_TO_DRAW:
                        score += SCORE_DRAW + SCORE_PAPER;
                        break;

                    case NEED_TO_WIN:
                        score += SCORE_WIN + SCORE_SCISSORS;
                        break;
                }

                break;
            }

            case OPP_SCISSORS:
            {
                switch (player_strategy) {
                    case NEED_TO_LOSE:
                        score += SCORE_PAPER;
                        break;

                    case NEED_TO_DRAW:
                        score += SCORE_DRAW + SCORE_SCISSORS;
                        break;

                    case NEED_TO_WIN:
                        score += SCORE_WIN + SCORE_ROCK;
                        break;
                }

                break;
            }
        }
    }

    printf("score: %u\n", score);


    return 0;
}
