#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> img = {{100,200,100}, {200,50,200}, {100,200,100}};
    vector<vector<int>> out_img = img;
    int a = img.size(), b = img[0].size();
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            int sum = 0;
            int n = 1;
            sum += img[i][j];
            if(i + 1 < a)
            {
                sum += img[i + 1][j];
                n++;
            }
            if(j + 1 < b)
            {
                sum += img[i][j + 1];
                n++;
            }
            if(i + 1 < a && j + 1 < b)
            {
                sum += img[i + 1][j + 1];
                n++;
            }
            if(i - 1 >= 0)
            {
                sum += img[i - 1][j];
                n++;
            }
            if(j - 1 >= 0)
            {
                sum += img[i][j - 1];
                n++;
            }
            if(i - 1 >= 0 && j - 1 >= 0)
            {
                sum += img[i - 1][j - 1];
                n++;
            }
            if(i - 1 >= 0 && j + 1 < b)
            {
                sum += img[i - 1][j + 1];
                n++;
            }
            if(j - 1 >= 0 && i + 1 < a)
            {
                sum += img[i + 1][j - 1];
                n++;
            }
            out_img[i][j] = sum / n;
        }
    }

    for(int i = 0; i < out_img.size(); i++)
    {
        for(int j = 0; j < out_img[0].size(); j++)
        {
            cout << out_img[i][j] << " ";
        }
    }
    return 0;
}