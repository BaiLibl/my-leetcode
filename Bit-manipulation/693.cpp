#include<iostream>
using namespace std;

bool hasAlternatingBits(int n) {
	if(n==0||n==1)return true;
	int i;
	i=1;
	int pre=(n&1);
	while(n>>i){
		int cur=((n>>i)&1);
		if(pre==cur)return false;
		pre=cur;
		i++;
	}       
	return true; 
}

int main(){
	while(1){
		int a;
		cin>>a;
		cout<<hasAlternatingBits(a)<<endl;
	}
	return 0;
} 
