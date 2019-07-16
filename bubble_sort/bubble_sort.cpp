#include<iostream>
#include<vector>

using namespace std;

void Bubblesort(vector<int > nums,int length);

int main()
{
	vector<int > nums{3,6,4,2,11,10,5,15};
	Bubblesort(nums,8);
	for (auto iter : nums)
		cout << iter<<" ";
	cout << endl;
	return 0;
}

void Bubblesort(vector<int > nums,int length)
{
	if(nums.size()<2||length<2) return;
	for(int i=0;i<length-1;i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(nums[j]<nums[i])
			{
				int temp=nums[i];
				nums[i]=nums[j];
				nums[j]=temp;
			}
		}
	}	
}

