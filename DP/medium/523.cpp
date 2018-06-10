#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
	map<int,int> mp;
	int i,j;
	//����k=0ʱ 
	if(k==0){
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]==0&&nums[i+1]==0)return true;
        }
        return false;
    }
	int sum=0;
	mp[0]=-1;//��modk==0ʱ���⿼�Ǳ���nums[0]%==0 (nums[0]+nums[1])%k==0
	//���mp[0]=nums[i]��ô���nums[i+1]modk==0���Ǿ��޷�����������������ߵý������⿼�� 
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
