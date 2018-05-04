#include<iostream>
#include<vector>
using namespace std;
/*
�ܽ᣺���������飬�������бȽϵģ�����ת������ĳһλ�ϼ��� 
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
//������ʱ 
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
//����ÿһλ���㣬����ڵ�iλ�ϣ���a��0��b��1,��ô�����ľ�����a*b
//ʱ�临�Ӷ���O(n*log k) log k�����������Ԫ���й� 
int totalHammingDistance(vector<int>& nums) {
	if(nums.size()<2)return 0;
    int res=0;
    int i,j;
	
	int index=0;
	while(1){
		int a=0;
		int b=0;
		int zerocount=0; //��ÿһ��ѭ����ͳ��0�ĸ�������ȫ��0ʱ��ֹͣ 
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
