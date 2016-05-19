//连续子数组的最大和
//输入一个整型数组，数组中有正数也有负数，数组中一个或连续的多个整数组成
//一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)
#include <iostream>
using namespace std;

//数组中必存在正数，否则为0
int MaxSubSum(int *arr, int len)
{
	int i;
	int MaxSum = 0;
	int CurSum = 0;
	for (i = 0; i < len; ++i)
	{
		CurSum += arr[i];
		if (CurSum > MaxSum)
		{
			MaxSum = CurSum;
		}
		//如果累加和出现小于0的情况，则和最大的子序列肯定
		//不可能包含前面的元素，这时累加和置为0
		//从下一个元素开始重新累加
		if (CurSum < 0)
		{
			CurSum = 0;
		}
	}
	return MaxSum;
}

//功能测试（输入的数组中有正数也有负数，输入的数组中全为正数，输入的数组中全为附属）
//特殊输入测试（表示数组的指针为NULL指针）
int main()
{
	int num0[] = { 2, 3, -10, 5 };
	//判断有相同的子串结果的输出
	int num1[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	//正常输出
	cout << MaxSubSum(num0, 4) << endl;
	cout << MaxSubSum(num1, 8) << endl;

	return 0;
}