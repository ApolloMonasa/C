/*************************************************************************
	> File Name: 2.function.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Feb 2025 07:07:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int add(int a, int b){
    return a + b;
}

double select_function(int flag, double x){
    switch (flag){
        case 1: return sqrt(x);
        case 2: return x * x;
        default: printf("Error flag\n"); break;
    }
    return 0;
}

void print_hello_world(int n){
    for(int i = 0; i < n; i++){
        printf("Hello Hangzhou\n");
    }
}

int main(){
    printf("3 + 4 = %d\n", add(3, 4));
    printf("sqrt(3) = %lf\n",select_function(1, 3));
    printf("4 * 4 = %lf\n",select_function(2, 4));
    print_hello_world(3);
    printf("--------\n");
    print_hello_world(5);
    return 0;
}
