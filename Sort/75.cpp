/*
ƽ�� 
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int i = -1; //0 
        int j = -1; //1
        int k = -1; //2
        for(int p = 0; p < n; p ++)
        {
            //���ݵ�i�����֣�Ų��0~i-1����
            if(A[p] == 0)
            {
                A[++k] = 2;    //2����Ų
                A[++j] = 1;    //1����Ų
                A[++i] = 0;    //0����Ų
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
