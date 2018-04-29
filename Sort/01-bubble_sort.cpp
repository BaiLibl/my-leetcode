#include<iostream>
#include<vector>
using namespace std;
//���������
//��������ʱ���¼ 
#include <stdlib.h> 
#include <time.h> 
/*
ð������ 
*/
void swap(int& i,int& j){
	int tmp=i;
	i=j;
	j=tmp;
}

void bubble_sort(vector<int>& num){
	int n=num.size();
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(num[i]>num[j])swap(num[i],num[j]); 
		}
	}
} 
/*
void bubble_sort(vector<int>& num){
	int n=num.size();
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(num[i]>num[j])swap(num[i],num[j]);
		}
	}
}
*/
//��������㷨����ȷ�� 
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
	
	//����������ʱ���㷨ִ��Ч��: Ч����� 
	start_time=clock();
	bubble_sort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//����������ʱ���㷨ִ��Ч����Ч����� 
	start_time=clock();
	bubble_sort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//���������ʱ���㷨ִ��Ч����Ч��һ�� 
	start_time=clock();
	bubble_sort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
