#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(69);
    v.push_back(84);
    v.push_back(45);
    v.push_back(32);
    v.push_back(6);
    v.pop_back();
    for(int i = 0; i < v.size(); i++)
        cout << "The vector values are " << v[i] << "\n";
    cout << "We gonna clear the vector now and you can't do anything about it hehe\n";
    v.clear();
    if(v.size() == 0)
    {
        cout << "MT";
    }

return 0;
}