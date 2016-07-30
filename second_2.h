#pragma once

//���ڽ׳˵�����
//ĳ�����Ľ׳˽��ĩβ�м���0
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

//��ĳ�����׳˽�������Ʊ�ʾ�����λ1��λ��
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