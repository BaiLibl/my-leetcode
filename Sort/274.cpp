#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool isless(int a,int b){
	return a>b;
}
int hIndex(vector<int>& citations) {
	if(citations.size()==0)return 0;
	if(citations.size()==1){
		if(citations[0]!=0)return 1;
		else{
			return 0;
		}
	}
	sort(citations.begin(),citations.end(),isless);
	int i;
	vector<int> tmp;
	for(i=0;i<citations.size();i++){
		if(citations[i]>=tmp.size()){
			tmp.push_back(citations[i]);
		}
	} 
    return tmp.size();     
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(0);
	a.push_back(3);
	a.push_back(6);
	a.push_back(5);
	cout<<hIndex(a)<<endl;
	return 0;
}

