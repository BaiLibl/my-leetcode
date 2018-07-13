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
       // ��������Ƿ���ڲ�ƽ��
       if (lch == -1 || rch == -1 || abs(lch - rch) > 1) return -1;
       
       // ���ص�ǰ�����߶�
       return (lch > rch ? lch : rch) + 1;
    }
bool isBalanced(TreeNode* root) {
    return check(root) != -1;
}
