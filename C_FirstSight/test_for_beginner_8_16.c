//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
////2.0 关系操作符
//C用于比较的表达式，称为“关系表达式”（relational expression）.里面使用的运算符就是关系运算符（relational operator），主要有六个：
//  >大于运算符
//  <小于运算符
//  >=大于等于运算符
//  <=小于等于运算符
//  ==相等运算符
//  !=不相等运算符
//  
//  关系表达式通常返回0或1，表示真假。
// int main()
//{
//	int a = 0;
//	int b = 0;
//	int b = 1;
//
//	int c = (a == b);//这个操作相当于初始化
//	printf("c = %d\n", c);
//
//	return 0;
//}
//
//【注意】关系操作符不适合连用，如a<b<c和你以为的不一样，它有两步 第一步：a和b比较得到返回值0或1，第二步：返回值和c比较
//【纠正】你想要的意思应该这样表达:[a<b && b<c]
//【例子】输入一个年龄，如果在18到36之间就输出青年
//int main()
//{
//	int age = 0;
//	printf("请输入你的年龄：");
//	scanf("%d", &age);
//	if (age > 18 && age < 36)
//		printf("青年\n")
//	return 0;
//}

////3.0 条件操作符（唯一一个三目操作符）
//【形式】(exp1 ? M : N)
//【运行】如果表达式1真，返回M，反之则返回N
//【实质】简化的if，else语句，
//【可以嵌套】
//【示例】用三目操作符改写下述代码：
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	if (a > 5)
//		b = 3;
//	else b = -3;
//	printf("%d\n", b);
//
//	return 0;
//}
//【改写后】
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	b = (a > 5 ? 3 : -3);
//	printf("%d", b);
//	return 0;
//}
//【练习】写一个比较两个整数大小的程序
 
 
////4.0 逻辑操作符：&&,||,!
//逻辑操作符提供逻辑判断功能，用于构建更复杂的表达式
// !  逻辑取反运算符（改变单个表达式的真假）
// && 逻辑与运算符，就是并且的意思（两侧的表达式都为真则真）
// || 逻辑或运算符，就是或者的意思（两侧的表达式都为假才假）
//【注意】0为假，非零为真

///4.1 逻辑取反运算符 ！
//【解释】a=0,那么!a=1;a!=0,那么!a=0
//【示例】
//int main()
//{
//	int flag = 0;
//	scanf("%d", &flag);
//	//如果flag为假就打印呵呵
//	if (!flag)
//		printf("hehe");
//	return 0;
//}

///4.2 逻辑与运算符（略）
///4.3 逻辑或运算符（略）

///4.4 【练习】闰年的判断
//int main()
//{
//	int year = 0;
//	printf("请输入年份：");
//	scanf("%d", &year);
//	if (year % 4 == 0 && year % 100 != 0)
//		printf("闰年");
//	else if (year % 400 == 0)
//		printf("闰年");
//	else
//		printf("不是闰年");
//
//	return 0;
//}
//【改进】
//int main()
//{
//	int year = 0;
//	printf("请输入年份：");
//	scanf("%d", &year);
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		printf("闰年");
//	else
//		printf("不是闰年");
//	return 0;
//}

///4.4 短路
//C语言中逻辑运算符还有一个特点，它总是先对左侧的表达式求值，在对右侧的表达式求值，这个顺序是保证的。
//如果算完左边的表达式就可以决定逻辑运算符的计算结果，就不再对右边的表达式求值，这种情况称为短路。简单来说，【与】（&&）遇假（0）则假（0）【或】（||）遇真（！=0）则真（1）
//【例子】
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	i = a++ || ++b ||d++;
//	printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//
//	return 0;
//}
////这个例子让我理解了逻辑操作符连接起来的结构是有返回值的，并且操作逻辑时的根据也是所连接部分的值；

////5.0 switch语句

