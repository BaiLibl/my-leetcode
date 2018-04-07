
#include<iostream>
#include<string>
using namespace std;

class TrieNode{
	public:
		TrieNode * children[26];
		bool end;
		TrieNode()
		{
			int i;
			for(i=0;i<26;i++)
				children[i]=NULL;
			end=false;	
		}
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
    	int i;
    	i=0;
    	TrieNode* cur=root;
    	while(i<word.length()&&cur->children[word[i]-'a']!=NULL){
    		cur=cur->children[word[i]-'a'];
    		i++;
    	}
    	if(i==word.length()){
    		cur->end=true;
    	}else{
    		while(i<word.length()){
    			cur->children[word[i]-'a']=new TrieNode();
    			cur=cur->children[word[i]-'a'];
    			i++;
    		}
    		cur->end=true;
    	}
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
    	return searchword(word,root);
    
    }
    bool searchword(string word,TrieNode* cur){
    	if(cur==NULL)return false;
    	if(word=="")return cur->end==true;
    	if(word[0]!='.'){
    		if(cur->children[word[0]-'a']==NULL)
    			return false;
    		else{
    			return searchword(word.substr(1),cur->children[word[0]-'a']);
    		}
    	}else{
    		int i;
    		for(i=0;i<26;i++){
    			if(searchword(word.substr(1),cur->children[i])){
    				return true;
    			}
    		}
    		return false;
    	}
    }
};
int main(){
	return 0;
}
