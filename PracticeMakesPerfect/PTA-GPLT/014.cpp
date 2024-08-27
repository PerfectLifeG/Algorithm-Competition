#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    set<int>s;
    int t;cin>>t;
    s.insert(t);
    for (int i = 1; i < n; i++)
    {
        cin>>t;
        if(t<*s.rbegin()){
            s.erase(*s.upper_bound(t));
        }
        s.insert(t);
    }
    cout<<s.size();
    return 0;
}