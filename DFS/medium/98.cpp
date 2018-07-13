#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> res;
void dfs(TreeNode* root){
	if(root==NULL)return;
	dfs(root->left);
	res.push_back(root->val);
	dfs(root->right);
}
bool isValidBST(TreeNode* root) {
	int i=1;
	dfs(root);
	while(i<res.size()&&res[i]>res[i-1])i++;
	if(i==res.size()){
		return true;
	}else{
		return false;
	}
}


//紧扣BST定义，左子树所有结点小于根结点，右子树左右结点都大于根结点 
/**
 * 判断以root为根节点的二叉树上的所有节点的值是否都大于val
 */
bool noLess(struct TreeNode *root, int val) {
    if (root == NULL)
        return true;
    // 如果根节点的值不大于val，返回false
    if (root->val <= val)
        return false;
    // 递归判定root的左右子树上的所有节点值是否都大于val
    return noLess(root->left, val) && noLess(root->right, val);
}

/**
 * 判断以root为根节点的二叉树上的所有节点的值是否都小于val
 */
bool noGreater(struct TreeNode *root, int val) {
    // 空，返回true
    if (root == NULL)
        return true;
    // 如果根节点的值不小于val，返回false
    if (root->val >= val)
        return false;
    // 递归判定root的左右子树上的所有节点值是否都小于val
    return noGreater(root->left, val) && noGreater(root->right, val);
}
/**
 * 验证二叉树是否为合法的二插查找树
 */
bool isValidBST(struct TreeNode *root) {
    if (root == NULL) return true;
    if (noGreater(root->left, root->val) && noLess(root->right, root->val))
        // 如果同时成立则，递归判断左右子树是二叉查找树是否同时成立
        return isValidBST(root->left) && isValidBST(root->right);
    else
        // 如果不同时成立，返回false
        return false;
}

int main(){
	return 0;
}
