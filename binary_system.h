#pragma once


//1.统计一个数二进制中1的个数
int CountOneNumber(int num)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		if ((num & 1) == 1)
			count++;
		num >>= 1;
	}
	return count;
}
//最优解
int CountOneNum(int num)
{
	int count = 0;
	while (num)
	{
		count++;
		num = num&(num - 1);
	}
	return count;
}
//2.那么你知道两个int(32位)整数m和n的二进制表达式中，有多少个位不同
int CountBitDiff(int m,int n)
{
	int count = 0;
	int num = m^n;
	while (num)
	{
		count++;
		num = num&(num - 1);
	}
	return count;
}
//3.判断一个数是不是2的n次方
bool IsPower(int num)
{
	int count = CountOneNum(num);
	if (count == 1)
		return true;
	else
		return false;
}
//4.写一个宏定义，实现的功能是将一个int型的数的奇偶位互换，例如6的二进制为0110，第一位与第二位
//互换，第三位与第四位互换，得到1001
#define Swap(N) (((N>>1)&0x55555555)|((N<<1)&0xaaaaaaaa))
int ExchangeBit(int num)
{
	return Swap(num);
}
//5.将一个数的二进制序列逆序，然后输出逆序之后的二进制序所对应的数
int Reverse(int num)
{
	int count = 0;
	for (int i = 0; i < 32;++i)
	{
		count <<= 1;
		count |= ((num >> i)&1);
	}
	return count;
}
//6.编写一个函数，这个函数可以将一个整数的指定位置1或置0
int ChangeBit(int num,int pos,int flag)
{
	if (flag == 1)
		num |= (1 << (pos - 1));
	else
		num &= ~(1 << (pos - 1));
	return num;
}
//7.给一组数，有一个数只出现一次，其他所有数都是成对出现的，怎么找出这个数
int FindOne(int num[],int size)
{
	int count = num[0];
	for (int i = 1; i < size;++i)
	{
		count ^= num[i];
	}
	return count;
}
//8.给一组数，有一个数只出现一次，其他所有数都是成对出现的，怎么找出这个数
void FindTwo(int num[],int size,int* first,int* second)
{
	int count = FindOne(num,size);
	int tmp = count;
	int pos = 0;
	for (int i = 0; i < size;++i)
	{
		if (((count >> i) & 1) == 1)
			break;
		else
			pos++;
	}
	for (int i = 0; i < size; ++i)
	{
		if (((num[i] >> pos) & 1) == 1)
			count ^= num[i];
	}
	*first = count;
	count = tmp;
	*second = (*first)^count;
}
void Test()
{
	//1、
	//int num = -1;
	//int count = CountOneNum(num);
	//int count = CountOneNumber(num);
	//printf("The number is:%d\n", count);

	//2、
	//int m = 1999, n = 2299;
	//int count = CountBitDiff(m,n);
	//printf("The number is:%d\n", count);

    //3、
	//int num = 255;
	//bool ispower = IsPower(num);
	//printf("The number is:%d\n", ispower);

	//4、
	//int num = 10;
	//int count = ExchangeBit(num);
	//printf("The number is:%d\n", count);

	//5、
	//int num = 8;
	//int count = Reverse(num);
	//printf("The number is:%d\n", count);

	//6、
	//int num = 15;
	//int count = ChangeBit(num,4,0);
	//printf("The number is:%d\n", count);

	//7、
	//int array[] = {1,2,4,5,2,1,5};
	//int count = FindOne(array,sizeof(array)/sizeof(array[0]));
	//printf("The number is:%d\n", count);

	//8、
	int array[] = {1,2,5,7,3,8,2,5,7,3};
	int ret1,ret2;
	FindTwo(array,sizeof(array)/sizeof(array[0]),&ret1,&ret2);
	printf("ret1 = %d,ret2 = %d\n",ret1,ret2);
}