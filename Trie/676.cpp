#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class MagicDictionary {
public:
  	map<int,vector<string> > mp;
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
		if(dict.size()==0)return;
		int i;
		for(i=0;i<dict.size();i++){
			mp[dict[i].length()].push_back(dict[i]);
		}
    }
      
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
       int i,j;
	   int a;
	   for(i=0;i<mp[word.length()].size();i++){
			string str=mp[word.length()][i];
			a=0;
			for(j=0;j<word.length();j++){
				if(word[j]!=str[j])a++;
				if(a>1)break;
			}
			if(a==1)return true;
	   } 
	   return false;
    }
};

int main(){
	MagicDictionary a;
//	vector<string> b={"leetcode","hello"};
	vector<string> b;
	b.push_back("leetcode");
	b.push_back("hello");
	b.push_back("hallo");
	a.buildDict(b);
	//cout<<a.search("leetcode")<<endl;
	cout<<a.search("hello")<<endl;
	return 0;
}
