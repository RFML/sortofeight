#include<iostream>
#include<vector>

using namespace std;

void Insertsort(vector<int >& nums,int length);
void Insertsort1(vector<int >& nums, int length);
void Shellsort(vector<int >& nums,int length);

int main()
{
	vector<int > nums{3,6,4,2,11,10,5,15};
	Insertsort(nums,8);
	for (auto iter : nums)
		cout << iter<<" ";
	cout << endl;
	return 0;
}


/******************************
名称：直接插入排序
时间复杂度：O(n)~O(n^2)
空间复杂度：O(1)
稳定性：稳定
*******************************/

void Insertsort(vector<int >& nums,int length)
{
	if (nums.size() < 2 || length < 2) return;
	for(int i=1;i<length;i++)
	{
		int preIndex=i-1;
		int current=nums[i];
		while(preIndex>=0&&nums[preIndex]>current)
		{
			nums[preIndex+1]=nums[preIndex];
			preIndex--;
		}
		nums[preIndex+1]=current;
		
	}	
}

/******************************
名称：折半插入排序
时间复杂度：O(n^2)
空间复杂度：O(1)
稳定性：稳定
*******************************/

void Insertsort1(vector<int >& nums,int length)
{
	if (nums.size() < 2 || length < 2) return;
	for(int i=1;i<length;i++)
	{
		int low=0;
		int hight=i-1;
		int current=nums[i];
		while(low<=hight)
		{
			int mid=(low+hight)>>1;
			if(nums[mid]>current)
				hight=mid-1;
			else
				low=mid+1;
		}
		for(int j=i;j>low;j--)
		{
			nums[j]=nums[j-1];
		}
		nums[low]=current;	
	}	
}

/******************************
名称：希尔排序
时间复杂度：与增量序列有关;
增量序列：增量序列{1,3,7，...,2^k-1}  O(n^1.5)
空间复杂度：O(1)
稳定性：不稳定
*******************************/

void Shellsort(vector<int >& nums,int length)
{
	if (nums.size() < 2 || length < 2) return;
	int Gap=1;
	while(Gap<length/3)
		Gap=Gap*3+1;
	while(Gap>=1)
	{
		for(int i=Gap;i<length;i++)
		{
			int preIndex=i-Gap;
			int current=nums[i];
			while(preIndex>=0&&nums[preIndex]>current)
			{
				nums[preIndex+Gap]=nums[preIndex];
				preIndex=preIndex-Gap;
			}
			nums[preIndex+Gap]=current;	
		}
		Gap/=3;
	}	
}







