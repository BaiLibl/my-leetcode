#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 int kthGrammar(int N, int K) {
        if(N==1||K==1)return 0;
        if(K%2==0){
            //ÊÇÓÒ×ÓÊ÷
            return kthGrammar(N-1,K/2)==0?1:0;
        }else{
            return kthGrammar(N-1,(K+1)/2)==0?0:1;
        }
        
    }

int main(){
	return 0;
}
