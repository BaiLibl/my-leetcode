#include<iostream>
using namespace std;

/*
�����������е�ƫ�[0,122]=0,�����������λ��Ϊ��׼�����ಹ��0��
��m&n��&���ȼ��ܵ� 
*/ 
/*
�ҵ��������λ�����඼��0 2018-4-29 
*/
int rangeBitwiseAnd(int m, int n) {
	int c=0;
	while(m!=n){
		m=(m>>1);
		n=(n>>1);
		c++;
	}
	return (m<<c);
	      
}

int main(){
	cout<<rangeBitwiseAnd(0,122);
	return 0;
}
