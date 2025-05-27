#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>


void filling_an_array(char *line, const int MAX_LINE);
void checks_the_number_of_characters_entered_and_downs_the_case_of_characters(char *line, const int MAX_LINE, char *line_1, char *line_2);
void clearing_memory_occupied_by_malloc_and_emergency_program_termination(char *line_1, char *line_2);
void search_for_the_second_string_in_the_first(char *line_1, char *line_2);


int main(){
    const int MAX_LINE = 100; // максимальное разрешённое (за один ввод/раз) колличество символов для ввода
    char *line_1 = (char *)malloc((2 + MAX_LINE) * sizeof(char)); // 2 + это для того чтобы там хранились \n \0
    char *line_2 = (char *)malloc((2 + MAX_LINE) * sizeof(char)); // 2 + это для того чтобы там хранились \n \0
    if(NULL == line_1 or NULL == line_2){ // проверка, выделил ли память malloc
        printf("malloc memory allocation error"); // сообщаем пользователю что функция malloc не выделила память, сообщить об ошибке вышестоящим
        clearing_memory_occupied_by_malloc_and_emergency_program_termination(line_1, line_2); // вызываю функцию которая освобождает память и экстренно завершает программу
    }
    printf("The program checks two lines with a range of no more than %d"
            "characters (the height of the letters is not taken into account),"
            "if the second line is completely contained in the first, then the"
            "index of the place where the second line begins in the first line"
            "is displayed, otherwise -1 is displayed.\n\n", MAX_LINE);
    filling_an_array(line_1, MAX_LINE); // вызов функции для заполнения массива
    checks_the_number_of_characters_entered_and_downs_the_case_of_characters(line_1, MAX_LINE, line_1, line_2); // вызов функции которая проверяет количество введенных символов и понижает регистр символов
    filling_an_array(line_2, MAX_LINE); // вызов функции для заполнения массива
    checks_the_number_of_characters_entered_and_downs_the_case_of_characters(line_2, MAX_LINE, line_1, line_2); // вызов функции которая проверяет количество введенных символов и понижает регистр символов
    
    search_for_the_second_string_in_the_first(line_1, line_2); // вызов функции которая будет искать вторую строку в первой без учёта регистров
    
    for(int i = 0; line_1[i] != '\n'; i++){
        printf("[%d]%c ", i, line_1[i]);
    }
    return 0;
}


void filling_an_array(char *line, const int MAX_LINE){
    printf("Enter characters, no more than %d\n", MAX_LINE);
    fgets(line, MAX_LINE + 2, stdin); // + 2 нужно записать \n \0
}

void checks_the_number_of_characters_entered_and_downs_the_case_of_characters(char *line, const int MAX_LINE, char *line_1, char *line_2){
    for(unsigned i = 0; ; i++){
        if(line[i] >= 'A' and line[i] <= 'Z'){ // проверка на большие символы
            line[i] = line[i] + 'a' - 'A'; // если большой символ найден то он станет маленьким
        }
        if('\n' == line[i]){ // проверка на конец строки
            break; // выход из цикла
        }
        if('\0' == line[i]){ // проверка на колличество введённых символов
            printf("more than %d characters were entered", MAX_LINE); // сообщение пользователю о избыточном вводе символов
            clearing_memory_occupied_by_malloc_and_emergency_program_termination(line_1, line_2); // вызываю функцию которая освобождает память и экстренно завершает программу
        }
    }
}

void clearing_memory_occupied_by_malloc_and_emergency_program_termination(char *line_1, char *line_2){
    free(line_1); // возвращаем занятую память системе
    free(line_2); // возвращаем занятую память системе
    abort(); // экстренно завершаю программу
}

void search_for_the_second_string_in_the_first(char *line_1, char *line_2){ // функция ищет вторую строку в первой, регистры не учитываются
    for(unsigned i = 0, j = 0; line_1[i] != '\n' and line_2[j] != '\n';){
        if(line_1[i] == line_2[j]){
            j++;
            if(line_2[j] == '\n'){
                printf("%d\n", i - j + 1);
                return;
            }
        }
        else if(0 != j){
            i--;
            j = 0;
        }
        i++;
    }
    printf("-1\n");
}