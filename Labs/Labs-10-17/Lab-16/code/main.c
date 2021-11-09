#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Window WINDOW*

void init_color_pairs() {
    init_pair('b', COLOR_WHITE, COLOR_BLACK);
    init_pair('w', COLOR_BLACK, COLOR_WHITE);
}

int get_center_x(int length, int current_position) {
    return (current_position != -1 ? current_position : COLS) / 2 - length / 2;
}

int get_center_y(int length, int current_position) {
    return (current_position != -1 ? current_position : LINES) / 2 - length / 2;
}

Window create_workspace(char* title) {
    Window initialized = initscr();
    if (!initialized || !has_colors()) {
        printf("Error initialising ncurses.\n");
        exit(1);
    }
    Window workspace = newwin(LINES, COLS, 0, 0);
    curs_set(0);
    start_color();
    init_color_pairs();
    if (strlen(title) > 0) {
        move(1, get_center_x(strlen(title), -1));
        attron(COLOR_PAIR('b'));
        printw(title);
        for (int x = COLS / 3; x < COLS * 2 / 3; ++x) {
            mvaddch(2, x, '-');
            refresh();
        }
        cbreak();
    }
    refresh();
    return workspace;
}

Window create_window(int width, int height, int x, int y, char* title) {
    Window window = newwin(height, width, y, x);
    wbkgd(window, COLOR_PAIR('w'));
    box(window, 0, 0);
    mvwprintw(window, 0, get_center_x(strlen(title), width), title);
    wrefresh(window);
    return window;
}

void window_end(Window window, char* ending) {
    delwin(window);
    endwin();
    printf(ending);
}

int print_matrix(Window window, int width, int height, int size, int matrix[size][size], int base_x, int base_y) {
    char* hint = "Input matrix elements:";
    int hint_size = strlen(hint);
    wmove(window, base_y - 1, get_center_x(hint_size, width));
    wprintw(window, hint);
    wrefresh(window);
    for (int i = 0; i < size; ++i) {
        hint = "%d";
        int new_hint_size = strlen(hint);
        wmove(window, base_y, get_center_x(new_hint_size, width) + 2 * i - 1);
        wprintw(window, hint, i + 1);
        wrefresh(window);
    }
    wmove(window, base_y + 1, base_x + 2);
    wprintw(window, "   ------------");
    wrefresh(window);
    //// Elements and layout
    int i = -1;
    while (i++ < size) {
        wmove(window, base_y + 2 + i, base_x + 2);
        wprintw(window, "%d | ", i + 1);
        for (int j = 0; j < size; ++j) {
            wprintw(window, "%d", matrix[i][j]);
            wmove(window, base_y + 2 + i, base_x + 2 * j + 8);
            wrefresh(window);
        }
    }

    return i;
}

void main() {
    const int size = 5;
    int matrix[size][size];

    // Create workspace
    Window workspace = create_workspace("");
    int width = 0.8 * COLS;
    int height = 0.8 * LINES;
    int x = get_center_x(width, -1);
    int y = get_center_y(height, -1);

    // Create data window
    Window window = create_window(width, height, x, y, " Lab 16: pseudo-graphics ");
    int base_x = width / 2 - 3 - size;
    int base_y = height / 2 - size / 2;

    // Input data
    curs_set(1);
    /// Matrix
    //// Hint and layout
    char* hint = "Input matrix elements:";
    int hint_size = strlen(hint);
    wmove(window, base_y - 1, get_center_x(hint_size, width));
    wprintw(window, hint);
    wrefresh(window);
    for (int i = 0; i < size; ++i) {
        hint = "%d";
        int new_hint_size = strlen(hint);
        wmove(window, base_y, get_center_x(new_hint_size, width) + 2 * i - 1);
        wprintw(window, hint, i + 1);
        wrefresh(window);
    }
    wmove(window, base_y + 1, base_x + 2);
    wprintw(window, "   ------------");
    wrefresh(window);
    //// Elements and layout
    for (int i = 0; i < size; ++i) {
        wmove(window, base_y + 2 + i, base_x + 2);
        wprintw(window, "%d | ", i + 1);
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = wgetch(window) - '0';
            wmove(window, base_y + 2 + i, base_x + 2 * j + 8);
            wrefresh(window);
        }
    }
    curs_set(0);

    // Clear window
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
            wmove(window, i, j);
            wprintw(window, " ");
            wrefresh(window);
        }
    }

    /// i
    hint = "Input i (1 >= i >= %d): ";
    hint_size = strlen(hint);
    wmove(window, base_y - 1, get_center_x(hint_size, width));
    wprintw(window, hint, size);
    wrefresh(window);
    int target_i = wgetch(window) - '0';

    /// j
    hint = "Input j (1 >= j >= %d): ";
    hint_size = strlen(hint);
    wmove(window, base_y + 1, get_center_x(hint_size, width));
    wprintw(window, hint, size);
    wrefresh(window);
    int target_j = wgetch(window) - '0';

    // Clear window
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
            wmove(window, i, j);
            wprintw(window, " ");
            wrefresh(window);
        }
    }

    // Print matrix
    int i = print_matrix(window, width, height, size, matrix, base_x, base_y);
    hint = "Press any key to complete next task";
    hint_size = strlen(hint);
    wmove(window, base_y + 1 + i, get_center_x(hint_size, width));
    wprintw(window, hint);
    wrefresh(window);
    getch();

    // After click
    int center_x = get_center_x(hint_size, width);
    //// Add product
    int product = 1;
    for (int i = 0; i < size; ++i) {
        product *= matrix[target_i - 1][i];
    }
    for (int i = 0; i < size; ++i) {
        product *= matrix[i][target_j - 1];
    }
    hint = "Product = %d";
    hint_size = strlen(hint);
    wmove(window, base_y + 2 + i, get_center_x(hint_size, width));
    wprintw(window, hint, product);
    wbkgd(window, COLOR_PAIR('b'));
    wrefresh(window);
    getch();
    //// Remove hint
    for (int j = 1; j < width - 1; ++j) {
        wmove(window, base_y + 1 + i, j);
        wprintw(window, " ");
    }
    //// Update matrix
    for (int j = 0; j < size; ++j) {
        for (int i = size - 1; i != size - 1 - j; --i) {
            matrix[i][j] = 0;
        }
    }
    //// Re-print matrix and hint
    wbkgd(window, COLOR_PAIR('w'));
    print_matrix(window, width, height, size, matrix, base_x, base_y);
    hint = "Press any key to exit";
    hint_size = strlen(hint);
    wmove(window, base_y + 1 + i, get_center_x(hint_size, width));
    wprintw(window, hint);
    wrefresh(window);
    getch();
    window_end(workspace, "Program finished successfully. Returned to normal mode");
}