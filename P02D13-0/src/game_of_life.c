// Copyright 2022 team19
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#define HEIGHT 25
#define WIDTH 80

int create_field(char field[HEIGHT][WIDTH]);
void print_field(char field[HEIGHT][WIDTH]);
void check_colony(char field[HEIGHT][WIDTH]);
int check_cell(char field[HEIGHT][WIDTH], int i, int j);
void kill_born_cells(char field[HEIGHT][WIDTH]);
void check_around(char field[HEIGHT][WIDTH], int i, int j);
void fill_field_from_file(char field[HEIGHT][WIDTH]);
unsigned char read_console();

int main() {
    char field[HEIGHT][WIDTH]; // Двумерный массив (игровое поле)
    fill_field_from_file(field); // Вызов функции, читающей файл txt
    if (freopen("/dev/tty", "r", stdin) != NULL) {
        create_field(field); // Весь цикл работы программы
    } else {
        printf("Couldn't read file");
    }
    return 0;
}

void fill_field_from_file(char field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {    // Циклы, заполняющие массив символами из полученного файла
        for (int j = 0; j < WIDTH; j++) {
            scanf("%c", &field[i][j]);
        }
    }
}

int create_field(char field[HEIGHT][WIDTH]) {
    int delay = 100000;  // Время задержки циклов (в микросекундах)
    
    
    
    while (1) {  // Основной бесконечный цикл игры
        
        
        
        print_field(field);  // Вызов функции, печатающей игровое поле в терминал
        
        
        
        char key;
        key = read_console();    // Функция, читающая нажатие клавиши с клавиатуры, и записывает её в переменную key
        if (key == '+') {
            delay -= 25000;
            if (delay < 0) {
                delay = 0;
            }
        }
        if (key == '-') {
            delay += 25000;
            if (delay > 1000000) {
                delay = 1000000;
            }
        }
        if (key == '\e') {  // \е - ESC - выход из игры
            break;
        }
        usleep(delay);  // Функция задержки
        
        
        
        for (int i = 0; i < HEIGHT; i++) {     // Самый главный цикл
            for (int j = 0; j < WIDTH; j++) {
                if (field[i][j] == '0') {       // Если нашли на поле 0
                    int neighbours = check_cell(field, i, j);   // Проверяем эту ячейку на количество соседей
                    if (neighbours < 2 || neighbours > 3) {    // neighbours - количество живых соседей клетки
                        field[i][j] = 'X';
                    }
                }
            }
        }
        // 0 - живая клетки
        // Х - умирающая клетка
        // О - рождающаяся клетка
        // . - мертвая клетка
        
        
        
        check_colony(field);      // Проверка на возможность появления новой клетки
        kill_born_cells(field);  // Вызов функции смены состояния клеток
        printf("\n");
    }
    return 0;
}

void print_field(char field[HEIGHT][WIDTH]) {  // Печать поля в терминал
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {  // Циклы, выводящие каждый символ матрицы в терминал
            printf("%c", field[i][j]);
        }
        printf("\n");  // "Нажатие Enter" после печати каждой строки
    }
    printf("NUM_PAD \"+\": +speed               NUM_PAD \"-\""
           ": -speed               ESC for exit\n");   // Инструкция под полем
}

void check_colony(char field[HEIGHT][WIDTH]) { // Функция проверки на возможность появления новой клетки
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (field[i][j] == '0' || field[i][j] == 'X') {
                check_around(field, i, j);    // Проверяет ячейки вокруг данной клетки
            }
        }
    }
}

void check_around(char field[HEIGHT][WIDTH], int i, int j) {  // Проверка ячеек вокруг клетки
    int p_steps = 3; // Количество шагов по вертикали
    for (int p = i - 1; p_steps > 0; p++, p_steps--) {
        if (p == -1) {
            p = HEIGHT - 1;
        }
        if (p == HEIGHT) {
            p = 0;
        }
        int k_steps = 3; // Количество шагов по горизонтали
        for (int k = j - 1; k_steps > 0; k++, k_steps--) {
            if (k == -1) {
                k = WIDTH - 1;
            }
            if (k == WIDTH) {
                k = 0;
            }
            
            
            
            if (field[p][k] != '.') {
                continue;
            }
            
            
            // Если клетка рядом с проверяемой ячейкой мертвая, проверяем количество соседей
            int neighbours = check_cell(field, p, k);
            if (neighbours == 3) {
                field[p][k] = 'O';
            }
        }
    }
}




int check_cell(char field[HEIGHT][WIDTH], int i, int j) {  // Тут проверяем количество соседей
    int neighbours = 0;
    
    
    // j - координата по горизонтали (от 0 до 79)
    // i - координата по вертикали (от 0 до 24)
    int prevJ = (j - 1) == -1 ? WIDTH - 1 : j - 1;   // Предыдущая j (j - 1)
    int prevI = (i - 1) == -1 ? HEIGHT - 1 : i - 1;  // Предыдущая i (i - 1)
    int nextJ = (j + 1) == WIDTH ? 0 : j + 1;        // Следующая j
    int nextI = (i + 1) == HEIGHT ? 0 : i + 1;       // Следующая i

    
    
    
    if (field[prevI][prevJ] == '0' || field[prevI][prevJ] == 'X') {
        neighbours++;
    }
    if (field[i][prevJ] == '0' || field[i][prevJ] == 'X') {
        neighbours++;
    }
    if (field[nextI][prevJ] == '0' || field[nextI][prevJ] == 'X') {
        neighbours++;
    }
    if (field[prevI][j] == '0' || field[prevI][j] == 'X') {
        neighbours++;
    }
    if (field[nextI][j] == '0' || field[nextI][j] == 'X') {
        neighbours++;
    }
    if (field[prevI][nextJ] == '0' || field[prevI][nextJ] == 'X') {
        neighbours++;
    }
    if (field[i][nextJ] == '0' || field[i][nextJ] == 'X') {
        neighbours++;
    }
    if (field[nextI][nextJ] == '0' || field[nextI][nextJ] == 'X') {
        neighbours++;
    }
    return neighbours;
}




void kill_born_cells(char field[HEIGHT][WIDTH]) { // Меняем промежуточные состояния ячеек на основные (Х - . , О - 0)
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (field[i][j] == 'X') {
                field[i][j] = '.';
            }
            if (field[i][j] == 'O') {
                field[i][j] = '0';
            }
        }
    }
}

unsigned char read_console() {
    unsigned char rb;
    struct timeval tv;
    int retval;
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    struct termios newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);
    tv.tv_sec = 0;
    tv.tv_usec = 10000;
    retval = select(1, &rfds, NULL, NULL, &tv);
    if (!retval) {
        rb = 0;
    } else {
        if (FD_ISSET(STDIN_FILENO, &rfds)) {
            rb = getchar();
        } else {
            rb = 0;
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return rb;
}
