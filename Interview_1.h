#pragma once
#include<stack>
#include<assert.h>

#if 0
//1.实现单例模式
//不考虑线程安全
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

//2.在一个二维数组中，每一行从左到右递增，每一列从上到下递增，请完成一个查找函数
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

//3.实现一个函数，将空格替换成%20
void ReplaceBlank(char* str,int len)
{
	if (str == NULL && len < 0)
		return;
	int blanknum = 0;
	int newlen = 0;
	int originlen = 0;
	//统计空格的个数
	while(str[originlen] != '\0')
	{
		if (str[originlen] == ' ')
			blanknum++;
		originlen++;
	}
	//计算新字符串的长度
	newlen = originlen + blanknum * 2;
	if (newlen <= len)
		return;
	//替换空格
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

//4.斐波那契数列
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

//5.找出旋转数组中的最小数
int InOrderMin(int* array,int begin,int end)
{
	int result = array[begin];
	for (int i = begin; i <= end; i++)
	{
		if (result > array[i])
			result = array[i];
	}
	return result;
}
int FindMin(int* array,int len)
{
	if (array == NULL || len <= 0)
		return -1;

	int begin = 0;
	int end = len - 1;
	int mid = 0;
	while (array[begin] >= array[end])
	{
		if (end - begin == 1)
		{
			mid = end;
			break;
		}

		mid = begin + (end - begin) / 2;
		//如果下标为begin，end，mid的三个数字相等，用顺序查找
		if (array[begin] == array[mid] && array[mid] == array[end])
			return InOrderMin(array,begin,end);

		if (array[mid] >= array[begin])
			begin = mid;
		else if (array[mid] <= array[end])
			end = mid;
	}
	return array[mid];
}

//6.数值的整数次方
double PowerExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerExponent(base, exponent>>1);
	result *= result;
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}
bool equel(double num1,double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}
double Power(double base,int exponent)
{
	if (equel(base, 0.0) && exponent < 0)
		return 0.0;

	unsigned int absexponent = (unsigned int)exponent;
	if(exponent < 0)
		absexponent = (unsigned int)(-exponent);

	double result = PowerExponent(base, absexponent);
	if(exponent < 0)
		result = 1.0/result;

	return result;
}

//7.打印1到最大的n位数
bool IsCrement(char* number)
{
	bool iscrement = false;
	int len = strlen(number);

	for (int i = len - 1; i >= 0; --i)
	{
		int snum = number[i] - '0' + 1;

		if (snum >= 10)
		{
			if (i == 0)
				iscrement = true;
			else
			{
				snum -= 10;
				number[i] = snum + '0';
			}
		}
		else
		{
			number[i] = snum + '0';
			break;
		}
	}
	return iscrement;
}

void PrintNumber(const char* number)
{
	int len = strlen(number);
	bool isbegin0 = true;

	for (int i = 0; i < len;++i)
	{
		if (isbegin0 && number[i] != '0')
			isbegin0 = false;
		if (!isbegin0)
		{
			printf("%c",number[i]);
		}
	}
	printf("\n");
}

void PrintOneToMax(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number,'0',n);
	number[n] = '\0';

	while (!IsCrement(number))
	{
		PrintNumber(number);
	}

}

//8.调整数组顺序使奇数位于偶数前面
void ReOrderArray(int* array, int len)
{
	int* begin = array;
	int* end = array + len - 1;

	while (begin < end)
	{
		while (begin < end && (*begin & 0x1) != 0)
			begin++;
		while (begin < end && (*end & 0x1) == 0)
			end--;
		if (begin < end)
		{
			int tmp = *begin;
			*begin = *end;
			*end = tmp;
		}
	}
}

//9.顺时针打印矩阵
void PrintMatrixOnlyOneCircle(int* array, int cols, int rows, int start)
{
	int endx = cols - 1 - start;
	int endy = rows - 1 - start;

	//从左到右打印
	for (int i = start; i <= endx;++i)
	{
		printf("%d ",array[start*cols+i]);
	}
	//从上到下打印
	if (start < endy)
	{
		for (int i = start + 1; i <= endy; ++i)
		{
			printf("%d ", array[(i+1)*cols-1-start]);
		}
	}
	//从右向左打印
	if (start < endx && start < endy)
	{
		for (int i = endx - 1; i >= start; --i)
		{
			printf("%d ",array[endy*cols+i]);
		}
	}
	//从下向上打印
	if (start < endx && start < endy-1)
	{
		for (int i = endy - 1; i > start; --i)
		{
			printf("%d ",array[i*cols+start]);
		}
	}
}
void PrintMatrix(int* array,int cols,int rows)
{
	if (array == NULL || cols <= 0 || rows <= 0)
		return;
	int start = 0;
	while(cols > start*2 && rows > start*2)
	{
		PrintMatrixOnlyOneCircle(array, cols, rows, start);
		start++;
	}
}

//10.包含min函数的栈
template<class T>
class StackWithMin
{
public:
	void Push(const T data)
	{
		m_data.push(data);

		if (m_min.size() == 0 || data < m_data.pop())
			m_min.push(data);
		else
			m_min.push(m_data.top());
	}
	void Pop()
	{
		assert(m_data.size() > 0 && m_min.size() > 0);

		m_data.pop();
		m_min.pop();
	}
	T& Min()
	{
		assert(m_min.size() > 0);

		return m_min.top();
	}
private:
	stack<T> m_data;
	stack<T> m_min;
};

//11.栈的压入、弹出序列
bool IsPopOrder(int* push,int* pop,int len)
{
	bool ispoporder = false;
	if (push && pop && len >= 0)
	{
		int* popnext = pop;
		int* pushnext = push;

		stack<int> stack;
		while (popnext - pop < len)
		{
			while (stack.empty() || stack.top() != *popnext)
			{
				if (pushnext - pop == len)
					break;

				stack.push(*pushnext);
				pushnext++;
			}

			if (stack.top() != *popnext)
				break;

			stack.pop();
			popnext++;
		}

		if (stack.empty() && popnext - pop == len)
			ispoporder = true;
	}
	return ispoporder;
}
#endif


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

	//5.
	int array[5] = {1,0,1,1,1};
	cout << FindMin(array, 5) << endl;

	//6.
	cout << Power(2,4) << endl;

	//7.
	PrintOneToMax(2);

	//8.
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	ReOrderArray(array,10);

	//9.
	int array[4][4] = { 
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	PrintMatrix(*array,4,4);
#endif


}