#include<iostream>
#include<vector>
#include<string>
using namespace std;

//dfs超时，学会问题转化 

//*有多少连续子串，就有多少以*为结尾的子串 
int findSubstringInWraproundString(string p) {
	if(p.length()<=1)return p.length();        
	vector<int> ch(26,0);
	ch[p[0]-'a']=1;
	int i,maxlen=1;
	for(i=1;i<p.length();i++){
		if(p[i]==(p[i-1]+1)||(p[i]=='a'&&p[i-1]=='z')){
			maxlen++;
		}else{
			maxlen=1;
		}
		ch[p[i]-'a']=max(ch[p[i]-'a'],maxlen);
	}
    int res=0;
	for(i=0;i<26;i++){
		res+=ch[i];
	}
	return res;
}

int main(){
	cout<<findSubstringInWraproundString("zab")<<endl;
	return 0;
} 
