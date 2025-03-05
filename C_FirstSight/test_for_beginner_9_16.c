//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <string.h>

///第22讲 动态内存分配
///【1.0】为什么要有动态内存分配
/// 我们已经掌握的内存开辟方式有：
/// 1.int val = 20;//在栈空间上开辟4字节
/// 2.char arr[10] = {0};//在栈空间上开辟十个字节的连续空间
/// 但是，上述方式有两个特点：
/// 1.空间开辟的大小是固定的
/// 2.数组在声明的时候，必须指定数组的长度，数组空间一旦确定大小就不能调整
/// 但有时我们需要的空间大小在程序运行的时候才能知道，于是C语言就引入了动态内存开辟，让程序员可以自己 申请和释放空间，就比较灵活了
/// 【2.0】malloc 和 free
/// [stdlib.h]
/// 【2.1】malloc
/// void* malloc (size_t size);
/// 分配内存块
///分配一个内存字节块，返回指向该块开头的指针。
///新分配的内存块的内容未初始化，仍为不确定的值。
///如果size为零，则返回值取决于特定的库（编译器）实现（它可能是也可能不是 null 指针），但不应取消引用返回的指针。
/// 开辟失败返回NULL，所以其返回值一定要检查
/// 
/// 【2.2】free
/// void free (void* ptr);
/// Deallocate memory block （释放内存块）
///以前通过调用 分配的内存块 ，或已解除分配，使其再次可用于进一步分配。
///如果不指向使用上述函数分配的内存块，则会导致未定义的行为。
///如果为 null 指针，则函数不执行任何操作。
///请注意，此函数不会更改其值，因此它仍然指向相同的（现在无效的）位置。

//int main()
//{
//	//int* p = (int*)malloc(10 * sizeof(int));
//	int* p = (int*)malloc(INT_MAX);///这是可能失败的情况，值得一提，x64能分配的空间很多，不容易失败，x86会失败的
//	
//	perror("malloc:");
//	assert(p != NULL);
//	for (int i = 0; i < 10; i++)
//	{
//		i[p] = i + 1;
//		printf("%d ", i[p]);
//	}
//	free(p);
//	p = NULL;
//
//
//	return 0;
//}

///【3.0】calloc 和 realloc
///【3.1】calloc
/// void* calloc (size_t num, size_t size);
/// 分配数组并对其进行零初始化
//为元素数组分配一个内存块，每个元素的长度为字节，并将其所有位初始化为零。
//有效的结果是分配一个初始化为零的字节内存块。
//如果为零，则返回值取决于特定的库实现（它可能是也可能不是 null 指针），但不应取消引用返回的指针。
///num是元素数，size是元素大小（字节）
///与malloc区别只在于会在返回地址前初始化0
//int main()
//{
//	//int* p = (int*)calloc(10, 4);
//	int* p = (int*)malloc(40);
//	///这个随机值取决于编译器，并且在堆区和栈区一般不同
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", i[p]);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
/// 【3.2】realloc
/// void* realloc (void* ptr, size_t size);
/// 重新分配内存块
//更改 指向的内存块的大小。
//该函数可以将内存块移动到新位置（其地址由函数返回）。
//内存块的内容将保留到新大小和旧大小中的较小者，即使该块被移动到新位置也是如此。如果 new 更大，则 new allocated 部分的值是不确定的。
//如果这是 null 指针，则该函数的行为类似于 ，分配一个新的字节块并返回一个指向其开头的指针。
/// ptr是要调整的内存地址
/// size是要调整成的新大小
/// 返回值是调整后的内存地址
/// 原来地址处空间够，原地开辟
/// 不够，迁移，释放原来空间 
/// 值得一提，还有一种情况，找不到新空间，函数给你返回个空指针，嘿嘿你要是把这个空指针赋值给原来那个指针，你就找不到原来那个空间了，最好还是有个中间变量
//int main()
//{
//	int* p = (int*)malloc(20);
//	perror("malloc:");
//	assert(p != NULL);
//	
//	for (int i = 0; i < 5; i++)
//	{
//		i[p] = i + 1;
//		printf("%d ", p[i]);
//	}
//	printf("\n");
//	///1 2 3 4 5
//	///扩大空间
//	int* pp = (int*)realloc(p, 40);
//	for (int i = 0; i < 10; i++)
//	{
//		i[pp] = i + 1;
//		printf("%d ", pp[i]);
//	}
//
//	return 0;
//}
/// 值得一提，当realloc函数第一个参数是NULL，那就等价于malloc
/// 
/// 【4.0】常见的动态内存的错误
/// 1.对空指针解引用
//int main()
//{
//	int* p = (int*)malloc(40);
//	//假设malloc开辟失败，返回空指针，对p解引用就会出问题
//	if (p == NULL)
//	{
//		perror("malloc:");
//		return 1;
//	}
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ",*(p+i));
//	}
//	return 0;
//}
/// 2.对动态开辟空间的越界访问
//int main()
//{
//	int* p = (int*)malloc(40);
//	//假设malloc开辟失败，返回空指针，对p解引用就会出问题
//	if (p == NULL)
//	{
//		perror("malloc:");
//		return 1;
//	}
//
//	int i = 0;
//	for (i = 0; i <= 40; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}

/// 3.对非动态开辟空间的free释放
//int main()
//{
//	int* p = (int*)malloc(40);
//	int a[10] = {0};//栈区的空间 
//	p = a;
//	free(p);
//
//	return 0;
//}
/// 4.使用free释放一块动态开辟空间的一部分
//int main()
//{
//	int* p = (int*)malloc(40);
//	free(++p);
//
//	return 0;
//}

///5.对同一块空间多次释放
/// 大多数时候发生这种错误是因为代码太长不小心忘记已经释放过了，解决方法是每次释放完就把指针置NULL
/// 
/// 6.动态内存空间忘记释放（内存泄露）

//void test()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//		return 1;
//}
//
//int main()
//{
//	test();
//	//函数结束，但malloc空间不会自动free，并且我p自动销毁，我找不到那份空间了，根本无法释放了
//	while (1)
//	return 0;
//}

/// 【5.0】动态内存分配经典面试题
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Getmemory_pro(char* p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");//
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
/// 程序崩溃，没有输出内容,GetMemory是传值，没有传地址，没有修改掉str,后续对空指针解引用，造成访问冲突
/// 而且还有个问题，这会造成内存泄露，后面使用完要释放哈
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

/// 是输出乱码或？
/// 原因是函数结束后数组空间直接退回了，原有数据就被覆盖了
///这类问题称为返回栈空间地址
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
/// 可以打印但内存泄露
/// 
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

/// 有非法访问，但是问题应该不明显（忘记置空了）
/// 
/// 
/// 【6.0】柔性数组
/// C99中，结构中的最后一个元素允许是未知大小的数组，就是柔性数组，前提是在结构体中。
/// 例如
//struct S
//{
//	int i;
//	int a[0];
//};
////或者
//struct R
//{
//	int j;
//	int arr[];
//};
///它不是独立使用的，而是结合动态内存管理来使用
/// 【6.1】柔性数组的特点
/// 1.结构中的柔性数组成员的前面必须至少有一个其他成员(因为第二条)
/// 2.sizeof返回的这种结构的大小不包括柔性数组的内存
/// 3.包含柔性数组的结构用malloc函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小
//struct S
//{
//	int n;
//	int arr[];//柔性数组
//};
//int main()
//{
//	//struct S s;//不会这样写
//	///会这样写
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	ps->n = 100;
//	for (int i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i + 1;
//	}
//	///柔性如何体现？ 
//	struct S* tmp = (struct S*)realloc(ps, sizeof(struct S) + 10 * sizeof(int));
//	if (tmp == NULL)
//	{
//		perror("realloc:");
//		return 1;
//	}
//	ps = tmp;
//	for (int i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i + 1;
//		printf("%d ", ps->arr[i]);
//	}
//	//printf("%zd\n", sizeof(struct S));
//	return 0;
//
//}
///改进： 
///无非就是在堆上开辟可变大小的空间
/// 
//struct S2
//{
//	int n;
//	int* arr;
//};
//int main()
//{
//	struct S2* ps = (struct S2*)malloc(sizeof(struct S2));
//	if (ps == NULL)
//	{
//		perror("malloc-1:");
//		return 1;
//	}
//	ps->n = 100;
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	if (ps->arr == NULL)
//	{
//		perror("malloc-2:");
//		return 1;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i + 1;
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//	int* ptr = (int*)realloc(ps->arr, 10 * sizeof(int));
//	if (ptr == NULL)
//	{
//		perror("realloc:");
//		return 1;
//	}
//	else
//	{
//		ps->arr = ptr;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i + 1;
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}

///https://coolshell.cn/articles/11377.html
/// 相关探讨
///我们可以看到这两种方案都可，但是方案一确实比方案二更优 ，更方便内存释放，用malloc更少，free也少，不易出错，还利于访问速度（连续内存更利于访问），可以减少内存碎块，减少不可利用的内存这就是柔性数组的优势所在。
///【7.0】总结C/C++中程序内存区域划分（自用）
/// file:///C:/Users/27847/Desktop/%E9%B9%8F%E5%93%A5C%E8%AF%AD%E8%A8%80%E8%AF%BE%E7%A8%8B%E4%B8%83%E6%9C%9F%E8%AF%BE%E4%BB%B6/%E7%AC%AC21%E8%AE%B2%EF%BC%9A%E5%8A%A8%E6%80%81%E5%86%85%E5%AD%98%E7%AE%A1%E7%90%86.pdf
/// 