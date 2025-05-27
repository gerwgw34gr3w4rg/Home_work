#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


int game(char player, char bot, char box1, char box2, char box3, char box4, char box5, char box6, char box7, char box8, char box9, int i, int num);
int move_bot(char player, char bot, char box1, char box2, char box3, char box4, char box5, char box6, char box7, char box8, char box9, int i, int num);

int main(){
    srand(time(NULL));
    char player = 'A';
    char bot = 'A';
    char box1 = '1', box2 = '2', box3 = '3', box4 = '4', box5 = '5', box6 = '6', box7 = '7', box8 = '8', box9 = '9';
    int cross = 1, zero = 0;
    printf("\n  Подсказка: Для игры рекомендуется использовать боковые клавиши справа\n");
    printf("\n  Подсказка: Поля под номерами от %c до %c (включительно) считаются свободными\n", box1, box9);
    int game_number = -1;
    printf("\n  Выбери чем будешь играть, если крестиком нажми %d, если ноликом нажми %d, (после нажми клавишу enter(ввод))\n\n  ", cross, zero);
    scanf("%d", &game_number);
    if(game_number != cross and game_number != zero){
        printf("\n  Нужно было ввести %d или %d\n", cross, zero);
        abort();
    }
    if(game_number == cross){
        player = 'X';
        bot = 'O';
    }
    else{
        player = 'O';
        bot = 'X';
    }
    system("clear");
    
    int i = box9 - '0';
    int num = -1;
    game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);

    
    return 0;
}

int game(char player, char bot, char box1, char box2, char box3, char box4, char box5, char box6, char box7, char box8, char box9, int i, int num){
    system("clear");
    printf("\n");
    printf("  +-------+-------+-------+\n");
    printf("  |       |       |       |\n");
    printf("  |   %c   |   %c   |   %c   |\n", box7, box8, box9);
    printf("  |       |       |       |\n");
    printf("  +-------+-------+-------+\n");
    printf("  |       |       |       |\n");
    printf("  |   %c   |   %c   |   %c   |\n", box4, box5, box6);
    printf("  |       |       |       |\n");
    printf("  +-------+-------+-------+\n");
    printf("  |       |       |       |\n");
    printf("  |   %c   |   %c   |   %c   |\n", box1, box2, box3);
    printf("  |       |       |       |\n");
    printf("  +-------+-------+-------+\n");
    printf("\n  Выбери любой свободный квадрат нажав соответствующую цифру\n");
    printf("\n  Напоимналка: Я %c, бот %c\n\n  ", player, bot);
    
    
    if(0 == i){
        printf("%d\n\n  Ничья\n", num);
        return 0;
    }
    
    if(-1 == i){
        printf("%d\n\n  Выиграл %c", num, player);
        return 0;
    }
    if(-2 == i){
        printf("%d\n\n  Выиграл %c", num, bot);
        return 0;
    }
    
    if(scanf("%d", &num) != 1){
        printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
        return 0;
    }
    if(1 == num){
        if(box1 == player or box1 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box1 = player;
        if(box1 == box2 and box2 == box3){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box1 == box5 and box5 == box9){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box1 == box4 and box4 == box7){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(2 == num){
        if(box2 == player or box2 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box2 = player;
        if(box2 == box1 and box2 == box3){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box2 == box5 and box5 == box8){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(3 == num){
        if(box3 == player or box3 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box3 = player;
        if(box3 == box2 and box2 == box1){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box3 == box5 and box5 == box7){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box3 == box6 and box6 == box9){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(4 == num){
        if(box4 == player or box4 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box4 = player;
        if(box4 == box5 and box5 == box6){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box4 == box1 and box4 == box7){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(5 == num){
        if(box5 == player or box5 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box5 = player;
        if(box5 == box4 and box4 == box6){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);;
        }
        else if(box5 == box2 and box2 == box8){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box5 == box7 and box7 == box3){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box5 == box9 and box9 == box1){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(6 == num){
        if(box6 == player or box6 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box6 = player;
        if(box6 == box4 and box4 == box5){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box6 == box3 and box3 == box9){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(7 == num){
        if(box7 == player or box7 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box7 = player;
        if(box7 == box8 and box8 == box9){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box7 == box5 and box5 == box3){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box7 == box4 and box4 == box1){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(8 == num){
        if(box8 == player or box8 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box8 = player;
        if(box8 == box7 and box7 == box9){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box8 == box5 and box5 == box2){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(9 == num){
        if(box9 == player or box9 == bot){
            printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
            return 0;
        }
        box9 = player;
        if(box9 == box7 and box7 == box8){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box9 == box5 and box5 == box1){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box9 == box6 and box6 == box3){
            i = -1;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else {
        printf("\n  Нужно было выбрать свободную клетку, победила команда %c\n", bot);
        return 0;
    }
    i--;
    if(0 == i){
        return game(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
    }
    
    
    return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
}


int move_bot(char player, char bot, char box1, char box2, char box3, char box4, char box5, char box6, char box7, char box8, char box9, int i, int num){
    if(1 == num){
        if(box1 == player or box1 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box1 = bot;
        if(box1 == box2 and box2 == box3){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box1 == box5 and box5 == box9){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box1 == box4 and box4 == box7){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(2 == num){
        if(box2 == player or box2 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box2 = bot;
        if(box2 == box1 and box2 == box3){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box2 == box5 and box5 == box8){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(3 == num){
        if(box3 == player or box3 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box3 = bot;
        if(box3 == box2 and box2 == box1){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box3 == box5 and box5 == box7){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box3 == box6 and box6 == box9){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(4 == num){
        if(box4 == player or box4 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box4 = bot;
        if(box4 == box5 and box5 == box6){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box4 == box1 and box4 == box7){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(5 == num){
        if(box5 == player or box5 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box5 = bot;
        if(box5 == box4 and box4 == box6){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);;
        }
        else if(box5 == box2 and box2 == box8){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box5 == box7 and box7 == box3){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box5 == box9 and box9 == box1){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(6 == num){
        if(box6 == player or box6 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box6 = bot;
        if(box6 == box4 and box4 == box5){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box6 == box3 and box3 == box9){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(7 == num){
        if(box7 == player or box7 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box7 = bot;
        if(box7 == box8 and box8 == box9){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box7 == box5 and box5 == box3){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box7 == box4 and box4 == box1){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(8 == num){
        if(box8 == player or box8 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box8 = bot;
        if(box8 == box7 and box7 == box9){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box8 == box5 and box5 == box2){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    else if(9 == num){
        if(box9 == player or box9 == bot){
            num = rand() % 9 + 1;
            return move_bot(player,bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        box9 = bot;
        if(box9 == box7 and box7 == box8){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box9 == box5 and box5 == box1){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
        else if(box9 == box6 and box6 == box3){
            i = -2;
            return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
        }
    }
    i--;
    return game(player, bot, box1, box2, box3, box4, box5, box6, box7, box8, box9, i, num);
}




