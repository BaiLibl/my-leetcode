#include<iostream>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
	if(n<0)return 0;
	if(n==0)return 1;
	if(n==1)return 10;
	int i;
	int cont = 9;
	int k=9;
	int res=10;
	while(n>=2){
		cont*=k;
		k--;
		n--;
		res+=cont;
	}       
	return res; 
}

int main(){
	cout<<countNumbersWithUniqueDigits(3)<<endl;
	return 0;
}
