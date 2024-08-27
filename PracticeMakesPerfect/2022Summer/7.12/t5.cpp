#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int main()
{
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {
        string a,b;
        cin>>a>>b;
        if(b=="a")
        cout<<1<<endl;
        else if(b.find('a')!=-1){
            cout<<-1<<endl;
        }else {
            ll ans=pow(2,a.size());
            cout<<ans<<endl;
        }
        
    }
    return 0;
}