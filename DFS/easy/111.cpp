#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
if(!root) return 0;
if(!root->left) return 1 + minDepth(root->right);
if(!root->right) return 1 + minDepth(root->left);
return 1+min(minDepth(root->left),minDepth(root->right));
*/
/*
//判断一个结点是否是叶节点，得通过左右子树是否为空判断，不能根据是否为空判断 
int dfs(TreeNode* root){
        if(root->right==NULL&&root->left==NULL)return 1;
        int a=0x7fffffff,b=0x7fffffff;
        if(root->left){
            a=dfs(root->left);
        }
        if(root->right){
            b=dfs(root->right);
        } 
        return min(a,b)+1;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return 1;
        return dfs(root);
    }
*/

int minDepth(TreeNode* root){
	if(root==NULL) return 0;
	if(root->left!=NULL) return 1+minDepth(root->right);
	if(root->right!=NULL) return 1+minDepth(root->left);
	return 1+min(minDepth(root->left),minDepth(root->right));
	
}

int main(){
	return 0;
}
