/*
平移 
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int i = -1; //0 
        int j = -1; //1
        int k = -1; //2
        for(int p = 0; p < n; p ++)
        {
            //根据第i个数字，挪动0~i-1串。
            if(A[p] == 0)
            {
                A[++k] = 2;    //2往后挪
                A[++j] = 1;    //1往后挪
                A[++i] = 0;    //0往后挪
            }
            else if(A[p] == 1)
            {
                A[++k] = 2;
                A[++j] = 1;
            }
            else
                A[++k] = 2;
        }

    }
};
