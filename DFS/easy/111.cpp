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
//�ж�һ������Ƿ���Ҷ�ڵ㣬��ͨ�����������Ƿ�Ϊ���жϣ����ܸ����Ƿ�Ϊ���ж� 
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
