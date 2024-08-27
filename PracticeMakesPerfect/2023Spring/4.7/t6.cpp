#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000010;
int q[N];
int hh=1,tt;
int n,m,k;
unordered_map<int,int>mp;
unordered_map<int,int>mp2;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    scanf("%lld%lld%lld",&n,&m,&k);
    set<int>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        int op;int x;scanf("%lld",&op);
        if(op==1){
            scanf("%lld",&x);
            if(tt-hh+1<m){
                q[++tt]=x;
                if(!mp2[x])mp2[x]=tt;
                mp[x]++;
                s.insert(x);
            }else{
                while(hh<=tt&&q[hh]<=k){
                    mp[q[hh]]--;
                    if(mp[q[hh]]==0){mp2[q[hh]]=0;s.erase(q[hh]);}
                    hh++;
                    cnt++;
                }
                if(tt-hh+1<m){
                    q[++tt]=x;
                    if(!mp2[x])mp2[x]=tt;
                    mp[x]++;
                    s.insert(x);
                }
            }
        }else if(op==2){
        	if(tt-hh+1)
            printf("%lld %lld\n",tt-hh+1,mp2[*--s.end()]-cnt);
        	else printf("0 0\n");
        }else{
            if(hh<=tt){
                printf("%lld\n",q[tt]);
                mp[q[tt]]--;
                if(mp[q[tt]]==0){mp2[q[tt]]=0;s.erase(q[tt]);}
                tt--;
            }
        }
    }
    return 0;
}