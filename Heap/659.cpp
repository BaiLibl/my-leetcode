#include<iostream>
#include<vector>
using namespace std;

/*
����ÿ�����֣������������������к�������ܣ��򴴽�һ���µ������� 
���ȷ����������ָ���С��3��������
�����Ӧ���������������ģ�ֻ�������ظ�consecutive integers 
*/

bool isPossible(vector<int>& nums){
	if(nums.size()==0)return false;
	vector<int> tail; //������һ������ 
	vector<int> cnt;  //��������д�С
	int i,j;
	for(i=0;i<nums.size();i++){
		//cout<<nums[i]<<endl;
		bool f=false;
		int index=-1;
		for(j=0;j<tail.size();j++){
			if(nums[i]==tail[j]+1){//����ֻ���ݴ�С�������һλ
				if(index==-1)index=j;//��һ�����ʵ�λ�� 
				if(cnt[j]<3){ //�������С��3���� 
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
			if(index!=-1){ //����������0�������һ������ 
				tail[index]=nums[i];
				cnt[index]++;
			}else{ //û�к��ʵ� 
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
