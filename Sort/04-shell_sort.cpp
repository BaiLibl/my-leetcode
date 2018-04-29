#include<iostream>
#include<vector>
using namespace std;
//随机数生成
//程序运行时间记录 
#include <stdlib.h> 
#include <time.h> 

/*
//希尔排序：插入排序的高效实现
先将整个记录分割成若干子序列分别进行排序，待整个序列基本有序时，再做一次完全插入排序 
*/ 
void shell_partition(vector<int>& num,int d){
	int n=num.size();
	int i,j;
	for(i=d;i<n;i++){
		j=i-d;
		int tmp=num[i];
		while(j>=0&&num[j]>tmp){
			num[j+d]=num[j];
			j=j-d;
		}
		if(j!=i-d)num[j+d]=tmp;//找到合适的位置插入 
								//若是就j<0跳出的，就应该查到j+d上 
	}
} 
void shell_sort(vector<int>& num){
	int n=num.size();
	int d=n/2;//间隔大小
	while(d){
		shell_partition(num,d);
		d=d/2;
	} 
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
	shell_sort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//当数据逆序时，算法执行效果：效果最差 
	start_time=clock();
	shell_sort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//当数据随机时，算法执行效果：效果一般 
	start_time=clock();
	shell_sort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
