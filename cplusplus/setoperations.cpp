#include<bits/stdc++.h>
using namespace std;


void unionOfSets(vector<int> A, vector<int> B)
{
    unordered_map<int, int> ump;

    for(int i = 0; i < A.size() + B.size(); i++)
    {
        if(i < A.size())
        {
            ump[A[i]]++;
        }
        else
        {
            ump[B[i - A.size()]]++;
        }
    }
    vector<int> temp;
    for(auto x : ump)
        temp.push_back(x.first);
    for(int i = temp.size() - 1; i >= 0; i--)
        cout << temp[i] << " ";
    cout << endl;
}

void intersection(vector<int> A, vector<int> B)
{
    unordered_map<int, int> ump;

    for(int i = 0; i < A.size() + B.size(); i++)
    {
        if(i < A.size())
        {
            ump[A[i]]++;
        }
        else
        {
            ump[B[i - A.size()]]++;
        }
    }
    vector<int> temp;
    for(auto x : ump)
    {
        if(x.second > 1)
            temp.push_back(x.first);
    }
    for(int i = temp.size() - 1; i >= 0; i--)
        cout << temp[i] << " ";
    cout << endl;
}

void setDifference(vector<int> A, vector<int> B)
{
    unordered_map<int, int> ump;

    for(int i = 0; i < A.size() + B.size(); i++)
    {
        if(i < A.size())
        {
            ump[A[i]]++;
        }
        else
        {
            ump[B[i - A.size()]]++;
        }
    }
    vector<int> temp;
    for(int i : A)
    {
        if(ump[i] == 1)
            cout << i << " ";
    }
    cout << endl;
}


int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {2, 5, 1, 6, 7, 8};

    unionOfSets(A, B);
    unionOfSets(B, A);

    intersection(A, B);
    intersection(B, A);

    setDifference(A, B);
    setDifference(B, A);

    return 0;
}