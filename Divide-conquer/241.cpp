#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

  vector<int> diffWaysToCompute(string input) {
        if(input.length()==0)return vector<int>();
        vector<int> res;
        int i,m,n;
        for(i=0;i<input.length();i++){
            char c=input[i];
            if(c>'9'||c<'0'){
                vector<int> left=diffWaysToCompute(input.substr(0,i));
                vector<int> right=diffWaysToCompute(input.substr(i+1));
                for(m=0;m<left.size();m++){
                    for(n=0;n<right.size();n++){
                        switch(c){
                            case '+':
                                res.push_back(left[m]+right[n]);
                                break;
                            case '-':
                                res.push_back(left[m]-right[n]);
                                break;
                            case '*':
                                res.push_back(left[m]*right[n]);
                                break;
                            default:
                                break;   
                        };
                    }
                }
            }
        }
        if(res.size()==0){
            //Ö»ÓÐÊý×Ö
            stringstream ss;
            ss<<input;
            ss>>i;
            res.push_back(i);
        }
        return res;
    }

int main(){
	stringstream ss;
	int a;
	string input="2-1-1";
	//ss<<input;
	//ss>>a;
	//cout<<a<<endl;
	//cout<<input.substr(0,3)<<endl;
	//cout<<input.substr(4)<<endl;
	vector<int> res=diffWaysToCompute(input);
	int i;
	for(i=0;i<res.size();i++)cout<<res[i]<<' ';
	return 0;
}
