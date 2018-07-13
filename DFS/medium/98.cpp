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


//����BST���壬���������н��С�ڸ���㣬���������ҽ�㶼���ڸ���� 
/**
 * �ж���rootΪ���ڵ�Ķ������ϵ����нڵ��ֵ�Ƿ񶼴���val
 */
bool noLess(struct TreeNode *root, int val) {
    if (root == NULL)
        return true;
    // ������ڵ��ֵ������val������false
    if (root->val <= val)
        return false;
    // �ݹ��ж�root�����������ϵ����нڵ�ֵ�Ƿ񶼴���val
    return noLess(root->left, val) && noLess(root->right, val);
}

/**
 * �ж���rootΪ���ڵ�Ķ������ϵ����нڵ��ֵ�Ƿ�С��val
 */
bool noGreater(struct TreeNode *root, int val) {
    // �գ�����true
    if (root == NULL)
        return true;
    // ������ڵ��ֵ��С��val������false
    if (root->val >= val)
        return false;
    // �ݹ��ж�root�����������ϵ����нڵ�ֵ�Ƿ�С��val
    return noGreater(root->left, val) && noGreater(root->right, val);
}
/**
 * ��֤�������Ƿ�Ϊ�Ϸ��Ķ��������
 */
bool isValidBST(struct TreeNode *root) {
    if (root == NULL) return true;
    if (noGreater(root->left, root->val) && noLess(root->right, root->val))
        // ���ͬʱ�����򣬵ݹ��ж����������Ƕ���������Ƿ�ͬʱ����
        return isValidBST(root->left) && isValidBST(root->right);
    else
        // �����ͬʱ����������false
        return false;
}

int main(){
	return 0;
}
