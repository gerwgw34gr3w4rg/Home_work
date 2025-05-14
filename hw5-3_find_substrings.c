#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


void down_register(char *line);
void scan_line(char *line_1, char *line_2, int SIZE_LINE);


int main(){
    const int SIZE_LINE = 100;
    
    char *line_1 = (char *)malloc(SIZE_LINE + 2);
    if (NULL == line_1){
        fprintf(stderr, "Error line_1 memory");
        abort();
    }
    printf("Enter something (but no more than %d characters)\n", SIZE_LINE);
    fgets(line_1, SIZE_LINE + 2, stdin);
    for(int i = 0; line_1[i] != '\n'; i++){
        if(line_1[i] == '\0'){
            free(line_1);
            fprintf(stderr, "You had to enter up to %d characters", SIZE_LINE);
            abort();
        }
    }
    down_register(line_1);
    printf("\n");
    
    char *line_2 = (char *)malloc(SIZE_LINE + 2);
    if (NULL == line_2){
        free(line_1);
        fprintf(stderr, "Error line_2 memory");
        abort();
    }
    printf("Enter something again (but no more than %d characters)\n", SIZE_LINE);
    fgets(line_2, SIZE_LINE + 2, stdin);
    for(int i = 0; line_2[i] != '\n'; i++){
        if(line_2[i] == '\0'){
            free(line_1);
            free(line_2);
            fprintf(stderr, "You had to enter up to %d characters", SIZE_LINE);
            abort();
        }
    }
    down_register(line_2);
    printf("\n");
    
    #if 0
    printf("\nline_1 = [");
    for(size_t i = 0; line_1[i] != '\0'; i++){
        printf("%d ", (int)line_1[i]);
    }
    printf("\b]\n");
    
    printf("\nline_2 = [");
    for(size_t i = 0; line_2[i] != '\0'; i++){
        printf("%d ", (int)line_2[i]);
    }
    printf("\b]\n");
    #endif
    scan_line(line_1, line_2, SIZE_LINE);
    
    free(line_1);
    free(line_2);
    return 0;
}

void scan_line(char *line_1, char *line_2, int SIZE_LINE){
    int box = -1;
    size_t j = 0;
    for(size_t i = 0; line_1[i] != '\n'; i++){
        if(line_1[i] == line_2[j]){
            j++;
            if(line_2[j] == '\n'){
                j--;
                box = i - j;
                break;
            }
        }
        else if(j != 0){
            if(line_1[i] == line_2[0]){
                j = 1;
            }
            else{
                j = 0;
            }
        }
        
    }
    printf("%d", box);
}

void down_register(char *line){
    for(int i = 0; line[i] != '\0'; i++){
        if(line[i] >= 'A' and line[i] <= 'Z'){
            line[i] = line[i] + 'a' - 'A';
        }
    }
}
