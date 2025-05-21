#include <stdio.h>

int main(){
    
    const int MAX = 11;
    //изначально я хотел создать массивы, но потом их закоментировал так как понел что они не нужны, но вопрос остался (вопрос находится после массивов)
    //int horizontal[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // если пишу int horizontal[MAX] то программа не компилируется
    //int vertical[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // если пишу int horizontal[MAX] то программа не компилируется
    
    printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
    for(unsigned int vertical = 1; vertical < MAX; vertical++){
        printf("%d\t", vertical);
        for(unsigned int horizontal = 1; horizontal < MAX; horizontal++){
            printf("%d\t", vertical * horizontal);
        }
        printf("\n");
    }
    
    

    return 0;
}