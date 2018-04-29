#include<iostream>
#include<vector>
using namespace std;
//���������
//��������ʱ���¼ 
#include <stdlib.h> 
#include <time.h> 

/*
//��������ð��+����+�ݹ����
//partition&sort 
*/ 
int partition(vector<int>& num,int start,int end){
	//����start-end���ҵ���������ȷλ��
	int p=num[start];
	while(start<end){
		while(start<end&&num[end]>=p)end--;
		num[start]=num[end];//startλ�õ�Ԫ���Ѿ�������
		while(start<end&&num[start]<=p)start++;
		num[end]=num[start]; 
	} 
	num[start]=p;
	return start;

}
void quickSort(vector<int>& num, int start, int end){
	if(start>=end)return;
	int p=partition(num,start,end);
	quickSort(num,start,p-1);//p֮ǰ�� 
	quickSort(num,p+1,end);  //p֮��� 
}
void quick_sort(vector<int>& num){
	quickSort(num,0,num.size()-1); 
}

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
	quick_sort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//����������ʱ���㷨ִ��Ч����Ч����� 
	start_time=clock();
	quick_sort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//���������ʱ���㷨ִ��Ч����Ч��һ�� 
	start_time=clock();
	quick_sort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
