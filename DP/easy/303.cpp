#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
	vector<int> num;
    NumArray(vector<int> nums) {
        int i;
        int sum=0;
        for(i=0;i<nums.size();i++){
        	sum+=nums[i];
        	num.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
		return num[j]-num[i-1];
    }
};

int main(){
	int i,j;
//	vector<int> nums;
//	NumArray obj = new NumArray(nums);
 //	int param_1 = obj.sumRange(i,j);
	return 0;
}
