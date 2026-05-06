#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void initialize_field(char **field, char initial_char) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            field[i][j] = initial_char;
}

void generate_mines(char **real_field) {
    int count = 0;
    srand(time(NULL));
    while (count < MINES) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (real_field[r][c] != 'X') {
            real_field[r][c] = 'X';
            count++;
        }
    }
}

void print_columns() {
    printf("     ");
    for (int j = 0; j < COLS; j++) {
        printf(" %d  ", j);
    }
    printf("\n-------------------------------------------------\n");
}

void reveal_field(char **field) {
    print_columns();
    for (int i = 0; i < ROWS; i++) {
        printf(" %d  |", i);
        for (int j = 0; j < COLS; j++) {
            printf(" %c |", field[i][j]);
        }
        printf("\n-------------------------------------------------\n");
    }
}

void display_visible(char **visible_field) {
    reveal_field(visible_field);
}

int is_mine(int row, int col, char **real_field) {
    return real_field[row][col] == 'X';
}

int count_mines_around(int row, int col, char **real_field) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !(i == 0 && j == 0)) {
                if (real_field[r][c] == 'X')
                    count++;
            }
        }
    }
    return count;
}

void reveal_safe_area(int row, int col, char **visible_field, char **real_field) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        return;
    if (visible_field[row][col] != '#')
        return;

    int mines = count_mines_around(row, col, real_field);
    visible_field[row][col] = mines + '0';

    if (mines == 0) {
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (!(i == 0 && j == 0))
                    reveal_safe_area(row + i, col + j, visible_field, real_field);
    }
}

int make_move(int row, int col, char **visible_field, char **real_field) {
    if (is_mine(row, col, real_field)) {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (real_field[i][j] == 'X')
                    visible_field[i][j] = 'X';
        return 0;
    } else {
        reveal_safe_area(row, col, visible_field, real_field);
        return 1;
    }
}

int check_victory(char **visible_field, char **real_field) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (real_field[i][j] != '*' && visible_field[i][j] == '#') {
                return 0;
            }
        }
    }
    return 1;
}
