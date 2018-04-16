#include<iostream>
#include<vector>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
	/*if(primes.size()==0)return 0;
	if(n==1)return 1;
	int p=primes.size();
	vector< vector<int> > res(p,vector<int>());
	int i,j;
	for(i=0;i<p;i++){
		res[i].push_back(1);
	}
	i=0;
	int mm;
	while(i<n){
		mm=res[0][0];
		for(j=1;j<p;j++){
			if(res[j][0]<mm){
				mm=res[j][0];
			}
		}
		//res[k].erase(res[k].begin());
		for(j=0;j<p;j++){
			if(mm==res[j][0])res[j].erase(res[j].begin()); //应该是在这里浪费了时间 
		}
		i++;
	}
	return mm;
	*/
	int k = primes.size();
	vector<int> pos(k, 0);
	vector<int> res(n);
	res[0] = 1;
	for (int i = 1; i < n; i++) {
		int temp = INT_MAX;
		for (int j = 0; j < k; j++) 
			temp = min(temp, res[pos[j]] * primes[j]);
		for (int j = 0; j < k; j++) {
			if (temp == res[pos[j]] * primes[j])
				pos[j]++;
		}
		res[i] = temp;
	}
	return res[n - 1];
}

int main(){
	vector<int> p;
	p.push_back(2);
	p.push_back(7);
	p.push_back(13);
	p.push_back(19);
	int a=nthSuperUglyNumber(12,p);
	return 0;
}
