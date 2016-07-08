#pragma once
#include<assert.h>
#include<string>

int Min(int t1, int t2, int t3)
{
	if (t1 < t2)
	{
		if (t3 < t1)
			return t3;
		else
			return t1;
	}
	else
	{
		if (t3 > t2)
			return t2;
		else
			return t3;
	}
}

int _SimilarityString(char* first,int fbegin,int fend,char* second,int sbegin,int send)
{
	assert(first);
	assert(second);

	if (fbegin > fend)
	{
		if (sbegin < send)
			return send - sbegin + 1;
		else
			return 0;
	}
	if (sbegin >send)
	{
		if (fbegin < fend)
			return fend - fbegin + 1;
		else
			return 0;
	}

	if (first[fbegin] == second[sbegin])
	{
		return _SimilarityString(first,fbegin+1,fend,second,sbegin+1,send)+1;
	}
	else
	{
		int t1 = _SimilarityString(first, fbegin+1, fend, second, sbegin+1, send)+1;
		int t2 = _SimilarityString(first, fbegin+1, fend, second, sbegin+2, send)+1;
		int t3 = _SimilarityString(first, fbegin+2, fend, second, sbegin+1, send)+1;
		return Min(t1, t2, t3);   //?
	}
}

void SimilarityString(char* _first,char* _second)
{
	assert(_first);
	assert(_second);
	int count = _SimilarityString(_first,0,strlen(_first),_second,0,strlen(_second))+1;
	printf("The similarity is:1/%d\n",count);
}

void TestString()
{
	char* first = "abxjhbcjhsdc";
	char* second = "ajkskjd";
	SimilarityString(first,second);
}