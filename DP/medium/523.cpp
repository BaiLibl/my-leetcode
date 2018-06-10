#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
	map<int,int> mp;
	int i,j;
	//考虑k=0时 
	if(k==0){
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]==0&&nums[i+1]==0)return true;
        }
        return false;
    }
	int sum=0;
	mp[0]=-1;//当modk==0时特殊考虑必须nums[0]%==0 (nums[0]+nums[1])%k==0
	//如果mp[0]=nums[i]那么如果nums[i+1]modk==0，那就无法考虑这种情况，或者得进行特殊考虑 
	for(i=0;i<nums.size();i++){
		sum+=nums[i];
		int tmp=sum%k;
		if(mp.find(tmp)!=mp.end()){
			if(i-mp[tmp]>1)return true;
		}else{
			mp[tmp]=i;
		}
	}
	return false;
	    /*
        int i,j;
        if(k==0){
            for(i=0;i<nums.size()-1;i++){
                if(nums[i]==0&&nums[i+1]==0)return true;
            }
            return false;
        }
        for(i=0;i<nums.size();i++){
            int sum=nums[i];
            for(j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum%k==0)return true;
            }
        }
        return false;  
        */
}

int main(){
	return 0;
}
