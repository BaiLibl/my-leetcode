#include<iostream>
using namespace std;

bool isPowerOfFour(int num) {
   if(num<=0) return false;
   int i=num;
   while(num>1){
		if(num%4!=0) return false;
		num=num/4;
   }
   return true;
}

int main(){
	int n;
	cin>>n;
	cout<<isPowerOfFour(n);
	return 0;
}
