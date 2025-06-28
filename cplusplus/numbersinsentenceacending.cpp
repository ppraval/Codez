#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
    stringstream ss(s);
    string w;
    vector<int> temp;
    int i = 0;
    while(ss >> w) 
    {
        if (isdigit(w[0])) 
        {
            int num = stoi(w);
            temp.push_back(num);
            if(i != 0)
            {
                if(temp[i] < temp[i-1])
                {
                    cout << "The numbers are not in ascending order." << endl;
                    return 0;
                }
            }
            i++;
        }
    }
    cout << "The numbers are in ascending order." << endl;
    return 1;
}