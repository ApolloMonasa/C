//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
////int main()
////{
////	double d = 0;
////	double h = 0;
////	double s = 0;
////
////	scanf("%lf %lf", &d, &h);
////	s = 0.5 * d * h;
////	printf("%.2lf", s);
////	return 0;
////}
////int main()
////{
////	int A = 0;
////	int B = 0;
////	scanf("%d %d", &A, &B);
////	printf("%d+%d=%d\n%d-%d=%d\n%d*%d=%d", A, B, A + B, A, B, A - B, A, B, A * B);
////	return 0;
////}
////int main()
////{
////	int n = 0;
////	double m = 0;
////	scanf("%lf %d", &m, &n);
////	printf("你好，可以借我%.2lf元钱吗？\n%d天后一定还！", m, n);
////
////
////	return 0;
////}
////【移花接木】
////int main()
////{
////	double a = 0;
////	double b = 0;
////	double c = 0;
////	double d = 0;
////	double A = 0;
////	double B = 0;
////	scanf("%lf %lf", &a, &b);
////	c = a - (int)a;
////	d = b - (int)b;
////	c = (c >= 0) ? c : -c;
////	d = (d >= 0) ? d : -d;//得到了a和b的小数部分c和d
////	A =  (int)a >= 0 ? (int)a + d: (int)a - d ;//用三目运算符解决正负问题
////	B = (int)b >= 0 ? (int)b + c : (int)b - c;
////	printf("%lf ", A);//打印出结果
////	printf("%lf", B);
////	
////
////	return 0;
////}
////【杜兄版本】
////#include<stdio.h>
////int main() {
////    double a, b;
////    scanf("%lf%lf", &a, &b);
////    int a2 = 1, b2 = 1;
////    if (a - 0 < 1e-7) {
////        a2 = -1;
////        a = -a;
////    }
////    if (b - 0 < 1e-7) {
////        b2 = -1;
////        b = -b;
////    }
////    int a1 = (int)a;//a1是整数部分，a是小数部分
////    a = a - a1;
////    int b1 = (int)b;
////    b = b - b1;
////    printf("%.6lf %.6lf", (a1 + b) * a2, (b1 + a) * b2);
////    return 0;
////}
////int main()
////{
////	double a = 0, b = 0, c = 0, d = 0, max = 0, min = 0;
////	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
////	max = a - b > 0 ? a : b;
////	max = max - c > 0 ? max : c;
////	max = max - d > 0 ? max : d;
////	min = a - b < 0 ? a : b;
////	min = min - c > 0 ? c : min;
////	min = min - d < 0 ? min : d;
////	printf("%.2lf %.2lf", max, min);
////	return 0;
////}
////int main()
////{
////	int input,sum = 0;
////	double cost = 0;
////	while (scanf("%d", &input) == 1)
////	{
////		if (input == -1)
////		{
////			break;
////		}
////		else
////		{
////			sum = sum + input;
////		}
////	}
////	if (sum <= 2760)
////		printf("%.1lf", 0.538 * sum);
////	else if (sum > 2760 && sum <= 4800)
////		printf("%.1lf", 2760 * 0.538 + (sum - 2760) * 0.588);
////	else if(sum>4800)
////		printf("%.1lf", 2760 * 0.538 + (4800 - 2760) * 0.588 + (sum - 4800) * 0.838);
////	return 0;
////}
//
//
////【第一次用math.h】
////函数声明阶乘
////long long factorial(int k) {
////	if (k == 0) {
////		return 1;
////	}
////	else {
////		return k * factorial(k - 1);
////	}
////}
////int main()
////{
////	double x = 0, sum = 1;
////	int n = 0;
////	int i = 1;
////	
////	scanf("%lf %d", &x, &n);
////	while (i <= n) {
////		sum = sum + pow(x, i) / factorial(i);
////	}
////	printf("%.4lf", sum);
////	return 0;
////}
////#include <stdio.h>
////int main()
////{
////	int n = 0;
////	scanf("%d", &n);
////
////	
////		int arr[ n ] = { 0 };
////
////		int i = 0;
////		for (i = 0; i < n; i++)
////		{
////			scanf("%d", &arr[i]);
////		}
////		for (i = 1; i < n - 1; i++)
////		{
////			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
////			{
////				printf("%d\n", arr[i]);
////			}
////		}
////	
////	return 0;
////}
////#include <stdio.h>
////#include <stdlib.h>
////
////int main()
////{
////    int n;
////    scanf("%d", &n);
////
////    int arr[n];
////    for (int i = 0; i < n; i++)
////    {
////        scanf("%d", &arr[i]);
////    }
////    // 冒泡排序,n个数的排列，我理论上最大循环n-1次，每次确定末端一个数
////    for (int i = 0; i < n - 1; i++)
////    {
////        for (int j = 0; j < n - 1 - i; j++)
////        {
////            if (abs(arr[j]) < abs(arr[j + 1]))
////            {
////                int temp = arr[j];
////                arr[j] = arr[j + 1];
////                arr[j + 1] = temp;
////            }
////        }
////    }
////
////    for (int i = 0; i < n; i++)
////    {
////        if (i > 0)
////        {
////            printf(" ");
////        }
////        printf("%d", arr[i]);
////    }
////    printf("\n");
////
////    return 0;
////}
////#define _CRT_SECURE_NO_WARNINGS 1
////#include <stdio.h>
////int ing_sum(int num)
////{
////	int temp = 0;
////	for (int i = 1; i < num; i++)
////	{
////		if (num % i == 0)
////		{
////			temp += i;
////		}
////	}
////	return temp;
////}
////int is_it_wan(int num)
////{
////	int t = ing_sum(num);
////	return (t == num);
////}
////int main()
////{
////	int num = 0;
////	scanf("%d", &num);
////	if (is_it_wan(num))
////		printf("是完数");
////	else
////		printf("不是完数");
////}
//
////#include <stdio.h>
////int main()
////{
////	int num = 0;
////	scanf("%d", &num);//12340
////	while (num % 10 == 0)
////	{
////		num /= 10;
////	}
////	if (num >= 0)
////	{
////		while (num > 0)
////		{
////			printf("%d", num % 10);
////			num /= 10;
////
////		}
////	}
////	else
////	{
////		num *= -1;
////		printf("%c", '-');
////		while (num > 0)
////		{
////			printf("%d", num % 10);
////			num /= 10;
////
////		}
////
////
////	}
////
////
////	
////
////	return 0;
////}
//#include <string.h>
//#include <stdio.h>
