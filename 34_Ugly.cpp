#include <iostream>
using namespace std;

//题目：我们把只包含因子2，3和5的数称为丑数（Ugly Number）
//求按从小到大的顺序的第1500个丑数。例如6，8，都是
//丑数，但14不是，因为它包含因子7.习惯上我们把1
//当做第一个丑数。

bool IsUgly(int number)
{
	while (number % 2 == 0)
	{
		number /= 2;
	}
	while (number % 3 == 0)
	{
		number /= 3;
	}
	while (number % 5 == 0)
	{
		number /= 5;
	}

	return (number == 1) ? true : false;
}

//直观但不高效的方法，时间复杂度过高
int Ugly(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	int number = 0;
	int count = 0;
	while (count < n)
	{
		++number;
		if (IsUgly(number))
		{
			++count;
		}
	}

	return number;
}

int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}

//有空间损耗，相当于用空间换时间
//创建数组保存已经找到的丑数
int GetUglyNumber(int index)
{
	if (index <= 0)
	{
		return 0;
	}
	int *pUglyNumbers = new int[index];
	//开辟数组空间
	pUglyNumbers[0] = 1;
	//1为第一个丑数
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while (nextUglyIndex < index)
	{
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
		{
			++pMultiply2;
		}
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
		{
			++pMultiply3;
		}
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
		{
			++pMultiply5;
		}
		++nextUglyIndex;
	}
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

//功能测试（输入2,3,4,5,6等）
//特殊输入测试（边界值1、无效输入0）
//性能测试（输入较大的数字1500）
int main()
{
	int n;
	cin >> n;
	cout << Ugly(n) << endl;
	//1500反应时间很长
	cout << GetUglyNumber(n) << endl;
	return 0;
}