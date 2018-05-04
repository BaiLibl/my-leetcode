#include<iostream>
using namespace std;

int hammingWeight(uint32_t n) {
	int res=0;
	while(n!=0){
		if(n&0x1) res++;
		n=n>>1;
	}
	return res;
}

int main(){
	cout<<hammingWeight(11)<<endl;
	return 0;
}
