#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    int n=0;
    vector<PII>v1,v2;
    map<int,int>mp1,mp2;
    while(T--){
            n++;
        int cnt=0;
        for(int i=n;i>=1;i--)
        {
            if(n&1)
            {
                for(int j=i;j>=1;j-=2)
                {
                    int q=j;
                    while(q%5==0){
                        cnt++;
                        q/=5;
                    }
                }
            }else{
                for(int j=i;j>=2;j-=2)
                {
                    int q=j;
                    while(q%5==0){
                        cnt++;
                        q/=5;
                    }
                }
            }
        }
        if(n&1)v1.push_back({n,cnt});
        else v2.push_back({n,cnt});
    }


    vector<int>mp3;
    int sum=0;
    for(int i=1;i<v1.size();i++){
        mp1[v1[i].second-v1[i-1].second]++;
    }
    for(int i=1;i<v2.size();i++){
        mp2[v2[i].second-v2[i-1].second]++;
    }
    // for(auto i:mp1)cout<<i.first<<' '<<i.second<<endl;
    //     cout<<endl;
    // for(auto i:mp2)cout<<i.first<<' '<<i.second<<endl;
    int cnt=0;
    for(auto i:mp1){cout<<i.first<<' ';cnt++;
        sum+=i.first*i.second;
        if(cnt==5){
            cout<<endl,cnt=0;
        }
        mp3.push_back(sum);
    }
    for(auto i:mp1){cout<<i.second<<' ';cnt++;
        if(cnt==5)cout<<endl,cnt=0;
    }
    for(auto i:mp3){cout<<i<<' ';cnt++;
        if(cnt==5)cout<<endl,cnt=0;
    }
}