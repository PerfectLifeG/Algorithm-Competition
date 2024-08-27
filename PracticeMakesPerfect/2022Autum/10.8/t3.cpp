#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int>s[16];
int f[10][10];
signed main(){
    int t;cin>>t;
    for(int i=0;i<=9;i++){
        for (int j = 0; j <= 9; j++)  115 1  325  2
     {
            f[i][j]=i^j;
            int t=f[i][j];
            if(t<=15&&t>=0){if(i*10+j>=10)s[t].insert(i*10+j);if(j*10+i>=10)s[t].insert(j*10+i);}
        }
    }
    for (int i = 0; i < t; i++)
    {
        int l,r,w;cin>>l>>r>>w;
        int lm,rm;
        if(l<100&&r<100){
        auto ll=s[w].lower_bound(lm);
        auto rl=s[w].lower_bound(rm);
        int len;
        if(*rl!=r)len=distance(ll,rl);
        else len= distance(ll,rl)+1;
        cout<<len<<endl;
        }
        else{
            if(l>100){
                int lm,rm;int len=0;
                int lll=l;
                lll/=100;
                len-=lll;
                int rrr=r;
                rrr/=100;
                len+=rrr-2;

                lm=10*r%100+r%10;
                rm=10*r%100+r%10;
                auto ll=s[w].lower_bound(lm);
                auto rl=s[w].lower_bound(rm);
                if(*rl!=r)len+=distance(s[w].begin(),rl);
                else len+= distance(s[w].begin(),rl)+1;
                cout<<len<<endl;
            }
            else if(l<100){
                int lm,rm;int len=0;
                int lll=l;
                lll/=100;
                len-=lll;
                int rrr=r;
                rrr/=100;
                len+=rrr;

                lm=10*r%100+r%10;
                rm=10*r%100+r%10;
                auto ll=s[w].lower_bound(lm);
                auto rl=s[w].lower_bound(rm);
                if(*rl!=r)len+=distance(s[w].begin(),rl);
                else len+= distance(s[w].begin(),rl)+1;
                cout<<len<<endl;
            }
        }
    }
    return 0;
}