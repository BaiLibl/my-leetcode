#include<iostream>
#include<vector>
#include<string>
using namespace std;

   void dfs(vector<string>& res, string s,int pos){
	if(pos==s.length()){
		res.push_back(s);
		return;
	}
	dfs(res,s,pos+1);   //������� 
	if(s[pos]>='a'&&s[pos]<='z'){
		s[pos]=s[pos]-'a'+'A';
		dfs(res,s,pos+1); // ����֮���ٴα��� 
	}else if(s[pos]>='A'&&s[pos]<='Z'){
		s[pos]=s[pos]-'A'+'a';
		dfs(res,s,pos+1);
	}
}

vector<string> letterCasePermutation(string S) {
	if(S.length()==0)return vector<string>(1,"");//Ϊ��ѹ��մ� 
	vector<string> res;
	dfs(res,S,0);
	return res;        
}

int main(){
	return 0;
} 
