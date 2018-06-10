#include<iostream>
#include<vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
	int n=nums.size();
	if(n==0)return 0;
	vector<int> res(n,1);
	vector<int> cou(n,1);
	int i,j;
	int maxlen =1;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(nums[j]<nums[i]&&res[j]+1>res[i])res[i]=res[j]+1;
		}
		maxlen = max(maxlen,res[i]); //最大值可能有重复的情况 
	}
	return maxlen;        
}

//用数组increase[]表示长度为i的序列最小结尾是多少
int lengthOfLIS2(vector<int>& nums) {
	if(nums.size()==0)return 0;
	vector<int> inc(nums.size()+1,0);
	int i,j;
	int size=0;
	for(i=0;i<nums.size();i++){
		//size
		int left=0,right=size-1;
		while(left<=right){
			int mid=left+(right-left)/2;
			if(inc[mid]<nums[i]){
				left=mid+1;	//顺序不能颠倒，因为有相等的时候 
			}else{
				right=mid-1;
			}
		}
		inc[left]=nums[i];
		if(left==size)size++;
	}        
	return size;
}

int main(){
	return 0;
}
