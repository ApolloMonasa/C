/*************************************************************************
	> File Name: 21.HZOJ-237.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 10:17:25 AM CST
 ************************************************************************/

#include<stdio.h>

int arr[8], vis[8] = {0};

void print_one_result(int n) {
    for(int i = 0; i < n; i++){
        if(i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return ;
}

void f(int i, int n){
    if(i == n) {
        print_one_result(n);
    }
    for(int k = 1; k <= n; k++){
        if(vis[k]) continue;
        arr[i] = k;
        vis[k] = 1;
        f(i + 1, n);
        vis[k] = 0;
    }
    return ;
}


int main(){
    int n;
    scanf("%d", &n);
    f(0, n);
    return 0;
}
