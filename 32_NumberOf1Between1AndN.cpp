#include <iostream>
using namespace std;

//从1到n整数中1出现的次数
//输入一个整数n，求从1到n这n个整数的十进制表示中1出现
//的次数。例如输入12，从1到12这些整数中包含1的数字有
//1，10，11，12，1一共出现了5次

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; ++i)
	{
		result *= 10;
	}
	return result;
}

int NumberOf1(const char * strN)
{
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
	{
		return 0;
	}
	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	//0
	if (length == 1 && first == 0)
	{
		return 0;
	}
	//1
	if (length == 1 && first > 0)
	{
		return 1;
	}
	//例如21345
	//出现在最高位中的1（10000~19999）
	int numFirstDigit = 0;
	if (first > 1)
	{
		numFirstDigit = PowerBase10(length - 1);
	}
	else if (first == 1)
	{
		numFirstDigit = atoi(strN + 1) + 1;
	}
	//是1346~21346除第一位以外数位中1的数目
	int numOtherDigits = first * (length - 1)*PowerBase10(length - 2);
	//是1~1346中的1的数目，用递归实现
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	//现将数字转换成字符串
	char strN[50];
	sprintf(strN, "%d", n);

	return NumberOf1(strN);
}

//时间复杂度极高的
int Number1(unsigned int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
		{
			number++;
		}
		n = n / 10;
	}

	return number;
}

int NumberOf1Between1AndN_(unsigned int n)
{
	int number = 0;
	for (unsigned int i = 1; i <= n; ++i)
	{
		number += Number1(i);
	}
	return number;
}

//功能测试（输入5，10,55,99等）
//边界值测试（输入0,1等）
//性能测试（输入较大的数字，10000/21235等）
int main()
{
	int num;
	cin >> num;
	cout << NumberOf1Between1AndN(num) << endl;
	cout << NumberOf1Between1AndN_(num) << endl;
	return 0;
}