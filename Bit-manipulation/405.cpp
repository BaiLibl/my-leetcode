#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

string toHex(int num){
	string hex;
	string charhex="0123456789abcdef";
	while(num){
		hex+=charhex[num&0xF];
		num=(unsigned)num>>4;
	} 
	reverse(hex.begin(),hex.end());
	return hex.empty()? "0":hex;
} 

string toHex1(int num) {
	string hex;
	int i,j;
	char c;
	if(num==0){
		return "0";
	}
	i=num;
	if(num<0){
		//ÌØÊâ¿¼ÂÇ 
	}
	while(i>0){
		j=i%16;
		if(j>9){
			c=j-10+'a';
		}else{
			c=j+'0';
		}
		hex=hex+c;
		i=i/16;
	}
	reverse(hex.begin(),hex.end());
	return hex;
        
}

int main(){
	while(true){
		int n;
		cin>>n;
		cout<<toHex(n)<<endl;	
	}
	
	return 0;
	
}
