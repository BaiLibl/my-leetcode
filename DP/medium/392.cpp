#include<iostream>
#include<string>
using namespace std;

  bool isSubsequence2(string s, string t) {
        int idx = 0;
        int cur = -1;
        for (auto & c : s) {
            if ((cur = t.find(c, idx)) < idx)//²éÕÒ
                return false;
            else
                idx = cur + 1;
        }

        return true;
        
    }

bool isSubsequence(string s, string t) {
	if(s.length()==0)return true;
	if(s.length()!=0&&t.length()==0)return false;
	int i,j;
	i=0;
	j=0;
	while(i<s.length()&&j<t.length()){
		if(s[i]==t[j]){
			i++;
			j++;
		}else{
			j++;
		}
	}
	if(i==s.length()){
		return true;
	}else{
		return false;
	}
    
}

int main(){
	string s="axc",t="ahbgdc";
	cout<<isSubsequence(s,t)<<endl;
	return 0;
}
