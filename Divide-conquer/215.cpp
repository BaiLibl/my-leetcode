#include<iostream>
#include<vector>
using namespace std;

void swap(int& a,int& b){
	int t=a;
	a=b;
	b=t;
}

int partition(vector<int>& res,int left,int right){
	int& p=res[left]; //一定要加入引用，不然在swap(p,res[right])是无效 
	left++;
	while(left<=right){
		if(res[left]<p&&res[right]>p){
			swap(res[left],res[right]);
			left++;
			right--;
		}
		if(res[left]>=p)left++;
		if(res[right]<=p)right--;
	}
	//cout<<res[right]<<'a'<<p<<endl;
	swap(p,res[right]);
	return right;
}

/*
 int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
                
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
*/
int findKthLargest(vector<int>& nums, int k) {
	if(nums.size()==0||k<0||k>nums.size())return 0;       
	int left=0,right=nums.size()-1;
	while(1){
		int i=partition(nums,left,right);
		if(i==k-1)return nums[i];
		else if(i>k-1){
			right=i-1;
		}else{
			left=i+1;
		}
	}
	
}

int main(){
	//[3,2,1,5,6,4]
	vector<int> a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.push_back(5);
	a.push_back(6);
	a.push_back(4);
	int i;
	//for(i=0;i<a.size();i++)cout<<a[i]<<' ';
	//cout<<endl;
	cout<<findKthLargest(a,2)<<endl;
	//for(i=0;i<a.size();i++)cout<<a[i]<<' ';
	//cout<<endl;
	//for(i=1;i<5;i++)cout<<findKthLargest(a,i)<<endl;
	//cout<<findKthLargest(a,4)<<endl;
	return 0;
} 
