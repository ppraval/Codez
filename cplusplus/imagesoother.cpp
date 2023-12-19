#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> img = {{100,200,100}, {200,50,200}, {100,200,100}};
    vector<vector<int>> out_img = img;
    int sum = 0, n = 0;
    for(int i = 0; i < img.size(); i++)
    {
        for(int j = 0; j < img[0].size(); j++)
        {
            sum += img[i][j];
            cout << sum << "\n";
            n++;
            if(i + 1 < img.size())
            {
                sum += img[i + 1][j];
                n++;
                cout << sum << " " << i << " " << j <<  "\n";
            }
            if(j + 1 < img[0].size())
            {
                sum += img[i][j + 1];
                n++;
                cout << sum << " " << i << " " << j <<  "\n";
            }
            if(i + 1 < img.size() && j + 1 < img[0].size())
            {
                sum += img[i + 1][j + 1];
                n++;
                cout << sum << " " << i << " " << j <<  "\n";
            }
            if(i - 1 > 0)
            {
                sum += img[i - 1][j];
                n++;
                cout << sum << " " << i << " " << j <<  "\n";
            }
            if(j - 1 > 0)
            {
                sum += img[i][j - 1];
                n++;
                cout << sum << " " << i << " " << j <<  "\n";
            }
            if(i - 1 > 0 && j - 1 > 0)
            {
                sum += img[i - 1][j - 1];
                n++;
                cout << sum << " " << i << " " << j <<  "\n";
            }
            if(i - 1 > 0 && j + 1 < img[0].size())
            {
                sum += img[i - 1][j + 1];
                n++;
                cout << sum << " " << i << " " << j <<  "\n";
            }
            if(j - 1 > 0 && i + 1 < img.size())
            {
                sum += img[i + 1][j - 1];
                n++;
                cout << sum << " " << i << " " << j <<  "\n";
            }
            out_img[i][j] = sum / n;
            cout << "\nFinal average is: " << sum / n << "\n";
            sum = 0;
            n = 0;
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