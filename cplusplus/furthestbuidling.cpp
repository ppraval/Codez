#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> h = {4,2,7,6,9,14,12};
    int b = 5;
    int l = 1;
    priority_queue<int> p;  
    int i, diff = 0; 
    for(i = 0; i < h.size() - 1; i++)
    { 
        
        diff = h[i + 1] - h[i];
        
        if(diff <= 0)
        {
            continue;
        }

        b -= diff; 
        p.push(diff); 
    
        if(b < 0)
        {
            b += p.top(); 
            p.pop(); 
            l--;
        }
        if(l < 0) 
            break;
    }
    cout << i << endl;
    return i;
}