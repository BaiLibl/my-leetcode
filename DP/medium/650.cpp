#include<iostream>
using namespace std;

//��K������ʱ��ֻ����k��ճ����� 
//ת���������ֽ� 
//�ܷ־����ֽ�
// 2+f(n/2) 3+f(n/3).... 

int minSteps(int n) {
    if(n<=1)return 0;
	int res = 0;
	int i;
	int k =n;
	for(i=2;i<=n&&k!=1;i++){
		while(k%i==0){ //9=3*3
			res+=i;//�Ѿ��ֽ��ˣ���γ��� 
			k=k/i;
		} 
	}	       
	return res;
}
/*
2*i��i������ճ������2��������2*i+i���� i������ճ������2�������ټ���1�����ƶ���
dp[j]=min(dp[j],dp[i]+k) j=2*i+(k-2)*i 
*/ 
 int minSteps(int n)
    {   if(n==1)return 0;
        if(n<=3)return n;
        vector<int> dp(1002,0);
        int i,j;
        dp[1]=0;
        for(i=2;i<1002;i++)dp[i]=i;
        for(i=1;i<1002;i++){
            int k=2;
            for(j=2*i;j<1002;j+=i){
                dp[j]=min(dp[j],dp[i]+k);
                k++;//j+i ����һ��
            }
        }
        return dp[n];
    }
int main(){
	int a=2;
	cout<<minSteps(a)<<endl;
	return 0;
}
