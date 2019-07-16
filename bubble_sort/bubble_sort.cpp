#include<iostream>
#include<vector>

using namespace std;

void Bubblesort(vector<int >& nums,int length);
void Bubblesort1(vector<int >& nums, int length);

int main()
{
	vector<int > nums{3,6,4,2,11,10,5,15};
	Bubblesort(nums,8);
	for (auto iter : nums)
		cout << iter<<" ";
	cout << endl;
	return 0;
}


/******************************
名称：没做优化的冒泡排序
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：稳定
*******************************/

void Bubblesort(vector<int >& nums,int length)
{
	if(nums.size()<2||length<2) return;
	for(int i=0;i<length-1;i++)
	{
		for (int j = 0; j < length-1-i; j++)
		{
			if (nums[j+1] < nums[j])
			{
				swap(nums[j], nums[j + 1]);
			}
		}
	}	
}


/******************************
名称：优化的冒泡排序
时间复杂度：O(n)~O(n^2)
空间复杂度：O(1)
稳定性：稳定
*******************************/

void Bubblesort1(vector<int >& nums, int length)
{
	if (nums.size() < 2 || length < 2) return;
	bool didswap= true;
	for (int i = 0; i < length - 1; i++)
	{
		didswap = false;
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (nums[j + 1] < nums[j])
			{
				didswap = true;
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}