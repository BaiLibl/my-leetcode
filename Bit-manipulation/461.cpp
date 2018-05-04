#include<iostream>
using namespace std;

int hammingDistance(int x, int y) {
	int res=0;
	int a=x,b=y;
	while(a!=0||b!=0){
		int a1,b1;
		a1=a%2;
		b1=b%2;
		if(a1!=b1)
			res++;
		a=a/2;
		b=b/2;
	}
	return res;      
}
/*
int count=0;
while(x!=0||y!=0){
	if((x&0x1)!=(y&0x1)) count++;
	x=x>>1;
	y=y>>1;
}
*/

int main(){
	cout<<hammingDistance(1,4)<<endl;
	return 0;
}
