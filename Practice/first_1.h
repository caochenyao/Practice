#pragma once
#include<windows.h>

//ʹCPU��ռ���ʹ̶���50%��Ϊһ��ֱ��
//�ⷨһ��
void Test1()
{
	//�ҵ�CPU��1.6GHz������ó�Ϊn=6.4*10^8(ѭ��/��)
	//��������һ��CPU����1�룬����Ϣ1��
	/*while(1)
	{
		for (INT64 i = 0; i < 640000000; ++i)
			;
		Sleep(1000);
	}*/
	//���ֵ�����Ƿ�ֵ�����ٳ���50%���п��ٽ������
	//��ʱ�併��10����
	while (1)
	{
		for (INT64 i = 0; i < 640000000; ++i)
			;
		Sleep(10);
	}
	//������һ�������ȶ���50%CPUռ����ֱ��
	//�������ַ����ܻ���Լ���ϴ󣬻����ı��Ҫ���¹���nֵ
}
//�ⷨ��
void Test2()
{
	//����ʱ��10����
	const INT64 busytime = 10;
	//��Ϣʱ��10����
	const INT64 relaxtime = 10;

	INT64 starttime = 0;
	while (1)
	{
		starttime = GetTickCount();
		while (GetTickCount() - starttime <= busytime)
			;
		Sleep(relaxtime);
	}
}