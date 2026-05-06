#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char **allocate_matrix() {
    char **matrix = malloc(ROWS * sizeof(char *));
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = malloc(COLS * sizeof(char));
    }
    return matrix;
}

void free_matrix(char **matrix) {
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    char **real_field = allocate_matrix();
    char **visible_field = allocate_matrix();

    initialize_field(real_field, ' ');
    initialize_field(visible_field, '#');

    generate_mines(real_field);

    int game_over = 0;
    while (!game_over) {
        display_visible(visible_field);
        int row, col;
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid position.\n");
            continue;
        }

        if (!make_move(row, col, visible_field, real_field)) {
            printf("Game Over! You stepped on a mine!\n");
            display_visible(real_field);  // Reveals all the mines
            break;
        }

        if (check_victory(visible_field, real_field)) {
            printf("Congratulations! You won the game!\n");
            display_visible(real_field);  //reveals the whole field
            break;
        }
    }

    free_matrix(real_field);
    free_matrix(visible_field);
    return 0;
}
