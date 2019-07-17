#include<iostream>
#include<vector>

using namespace std;

void Mergesort(vector<int >& nums, int start,int end);
void MergeCore(vector<int >& nums, int L1, int L2, int r1, int r2);

int main()
{
	vector<int > nums{ 3,5,2,6,7,9,1,4};
	Mergesort(nums, 0,7);
	for (auto iter : nums)
		cout << iter << " ";
	cout << endl;
	return 0;
}


/******************************
名称：递归归并排序
时间复杂度：O(n^2)
空间复杂度：O(n)
稳定性：稳定
*******************************/

void Mergesort(vector<int >& nums, int start, int end)
{
	if (start > end || nums.size() < 1) return;
	if(start < end)
	{
		int mid = (start + end) >> 1;
		Mergesort(nums, start, mid);
		Mergesort(nums, mid+1, end);
		MergeCore(nums, start, mid + 1, mid, end);
	}
}

void MergeCore(vector<int >& nums, int L1, int L2, int r1, int r2)
{
	if (L1 > r1 || L2 > r2 || nums.size() < 1) return;
	int n = r1 - L1 + 1 + r2 - L2 + 1;
	vector<int > temp(n);
	int i = L1, j = L2, k = 0;
	while (i <= r1 && j <= r2)
	{
		if (nums[i] <= nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	//如果还有剩余直接放到辅助数组
	while(i<=r1)
		temp[k++] = nums[i++];
	while(j<=r2)
		temp[k++] = nums[j++];
	//更新原始数组
	for (int i = 0; i < n; i++)
	{
		nums[L1 + i] = temp[i];
	}

}


/******************************
名称：非递归归并排序
时间复杂度：O(n^2)
空间复杂度：O(n)
稳定性：稳定
*******************************/

void Mergesort(vector<int >& nums, int length)
{
	if (nums.size() < 2 || length < 2) return;
	for (int i = 1; i < length; i++)
	{
		int low = 0;
		int hight = i - 1;
		int current = nums[i];
		while (low <= hight)
		{
			int mid = (low + hight) >> 1;
			if (nums[mid] > current)
				hight = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i; j > low; j--)
		{
			nums[j] = nums[j - 1];
		}
		nums[low] = current;

	}
}

