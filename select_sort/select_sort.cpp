#include<iostream>
#include<vector>

using namespace std;
void Selectsort(vector<int >&nums, int length);
void Selectsort1(vector<int >&nums, int length);

int main()
{
	vector<int > nums{ 3,6,4,2,11,10,5,15 };
	Selectsort1(nums, 8);
	for (auto iter : nums)
		cout << iter << " ";
	cout << endl;
	return 0;
}

/******************************
名称：一般选择排序
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：不稳定
*******************************/

void Selectsort(vector<int >&nums, int length)
{
	if (nums.size() < 2 || length < 2) return;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (nums[i] > nums[j])
				swap(nums[i], nums[j]);
		}

	}
}

/******************************
名称：优化选择排序
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：不稳定
*******************************/

void Selectsort1(vector<int >&nums, int length)
{
	if (nums.size() < 2 || length < 2) return;
	int right = length - 1;
	int left = 0;
	int minIndex = 0;           //最小值下标
	int maxIndex = 0;			 //最大值下标
	while (left < right)
	{
		minIndex = left;
		maxIndex = left;
		/**********确定最大值下标及最小值下标************/
		for (int i = left; i <= right; i++)
		{
			if (nums[minIndex] > nums[i])
				minIndex = i;
			if (nums[maxIndex] < nums[i])
				maxIndex = i;
		}
		if (maxIndex != right)
			swap(nums[right], nums[maxIndex]);
		if (minIndex == right)                 //如果最小值在最右边；上面的if已经把最小值交换到最大值下标处。
			minIndex = maxIndex;
		if (minIndex != left)
			swap(nums[left], nums[minIndex]);
		left++;
		right--;
	}
}





