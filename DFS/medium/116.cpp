#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void dfs(TreeLinkNode* curr,TreeLinkNode* next){
	if(curr==NULL){
		return;
	}else{
		curr->next = next;
		dfs(curr->left,curr->right);
		if(next==NULL){
			dfs(curr->right,NULL);
		}else if(next->left){
			dfs(curr->right,next->left);
		}else{
			dfs(curr->right,NULL);
		}
	}
}

void connect(TreeLinkNode *root) {
	if(root==NULL)return;
	 dfs(root,NULL);      
    
}

int main(){
	return 0;
}
