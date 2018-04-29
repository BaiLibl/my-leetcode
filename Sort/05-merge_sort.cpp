#include<iostream>
#include<vector>
using namespace std;
//���������
//��������ʱ���¼ 
#include <stdlib.h> 
#include <time.h> 

/*
�鲢���򣺷���˼�� 
*/ 
void Merge(vector<int>& num,int left,int mid,int right){
	vector<int> res;//��Ϊ����������ʱ��������
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
	if(left>=right)return;//�ݹ��������
	int mid=left+(right-left)/2;
	merge_sort(num,left,mid);
	merge_sort(num,mid+1,right);
	Merge(num,left,mid,right); 
}

void MergeSort(vector<int>& num){
	merge_sort(num,0,num.size()-1);
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
	MergeSort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//����������ʱ���㷨ִ��Ч����Ч����� 
	start_time=clock();
	MergeSort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//���������ʱ���㷨ִ��Ч����Ч��һ�� 
	start_time=clock();
	MergeSort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
