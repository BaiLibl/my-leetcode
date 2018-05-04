#include<iostream>
#include<vector>
#include<map>
using namespace std;

int singleNumber2(vector<int>& nums) {
	map<int,int> mp;
	int i;
	for(i=0;i<nums.size();i++){
		mp[nums[i]]++;
	}
	map<int,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		if(it->second==1)return it->first;
	}
}

int singleNumber(vector<int>& nums) {
	// k is the numberOfOccurence-1, in this case, it is 3-1 = 2
    int k = 2;
    vector<int> bits(k,0);
    int i,j,m;
    for(m=0;m<nums.size();m++){
    	int x=nums[m];
        // try to flip every bit in the bits array using xor, and the constrain is that there can be at most 1 bit being 1 at at time. see graph
        //[0,0,...0] ----> [0,x,...0] ----> [0,0,x...0] ... [0,0,...x] ----> [0,0,...x].
        for(i = 0; i < k; i++){
            int temp = -1; // -1 is 32bits of 1s
            // check every other bits
            for(j = 0; j < k; j++){
                if(j != i){
                    temp &= ~bits[j]; // check for other bits except ith bit, if any of other bit is 1, them temp will be 0, otherwise it is 1 
                }
            }
            // try flip every bits,(inside parenthis), and also & with the result to make sure if other bits are 0
            bits[i] = (x ^ bits[i]) & temp;
        }
    }
    // bits[0] was original 0, those bits occurs 3 times will cancel out. The bits that occurs 1 times will remain, which is the answer
    return bits[0];
}



int main(){
	vector<int> a;
	a.push_back(-19);
	a.push_back(-19);
	a.push_back(-19);
	a.push_back(-28);
	cout<<singleNumber(a)<<endl;
	return 0;
} 
