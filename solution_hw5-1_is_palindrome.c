#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


#define LIMIT_LINE 101


int main(){
    char *custom_arr = (char *)malloc(sizeof(char) * LIMIT_LINE);
    if (NULL == custom_arr){
        printf("Error malloc");
        free(custom_arr);
        return 1;
    }
    printf("Enter up to %d characters, then press Enter.\n", LIMIT_LINE - 1);
    fgets(custom_arr, LIMIT_LINE, stdin);
    int right = 0;
    while(custom_arr[right] != '\0'){
        right++;
    }
    right = right -2;  // last two characters are '\n', '\0'
    for(int left = 0; left < right;){
        if(custom_arr[left] == ' ' or custom_arr[left] == 0){
            left++;
        }
        else if(custom_arr[right] == ' ' or custom_arr[right] == 0){
            right--;
        }
        else {
            if(custom_arr[left] > '@' and custom_arr[left] < '['){
                custom_arr[left] = custom_arr[left] + ' ';
            }
            if(custom_arr[right] > '@' and custom_arr[right] < '['){
                custom_arr[right] = custom_arr[right] + ' ';
            }
            if(custom_arr[left] != custom_arr[right]){
                printf("This is not a palindrome\n");
                free(custom_arr);
                return 0;
            }
        }
        left++;
        right--;
    }
    printf("This is a palindrome");
    free(custom_arr);
    return 0;
}