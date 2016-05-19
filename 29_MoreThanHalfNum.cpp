#include <iostream>
using namespace std;

//数组中出现次数超过一半的数字
//排序无疑是最直观的算法，但是除此之外还需要思考其他的途径。
//用快速排序和以下方法的时间复杂度都是O(n)，只是前一个方法
//会改变数组（由于有交换）

bool g_bInputInvalid = false;
bool isMoreThanHalf = true;

bool CheckInvalidArray(int * numbers, int length)
{
	//检测输入数据是否合法
	if (NULL == numbers && length <= 0)
	{
		g_bInputInvalid = true;
	}
	return g_bInputInvalid;
}

bool CheckMoreThanHalf(int * numbers, int length, int number)
{
	//检测出现频路最高的有没有超过数组的一半
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == number)
		{
			times++;
		}
	}

	bool isMoreThanHalf = true;
	if (times * 2 <= length)
	{
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

int MoreThanHalfNum(int * numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
	{
		return -1;
	}

	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	if (!CheckMoreThanHalf(numbers, length, result))
	{
		result = -1;
	}

	return result;
}

//功能测试（输入数组中存在一个出现次数超过数组长度一般的数字，
//输入的数组不存在一个出现次数超过数组长度一半的数字）
//特殊输入测试（输入的数组中只有一个数字，输入NULL指针）
int main()
{
	int num1[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	//符合条件的随机数组
	int num2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	//相同元素的数组，判断边界条件
	int num3[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
	//判断若存在数组元素刚好是数组的一半，判断边界条件
	int num4[] = { 1, 1, 1, 2, 3, 4, 5, 6, 7 };
	//判断若最多出现次数的元素不大于数组的一半

	cout << MoreThanHalfNum(num1, 9) << endl;
	cout << MoreThanHalfNum(num2, 10) << endl;
	cout << MoreThanHalfNum(num3, 10) << endl;
	cout << MoreThanHalfNum(num4, 9) << endl;

	return 0;
}