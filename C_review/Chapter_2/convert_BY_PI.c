/*************************************************************************
	> File Name: convert_BY_PI.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 08:29:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main(){
    printf("Input a angle, and you will get the corresponding radians.\n");
    double angle;
    scanf("%lf",&angle);
    printf("%lf\n",angle*M_PI/180);
    return 0;
}
