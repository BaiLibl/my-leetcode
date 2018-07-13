#include<iostream>
#include<vector>
using namespace std;

//搜索哪些位置的水可以同时流进太平洋和大西洋 


int nx[]={-1,1,0,0};
int ny[]={0,0,1,-1};
//index标志到达的地方，求解两个方向到达的位置 
void dfs(vector< vector<int> >& matrix,vector<vector<int> >& index,int x,int y){
     	
	index[x][y]=1;//到达
	int n=matrix.size();
	int m=matrix[0].size();
	int i;
	int a,b;
	for(i=0;i<4;i++){ //上下左右四种情况 
		a=x+nx[i];
		b=y+ny[i];
		if(a>=0&&a<n&&b>=0&&b<m){
			if(index[a][b]!=1&&matrix[a][b]>=matrix[x][y]){ //是大于等于，反过来
			//从边缘往中间靠近，反着找的 
				dfs(matrix,index,a,b);
			}
		}
	} 
	
}

vector<pair<int, int> > pacificAtlantic(vector< vector<int> >& matrix){
	if(matrix.size()==0||matrix[0].size()==0)return vector<pair<int,int> >();
	int n=matrix.size();
	int m=matrix[0].size();
	vector< vector<int> > res1(n,vector<int>(m,0));
	vector< vector<int> > res2(n,vector<int>(m,0));
	int i,j;
	for(i=0;i<n;i++){
		dfs(matrix,res1,i,0);//太平洋
		dfs(matrix,res2,i,m-1);//大西洋 
	}
	for(j=0;j<m;j++){
		dfs(matrix,res1,0,j);
		dfs(matrix,res2,n-1,j);
	} 
	vector<pair<int,int> > res;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(res1[i][j]&&res2[i][j]){
				res.push_back(pair<int,int>(i,j));
			}
		}
	}
	//dfs(matrix,res,0,0);
	return res; 
        
}

int main(){
	//[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
	return 0;
}
