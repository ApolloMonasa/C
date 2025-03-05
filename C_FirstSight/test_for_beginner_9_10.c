//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>


///第17讲 C语言内存函数
/// 【1.0】memcpy的使用和模拟实现
/// void * memcpy ( void * destination, const void * source, size_t num ); 
/// num是要复制的字节数
/// 【头文件】string.h
/// 复制内存块（跟\0无关）,返回目标起始地址
///将 num bytes 的值从 source 指向的位置直接复制到 destination 指向的内存块。
///源指针和目标指针指向的对象的基础类型与此函数无关; 结果是数据的二进制副本。
///该函数不会检查 source 中是否有任何终止 null 字符 - 它始终精确复制 num 个字节。
///为避免溢出，destination 和 source 参数指向的数组的大小应至少为 num 字节，并且不应重叠（对于重叠的内存块，memmove 是一种更安全的方法）。
/// 
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = { 0 };
//	strcpy(arr2, arr1);
//
//	int arr3[] = { 1,2,3,4 };
//	int arr4[5] = { 0 };
//	memcpy(arr4, arr3+2, 2*sizeof(int));
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d ", arr4[i]);
//	}
//	return 0;
//
//}
///【1.1】模拟实现

//void* my_memcpy(void* desti, const void* source,size_t num)
//{
//	void* ret = desti;
//	assert(source && desti);
//	int i = 0;
//	while (num--)
//	{
//		*(char*)desti = *(char*)source;
//		desti = (char*)desti + 1;
//		source = (char*)source + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = { 0 };
//	strcpy(arr2, arr1);
//
//	int arr3[] = { 1,2,3,4 };
//	int arr4[5] = { 0 };
//	my_memcpy(arr4, arr3, 4*sizeof(int));
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d ", arr4[i]);
//	}
//	return 0;
//
//}

///【注意】这个函数只处理不重叠的情况(但是你会发现VS实现了重叠拷贝，实际上标准没有要求，但是VS做到了，但你不能指望所有编译器都这样)，重叠情况交给下一个函数
/// 【2.0】memmove的使用和模拟实现
/// void * memmove ( void * destination, const void * source, size_t num );
/// 移动内存块
///将 num 字节的值从 source 指向的位置复制到 destination 指向的内存块。复制就像使用中间缓冲区一样进行，从而允许目标和源重叠。
///源指针和目标指针指向的对象的基础类型与此函数无关; 结果是数据的二进制副本。
///该函数不会检查 source 中是否有任何终止 null 字符 - 它始终精确复制 num 个字节。
///为避免溢出，destination 和 source 参数指向的数组的大小应至少为 num 字节。
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr1 + 2, arr1, 5 * sizeof(int));
//	return 0;
//}

///【2.1】模拟实现

//void* my_memmove(void* desti, const void* source, size_t num)
//{
//	if (desti <source)
//	{
//		//从前向后
//		while (num--)
//		{
//			*(char*)desti = *(char*)source;
//			desti = (char*)desti + 1;
//			source = (char*)source + 1;
//		}
//		return desti;
//	}
//	else if (desti == source)
//		return desti;
//	else
//	{
//		//从后向前
//		while (num--)
//		{
//			*((char*)desti + num) = *((char*)source + num);
//		}
//		return desti;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr, arr+2, 5 * sizeof(int));
//	return 0;
//}

/// 【3.0】memset函数的使用
/// void * memset ( void * ptr, int value, size_t num );
/// 填充内存块
///将 ptr 指向的内存块的前字节数设置为指定值（解释为 unsigned char）。
/// 
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		i[arr] = i + 1;
//	}
//	//把内容置为0
//	memset(arr, 0, 10*sizeof(int));
//	///【注意】第二个参数是把每个字节设置的值，不是每个元素
//
//	return 0;
//}
/// 【4.0】memcmp函数的使用
///int memcmp ( const void * ptr1, const void * ptr2, size_t num );
/// 比较两个内存块
///将 ptr1 指向的内存块的前 num 个字节与 ptr2 指向的第一个 num 字节进行比较，如果它们都匹配，则返回零，或者返回一个不等于 0 的值，如果不匹配，则返回更大。
///请注意，与 strcmp 不同，该函数在找到 null 字符后不会停止比较。
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 1,2,3,3 };
//	///01 00 00 00 02 00 00 00 03 00 00 00<04>00 00 00
//	///01 00 00 00 02 00 00 00 03 00 00 00<03>00 00 00
//	/// 是倒着放的
//	int ret = memcmp(arr1, arr2,13);
//	printf("%d", ret);
//	return 0;
//}
