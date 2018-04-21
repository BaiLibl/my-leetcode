#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
考虑其中一种特殊的例子，最大值和最小值排序
但是我从首部和中间向后排不对，用中部和尾部向前排就可以，而且是 
*/

/*
题目提示用O(N)复杂度和O(1)空间代价实现，但是看了一下别人的解题思路，用中位数。
先找到中位数，比它大的，比它小的轮流放置。但是找中位数的复杂度是O(N)吗？？？ 
*/ 
void wiggleSort(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	vector<int> tmp=nums;
	int p=(nums.size()-1)/2,q=nums.size()-1; //重点！！！ 
	int i,j;
	for(i=0,j=1;i<nums.size();i+=2,j+=2){
		nums[i]=tmp[p];
		p--;
		if(j<nums.size()){
			nums[j]=tmp[q];
			q--;
		}
	}        
}

int main(){
	return 0;
}
