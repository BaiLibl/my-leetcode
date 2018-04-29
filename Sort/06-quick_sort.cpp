#include<iostream>
#include<vector>
using namespace std;
//随机数生成
//程序运行时间记录 
#include <stdlib.h> 
#include <time.h> 

/*
//快速排序：冒泡+二分+递归分析
//partition&sort 
*/ 
int partition(vector<int>& num,int start,int end){
	//数组start-end，找到基数的正确位置
	int p=num[start];
	while(start<end){
		while(start<end&&num[end]>=p)end--;
		num[start]=num[end];//start位置的元素已经被保存
		while(start<end&&num[start]<=p)start++;
		num[end]=num[start]; 
	} 
	num[start]=p;
	return start;

}
void quickSort(vector<int>& num, int start, int end){
	if(start>=end)return;
	int p=partition(num,start,end);
	quickSort(num,start,p-1);//p之前的 
	quickSort(num,p+1,end);  //p之后的 
}
void quick_sort(vector<int>& num){
	quickSort(num,0,num.size()-1); 
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
	quick_sort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//当数据逆序时，算法执行效果：效果最差 
	start_time=clock();
	quick_sort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//当数据随机时，算法执行效果：效果一般 
	start_time=clock();
	quick_sort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
