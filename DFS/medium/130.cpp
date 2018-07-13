#include<iostream>
#include<vector>
using namespace std;

class uf{
	private:
		vector<int> id;
		vector<int> sz;
		int count;
	public:
		uf(int n){
			count=n;
			sz=vector<int>(n,1);
			int i;
			for(i=0;i<n;i++)id.push_back(i);
		}
		int find(int p){
			while(p!=id[p]){
				p=id[p];
			}
			return p;
		}
		bool connected(int p,int q){
			return find(p)==find(q);
		}
		void unions(int p,int q){
			p=find(p);
			q=find(q);
			if(p==q)return;
			if(sz[p]>sz[q]){
				id[q]=p;
				sz[p]+=sz[q];
			}else{
				id[p]=q;
				sz[q]+=sz[p];
			}
		}
		int con(){
			return count;
		}
};


void solve(vector< vector<char> >& board) {
	if(board.size()==0||board[0].size()==0)return;
	int n=board.size();
	int m=board[0].size();
	uf uf(n*m+1); //额外设置一个结点，作为边缘结点的群 
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			//cout<<i<<' '<<j<<endl;
			if(board[i][j]=='X')continue;
			if(i==0||i==n-1||j==0||j==m-1){
				uf.unions(i*m+j,n*m);
				continue;//执行完这一步就应该跳出来 
			}//connect n*m,bound node
			if(board[i-1][j]=='O'){ //上面同类 
				uf.unions(i*m+j,i*m+j-m);
			}
			if(board[i+1][j]=='O'){ //下面同类 
				uf.unions(i*m+j,i*m+j+m);
			} 
			if(board[i][j+1]=='O'){ //右边同类 
				uf.unions(i*m+j,i*m+j+1);
			}
			if(board[i][j-1]=='O'){ //left
				uf.unions(i*m+j,i*m+j-1);
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(board[i][j]=='O'&&!uf.connected(i*m+j,n*m)){
				board[i][j]='X';
				
			}
		}
	}
}
//BFS，将与边缘O相连的 O都标记成A，是不动的 
//DFS,超时了。。。 
void check(vector<vector<char>>& board,int i,int j)
    {
        if(i<board.size()&&j<board[0].size())
        {
            if(board[i][j]=='O')//以边缘O向四方伸展 
            {
                board[i][j]='A';
                check(board,i+1,j);
                check(board,i,j+1);
                check(board,i-1,j);
                check(board,i,j-1);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int i,j;
        int n,m;
        if(board.size()==0)
            return;
        n=board.size();
        m=board[0].size();
        if(n==0 or m==0)
            return;
        for(i=0;i<n;i++)
        {
                if(board[i][0]=='O')check(board,i,0);
                if(board[i][m-1]=='O')check(board,i,m-1);
        }

        for(i=0;i<m;i++)
        {
                if(board[0][i]=='O')check(board,0,i);
				if(board[n-1][i]=='O')check(board,n-1,i);
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(board[i][j]=='A')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
int main(){
	vector< vector<char> > res;
	vector<char> a(4,'X');
	res.push_back(a);
	a[0]='X'; a[1]='O'; a[2]='O'; a[3]='X';
	res.push_back(a);
	 a[0]='X'; a[1]='X'; a[2]='O'; a[3]='X';
	res.push_back(a);
	
	a[0]='X'; a[1]='O'; a[2]='X'; a[3]='X';
	res.push_back(a);
	solve(res);
	int i,j;
	for(i=0;i<res.size();i++){
		for(j=0;j<res[i].size();j++)cout<<res[i][j]<<' ';
		cout<<endl; 
	} 
	
	return 0;
}
