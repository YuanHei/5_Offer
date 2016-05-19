#include <iostream>
using namespace std;

//最小的k个数
//输入n个整数，找出其中最小的k个数。例如输入4，5，1，6，2，7，3，8
//这8个数字，则最小的四个数字是1，2，3，4
int Partition(int * input, int start, int end)
{
	int pivotpos = start;
	int pivot = input[start];

	for (int i = start + 1; i < end + 1; ++i)
	{
		if (input[i] < pivot)
		{
			pivotpos++;
			if (pivotpos != i)
			{
				int temp = input[pivotpos];
				input[pivotpos] = input[i];
				input[i] = temp;
			}
		}
	}
	input[start] = input[pivotpos];
	input[pivotpos] = pivot;

	return pivotpos;
}
//方法一:
//最直观的方法是直接快速排序然后进行遍历，时间复杂度是O(nlogn)
void QuickSort(int * input, int left, int right)
{
	if (left < right)
	{
		int pivotpos = Partition(input, left, right);
		QuickSort(input, left, pivotpos - 1);
		QuickSort(input, pivotpos + 1, right);
	}
}

void Show_K(int * input, int k)
{
	for (int i = 0; i < k; ++i)
	{
		cout << input[i] << " ";
	}
	cout << endl;
}

//方法二：
//基于数组的第k个数字大的所有数字都位于数组的右边，这样
//调整之后，位于数组中左边的k个数字就是最小的k个数字
//（不一定是排序的）

void GetLeastNumber(int * input, int n, int * output, int k)
{
	if (input == NULL || output == NULL || k > n || n <= 0 || k <= 0)
	{
		return;
	}

	int start = 0;
	int end = n - 1;
	int index = Partition(input, start, end);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(input, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(input, start, end);
		}
	}
	int i = 0;
	for (i = 0; i < k; ++i)
	{
		output[i] = input[i];
	}
	output[i] = '\0';
}

//功能测试（输入的数组中有相同的数字，输入的数组中没有相同的数字）
//边界值测试（输入的刊登于1或者等于数组的长度）
//特殊输入测试（k小于1、k大于数组的长度、指向数组的指针为NULL）
int main()
{
	int k;
	cin >> k;
	int num[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int num1[] = { 0 };
	GetLeastNumber(num, 8, num1, k);
	for (int i = 0; i < k; ++i)
	{
		cout << num1[i] << " ";
	}
	cout << endl;
//	QuickSort(num, 0, 7);
//	Show_K(num, k);
	return 0;
}