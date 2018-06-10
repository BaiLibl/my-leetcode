#include<iostream>
#include<vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
 		int n = nums.size();
        if(n <= 1)
            return n;
        int result = nums[0] != nums[1] ? 2:1;
        int flag = nums[1] - nums[0];
        for(int i=2;i<nums.size();i++){
            if((nums[i] - nums[i-1]) * flag < 0 || (flag==0 && (nums[i] - nums[i-1])!=0)){
                result ++;
                flag = nums[i] - nums[i-1];
            }
        }
        return result;
}
/*
 //这也没有用到贪心啊
        if(nums.size()<2)return nums.size();
        int i;
        int flag=0;
        int len=nums.size();
        for(i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])len--; //相等不长度减一
            else if(nums[i]>nums[i-1])flag==1?len--:flag=1; //
            else if(nums[i]<nums[i-1])flag==-1?len--:flag=-1;
        }
        return len;
*/
int main(){
	vector<int> a;
/*	a.push_back(1);
	a.push_back(17);
	a.push_back(5);
	a.push_back(10);
	a.push_back(13);
	a.push_back(15);
	a.push_back(10);*/
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	cout<<wiggleMaxLength(a)<<endl;
	return 0;
}
