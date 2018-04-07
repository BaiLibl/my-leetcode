#include<iostream>
#include<vector>
#include<string>
using namespace std;

//�ֵ���
/* 
	struct TrieTree
	{
			int count;//ÿ���ڵ��Ĵ���
			struct TrieTree* next[26]={NULL};//ÿ���ڵ�洢�����ڵ�ָ��
			//ÿһ��������������26������ 
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
					//��ʶ�Ƿ��м̳У����ǵ������ٵ�һ��·����·���Ͻ���Ϊ0 
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
			TireTree():count(0){}//��ʼ������ 
		};
		TireTree* createTree(vector<string> words){
			if(words.size()==0)return NULL;
			TireTree* root=new TireTree();//�ս��
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
					string res=c+search(cur->next[i],temp);//���ۼӱ仯 
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
