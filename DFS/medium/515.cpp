#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root,int p,vector<int>& res){
	if(root==NULL)return;
	p++;
	if(res.size()<p){
		res.push_back(root->val);
	}else{
		res[p-1]=max(root->val,res[p-1]);
	}
	dfs(root->left,p,res);
	dfs(root->right,p,res);
}

vector<int> largestValues(TreeNode* root) {
	 vector<int> res;
	 if(root==NULL)return res;
	 dfs(root,0,res);
	 return res;    
    
}

int main(){
	return 0;
}
