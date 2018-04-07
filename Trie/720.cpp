#include<iostream>
#include<vector>
#include<string>
using namespace std;

//字典树
/* 
	struct TrieTree
	{
			int count;//每个节点存的次数
			struct TrieTree* next[26]={NULL};//每个节点存储两个节点指针
			//每一个结点下面可能有26个可能 
			TrieTree():count(0){}
	};

	TrieTree* construction(vector<string> words){
			TrieTree*  root = new TrieTree();
			for(auto word: words){
					TrieTree*  cur = root;
					for(auto s: word){
							//cout<<s<<endl;
							if(cur->next[s-'a']==NULL) cur->next[s-'a']= new TrieTree();
							//else ++(cur->next[s-'a']->count) ;
							cur = cur->next[s-'a'];
					}
					cur->count =max(cur->count, 1);
					//标识是否有继承，若是单独开辟的一条路径，路径上结点均为0 
			}
			return root;
	}

	string  serachtire(TrieTree* root, string ret){
			if(!root) return "";
			string temp=ret;
			for(int i=0;i<26;i++){
					if(root->next[i] && root->next[i]->count){
							char c =('a'+i);
							string ttemp= c+serachtire(root->next[i], temp);
							if(ret.size()<ttemp.size()) ret=ttemp;
					}
			}
			return ret;
	}

*/
	struct TireTree{
			int count;
			struct TireTree* next[26]={NULL};
			TireTree():count(0){}//初始化函数 
		};
		TireTree* createTree(vector<string> words){
			if(words.size()==0)return NULL;
			TireTree* root=new TireTree();//空结点
			int i,j;
			for(i=0;i<words.size();i++){
				TireTree* cur=root;
				for(j=0;j<words[i].size();j++){
					char c=words[i][j];
					if(cur->next[c-'a']==NULL)cur->next[c-'a']=new TireTree();
					cur=cur->next[c-'a'];
				}
				cur->count=max(cur->count,1);
			} 
			return root;
		}
		string search(TireTree* root,string tmp){
			if(root==NULL)return "";
			int i;
			TireTree* cur=root;
			string temp=tmp;
			for(i=0;i<26;i++){
				if(cur->next[i]&&cur->next[i]->count){
					char c=(i+'a');
					string res=c+search(cur->next[i],temp);//不累加变化 
					if(res.size()>tmp.size())tmp=res;
				}
			}
			return tmp;
		}
string longestWord(vector<string>& words) {
    TireTree* root =createTree(words);
    return search(root, "");
}
 

int main(){
	return 0;
}
