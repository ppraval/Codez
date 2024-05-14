#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,4};
    int k = 5;
    auto it1=nums.begin();
    auto it2=nums.end();

    sort(it1,it2);

    map<int,int> m;

    for(int i : nums){
        m[i]=m[i]+1;
    }
    auto i=m.begin();
    int max=(*i).second;
    for(auto it=m.begin();it!=m.end();it++){
        if((*it).second>max) max=(*it).second;
        else continue;
    }

    vector<int> v;

    for(auto it =m.begin();it!=m.end();it++){
        v.push_back((*it).first);
    }
    for(int i : v)
        cout << i << " ";
    cout << endl;
    /*for(auto it=m.begin();it!=m.end();it++){
        if((*it).second==max) v.push_back((*it).first);
        else continue;
    }*/
    int max1=max;
    for(int a : v){
        /*auto it =m.find(a);
        int count =(*it).second;*/
        int count=1;
        int l=k;
        multiset<int> ml;

        for(int b :nums){
            if(a>b){
                ml.insert(a-b);
            }
            else{
                continue;
            }
        }

        for(auto it =ml.begin();it!=ml.end();it++){            
            cout << (*it) << endl;
            if(it == ml.end())
            {
                cout << "pain" << endl;
            }
            if(l>=(*it)){
                l=l-(*it);
                count++;
                cout << "count = " << count << " it = " << (*it) << endl;                      
            }
            else{
                break;
            }
            
        }
        if(count>max1){
            max1=count;
        }
        else continue;
    }
    cout << max1 << endl;
    return max1;
}