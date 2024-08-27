#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a;ll b;
    cin>>a>>b;
    ll i=1;
    ll s;
    ll aa=a;
    int cnt=0;
    while(aa){
        aa/=2;
        cnt++;
    }
    for (int k = 0; k < cnt; k++)
    {
        if(a&i == b&i){
            s+=i;
            if(s>pow(2,63)){
                cout<<s-i;
                return 0;}
        }
        i*=2;   
    }
    cout<<s;
    return 0;
}