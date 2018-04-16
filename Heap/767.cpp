#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
先可着频率大的字符来 
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
		//先找到最多的 
		for(it=mp.begin();it!=mp.end();it++){
			if(it->second&&m<(it->second)){
				m=it->second;
				c=it->first;
			}	
		}
		//cout<<'1'<<c<<' '<<mp[c]<<endl; 
		if(res.length()&&res[res.length()-1]==c){//最多的和上次一样 
			//又找到和上次一样的了
			 for(it=mp.begin();it!=mp.end();it++){
			 	if(it->second&&it->first!=c){
			 		c=it->first;
			 		break;
			 	}
			 }
			 if(c==res[res.length()-1])return "";//全是一样的了 
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
