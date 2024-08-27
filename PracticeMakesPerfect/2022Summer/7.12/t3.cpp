#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int main()
{
    int t;cin>>t;
    for (int k = 0; k < t; k++)
    {
        int n;cin>>n;
        ll sum=0;ll max=1;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        max=a[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            if(a[i]%2==0){
                sum++;
                max*=a[i];
            }else{
                if(a[i]>max){
                    ll t=a[i];
                    a[i]=max;
                    max=t;
                }
                sum+=a[i];
            }
        }
        sum+=max;
        cout<<sum<<endl;
    }
    return 0;
}