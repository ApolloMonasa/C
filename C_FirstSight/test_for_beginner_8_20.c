//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <Windows.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//goto不是必须的，有替代选项
//举例：关机程序，运行起来之后，你的电脑将在一分钟内关机，但是输入：我是猪，就能取消关机
//int main()
//{
//	char input[20] = { 0 };
//	//怎么关机：在命令行里面输入shutdown -s -t 60倒计时关机；shutdown -a取消关机
//	//system函数可以执行系统命令，在windows.h里面
//	system("shutdown -s -t 60");
//	again:
//	printf("请注意，你的电脑将在一分钟内关机，如果输入：我是猪，就取消关机。");
//	scanf("%s", input);
//	if (0 == strcmp(input,"我是猪"))//注意，两个字符串不能用==比较大小，应该使用strcmp比较字符串大小,如果两个 字符串相等，就返回0//在string.h里面
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//
//
//
//	return 0;
//}

//不能用goto 【改进】【循环】
//int main()
//{
//	char input[20] = { 0 };
//	//怎么关机：在命令行里面输入shutdown -s -t 60倒计时关机；shutdown -a取消关机
//	//system函数可以执行系统命令，在windows.h里面
//	system("shutdown -s -t 60");
//
//	while (1)
//	{
//	again:
//		printf("请注意，你的电脑将在一分钟内关机，如果输入：我是猪，就取消关机。");
//		scanf("%s", input);
//		if (0 == strcmp(input, "我是猪"))//注意，两个字符串不能用==比较大小，应该使用strcmp比较字符串大小,如果两个 字符串相等，就返回0//在string.h里面
//		{
//			system("shutdown -a");
//			break;
//		}
//		
//
//	}
//	return 0;
//}

//至此，分支循环（上）学完了

//分支循环（下）
//**************【猜数字游戏】**********  要求：电脑随机生成一个1-100之间的数字，玩家猜测数字，猜大了或者猜小了都会告诉你，直到你猜对了，就会恭喜你，结束游戏，提供再来一次的功能。
//【1】如何生成随机数？
//C提供了一个函数叫rand，用于生成随机数，原型如下：
//int rand(void)
//rand会返回一个【伪随机数】，这个数的范围是0到RANF_MAX,这个最大值由编译器决定，但大部分是32767
//【头文件】stdlib.h
//int main()
//{
//	int r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	return 0;
//}
//多次运行后你会发现，每一次生成的随机数都是一样的，若要深究，rand函数其实是对一个叫“种子”的基准值（默认是1）进行运算来得到随机数，若要生成不同随机数，种子就得变化。
//【2】于是C语言又提供了一个函数叫srand，用来初始化随机数生成器，原型如下：
//void srand(unsigned int seed);
//int main()
//{
//	srand(1);
//	int r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	return 0;
//}
//
//但这时候你会发现你需要种子随时变化，所以我们就把程序运行的时间作为种子，因为时间时刻不停；
//【3】于是，C提供了函数time，可以获得一个时间戳，time会返回当前的日历时间，其实返回的是1970年1月1日0时0分0秒到现在程序运行到这个点的时间差（就是时间戳），单位是秒。
//【返回类型】time_t，本质上是32或64位的整型类型。【头文件】time.h
//【原型】time_t time (time_t* timer)//类型后面加*表示指针类型，不用的话就填NULL空指针
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	r = rand();
//	printf("%d\n", r);
//	return 0;
//}
//【4】设置随机数范围
//【方法】给rand%100就可以产生0到99，加1就是1-100//即：要产生a-b的数，就是a+rand（）%（a-b+1）
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int r = rand()%100+1;
//	printf("%d\n", r);
//	r = rand()%100+1;
//	printf("%d\n", r);
//	r = rand()%100+1;
//	printf("%d\n", r);
//	r = rand()%100+1;
//	printf("%d\n", r);
//	r = rand()%100+1;
//	printf("%d\n", r);
//	r = rand()%100+1;
//	printf("%d\n", r);
//	return 0;
//}
//【5】猜数字游戏的实现   【注意】srand只需要调用一次，不能频繁调用,所以放在主函数里面。
//void menu()
//{
//	printf("*************************\n");
//	printf("*****   1.play   ********\n");
//	printf("*****   0.exit   ********\n");
//	printf("*************************\n");
//}
//void game()//无限版本
//{
//	//1.生成随机数
//	int r = rand() % 100 + 1;
//	//2.猜数字
//	int guess = 0;
//	while (1)
//	{
//		printf("请猜数字：\n");
//		scanf("%d", &guess);
//		if (guess < r)
//		{
//			printf("小了\n");
//		}
//		if (guess > r)
//		{
//			printf("大了\n");
//		}
//		if (guess == r)
//		{
//			printf("恭喜你，中了，随机数是%d\n", r);
//			break;
//		}
//	}
//
//}
//void gamepro()//有限制
//{
//	int guess = 0;
//	//生成随机数
//	int r = rand() % 100 + 1;
//	//开始猜测,设置限制
//	int count = 5;
//	while (count)
//	{
//		printf("请输入一个一到一百的数字，你还有%d次机会：\n", count);
//		scanf("%d", &guess);
//		if (guess < r)
//		{
//			printf("小了\n");
//			count--;
//		}
//		if (guess > r)
//		{
//			printf("大了\n");
//			count--;
//		}
//		if (guess == r)
//		{
//			printf("恭喜你，中了，随机数是%d\n", r);
//			break;
//		}
//		
//		
//	}
//	if (count == 0)
//	{
//		printf("你的机会已经用完，游戏失败！正确答案是%d\n",r);
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		//打印简易菜单
//		menu();//调用函数
//		printf("请选择:>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("猜数字开始\n");
//			gamepro();//玩游戏的过程
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n");
//			break;
//
//		}
//	} while (input);
//	return 0;
//}
