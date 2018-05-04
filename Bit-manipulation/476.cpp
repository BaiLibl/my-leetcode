#include<iostream>
#include<vector>
using namespace std;

int findComplement(int num) {
	vector<int> res;
	if(num==0) return 1;
	if(num==1) return 0;
	while(num>0){
		res.push_back(num%2);
		num=num/2;
	}
	int i=0,sum=0,dig=1;
	for(i=0;i<res.size();i++){
		int a= (res[i]==1)? 0:1;
		sum+=a*dig;
		dig*=2;
	}        
	return sum;
}
//使用位运算 
int fun(int num){
	if(num==0)return 1;
    int res=0;
    int i=0;
    while((num>>i)){
       	int c=((num>>i)&1);
       	//cout<<((num>>i)&1)<<' '<<(c^1)<<endl;
       	c^=1;
        res |= (c<<i);
        i++;
	}
    return res;
}

int main(){
	int i;
	cin>>i;
	cout<<findComplement(i)<<endl;
	return 0;
}
