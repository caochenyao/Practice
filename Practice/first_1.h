#pragma once
#include<windows.h>

//使CPU的占用率固定在50%，为一条直线
//解法一：
void Test1()
{
	//我的CPU是1.6GHz，计算得出为n=6.4*10^8(循环/秒)
	//首先试验一下CPU工作1秒，再休息1秒
	/*while(1)
	{
		for (INT64 i = 0; i < 640000000; ++i)
			;
		Sleep(1000);
	}*/
	//出现的情况是峰值，快速超过50%，有快速降到最低
	//将时间降到10毫秒
	while (1)
	{
		for (INT64 i = 0; i < 640000000; ++i)
			;
		Sleep(10);
	}
	//出现了一条基本稳定的50%CPU占用率直线
	//不过这种方法受机器约束较大，机器改变就要重新估算n值
}
//解法二
void Test2()
{
	//工作时长10毫秒
	const INT64 busytime = 10;
	//休息时长10毫秒
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