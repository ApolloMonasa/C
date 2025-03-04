/*************************************************************************
	> File Name: digit.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 05:25:20 PM CST
 ************************************************************************/

#include<stdio.h>

void print_digit(int x){
    for(int i = 31;i >= 0;i--){
        printf("%c",(x & (1 << i))? '1':'0');
    }
    printf("\n");
}

int main(){
    int a = 5, b = 3;
    printf("a =     ");print_digit(a);
    printf("b =     ");print_digit(b);
    printf("a & b = ");print_digit(a & b);
    printf("a | b = ");print_digit(a | b);
    printf("a ^ b = ");print_digit(a ^ b);//^:统计各个位上的1的奇偶性，若为奇，则输出1；自己就是自己的逆运算，可以交换两个数的值，总结下来，可以用来交换两个数的算法必须含有一对逆运算，+-，*/，^^都行。
    a ^= b; b ^= a; a ^=b;
    printf("a =     ");print_digit(a);
    printf("b =     ");print_digit(b);
    printf("~a =    ");print_digit(~a);
    printf("(~b + 1)（可得负数）= ");printf("%d\n",~b+1);
    //巧妙算法算最低位权
    printf("Now input a number,and you will get the lowest binary bit weight:\n");
    int x;
    scanf("%d",&x);
    printf("x =        ");print_digit(x);
    printf("(-x & x) = ");print_digit(-x & x);

    //左右位移：末尾补0，开头补符号位
    int c = 1279813123,d = -c;
    printf("c =      ");print_digit(c);
    printf("d =      ");print_digit(d);
    printf("c << 1 = ");print_digit(c << 1);
    printf("c >> 1 = ");print_digit(c >> 1);
    printf("d << 1 = ");print_digit(d << 1);
    printf("d >> 1 = ");print_digit(d >> 1);

    //左移就是*2，右移是向下取整的/2（注意和C语言的向0取整的/2区别开）,所以右移对正数来说和除法是一样的，区别在于负数。
    printf("-5 / 2 =  ");printf("%d\n",-5/2);
    printf("-5 >> 1 = ");printf("%d\n",-5>>1);
    printf("-5 << 1 = ");printf("%d\n",-5<<1);

    return 0;
}
