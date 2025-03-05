//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
//【练习】计算1到100之间3的倍数之和
//int main()
//{
//	int i,sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			sum += i;
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}
//【while】
//int main()
//{
//	int i=0,sum = 0;
//	while (i <= 100)
//	{
//		if(i%3==0)
//		{
//			sum += i;
//		}
//		i++;
//	}
//	printf("%d", sum);
//	return 0;
//}

////8.0 do-while循环(出口判断，循环体至少执行一次)所以用的少 
///8.1【语法形式】
//do
//语句;
//while(表达式)

//do
//{
//
//}
//while()
//【练习】打印1-10
//int main()
//{
//	int i = 0;
//	do
//	{
//		i++;
//		//if(i%3==0)
//		printf("%d ", i);
//	} while (i <= 9);
//	return 0;
//}
//【练习】输入一个整数判断是几位数
//int main()
//{
//	int n = 0, m = 0;
//	scanf("%d", &n);
//	do
//	{
//		n /= 10;
//		m++;
//	} while (n > 0);
//	printf("%d", m);
//	return 0;
//}

////9.0 break和continue语句
//在循环执行过程中，如果某些状况发生的时候，需要提前终止循环，这是非常常见的现象。C中提供了break和continue两个关键字，就是运用到循环中的。
//break的作用是用于永久终止循环，只要break被执行，直接就会跳出循环，继续往后执行。
//continue的作用是跳过本次循环中continue后面的代码，在for和while循环中有所差异。

///9.1 for/while循环中的break和continue
//9.1.1【举例】
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//		{
//			break;//continur?当i=5，跳过后面的代码直接判断,那不就死循环了嘛//【总结】变量调整如果在continue后面那就会死循环
//		}
//		printf("%d ", i);
//			i++; 
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//		{
//			continue;
//		}
//		printf("%d\n", i);
//	}
//	return 0;
//}

///9.2 do...while循环

//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d\n", i);
//		i++;
//		if (i == 5)
//		{
//			break;
//		}
//	} while (i <= 10);
//	return 0;
//}
//和while里面几乎一模一样

////10.0 循环的嵌套
//【练习】找出100到200之间的素数
// 
// 【第一版本】
//int main()
//{
//	for (int i = 100; i <= 200; i++)//产生100-200的数字
//	{
//		int x = 1;//表示是素数
//		//下面判断是否为素数
//		for (int k = 2; k < i; k++)
//		{
//			if (i % k == 0)
//			{
//				x = 0;//表示不是素数
//				break;//这种结构我称之为“但凡”
//			}
//		}
//		if (x == 1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
//【改进】k只需要试到根号i,而且素数不可能是偶数
//int main()
//{
//	for (int i = 101; i <= 200; i+= 2)//产生100-200的数字
//	{
//		int x = 1;//表示是素数
//		//下面判断是否为素数
//		for (int k = 2; k <= sqrt(i); k++)//sqrt()是一个库函数，表示开平方
//		{
//			if (i % k == 0)
//			{
//				x = 0;//表示不是素数
//				break;//这种结构我称之为“但凡”
//			}
//		}
//		if (x == 1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

////【素数的判断有很多种方法】可以看看文章https://blog.csdn.net/2201_75806908/article/details/131872662

////11.0 goto语句
//C语言提供了一种非常特别的语法，就是【goto语句】和【跳转标号】，【goto语句】可以实现【在同一个函数内部】跳转到设置好的标号处。
//int main()
//{
//	printf("hehe\n");
//	goto next;
//	printf("haha\n");
//next:
//	printf("跳过了哈哈的打印\n");
//	return 0;
//}
//【注意】goto语句如果使用不当的话，会导致在函数内部随意乱跳转，打乱程序的执行流程，所以我能不用就不用；但是它也不算一无是处，在多层循环的代码中，如果想快速跳出，使用goto语句就非常方便。