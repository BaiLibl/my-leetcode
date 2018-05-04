#include<iostream>
#include<vector>
using namespace std;
/*
总结：像这种数组，两两进行比较的，可以转化成在某一位上计算 
*/ 


int hamming(int x,int y){
	int count=0;
	while(x!=0||y!=0){
		if((x&1)!=(y&1))count++; 
		x=x>>1;
		y=y>>1;
	}
	return count;
}
//暴力超时 
int totalHammingDistance2(vector<int>& nums) {
    int res=0;
    int i,j;
	for(i=0;i<nums.size();i++){
		for(j=i+1;j<nums.size();j++){
			res+=hamming(nums[i],nums[j]);
		}
	} 
    return res;
    
}
//按照每一位计算，如果在第i位上，有a个0，b个1,那么产生的距离是a*b
//时间复杂度是O(n*log k) log k跟数组中最大元素有关 
int totalHammingDistance(vector<int>& nums) {
	if(nums.size()<2)return 0;
    int res=0;
    int i,j;
	
	int index=0;
	while(1){
		int a=0;
		int b=0;
		int zerocount=0; //在每一轮循环里统计0的个数，当全是0时就停止 
		for(i=0;i<nums.size();i++){
			if(nums[i]==0)zerocount++;
			if(nums[i]&1){
				a++;
			}else{
				b++;
			}
			nums[i]=(nums[i]>>1);
		}
		res+=a*b;
		if(zerocount==nums.size())break;
	}
    return res;
    
}
  int totalHammingDistance2(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        int ans = 0;
        int *zeroOne = new int[2];
        while(true)
        {
            int zeroCount = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0) zeroCount++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            ans += zeroOne[0] * zeroOne[1];
            if(zeroCount == nums.size()) return ans;
        }
    }

int main(){
	while(1){
		int a,b;
		cin>>a>>b;
		cout<<hamming(a,b)<<endl;
	}
	return 0;
}
