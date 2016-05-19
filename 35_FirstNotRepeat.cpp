#include <iostream>
using namespace std;

//第一个只出现一次的字符
//在字符串中找出第一个只出现一次的字符

//解法：建立哈希表，时间复杂度O(0)、空间复杂度O(1)
const int tableSize = 256;
char FirstNotRepeatingChar(char * pString)
{
	if (pString == NULL)
	{
		return '\0';
	}
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i < tableSize; ++i)
	{
		hashTable[i] = 0;
	}

	char *pHashKey = pString;
	while (*(pHashKey) != '\0')
	{
		hashTable[*(pHashKey++)]++;
	}

	pHashKey = pString;

	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
		{
			return *pHashKey;
		}
		pHashKey++;
	}

	return '\0';
}

//功能测试（字符串中存在只出现一次的字符，字符串中不存在只出现
//一次字符，字符串中所有的字符只出现一次）
//特殊输入测试（字符串为NULL指针）
int main()
{
	char * str = "abaccdeff";
	cout << FirstNotRepeatingChar(str) << endl;
	return 0;
}