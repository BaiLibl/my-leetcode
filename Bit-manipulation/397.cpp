#include<iostream>
using namespace std;

/*
2147483647报超时，太大，换成long long，连原有的函数参数和返回值类型都换了 
*/

//后面有几个0 
long long fun(long long n){
	long long i=0;
	while(n%2==0){
		n=(n>>1);
		i++;
	}
	return i;
}

long long integerReplacement(long long n) {
	if(n==1)return 0;
	long long res=0;
	while(n!=1){
		if(n%2==0){
			n=(n>>1);
		}else if((fun(n-1)>fun(n+1))||n==3){
			n=n-1;
		}else{
			n=n+1;
		}
		res++;
	}
	return res;
}

//递归
long long integerReplacement2(long long  n) {
    if(n == 1)
        return 0;
    if(n%2 == 0)
         return 1+integerReplacement(n/2);
    else
        return 1 + min(integerReplacement(n+1),integerReplacement(n-1));
} 
int main(){
	while(1){
		int a=2147483647;
		//cin>>a;
		cout<<integerReplacement(a)<<endl;
		//cout<<fun(a)<<endl;
		cin>>a;
	}
	return 0;
}
