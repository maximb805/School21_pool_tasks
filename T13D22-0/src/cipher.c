#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void read_file();
char * get_file_name();
void print_file(char * file_name);
void menu_work(int * n, int * run, int * flag, char ** file_name);
char * get_string();
void clear_h_encrypt_c();
int check_name(struct dirent * entry, char * type);
char * get_full_path(char * path, char * addition);
char * encrypt(FILE * file, int step);

int main() {
    read_file();
    return 0;
}

void read_file() {
    int n = 1, run = 1, last_n = 0;
    char * file_name;
    char check;
    while (run) {
        int flag = 1;
        int sc_check = scanf("%d", &n);
        scanf("%c", &check);
        if (last_n == 1 && n == 1 && file_name != NULL) {
            free(file_name);
            file_name = NULL;
        }
        if (sc_check == 1 && check == '\n') {
            menu_work(&n, &run, &flag, &file_name);
        } else {
            flag = 0;
        }
        if (flag == 0) {
            char destroy = '0';
            while (destroy != '\n' && check != '\n' && check != '\0') {
                scanf("%c", &destroy);
            }
            printf("n/a\n");
        }
        last_n = n;
    }
}

char * get_file_name() {
    char symbol;
    char * file_name;
    file_name = malloc(1);
    file_name[0] = '\0';
    if (file_name != NULL) {
        scanf("%c", &symbol);
        int i = 0;
        while (symbol != '\n') {
            char * tmp = realloc(file_name, i + 1);
            if (tmp != NULL) {
                file_name = tmp;
                file_name[i] = symbol;
            } else {
                break;
            }
            scanf("%c", &symbol);
            i++;
        }
    }
    return file_name;
}

char * get_string() {
    char * string = get_file_name();
    return string;
}

void print_file(char * file_name) {
    char symbol;
    int symbols_count = 0;
    FILE * file;
    file = fopen(file_name, "r");
    if (file != NULL) {
        while ((symbol = fgetc(file)) != EOF) {
            printf("%c", symbol);
            symbols_count++;
        }
        if (symbols_count == 0) {
            printf("n/a");
        }
        printf("\n");
    } else {
        printf("n/a\n");
    }
    fclose(file);
}

void menu_work(int * n, int * run, int * flag, char ** file_name) {
    switch (*n) {
        case -1 : {
            if (*file_name != NULL) {
                free(*file_name);
                *file_name = NULL;
            }
            *run = 0;
            break;
        }
        case 1 : {
            *file_name = get_file_name();
            if (*file_name == NULL) {
                *flag = 0;
            } else {
                print_file(*file_name);
            }
            break;
        }
        case 2 : {
            char * string = get_string();
            if (*file_name != NULL) {
                FILE * file = fopen(*file_name, "r");
                if (file != NULL) {
                    file = freopen(*file_name, "a", file);
                    fputs(string, file);
                    fclose(file);
                    print_file(*file_name);
                } else {
                    printf("n/a\n");
                }
                fclose(file);
                free(*file_name);
                *file_name = NULL;
            } else {
                printf("n/a\n");
            }
            free(string);
            break;
        }
        case 3: {
            clear_h_encrypt_c();
            if (*file_name != NULL) {
                free(*file_name);
                *file_name = NULL;
            }
            break;
        }
        default : {
            if (*file_name != NULL) {
                free(*file_name);
                *file_name = NULL;
            }
            *flag = 0;
            break;
        }
    }
}

void clear_h_encrypt_c() {
    int shift;
    char check;
    printf("Enter directory path: ");
    char * dir = get_file_name();
    if (dir != NULL) {
        DIR *mydir = opendir(dir);
        if (mydir != NULL) {
            printf("Enter encryption step: ");
            if (scanf("%d%c", &shift, &check)
                == 2 && check == '\n') {
                struct dirent * entry = readdir(mydir);
                while (entry) {
                    if (check_name(entry, ".h")) {
                        char * full_path = get_full_path(dir, entry->d_name);
                        FILE * file = fopen(full_path, "r");
                        if (file != NULL) {
                            file = freopen(full_path, "w", file);
                            fputs("", file);
                            fclose(file);
                        }
                        if (full_path != NULL) {
                            free(full_path);
                            full_path = NULL;
                        }
                    }
                    if (check_name(entry, ".c")) {
                        char * full_path = get_full_path(dir, entry->d_name);
                        FILE * file = fopen(full_path, "r");
                        if (file != NULL) {
                            char * encrypted_str = encrypt(file, shift);
                            if (encrypted_str != NULL) {
                                file = freopen(full_path, "w", file);
                                fputs(encrypted_str, file);
                                free(encrypted_str);
                            }
                            fclose(file);
                        }
                        if (full_path != NULL) {
                            free(full_path);
                            full_path = NULL;
                        }
                    }
                entry = readdir(mydir);
                }
            closedir(mydir);
            } else {
                printf("Wrong encryption shift value!\n");
            }
        } else {
            printf("Wrong directory path!\n");
        }
    } else {
        printf("Out of memory!\n");
    }
    free(dir);
}

int check_name(struct dirent * entry, char * type) {
    int type_l = 0, name_l = 0;
    for (int i = 0; type[i] != '\0'; i++) {
        type_l++;
    }
    for (int i = 0; entry->d_name[i] != '\0'; i++) {
        name_l++;
    }
    int result = 1;
    if (type_l > name_l) {
        result = 0;
    }
    while (result) {
        if (type_l == 0) {
            break;
        }
        if (type[type_l-1] != entry->d_name[name_l-1]) {
            result = 0;
        }
        type_l--;
        name_l--;
    }
    return result;
}

char * get_full_path(char * path, char * addition) {
    int path_l = 0;
    for (int i = 0; path[i] != '\0'; i++) {
        path_l++;
    }
    char * full_path = malloc(path_l + 2);
    if (full_path != NULL) {
        full_path = strcpy(full_path, path);
        full_path[path_l] = '/';
        int i = 0;
        while (addition[i] != '\0') {
            full_path[path_l + i + 1] = addition[i];
            char * tmp = realloc(full_path, path_l + i + 3);
            if (tmp != NULL) {
                full_path = tmp;
            } else {
                free(full_path);
                full_path = NULL;
                break;
            }
            i++;
        }
    }
    return full_path;
}

char * encrypt(FILE * file, int shift) {
    shift = shift % 127;
    char * string = NULL;
    int zero, inverted_zero;
    if (shift != 0) {
        if (shift < 0) {
            zero = 127;
            inverted_zero = 1;
        } else {
            zero = 1;
            inverted_zero = 127;
        }
        string = malloc(1);
        if (string != NULL) {
            char symbol;
            int i = 0;
            while ((symbol = fgetc(file)) != EOF) {
                if (symbol == inverted_zero) {
                    symbol = 0;
                }
                symbol = symbol + shift;
                if (symbol < 0) {
                    if (zero == 127) {
                        symbol = 128 + symbol + 1;
                    } else {
                        symbol = 127 + symbol;
                    }
                }
                if (symbol == '\0') {
                    symbol = zero;
                }
                string[i] = symbol;
                char * tmp = realloc(string, i + 2);
                if (tmp != NULL) {
                    string = tmp;
                } else {
                    free(string);
                    string = NULL;
                    break;
                }
                i++;
            }
        }
    }
    return string;
}
