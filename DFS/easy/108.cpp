#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* create(vector<int>& nums,int i,int j){
	
	if(i>j)return NULL;
	if(i==j){
        TreeNode* root=new TreeNode(nums[i]);
		//root->left=NULL;
		//root->right=NULL;
		return root;
	}else{
		int pos=i+(j-i)/2;
        TreeNode* root=new TreeNode(nums[pos]);
		root->left=create(nums,i,pos-1);
		root->right=create(nums,pos+1,j);
		return root;
	}
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
	if(nums.size()==0)return NULL;
	root = create(nums,0,nums.size()-1);
	return root;
    }

int main(){
	vector<int> a;
	int i;
	for(i=1;i<9;i++)a.push_back(i);
	TreeNode* root=sortedArrayToBST(a);
	return 0;
}
