#include<iostream>
#include<string>
using namespace std;

char findTheDifference(string s, string t) {
	int s1[26],t1[26];
	int p=-1;
	int i;
	char m,a;
	for(i=0;i<26;i++){
		s1[i]=0;
		t1[i]=0;	
	}	
	for(i=0;i<s.length();i++){
		a=s[i];
		s1[a-'a']++;
	}
	for(i=0;i<t.length();i++){
		a=t[i];
		t1[a-'a']++;
	} 
	
    for(i=0;i<26;i++){
    	if(s1[i]!=t1[i]){
    		p=i;
    		break;
    	}
    } 
	 
	if(p==-1){
		return m;
	}else{
		m=p+'a';
		return m;
	}
}

int main(){
	string s,t;
	cin>>s;
	cin>>t;
	cout<<findTheDifference(s,t)<<endl;
	return 0;
}
