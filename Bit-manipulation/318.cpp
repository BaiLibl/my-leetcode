#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//直接计算：O（n^2） 
bool iscommon(string a,string b){
	int i;
	vector<int> d(26,0);
	for(i=0;i<a.length();i++)d[a[i]-'a']++;
	for(i=0;i<b.length();i++){
		if(d[b[i]-'a']!=0)return false;
	}
	return true;
}

bool cmp(string a,string b){
	return a.length()>b.length();
}

int maxProduct(vector<string>& words){
    if(words.size()<=1)return 0;
    sort(words.begin(),words.end(),cmp);
    int i,j;
    int res=0;
    for(i=0;i<words.size();i++){
    	for(j=i+1;j<words.size();j++){
    		if(iscommon(words[i],words[j])&&(words[i].length()*words[j].length()>res)){
    			cout<<words[i]<<' '<<words[j]<<endl;
    			res=words[i].length()*words[j].length();
    		}
    	}
    }
    return res;
}

//使用位运算判断两个字符串是否出现相同的位数 
int maxProduct(vector<string>& words) {
        int maxlen = 0;
        vector<int>val(words.size());
        for(int i = 0; i < words.size(); i++)
            for(auto c: words[i]) val[i] |= (1 << (c - 'a')); 
			//|是按位或，将每个字符串都表示成一个数字（26）,出现的字符，对应位置为1 
        
        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++)
                if((val[i] & val[j]) == 0 && words[i].size() * words[j].size() > maxlen)
                    maxlen = max(maxlen, (int)(words[i].size() * words[j].size()));
        return maxlen;
}

int main(){
	vector<string> a;
	//["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
	a.push_back("a");
	a.push_back("ab");
	a.push_back("abc");
	a.push_back("d");
	a.push_back("cd");
	a.push_back("bcd");
	a.push_back("abcd");
	//["a","ab","abc","d","cd","bcd","abcd"]
	cout<<maxProduct(a)<<endl;
	return 0;
} 
