#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//һ��һ�������ӣ������Ӽ�����Ϊi��Ԫ�أ�����Ϊi+1��Ԫ���ڸ���Ϊi��Ԫ��֮�Ͻ��й���
vector< vector<int> > subsets(vector<int>& nums) {
	vector< vector<int> > res(1,vector<int>());
	//��������
	int i,j;
	int pre_size = 0;//pre_size��ʾÿ��Ӧ�ü�һ��Ԫ�ص����ݡ�
	//��һ�εĴ�С�����治����size���Ӽ����� 
	for(i=0;i<nums.size();i++){
		int n = res.size();
		for(j=0;j<n;j++){
			if(i==0||j>=pre_size||nums[i] != nums[i -1]){
				res.push_back(res[j]);
				res.back().push_back(nums[i]); //������Ԫ�ػ����Ϲ�����Ԫ����ѹջ 
			}
		}
		pre_size = n;
	} 
        
    //res.push_back(44);
    return res;
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	vector< vector<int> > b=subsets(a);
	int i,j;
	for(i=0;i<b.size();i++){
		for(j=0;j<b[i].size();j++){
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
