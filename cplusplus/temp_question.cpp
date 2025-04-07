#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> B = {
        {1, 2, 3},            
        {0, 2, 3},        
        {0, 0, 3}        
    };
    int K = 50;
    int temp;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            temp = B[i][j] + K;
            B[i][j] = B[j][i];
            B[j][i] = temp - K;
        }

    }
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    return 0;
}