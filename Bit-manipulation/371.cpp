#include<iostream>
using namespace std;
//ʵ�������ӷ�������������+-���� 

int getSum(int a, int b) {
	if(a==0)return b;
	int x=a^b;//���û�н�λx=a+b;
	int c=(a&b)<<1;//�ҵ�Ӧ�ý�λ��λ�ã�ǰ��1λ
	return getSum(c,x);        
}

int main(){
	return 0;
}
