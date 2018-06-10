#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
	if(s.length()==0){
		int i;
		for(i=0;i<wordDict.size();i++)if(wordDict[i]==s)return true;
		return false;
	}
	vector<int> dp(s.length()+1);
	map<string,int> dict;
	int i,j,k;
	for(i=0;i<wordDict.size();i++)dict[wordDict[i]]=i;
	dp[0]=1;//
	for(i=1;i<s.length()+1;i++){
		for(j=i-1;j>=0;j--){
			if(dp[j]==1&&dict.find(s.substr(j,i-j))!=dict.end()){
				dp[i]=1;
				break;
			}	
		}
	}
	return dp[s.length()];
}
/*
//dfs time exceed
bool dfs(map<string,int>& mp,string s,int start,int end){
	if(start>end){
		return false;
	}else{
		string cur="";
		int i;
		for(i=start;i<=end;i++)cur+=s[i];
	//	cout<<cur<<endl;
		if(mp.find(cur)!=mp.end())return true;
		for(i=start;i<end;i++){
			if(dfs(mp,s,start,i)&&dfs(mp,s,i+1,end))return true;
		}
		return false;
	}
}

bool wordBreak(string s, vector<string>& wordDict) {
	int i;
	map<string,int> mp;
	for(i=0;i<wordDict.size();i++){
		if(wordDict[i]==s)return true;
		mp[wordDict[i]]=1;
	}
	if(s.length()==0){
		return false;
	}        
	return dfs(mp,s,0,s.length()-1);
}
*/

int main(){
//	while(1){
		string s1,s2;
		s1="leetcode";
		vector<string> a;
		s2="leet";
		a.push_back(s2);
		s2="code";
		a.push_back(s2);
	//	s2="gs";
		a.push_back(s2);
		cout<<wordBreak(s1,a)<<endl;
//	}
	return 0;
}
