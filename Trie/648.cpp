#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

string replaceWords(vector<string>& dict, string sentence) {
    string res;
    map<int,vector<string> > mp;
    int i,j,m;
    for(i=0;i<dict.size();i++){
    	string tmp = dict[i];
    	mp[tmp.length()].push_back(tmp);
    }
    i=0;
    while(i<sentence.length()){
    	string ss="";
    	while(sentence[i]!=' '){
    		ss+=sentence[i];
    		i++;
    	}    	
    	for(j=1;j<ss.length();j++){
    		map<int,vector<string> >::iterator it = mp.find(j);
    		if(it!=mp.end()){
    			vector<string> dd=mp[j];
    			for(m=0;m<dd.size();m++){
    				if(ss.find(dd[m])==0){
    					ss=dd[m];
    					break;
    				}
    			}	
    		}else{
    			continue;
    		}
    	}
    	res+=ss+' ';
    	i++;
    }
    string::iterator it;
    it = res.begin()+res.length()-1;
    res.erase(it);
    return res;
	        
}

int main(){
	string s1="the cattle was rattled by the battery";
	vector<string> dict;
	dict.push_back("cat");
	dict.push_back("bat");
	dict.push_back("rat");
	cout<<replaceWords(dict,s1)<<endl;
	
	return 0;
}
