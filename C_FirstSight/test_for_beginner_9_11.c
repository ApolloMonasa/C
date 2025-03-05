//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include <math.h>

///第18讲 数据在内存中的存储
///【1.0】整数在内存中的存储
/// 整数的二进制表示方法有三种：原码，反码和补码
/// 正整数的三种码相同
/// 负整数的三种码各不相同
/// 原码：直接将数值按照正负数的形式翻译成二进制得到的就是原码
/// 反码：将原码除符号位以外的数值取反即可
/// 补码：反码加1
/// 对整型来说：数据存放内存中其实存放的是二进制的补码
/// 而且是倒着存放的
//int main()
//{
//	int a = 0x11223344;
//
//	return 0;
//}

/// 为什么呢？这就涉及到大小端的问题了
/// 【2.0】大小端字节序和字节序判断
/// 【2.1】什么是大小端
/// 小端字节序存储：一个数据的低位字节的数据存放在内存的低地址处
/// 大端字节序存储：一个数据的低位字节的数据存放在内存的高地址处
/// 【2.2】为什么会有大小端？
/// 这是因为在计算机系统中，我们是以字节为单位的，每个地址单元都对应着一个字节，一个字节为8bit位，但是在C语言中除了8bit的char外，还有16bit的short型，32bit的long型（要看具体的编译器）
/// 另外，对于位数大于八位的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字节，那么必然存在着一个如何将多个字节安排的问题，因此就产生了大端存储模式和小端存储模式
/// 【百度面试】
/// 请简述大端字节序和小端字节序的概念，设计一个小程序来判断当前机器的字节序
////【解法1】
//int main()
//{
//	int a = 1;
//	//0x: 00 00 00 01
//	//大端：00 00 00 01
//	//小端：01 00 00 00
//	//那我只需要拿第一个字节对比一下即好
//	//&a//得到的是a的四个字节中地址较小的地址
//	if ((*(char*)&a) == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}
////【解法2】
//int check_sys()
//{
//	return (*(char*)&a);
//}

//【面试题：截断原则是保留低位数据】
//int main()
//{
//	char a = -1;
//	//-1
//	//原码：10000000 00000000 00000000 00000001
//	//反码：11111111 11111111 11111111 11111110
//	//补码：11111111 11111111 11111111 11111111
//	//现在往8bit里面塞，发生截断，保留低位数据
//	//截断后：11111111
//	// （有符号）整型提升：11111111 11111111 11111111 11111111就是原来-1的补码
//	// （无符号）整型提升：00000000 00000000 00000000 11111111
//	//那不是255嘛？
//	signed char b = -1;
//	unsigned char c = -1;
//
//	//char--signed char取值：-128~127
//	//unsigned char 取值：0-255
//	//char到底是signed还是unsigned是由编译器决定的
//	//但是在VS上,char==signed char
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	//打印发生整型提升
//
//	return 0;
//}

///在这里我不禁感叹类型的作用：第一：申请内存的权限；第二，看待内存中数据的方式（整型提升）

//【面试题：】
//int main()
//{
//	char a = -128;
//	//原码：10000000 00000000 00000000 10000000
//	//补码：11111111 11111111 11111111 10000000
//	//截断：10000000
//	//整型提升：11111111 11111111 11111111 10000000
//	//无符号数的原码和补码相同
//	//那不就是：4294967168
//	printf("%u\n", a);
//	return 0;
//}

//【面试】

//int main()
//{
//	char a = 128;
//	//原码：00000000 00000000 00000000 10000000
//	//补码：01111111 11111111 11111111 10000000
//	//截断：10000000
//	//整型提升：11111111 11111111 11111111 10000000--补码==原码
//
//	printf("%u\n", a);
//	return 0;
//}

//【面试：溢出的理解 】

//int main()
//{
//	char a[1000];
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		i[a] = -1 - i;
//	}
//	printf("%zd", strlen(a));
//	//strlen是求字符串长度的，那就要关注\0；即0
//	//从00000000到10000000（-128）再到11111111
//	//就是0，1，2，3......127，-128，-127......-2，-1
//	//最终结果就是127+128=255
//
//	return 0;
//}

//【面试】

//unsigned char i = 0;
////最大值：2^8-1=255,会死循环
//
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//	}
//	return 0;
//}

//【面试】

//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)//死循环毫无悬念
//	{
//		printf("%u\n", i);
//		Sleep(100);
//	}
//	return 0;
//}

//【面试】
//x86环境，小端字节序
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%#x,%#x", ptr1[-1], *ptr2);
//	return 0;
//}
/// 【3.0】浮点数在内存中的存储
///犹记：浮点数在内存中无法精确保存！
/// 浮点数范围在float.h中定义
/// 浮点数包括：float ,double ,long double ,[num]e(E)int
/// 
/// 【例题引入】
//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);//是9没问题
//	///这就不合我们的想法了
//	///说明整型在内存中的存储方式和浮点数在内存中的存储方式是不一样的
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	*pFloat = 9.0;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	return 0;
//}
///在上述内容中，n和*pFloat里面存的明明是同一个数字，可是浮点数和整型解读差别会那么大呢？
///根据国际标准IEEE（电气和电子工程协会）754，任意一个二进制浮点数V可以表示成下面的形式：
/// V=[(-1)^S]*M*(2^E)
/// (-1)^S表示符号位，当S=0，V为正数；当S等于1，V为负数
/// M是有效数字，M是大于等于1小于2的
/// 2^E表示指数位
/// 【例子】5.5的二进制写法
/// 101.1，用科学计数法表示：1.011*（2^2）
/// 写成标准：[（-1）^0]*1.011*（2^2）
/// 
/// 那么当我们以这样的标准来存储浮点数时，只需要存储上述:S E M
/// IEEE754规定：
/// 对32位浮点数：采用1+8+23
/// 对64位浮点数：采用1+11+52
/// 【3.2.1】浮点数存储的过程
/// IEEE 754对有效数字M和指数E还有一些特别的规定。
/// 前面说过1<M<2,也就是说，M一定可以表示成1.xxxxx....的形式
/// IEEE 754规定，在计算机存储M时，默认这个数字第一位是1，因此可以被舍弃，只保存后面的xxxxx部分
/// 这样做的目的，是节省一位有效数字，以32位浮点数为例，实际上可以保存24位有效数字
/// 
/// 至于E就比较复杂
/// 首先，E为一个无符号整数(unsigned int)
/// 这就意味着，如果E为8位，它的取值范围就是0-255；如果E为11位，范围是0-2047.但是我们知道E是可能为负数的
/// 所以，就规定：存入内存时E的真实值必须加上一个中间数，对应8位的E，这个中间数是127；对应11位的E这个中间数是1023.
/// [举例]比如2^10的E是10，保存为32位浮点数时必须保存成10+127=137，即 10001001.
/// 
/// 那么我们来分析5.5的存储（32位）
/// 101.1
/// 1.011*2^2
/// S=0
/// E=2
/// M=1.011（只存小数，不足后面补0）
/// 0 10000001 01100000000000000000000
/// 01000000 10110000 00000000 00000000
//0x40 b0 00 00
//int main()
//{
//	float f = 5.5;
//	return 0;
//}
/// 【3.2.2】浮点数的读取
/// 指数E从内存中取出还可以再分为3种情况
/// [E不全为0或不全为1（常规情况）]
/// 这时，浮点数就采用下面规则表示：
/// 即指数E计算值减去中间值127/1023得到真实值，再将有效数字M前面的1加上，逆推就行
/// [E全0]
/// 这时候有效数字M的整数部分的1就不要了，这样子是为了表示+-0，以及接近于0很小的数字
/// [E全1]
/// 这时如果有效数字M全为0，表示+-无穷大
/// 
/// 【3.3】题目解析
//[1]
//int main()
//{
//	int n = 9;
//	///这里怎么存
//	//00000000 00000000 00000000 00001001（原码/补码）
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);//是9没问题
//	///这就不合我们的想法了
//	///说明整型在内存中的存储方式和浮点数在内存中的读取-方式是不一样的
//	/// 这里怎么读
//	//0 00000000 00000000000000000001001
//	//E为全0，那M只要小数部分，是个很小的数，无限接近0，更别说只打印6位
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	*pFloat = 9.0;
//	///怎么存？
//	//1001.0==1.001*2^3
//	//S=0 E=3 M=1.001
//	//0 10000010 00100000000000000000000
//	printf("n的值为：%d\n", n);
//	///怎么读？
//	//01000001000100000000000000000000（正数补码==原码）拿计算器算出来就是这样
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}


///【补充】浮点数相等判断
//int main()
//{
//	if (0.1 + 0.2 == 0.3)
//		printf("==\n");
//	else
//		printf("!=\n");
//	return 0;
//}
///所以我们在比较他们时应该使用限定精度来比较
//int main()
//{
//	if (fabs(0.3 - 0.1 - 0.2) < 0.0000000001)
//		printf("==\n");
//	else
//		printf("!=\n");
//	return 0;
//}


///【补充】浮点数的加减法和截断现象
//#include <stdio.h>
//
//int main(void) {
//    float a, b;
//    a = 123456.789e5;
//    //12345678900对应的二进制序列是：
//    //（34位）1 01101111111011100000111 0000110100
//    //M=1.011011111110111000001110000110100
//    //E=33
//    //截断后
//    //12345678900在内存中对应的二进制序列是：
//    //（23位）1 011 0111 1111 0111 0000 0111（0000110100）
//    //对应二进制数字是：
//    //1 01101111111011100000111 0000000000
//
//    b = a + 20;
//    //浮点数的加减法运算遵循以下规则：
//    //1.解析浮点数：符号位（S），指数（E），尾数（M）
//    //2.对阶：将两个浮点数的尾数部分对齐，即指数部分相同，尾数部分左对齐
//    //3.尾数相加：将两个浮点数的尾数部分相加，得到新的尾数部分
//    printf("\na=%f\n", a);
//    printf("\nb=%f\n", b);
//    return 0;
//}
