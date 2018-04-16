#include<iostream>
#include<vector>
using namespace std;

/*
对于每个数字，尽量放在已有子序列后，如果不能，则创建一个新的子序列 
优先放满足条件又个数小于3的子序列
这个题应该是针对连续数组的，只不过有重复consecutive integers 
*/

bool isPossible(vector<int>& nums){
	if(nums.size()==0)return false;
	vector<int> tail; //存放最后一个数字 
	vector<int> cnt;  //存放子序列大小
	int i,j;
	for(i=0;i<nums.size();i++){
		//cout<<nums[i]<<endl;
		bool f=false;
		int index=-1;
		for(j=0;j<tail.size();j++){
			if(nums[i]==tail[j]+1){//不能只根据大小放在最后一位
				if(index==-1)index=j;//第一个合适的位置 
				if(cnt[j]<3){ //如果个数小于3插入 
					//cout<<tail[j]<<' '<<nums[i]<<endl;
					tail[j]=nums[i];
					cnt[j]++;
					f=true;
					break;		
				}
			}
			if(tail[j]<nums[i]-1&&cnt[j]<3)return false; 
		}
		if(!f){
			if(index!=-1){ //个数都大于0，插入第一个后面 
				tail[index]=nums[i];
				cnt[index]++;
			}else{ //没有合适的 
				tail.push_back(nums[i]);
				cnt.push_back(1);
				//cout<<nums[i]<<endl;
			}			
		}
		//cout<<nums[i]<<' '<<index<<endl;
		//if(nums[i]==4)cout<<index<<endl; 
		cout<<i<<endl;
		for(j=0;j<tail.size();j++)cout<<tail[j]<<' '<<cnt[j]<<endl;
	} 
	//for(j=0;j<tail.size();j++)cout<<tail[j]<<' '<<cnt[j]<<endl;
	i=0;
	while(i<tail.size()&&cnt[i]>=3)i++;
	return i==tail.size();
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(4);
	a.push_back(4);
	a.push_back(5);
	a.push_back(5);
	cout<<isPossible(a)<<endl;
	return 0;
}
