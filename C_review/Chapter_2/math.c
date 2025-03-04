/*************************************************************************
	> File Name: math.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 07:56:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    printf("pow(2,3)      = %lf\n",pow(2.0, 3));
    printf("sqrt(2)       = %lf\n",sqrt(2));
    printf("ceil(4.01)    = %lf\n",ceil(4.01));//上取整
    printf("floor(4.99)   = %lf\n",floor(4.99));//下取整
    //注意：abs这个求整数绝对值的函数定义在<stdlib.h>
    printf("abs(-65)      = %d\n",abs(-65));
    printf("fabs(-95.9)   = %lf\n",fabs(-95.9));

    printf("log(9)        = %lf\n",log(9));
    printf("log10(1000)   = %lf\n",log10(1000));

    printf("acos(-1)[PI]  = %lf\n",acos(-1));
    printf("asin(1)[PI/2] = %lf\n",asin(1));
    printf("atan(-1)      = %lf\n",atan(-1));
    printf("atan2(1,1)    = %lf\n",atan2(1,1));
    

    return 0;
}
