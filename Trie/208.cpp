#include<iostream>
#include<vector>
using namespace std;



class Trie {
public:
    /** Initialize your data structure here. */
    Trie* next[26]={NULL};
    bool is_word=false;
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	if(word.length()==0)return;
		int i;
		Trie* cur=this;
		for(i=0;i<word.length();i++){
			char c=word[i];
			if(cur->next[c-'a']==NULL)cur->next[c-'a']=new Trie();
			cur=cur->next[c-'a'];
		} 
		cur->is_word=true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	if(word.length()==0)return true;
    	int i;
    	Trie* cur=this;
    	for(i=0;i<word.length();i++){
    		char c=word[i];
    		if(cur->next[c-'a']==NULL)return false;
    		cur=cur->next[c-'a'];
    	}
    	return cur->is_word;//与前缀唯一区别是有路径并且是单词 
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
    	if(prefix.length()==0)return true;
    	int i;
    	Trie* cur=this;
    	for(i=0;i<prefix.length();i++){
    		char c=prefix[i];
    		if(cur->next[c-'a']==NULL)return false;
    		cur=cur->next[c-'a'];
    	}
    	return true;
    }
};

int main(){
	return 0;
}
