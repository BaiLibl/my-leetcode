#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//methods 2:
//更新有关(i,j)四个方向的 
void dfs(vector< vector<int> >& matrix,int x,int y,int val){
	    if(x<0||y<0||y>=matrix[0].size()||x>=matrix.size()||matrix[x][y]<=val)
            return;
        
        if(val>0) matrix[x][y] = val;
        
        dfs(matrix, x+1, y, matrix[x][y]+1);
        dfs(matrix, x-1, y, matrix[x][y]+1);
        dfs(matrix, x, y+1, matrix[x][y]+1);
        dfs(matrix, x, y-1, matrix[x][y]+1);
}
//判断(i,j)四周是否有0 
bool istrue(vector< vector<int> >& matrix,int x,int y){
	    if(x>0&&matrix[x-1][y]==0) return true;
        if(x<matrix.size()-1&&matrix[x+1][y]==0) return true;
        if(y>0&&matrix[x][y-1]==0) return true;
        if(y<matrix[0].size()-1&&matrix[x][y+1]==0) return true;
        
        return false;
}
vector< vector<int> > updateMatrix(vector< vector<int> >& matrix) {
	if(matrix.size()==0||matrix[0].size()==0)return vector< vector<int> >();
	int n=matrix.size();
	int m=matrix[0].size();
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(matrix[i][j]==1&&!istrue(matrix,i,j)){
				matrix[i][j]=max(n,m);//把标1的且又不挨着0的标成最大
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(matrix[i][j]==1){
				dfs(matrix,i,j,-1);
				 //并不是直接更新matrix[i][j]，而是用matrix[i][j]更新四周 
			}
		}
	}
    return matrix;  
}


     
    vector< vector<int> > updateMatrix(vector < vector<int> >& matrix) {
    	int dx[4] = {0, 0, -1, 1};
    	int dy[4] = {1, -1, 0, 0};
        if(matrix.size() == 0 || matrix[0].size()==0){
            vector<vector<int> > ans;
            return ans;
        }
        int row = matrix.size(), colum = matrix[0].size();
         
        vector< vector<int> > ans(row, vector<int>(colum, 0));
         
        queue< pair<int,int> > seq;
        vector< vector<int> > vis(row, vector<int>(colum, 0));
        for(int i=0; i<row; ++i){
            for(int j=0; j<colum; ++j){
                if(matrix[i][j] == 1){
                    if((i>0 && matrix[i-1][j]==0) || (i+1<row && matrix[i+1][j]==0) ||
                        (j>0 && matrix[i][j-1]==0)|| (j+1<colum && matrix[i][j+1]==0) ){
                            seq.push(make_pair(i, j));
                            ans[i][j] = 1;
                            vis[i][j] = 1;
                        }
                }
            }
        }
         for(int i=0; i<row; ++i){
         	for(int j=0; j<colum; ++j){
         		cout<<ans[i][j]<<' ';	
         	}
         	cout<<endl;
         }
         for(int i=0; i<row; ++i){
         	for(int j=0; j<colum; ++j){
         		cout<<vis[i][j]<<' ';	
         	}
         	cout<<endl;
         }
         
        int x, y, tmp_x, tmp_y;
        while(!seq.empty()){
            x = seq.front().first; y = seq.front().second;
            seq.pop();
            for(int i=0; i<4; ++i){
                tmp_x = dx[i] + x; tmp_y = dy[i] + y;
                if(tmp_x >=0 && tmp_x <row && tmp_y >=0 && tmp_y < colum &&
				    matrix[tmp_x][tmp_y] == 1 && vis[tmp_x][tmp_y]==0){
				   // cout<<x<<' '<<y<<' '<<tmp_x<<' '<<tmp_y<<endl;
                    ans[tmp_x][tmp_y] = ans[x][y] + 1;
                    vis[tmp_x][tmp_y] = 1;
                    seq.push(make_pair(tmp_x, tmp_y));
                }
            }
        }
         
        return ans;
    }

int main(){
	vector< vector<int> > res,res1;
	int i,j;
	for(i=0;i<3;i++){
		vector<int> tmp;
		for(j=0;j<3;j++){
			int n;
			cin>>n;
			tmp.push_back(n);
		}
		res.push_back(tmp);
	}
	res1=updateMatrix(res);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		cout<<res1[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}
