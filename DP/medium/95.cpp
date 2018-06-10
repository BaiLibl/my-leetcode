#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> res;
	TreeNode* tmp;
	if(n<=0)return res;
	if(n==1){
		tmp = new TreeNode(1);
		res.push_back(tmp);
		return res;
	} 
	vector< vector<TreeNode*> > dp;
	tmp=NULL;
	res.push_back(tmp);
	dp.push_back(res);
	res[0] = new TreeNode(1);
	dp.push_back(res);
	int i,j;
	for(i=2;i<=n;i++){
		vector<TreeNode*> temp;
		for(j=1;j<=i;j++){
			int left_size = dp[j-1].size();
			int right_size = dp[i-j].size();
			int k1,k2;
			for(k1=0;k1<left_size;k1++){
				for(k2=0;k2<right_size;k2++){
					TreeNode* root = new TreeNode(j);
					root->left = dp[j-1][k1];
					root->right = dp[i-j][k2];
					temp.push_back(root);
				}
			}
		}
		//dp[i]=temp;
		dp.push_back(temp);
	}       
	return dp[n];
}

/*
    vector<TreeNode *> generateTrees(int n) {
    	vector<TreeNode*> res;
    	if(n==0)return res;
        return Helper(1, n);
    }
    vector<TreeNode *> Helper(int begin, int end)
    {
        vector<TreeNode *> ret;
        if(begin > end)
            ret.push_back(NULL);
        else if(begin == end)
        {
            TreeNode* node = new TreeNode(begin);
            ret.push_back(node);
        }
        else
        {
            for(int i = begin; i <= end; i ++)
            {//root
                vector<TreeNode *> left = Helper(begin, i-1);
                vector<TreeNode *> right = Helper(i+1, end);
                for(int l = 0; l < left.size(); l ++)
                {
                    for(int r = 0; r < right.size(); r ++)
                    {
                        //new tree
                        TreeNode* root = new TreeNode(i);
                        root->left = left[l];
                        root->right = right[r];
                        ret.push_back(root);
                    }
                }
            }
        }
        return ret;
    }
    }
*/
int main(){
	return 0;
}
