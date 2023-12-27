 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
    int t;
    cin >> t;
    int count = 0;
    while(t > 0)
    {
        int p, q;
        cin >> p >> q;
        if(q - p >= 2)
            count++;
        t--;
    }
    cout << count;
    return 0;
 }