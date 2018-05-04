#include<iostream>
using namespace std;

/*
我理解的题意有点偏差，[0,122]=0,是以最大数的位数为基准，其余补充0；
（m&n）&优先级很低 
*/ 
/*
找到公共最高位，其余都是0 2018-4-29 
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
