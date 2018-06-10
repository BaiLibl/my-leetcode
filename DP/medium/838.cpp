#include<iostream>
#include<string>
using namespace std;

/*
һ�������Ƿ��£�����LR�����ľ��� 
*/

//string(int n,char c);     
//��n���ַ�c��ʼ�� 
string pushDominoes(string dominoes) {
        /*string d=dominoes;
        d = 'L' + d + 'R';
        string res = "";
        for (int i = 0, j = 1; j < d.length(); ++j) {
            if (d[j] == '.') continue;
            int middle = j - i - 1;//��¼.���� 
            if (i > 0) res += d[i];
            if (d[i] == d[j]) res += string(middle, d[i]);
            else if (d[i] == 'L' && d[j] == 'R') res += string(middle, '.');
            else res += string(middle / 2, 'R') + string(middle % 2,'.') + string(middle / 2, 'L');
            i = j;
        }
        return res;*/
        string d=dominoes;
        int i,j;
        int idl=-1;//��־L
        int idr=-1;//��־R
        for(i=0;i<d.length();i++){
            if(i==d.length()||d[i]=='R'){
                if(idl<idr){ //idL idR R 
                    for(j=idr+1;j<i;j++)d[j]='R';
                }
                //else����ײ
                idr = i;
            }else if(d[i]=='L'){
                if(idl<idr){ //idL idR L
                    //�԰뿳
                    int mid=i-idr-1;//���䳤��
                    //int j;
                    for(j=idr+1;j-idr<=mid/2;j++)d[j]='R';
                    for(j=i-1;i-j<=mid/2;j--)d[j]='L';
                }else{
                   //idR idL L
                    for(j=idl+1;j<i;j++)d[j]='L'; 
                }
                idl=i;
            }
        }
        return d;
}
/*
  int n = dominoes.size();
        int idxL = -1; // last L
        int idxR = -1; // last R
        for (int i = 0;i <= n;i++)
        {
            if (i == n || dominoes[i] == 'R')
            {
                // Encountered an 'R'
                if (idxR > idxL)
                {
                    // L....R.....R
                    // ^    ^     ^
                    // idxL idxR  i
                    // Fill ^-----^
                    for (auto k = idxR + 1;k < i;k++) dominoes[k] = 'R';
                }
		//          already processed
		//               v
                // No fill for R****L....R
                //             ^    ^    ^
                //             idxR idxL i
                idxR = i;
            }
            else if (dominoes[i] == 'L')
            {
                // Encountered an 'L'
                if (idxR > idxL)
                {
                    // ..L....R....L
                    //   ^    ^    ^
                    //  idxL idxR  i
                    //        ^----^
                    // Collision!
                    const auto interval = i - idxR - 1;
                    // R..L -> RRLL
                    // R...L -> RR.LL
                    // Fill
                    for (auto k = 1;k <= interval / 2;k++)
                    {
                        dominoes[idxR + k] = 'R';
                        dominoes[i - k] = 'L';
                    }
                }
                else
                {
                    // .R....L....L.
                    //  ^    ^    ^
                    // idxR idxL  i
                    // Fill  ^----^
                    for (int k = idxL + 1;k < i;k++) dominoes[k] = 'L';
                }
                idxL = i;
            }
        }
        return dominoes;
*/ 


int main(){
	string s=".L.R...LR..L..";
	cout<<pushDominoes(s)<<endl;
	return 0;
}
