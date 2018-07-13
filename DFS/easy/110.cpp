#include<iostream>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
int check(TreeNode* root) {
       if (!root) return 0;   //root=NULL 
       int lch = check(root -> left);
       int rch = check(root -> right);
       // 检查子树是否存在不平衡
       if (lch == -1 || rch == -1 || abs(lch - rch) > 1) return -1;
       
       // 返回当前子树高度
       return (lch > rch ? lch : rch) + 1;
    }
bool isBalanced(TreeNode* root) {
    return check(root) != -1;
}
