#include<iostream>
#include<vector>
#include<string>
using namespace std;

  bool similiar(string s,string str){
    int i,j;
    i=0;
    j=0;
    while(i<s.length()&&j<str.length()){
    	if(s[i]==str[j]){
    		i++;
    		j++;
    	}else{
    		i++;
    	}
    }
    return j==str.length();
}
string findLongestWord(string s, vector<string>& d) {
	string res="";
	int i;
	if(d.size()==0)return "";
	for(i=0;i<d.size();i++){
		if(similiar(s,d[i])&&(d[i].length()>res.length()||(d[i].length()==res.length()&&d[i]<res))){
			res=d[i];
		}
	}
    return res;
}

int main(){
	string s="abpcplea";
	vector<string> d;
	string str="ale";
	d.push_back(str);
	str="apple";
	d.push_back(str);
	str="monkey";
	d.push_back(str);
	str="plea";
	d.push_back(str);
	cout<<findLongestWord(s,d)<<endl;
	return 0;
}
