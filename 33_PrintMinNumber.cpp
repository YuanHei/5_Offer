#include <iostream>
using namespace std;

//输入一个正整数数组，把数组中所有的数字拼接起来组成一个数，
//打印出能拼接成所有数字中最小的一个。
//例如输入数组{3，32，321}，则输出321323

const int g_MaxNumberLength = 10;

char * g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char * g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

//内部的将字符串排序
int compare(const void * strNumber1, const void * strNumber2)
{
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	strcat(g_StrCombine1, *(const char**)strNumber2);

	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcat(g_StrCombine2, *(const char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(int * number, int length)
{
	if (number == NULL || length <= 0)
	{
		return;
	}

	char ** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; ++i)
	{
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", number[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0; i < length; ++i)
	{
		printf("%s", strNumbers[i]);
	}
	printf("\n");

	for (int i = 0; i < length; ++i)
	{
		delete[] strNumbers[i];
	}
	delete[] strNumbers;
}

//功能测试（输入的数组中有多个数字，输入的数组中的数字有重复的数位，输入的数字只有一个数字）
//特殊输入测试（表示数组的指针为NULL指针）

int main()
{
	//由于是正整数数组，为大于0的数组，故不需要考虑数位存在0
	//而后是两组测试用例
	int num[] = { 3, 32, 321 };
	int num1[] = { 45,1, 2, 3 };
	PrintMinNumber(num, 3);
	PrintMinNumber(num1, 4);
	return 0;
}