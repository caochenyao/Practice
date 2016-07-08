#pragma once


//1.ͳ��һ������������1�ĸ���
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
//���Ž�
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
//2.��ô��֪������int(32λ)����m��n�Ķ����Ʊ��ʽ�У��ж��ٸ�λ��ͬ
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
//3.�ж�һ�����ǲ���2��n�η�
bool IsPower(int num)
{
	int count = CountOneNum(num);
	if (count == 1)
		return true;
	else
		return false;
}
//4.дһ���궨�壬ʵ�ֵĹ����ǽ�һ��int�͵�������żλ����������6�Ķ�����Ϊ0110����һλ��ڶ�λ
//����������λ�����λ�������õ�1001
#define Swap(N) (((N>>1)&0x55555555)|((N<<1)&0xaaaaaaaa))
int ExchangeBit(int num)
{
	return Swap(num);
}
//5.��һ�����Ķ�������������Ȼ���������֮��Ķ�����������Ӧ����
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
//6.��дһ������������������Խ�һ��������ָ��λ��1����0
int ChangeBit(int num,int pos,int flag)
{
	if (flag == 1)
		num |= (1 << (pos - 1));
	else
		num &= ~(1 << (pos - 1));
	return num;
}
//7.��һ��������һ����ֻ����һ�Σ��������������ǳɶԳ��ֵģ���ô�ҳ������
int FindOne(int num[],int size)
{
	int count = num[0];
	for (int i = 1; i < size;++i)
	{
		count ^= num[i];
	}
	return count;
}
//8.��һ��������һ����ֻ����һ�Σ��������������ǳɶԳ��ֵģ���ô�ҳ������
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
	//1��
	//int num = -1;
	//int count = CountOneNum(num);
	//int count = CountOneNumber(num);
	//printf("The number is:%d\n", count);

	//2��
	//int m = 1999, n = 2299;
	//int count = CountBitDiff(m,n);
	//printf("The number is:%d\n", count);

    //3��
	//int num = 255;
	//bool ispower = IsPower(num);
	//printf("The number is:%d\n", ispower);

	//4��
	//int num = 10;
	//int count = ExchangeBit(num);
	//printf("The number is:%d\n", count);

	//5��
	//int num = 8;
	//int count = Reverse(num);
	//printf("The number is:%d\n", count);

	//6��
	//int num = 15;
	//int count = ChangeBit(num,4,0);
	//printf("The number is:%d\n", count);

	//7��
	//int array[] = {1,2,4,5,2,1,5};
	//int count = FindOne(array,sizeof(array)/sizeof(array[0]));
	//printf("The number is:%d\n", count);

	//8��
	int array[] = {1,2,5,7,3,8,2,5,7,3};
	int ret1,ret2;
	FindTwo(array,sizeof(array)/sizeof(array[0]),&ret1,&ret2);
	printf("ret1 = %d,ret2 = %d\n",ret1,ret2);
}