#include<iostream>
using namespace std;
//实现整数加法，但不允许用+-符号 

int getSum(int a, int b) {
	if(a==0)return b;
	int x=a^b;//如果没有进位x=a+b;
	int c=(a&b)<<1;//找到应该进位的位置，前置1位
	return getSum(c,x);        
}

int main(){
	return 0;
}
