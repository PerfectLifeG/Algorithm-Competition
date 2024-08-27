#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int s=0;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        s+=a;
    }
    int sta=n*(1+n)/2;
    int cnt=s-sta;
    if(cnt%2==0){
        cout<<"ZZZ";
    }else cout<<"SSZ";
    return 0;
}