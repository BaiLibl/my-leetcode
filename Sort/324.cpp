#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
��������һ����������ӣ����ֵ����Сֵ����
�����Ҵ��ײ����м�����Ų��ԣ����в���β����ǰ�žͿ��ԣ������� 
*/

/*
��Ŀ��ʾ��O(N)���ӶȺ�O(1)�ռ����ʵ�֣����ǿ���һ�±��˵Ľ���˼·������λ����
���ҵ���λ����������ģ�����С���������á���������λ���ĸ��Ӷ���O(N)�𣿣��� 
*/ 
void wiggleSort(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	vector<int> tmp=nums;
	int p=(nums.size()-1)/2,q=nums.size()-1; //�ص㣡���� 
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
