#pragma once

int OneCount(int n)
{
	int icount = 0;
	int iflag = 1;

	int ilow = n - (n / iflag)*iflag;
	int icur = (n / iflag) % 10;
	int ihigh = n / (iflag * 10);

	switch (icur)
	{
		case 0:
			icount += ihigh*iflag;
			break;
		case 1:
			icount += ihigh*iflag + ilow + 1;
			break;
		default:
			icount += (ihigh + 1)*iflag;
			break;
	}
	return icount;
}

void Test2_4()
{
	int n = 10;
	cout << OneCount(n) << endl;
}