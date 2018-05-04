#include<iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
	uint32_t num=0;
	int i;
	for(i=0;i<32;i++){
		num=(num<<1)|((n>>i)&1);
	}
	return num;
}

int main(){
	int n;
	cin>>n;
	cout<<reverseBits(n);
	
	return 0;
}
