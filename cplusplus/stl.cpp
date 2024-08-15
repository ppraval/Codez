#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
        cout << v.back() << " ";
    }
    
    cout << endl;
    pair<int, int> p;
    p.first = 1;
    p.second = 2;
    cout << p.first << "~" << p.second << endl;
    cout << "We have a stack now" << endl;
    stack<int> s;
    for(int i : v)
    {
        s.push(i);
    }
    s.pop();
    cout << s.top() << " "; 
    cout << endl << "We now move to queues" << endl;

    queue<int> q;
    vector<int> v1 = {2,4,5,1,5,12,6,3};
    for(int i : v1)
    {
        q.push(i);
        cout << q.front() << " ";  
        q.pop();
    }
    cout << endl << "Pq now" << endl;
    priority_queue<int> q1;
    for(int i : v1)
    {
        q1.push(i);
    }
    cout << q1.top() << endl;
    while(!q1.empty())
    {
        cout << q1.top() << " ";  
        q1.pop();
    }
    cout << endl << "We use sets now" << endl;
    unordered_set<int> s1;
    for(int i : v1)
        s1.insert(i);
    for(auto x : s1)
    {
        cout << x << " ";
    }
    cout << endl << "MAPS" << endl;
    unordered_map<int, int> mp;
    for(int i = 0; i < v1.size(); i++)
    {
        mp[v1[i]] = v.size() - i - 1;
    }
    for(auto x : mp)
    {
        cout << x.first << "~" << x.second << " ";
    }
    cout << endl;
    string t = "I love her";
    unordered_map<char, string> mpp;
    for(int i = 0; i < t.length(); i++)
    {
        mpp[t[i]] = "Pain";
    }
    for(auto x : mpp)
    {
        cout << x.first << "~" << x.second << " ";
    }

    cout << endl;

    vector<vector<int>> vv = {
        {1,2,3},
        {11,21,31},
        {12,22,32}
    };
    for(auto x : vv)
    {
        for(int i : x)
            cout << i << " ";
        cout << endl;
    }
    cout << "First element of v1 = " << *(v1.begin()) << endl;
    cout << "We have the unnsorted vector v1 = ";
    for(int i : v1) 
        cout << i << " ";
    cout << endl;
    cout << "Let's sort it = "; 
    sort(v1.begin(), v1.end());
    for(int i : v1)
        cout << i << " ";
    cout << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr)
        cin >> i;
    for(int i : arr)
        cout << i << " ";
    cout << endl;
    cout << "sum of elements in arr =  " << accumulate(arr.begin(), arr.end(), 0) << endl;
    cout << "The max element in arr = " << *max_element(arr.begin(), arr.end()) << endl;
    cout << "We sort a list which is not a vector ";
    int list[5] = {1,2,3,4,5};
    sort(list, list + 5, greater<int>());
    for(int i  = 0; i < 5; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    cout << "sum of elements in list =  " << accumulate(list, list + 5, 0) << endl;
    cout << endl;
    return 0;
}
