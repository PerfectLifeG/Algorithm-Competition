#include<bits/stdc++.h>
using namespace std;
#define int long long 
set<int>s;
signed main(){
    int n;scanf("%lld",&n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        for(int j=2;j*j<=a;j++){
            if(a%j==0)
            {
                s.insert(j);
                while(a%j==0)a/=j;
            }
        }
        if(a!=1)s.insert(a);
    }
    int flag=1;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        for(int j=2;j*j<=a;j++){
            if(a%j==0){
                if(s.count(j)){flag=0;break;}
                while(a%j==0)a/=j;
            }
        }
        if(a!=1&&s.count(a)){flag=0;break;}
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
    return 0;
}