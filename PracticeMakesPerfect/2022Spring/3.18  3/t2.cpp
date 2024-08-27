#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    int n;int cnt=0;int flag=1;ll s=0;
    cin>>n;
    map<pair<ll,ll>,map<ll,ll>>mp;
    for (int i = 0; i < n; i++)
    {
        ll x,y,num;
        scanf("%lld %lld %lld",&x,&y,&num);
        s+=num;
        int t=abs(__gcd(x,y));
        int d=x*x+y*y;
        x/=t;
        y/=t;
        mp[{x,y}].insert({d,num});
    }
    map<pair<ll,ll>,map<ll,ll>>::iterator it=mp.begin();
    for ( ; it!=mp.end(); it++)
    {
        map<ll,ll>::iterator itt=it->second.begin();
        for (;itt!=it->second.end(); itt++)
        {
            if(itt->second==1){
                while (1)
                {
                if(flag){cnt++;flag=0;}
                itt++;
                if(itt->second!=1)break;
                }
            }
            cnt++;
            flag =1;
        }
    }
    cout<<s<<" "<<cnt;
    return 0;
}