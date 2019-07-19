#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void Heap_sort(vector<int > &nums, int length);
void Heap_sortCore(vector<int > &nums, int parent, int length);

int main()
{
	vector<int > nums{ 4,1,7,6,9,2,8,0,3,5};
	Heap_sort(nums, nums.size());
		for (auto iter : nums)
			cout << iter << " ";
	cout << endl;
	return 0;
}


/******************************
名称：堆排序
时间复杂度：O(N*logN)
空间复杂度：O(1)
稳定性：不稳定
*******************************/
void Heap_sort(vector<int > &nums, int length)
{
	for(int i=length/2;i>=0;i--)      //创建大根堆
		Heap_sortCore(nums,i,length);
	/*******堆排序**********/
	for(int i=length-1;i>0;i--)
	{
		swap(nums[0],nums[i]);      
		Heap_sortCore(nums,0,i);       //把根节点放到末尾后；维护大根堆
	}	
}

/********创建并维护堆************/
void Heap_sortCore(vector<int > &nums, int parent, int length)
{
	int root=nums[parent];
	int child=2*parent+1;
	while(child<length)
	{
		//若有右孩子，并且右孩子值大于左孩子值，则选取右孩子结点
		if(child+1<length&&nums[child]<nums[child+1])
			child++;
		if(root>=nums[child])       //根节点比子节点大；则满足大根堆；跳出
			break;
		//把较大结点赋值给父节点
		nums[parent]=nums[child];
		parent=child;
		child=2*parent+1;
	}
	//找到合适的安插位置
	nums[parent]=root;
}