#include<iostream>
#include<vector>
using namespace std;
//随机数生成
//程序运行时间记录 
#include <stdlib.h> 
#include <time.h> 

/*
归并排序：分治思想 
*/ 
void Merge(vector<int>& num,int left,int mid,int right){
	vector<int> res;//作为排序结果的临时保存数组
	int n=num.size()-1;
	int i=left;
	int j=mid+1;
	while(i<=mid&&j<=right){
		if(num[i]<num[j]){
			res.push_back(num[i]);
			i++;
		}else{
			res.push_back(num[j]);
			j++;
		}
	} 
	while(i<=mid){
		res.push_back(num[i]);
		i++;
	}
	while(j<=right){
		res.push_back(num[j]);
		j++;
	}
	for(i=0;i<res.size();i++){
		num[i+left]=res[i];
	}
}
void merge_sort(vector<int>& num,int left,int right){
	if(left>=right)return;//递归结束条件
	int mid=left+(right-left)/2;
	merge_sort(num,left,mid);
	merge_sort(num,mid+1,right);
	Merge(num,left,mid,right); 
}

void MergeSort(vector<int>& num){
	merge_sort(num,0,num.size()-1);
}

//检测排序算法的正确性 
bool istrue(vector<int>& a){
	int i;
	i=1;
	while(i<a.size()&&a[i]>=a[i-1])i++;
	if(i==a.size())return true;
	return false;
}

int main(){
	vector<int> a;
	vector<int> b;
	vector<int> c;
	int i,j;
	clock_t start_time;
	clock_t end_time;
	
	for(i=0;i<10000;i++)a.push_back(i);
	for(i=10000;i>=0;i--)b.push_back(i);
	srand((unsigned)time(NULL)); 
	for(i=0;i<10000;i++){
		  c.push_back(rand()%10000);
	}
	
	//当数据有序时，算法执行效果: 效果最好 
	start_time=clock();
	MergeSort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//当数据逆序时，算法执行效果：效果最差 
	start_time=clock();
	MergeSort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//当数据随机时，算法执行效果：效果一般 
	start_time=clock();
	MergeSort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
