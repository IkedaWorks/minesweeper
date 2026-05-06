#ifndef GAME_H
#define GAME_H

#define ROWS 10
#define COLS 10
#define MINES 10

void generate_mines(char **real_field);
void initialize_field(char **field, char initial_char);
void print_columns();
void reveal_field(char **field);
void display_visible(char **visible_field);
int is_mine(int row, int col, char **real_field);
int count_mines_around(int row, int col, char **real_field);
void reveal_safe_area(int row, int col, char **visible_field, char **real_field);
int make_move(int row, int col, char **visible_field, char **real_field);
int check_victory(char **visible_field, char **real_field);


#endif
