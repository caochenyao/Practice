#pragma once

//关于阶乘的问题
//某个数的阶乘结果末尾有几个0
int ZeroCount(int n)
{
	int count = 0;
	while (n)
	{
		count += n / 5;
		n /= 5;
	}
	return count;
}

//求某个数阶乘结果二进制表示中最低位1的位置
int LowestOneLocation(int n)
{
	int count = 0;
	while (n)
	{
		n >>= 1;
		count += n;
	}
	return count;
}

void Test2_2()
{
	int n = 10;
	cout << ZeroCount(n) << endl;
	cout << LowestOneLocation(n) << endl;
}