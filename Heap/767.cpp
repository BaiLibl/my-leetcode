#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
�ȿ���Ƶ�ʴ���ַ��� 
*/

string reorganizeString(string S) {
	if(S.length()<=1)return S;
	int i,j;
	map<char,int> mp;        
	for(i=0;i<S.length();i++){
		mp[S[i]]++;
	}
	string res="";
	bool f=true;
	map<char,int>::iterator it;
	while(res.length()!=S.length()){
		int m=0;
		char c;
		//���ҵ����� 
		for(it=mp.begin();it!=mp.end();it++){
			if(it->second&&m<(it->second)){
				m=it->second;
				c=it->first;
			}	
		}
		//cout<<'1'<<c<<' '<<mp[c]<<endl; 
		if(res.length()&&res[res.length()-1]==c){//���ĺ��ϴ�һ�� 
			//���ҵ����ϴ�һ������
			 for(it=mp.begin();it!=mp.end();it++){
			 	if(it->second&&it->first!=c){
			 		c=it->first;
			 		break;
			 	}
			 }
			 if(c==res[res.length()-1])return "";//ȫ��һ������ 
		}
		res+=c;
		mp[c]--;
		//cout<<'2'<<c<<' '<<mp[c]<<endl; 
	}
	return res;
}

int main(){
	//string s="vvvlo";
	string s="aaab";
	cout<<reorganizeString(s)<<endl;
	return 0;
}
