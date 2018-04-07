#include<iostream>
#include<vector>
using namespace std;


/*
读题去~~~~
如果已经有Key,则进行更新 
*/ 
class MapSum {
private:
	//MapSum* next[26]={NULL};
	//int count=0;
	
public:
	struct TrieTree{
		int count;
		int sum;
		bool iskey;
		struct TrieTree* next[26]={NULL};
		TrieTree(){
			count=0;
			sum=0;
			iskey=false;
		}//初始化函数 
	};
	TrieTree* root;
    /** Initialize your data structure here. */
    MapSum() { 
		root=new TrieTree();  
    }
    
    void insert(string key, int val) {
        if(key.length()==0)return;
        int i;
        //MapSum* cur=this;
        vector<TrieTree*> node;
        TrieTree* cur=root;
        for(i=0;i<key.length();i++){
        	int j=key[i]-'a';
        	if(cur->next[j]==NULL){
        		cur->next[j]=new TrieTree();
        	}
        	cur=cur->next[j];
        	cur->sum += val;
        	node.push_back(cur);
        }
        if(cur->iskey){
        	for(i=0;i<node.size();i++){ //已经存在，覆盖 
        		node[i]->sum -= cur->count;
        	}
        }
        cur->count=val;
        cur->iskey=true;
    }
    
    int sum(string prefix) {
        if(prefix.length()==0)return 0;
        int i;
        int res=0;
        //MapSum* cur=this;
        TrieTree* cur=root;
        for(i=0;i<prefix.length();i++){
        	int j=prefix[i]-'a';
        	if(cur->next[j]==NULL){
        		return 0;
        	}
        	//res=cur->next[j]->count;
        	cur=cur->next[j];
        }
        return cur->sum;
    }
};

int main(){
	MapSum a;
	a.insert("aa",3);
	cout<<a.sum("a")<<endl;
	a.insert("aa",2);
	cout<<a.sum("a")<<endl;
	return 0;
}
