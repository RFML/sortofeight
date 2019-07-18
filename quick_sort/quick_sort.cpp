#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void Quick_sort(vector<int > &nums, int low, int hight);
int Find_pos(vector<int > &nums, int low, int height);

int main()
{
	vector<int > nums{ 4,1,7,6,9,2,8,0,3,5};
	Quick_sort(nums, 0, nums.size() - 1);
		for (auto iter : nums)
			cout << iter << " ";
	cout << endl;
	return 0;
}

/******************************
名称：递归快速排序
时间复杂度：O(N*logN)~O(N^2)
空间复杂度：O(N*logN)
稳定性：不稳定
*******************************/

void Quick_sort(vector<int > &nums, int low, int hight)
{
	if (hight <= low) return;
	int pos;
	if (low < hight)
	{
		pos = Find_pos(nums, low, hight);
		Quick_sort(nums, low, pos - 1);
		Quick_sort(nums, pos + 1, hight);
	}
}

int Find_pos(vector<int > &nums, int low, int height)
{
	int key = nums[height];                   //如果key一直选到序列中最大或最小的数；快速排序效率很低
	while (low < height)
	{
		while (low < height && nums[low] <= key)
			low++;
		nums[height] = nums[low];
		while (low < height && key <= nums[height])
			height--;
		nums[low] = nums[height];
	}
	nums[height] = key;
	return height;
}
