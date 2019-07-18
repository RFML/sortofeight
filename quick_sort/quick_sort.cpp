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

void Quick_sort(vector<int > &nums, int low, int hight)
{
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
	int key = nums[height];
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
