#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bulit(vector<int>& inorder, int is,int ie,vector<int>& postorder,int ps,int pe){
	if(is>ie||ps>pe)return NULL;
	if(is==ie&&ps==pe){
		return new TreeNode(postorder[pe]);
	}
	//int len = 
	TreeNode* root=new TreeNode(postorder[pe]);
	int i;
	for(i=is;i<=ie;i++){
		if(inorder[i]==postorder[pe])break;
	}
	int leftlen = i-is;
	root->left = bulit(inorder,is,is+leftlen-1,postorder,ps,ps+leftlen-1);
	root->right = bulit(inorder,is+leftlen+1,ie,postorder,ps+leftlen,pe-1);
	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if(inorder.size()==0||inorder.size()!=postorder.size())return NULL;
	return bulit(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);        
}
int main(){
	vector<int> p;
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);
	p.push_back(4);
	vector<int> i;
	i.push_back(2);
	i.push_back(1);
	i.push_back(4);
	i.push_back(3);
	//TreeNode* root=buildTree(p,i);
	//dfs(root);
	return 0;
}
