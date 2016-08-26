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

//12.字符串排列?
void _Permutation(char* str, char* cur)
{
	if (*cur == '\0')
	{
		printf("%s", str);
	}
	else
	{
		for (char* ch = cur; ch != '\0';ch++)
		{
			char tmp = *ch;
			*ch = *cur;
			*cur = tmp;

			_Permutation(str, cur+1);

			tmp = *ch;
			*ch = *cur;
			*cur = tmp;
		}
	}
}
void Permutation(char* str)
{
	if (str == NULL)
		return;

	_Permutation(str, str);
}

//13.数组中出现次数超过一半的数字
int MoreThanHalf(int* number, int len)
{
	if (number == NULL)
		return 0;

	int result = number[0];
	int time = 1;
	for (int i = 1; i < len;++i)
	{
		if (number[i] == result)
			time++;
		else
			time--;
		if (time == 0)
		{
			result = number[i];
			time = 1;
		}
	}
	return result;
}

//14.最小的k个数
//15.连续子数组的最大和
int FindGreatestSubArray(int* number, int len)
{
	if (number == NULL || len <= 0)
		return 0;

	int nSum = 0;
	int nGreatestSum = nSum;
	for (int i = 0; i < len;++i)
	{
		if (nSum <= 0)
			nSum = number[i];
		else
			nSum += number[i];
		
		if (nSum > nGreatestSum)
			nGreatestSum = nSum;
	}

	return nGreatestSum;
}

//16.把数组排成最小的数
const int MaxNumber = 10;
char* StrCombine1 = new char[MaxNumber * 2 + 1];
char* StrCombine2 = new char[MaxNumber * 2 + 1];

int compare(const void* strnumber1, const void* strnumber2)
{
	strcpy(StrCombine1, *(char**)strnumber1);
	strcat(StrCombine1, *(char**)strnumber2);

	strcpy(StrCombine2, *(char**)strnumber2);
	strcat(StrCombine2, *(char**)strnumber1);

	return strcmp(StrCombine1, StrCombine2);
}
void PrintMinNumber(int* number, int len)
{
	if (number == NULL || len <= 0)
		return;

	char** StrNumber = (char**)new int[len];

	for (int i = 0; i < len; ++i)
	{
		StrNumber[i] = new char[MaxNumber+1];
		sprintf(StrNumber[i], "%d",number[i]);
	}

	qsort(StrNumber, len, sizeof(char*), compare);

	for (int i = 0; i < len; ++i)
		printf("%s", StrNumber[i]);
	printf("\n");

	for (int i = 0; i < len; ++i)
		delete[] StrNumber[i];
	delete[] StrNumber;
}

//17.丑数
int MinNumber(int num1, int num2, int num3)
{
	int min = num1 < num2 ? num1 : num2;
	min = min < num3 ? min : num3;
	return min;
}
int GetUglyNumber(int number)
{
	if (number <= 0)
		return 0;
	int *UglyNumber = new int[number];
	UglyNumber[0] = 1;
	int index = 1;

	int* multip2 = UglyNumber;
	int* multip3 = UglyNumber;
	int* multip5 = UglyNumber;

	while (index < number)
	{
		int min = MinNumber(*multip2*2, *multip3*3, *multip5*5);
		UglyNumber[index] = min;

		while (*multip2 * 2 <= UglyNumber[index])
			multip2++;
		while (*multip3 * 3 <= UglyNumber[index])
			multip3++;
		while (*multip5 * 5 <= UglyNumber[index])
			multip5++;

		index++;
	}

	int result = UglyNumber[index-1];
	delete[] UglyNumber;
	return result;
}

//18.第一个只出现一次的字符
char FindTheFirstOnceChar(char* str)
{
	if (str == NULL)
		return '\0';

	const int size = 256;
	unsigned int Hashtable[size];
	for (unsigned int i = 0; i < size; ++i)
		Hashtable[i] = 0;

	char* hashkey = str;
	while (*hashkey != '\0')
	{
		Hashtable[*hashkey++]++;
	}

	hashkey = str;
	while (*hashkey != '\0')
	{
		if (Hashtable[*hashkey] == 1)
			return *hashkey;
		hashkey++;
	}

	return '\0';
}

//19.数组中的逆序对
int InversePairCore(int* number, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = number[start];
		return 0;
	}

	int mid = start + (end-start)/2;

	int left = InversePairCore(number, copy, start, mid);
	int right = InversePairCore(number, copy, mid+1, end);

	int i = mid;
	int j = end;
	int index = end;
	int count = 0;
	while (i >= start && j >= mid + 1)
	{
		if (number[i] > number[j])
		{
			copy[index--] = number[i--];
			count += j - mid;
		}
		else
		{
			copy[index--] = number[j--];
		}
	}

	for (; i >= start; i--)
		copy[index--] = number[i];
	for (; j >= mid; j--)
		copy[index--] = number[j];

	return count + left + right;
}
int InversePairs(int* number, int len)
{
	if (number == NULL || len <= 0)
		return 0;

	int* copy = new int[len];
	for (int i = 0; i < len; ++i)
		copy[i] = number[i];

	int count = InversePairCore(number, copy, 0, len-1);
	delete[] copy;

	return count;
}

int GetFirstK(int* number, int k, int start, int end)
{
	if (start > end)
		return -1;

	int mid = start + (end-start)/2;
	if (number[mid] == k)
	{
		if ((mid > 0 && number[mid - 1] != k) || mid == 0)
			return mid;
		else
			end = mid - 1;
	}
	else if (number[mid] > k)
		end = mid - 1;
	else
		start = mid + 1;

	return GetFirstK(number, k, start, end);
}
int GetLastK(int* number, int k, int start, int end)
{
	if (start > end)
		return -1;

	int mid = start + (end - start) / 2;
	if (number[mid] == k)
	{
		if ((mid > 0 && number[mid + 1] != k) || mid == 0)
			return mid;
		else
			start = mid + 1;
	}
	else if (number[mid] > k)
		end = mid - 1;
	else
		start = mid + 1;

	return GetLastK(number, k, start, end);
}
int NumberTime(int* number, int len, int k)
{
	int count = 0;

	if (number && len > 0)
	{
		int first = GetFirstK(number, k, 0, len-1);
		int last = GetLastK(number, k, 0, len-1);

		if (first > -1 && last > -1)
			count = last - first + 1;
	}

	return count;
}

//21.数组中只出现一次的数字
//22.和为s的两个数字
bool FindNumberWithSum(int* number, int len, int data, int* num1, int* num2)
{
	if (number == NULL || len <= 0 || num1 == NULL || num2 == NULL)
		return false;

	int begin = 0;
	int end = len - 1;

	while (begin < end)
	{
		int Sum = number[begin] + number[end];
		if (Sum == data)
		{
			*num1 = number[begin];
			*num2 = number[end];
			return true;
		}
		else if (Sum > data)
			end--;
		else
			begin++;
	}

	return false;
}
//和为s的正数序列
void PrintSequence(int smallnum, int bignum)
{
	for (int i = smallnum; i <= bignum; ++i)
		printf("%d ", i);
	printf("\n");
}
void FindAddEquelS(int sum)
{
	if (sum < 3)
		return;
	
	int smallnum = 1;
	int bignum = 2;
	int biggestsmall = (sum + 1) / 2;
	int count = smallnum + bignum;

	while (smallnum < biggestsmall)
	{
		if (count == sum)
			PrintSequence(smallnum, bignum);

		while (count > sum && smallnum < biggestsmall)
		{
			count -= smallnum;
			smallnum++;

			if (count == sum)
				PrintSequence(smallnum, bignum);
		}

		bignum++;
		count += bignum;
	}
}

//23.翻转单词顺序
void Reverse(char* begin, char* end)
{
	if (begin == NULL || end == NULL)
		return;

	while (begin < end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;

		begin++;
		end--;
	}
}
char* ReverseSentence(char* sentence)
{
	if (sentence == NULL)
		return NULL;

	char* begin = sentence;
	char* end = sentence;
	while (*end != '\0')
		end++;
	end--;

	Reverse(begin, end);

	begin = end = sentence;
	while(*begin != '\0')
	{
		if (*begin == ' ')
		{
			begin++;
			end++;
		}
		else if (*end == ' ' || *end == '\0')
		{
			Reverse(begin, --end);
			begin = end++;
		}
		else
		{
			end++;
		}
	}

	return sentence;
}

//字符串的左旋转操作
char* ReverseString(char* string, int n)
{
	if (string == NULL)
		return NULL;

	int len = static_cast<int>(strlen(string));
	if (len > 0 && n > 0 && n < len)
	{
		char* firstbegin = string;
		char* firstend = string + n - 1;
		char* secondbegin = string + n;
		char* secondend = string + len - 1;

		//翻转前n个字符
		Reverse(firstbegin, firstend);
		//翻转后面的字符
		Reverse(secondbegin, secondend);
		//整体进行翻转
		Reverse(firstbegin, secondend);
	}
	return string;
}
#endif
//24.


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

	//12.
	Permutation("abc");

	//13.
	int number[9] = {5,1,5,2,5,3,5,4,5};
	cout << MoreThanHalf(number, sizeof(number)/sizeof(int)) << endl;

	//15.
	int number[] = { 1, -2, 3, 4, -5, 6, 7, -8 };
	cout << FindGreatestSubArray(number, sizeof(number)/sizeof(int)) << endl;

	//16.
	int number[3] = { 3, 32, 321 };
	PrintMinNumber(number, sizeof(number)/sizeof(int));

	//17.
	cout << GetUglyNumber(20) << endl;

	//18.
	char* string = "abbbcdade";
	cout << FindTheFirstOnceChar(string) << endl;

	//19.
	int number[] = { 7, 5, 6, 4 };
	cout << InversePairs(number, sizeof(number)/sizeof(int)) << endl;

	//20.
	int number[] = { 1, 2, 3, 4, 5, 5, 6, 7, 8 };
	cout << NumberTime(number, sizeof(number)/sizeof(int), 5) << endl;

	//22.
	FindAddEquelS(15);

	//23.
	char* sentence = "I am a student!";
	cout << sentence << endl;
	sentence = ReverseSentence(sentence);
	cout << sentence << endl;
#endif



}