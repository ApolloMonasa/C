/*************************************************************************
	> File Name: 9.print_1-100.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 09:29:14 PM CST
 ************************************************************************/

#include<stdio.h>

/*void print(int n) {
    if (n == 1) {
        printf("%d\n", n);
        return ;
    }
    print(n - 1);
    printf("%d\n", n);
    return ;
}
*/

int cnt =100;

int main() {
    //print(100);
    int n = cnt;
    cnt -= 1;
    if (n == 1) {
        printf("%d\n", n);
        return 0;
    }
    main();
    printf("%d\n", n);

    return 0;
}
