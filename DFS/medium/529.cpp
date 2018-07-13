#include<iostream>
#include<vector>
using namespace std;

void dfs(vector< vector<char> >& board,int i,int j){
     int n=board.size();
	 int m=board[0].size();
	 if(i<0||j<0||i>=n||j>=m)return;
	 if(board[i][j]=='M'){
	 	board[i][j]='X';
	 	return;
	 }else if(board[i][j]=='E'){
	 	 bool f1=(i-1<0||board[i-1][j]!='M')&&(j-1<0||board[i][j-1]!='M');
	 	 bool f2=(i+1>=n||board[i+1][j]!='M')&&(j+1>=m||board[i][j+1]!='M');
	 	 bool f3=(i-1<0||j-1<0||board[i-1][j-1]!='M')&&(i-1<0||j+1>=m||board[i-1][j+1]!='M');
	 	 bool f4=(i+1>=n||j-1<0||board[i+1][j-1]!='M')&&(i+1>=n||j+1>=m||board[i+1][j+1]!='M');
	     if(f1&&f2&&f3&&f4){
	     	board[i][j]='B';
	     	dfs(board,i+1,j);
	     	dfs(board,i-1,j);
	     	dfs(board,i,j-1);
	     	dfs(board,i,j+1);
            dfs(board,i-1,j-1);
            dfs(board,i-1,j+1);
            dfs(board,i+1,j+1);
            dfs(board,i+1,j-1);
	     }else{
	     	int c=0;
	     	if(i-1>=0&&board[i-1][j]=='M')c++;
	     	if(j-1>=0&&board[i][j-1]=='M')c++;
	     	if(i+1<n&&board[i+1][j]=='M')c++;
	     	if(j+1<m&&board[i][j+1]=='M')c++;
	     	if(i-1>=0&&j-1>=0&&board[i-1][j-1]=='M')c++;
	     	if(i-1>=0&&j+1<m&&board[i-1][j+1]=='M')c++;
	     	if(i+1<n&&j-1>=0&&board[i+1][j-1]=='M')c++;
	     	if(i+1<n&&j+1<m&&board[i+1][j+1]=='M')c++;
	     	board[i][j]=c+'0';
	     	return;
	     }
	 }else{
	 	return;
	 }
}

vector< vector<char> > updateBoard(vector< vector<char> >& board, vector<int>& click) {
     int n=board.size();
	 int m=board[0].size();
	 if(click[0]>=n||click[1]>=m)return board;
	 dfs(board,click[0],click[1]);
	 return board;   
}

int main(){
	return 0;
}
