#pragma once
#if 0
//1.ʵ�ֵ���ģʽ
//�������̰߳�ȫ
class Singleton
{
public:
	static void Instance()
	{
		if (_instance == NULL)
		{
			_instance = new Singleton();
		}
	}
	static void Delete()
	{
		if (_instance)
		{
			delete _instance;
			_instance = NULL;
		}
	}
	void Print()
	{
		cout << _data << endl;
	}
private:
	Singleton()
		:_data(0)
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	
	static Singleton* _instance;

	int _data;
};

//2.��һ����ά�����У�ÿһ�д����ҵ�����ÿһ�д��ϵ��µ����������һ�����Һ���
bool Find(int* array, int rows, int cols, int number)
{
	bool found = false;
	if (array && rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (array[row*cols + col] == number)
			{
				found = true;
				break;
			}
			else if (array[row*cols + col] > number)
			{
				col--;
			}
			else
			{
				row++;
			}
		}
	}
	return found;
}

//3.ʵ��һ�����������ո��滻��%20
void ReplaceBlank(char* str,int len)
{
	if (str == NULL && len < 0)
		return;
	int blanknum = 0;
	int newlen = 0;
	int originlen = 0;
	//ͳ�ƿո�ĸ���
	while(str[originlen] != '\0')
	{
		if (str[originlen] == ' ')
			blanknum++;
		originlen++;
	}
	//�������ַ����ĳ���
	newlen = originlen + blanknum * 2;
	if (newlen > len)
		return;
	//�滻�ո�
	while (newlen>0 && newlen>originlen)
	{
		if(str[originlen] == ' ')
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else
		{
			str[newlen--] = str[originlen];
		}
		originlen--;
	}
}

//4.쳲���������
long long Fibonacci(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];

	long long fibnumone = 0;
	long long fibnumtwo = 1;
	long long fib = 0;
	for (int i = 2; i <= n;i++)
	{
		fib = fibnumone + fibnumtwo;
		fibnumone = fibnumtwo;
		fibnumtwo = fib;
	}
	return fib;
}
#endif
//

void InterviewTest()
{
#if 0
	//2.
	int array[3][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	cout << Find(*array, 3, 5, 9) << endl;

	//3.
	char str[25] = "we are coming!";
	ReplaceBlank(str,20);

	cout << Fibonacci(3) << endl;
#endif
}