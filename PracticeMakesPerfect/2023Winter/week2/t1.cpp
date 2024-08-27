#include<bits/stdc++.h>
using namespace std;
typedef pair<char,char> PCC;
unordered_map<char,PCC>mp1;
unordered_map<char,PCC>mp2;
int main(){
    int n;cin>>n;
    char a1[11],a2[11];
    for(int i=0;i<n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        a1[i]=a;
        mp1[a]={b,c};
    }
    for(int i=0;i<n;i++){
        char a='-',b='-';
        if(mp1[a1[i]].first!='-')a=a1[mp1[a1[i]].first-'0'];
        if(mp1[a1[i]].second!='-')b=a1[mp1[a1[i]].second-'0'];
        mp1[a1[i]]={a,b};
    }
    int m;cin>>m;if(m!=n){cout<<"No";return 0;}
    for(int i=0;i<n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        a2[i]=a;
        mp2[a]={b,c};
    }
    int flag=1;
    for(int i=0;i<n;i++){
        char a='-',b='-';
        if(mp2[a2[i]].first!='-')a=a2[mp2[a2[i]].first-'0'];
        if(mp2[a2[i]].second!='-')b=a2[mp2[a2[i]].second-'0'];
        if(!(a==mp1[a2[i]].first&&b==mp1[a2[i]].second||a==mp1[a2[i]].second&&b==mp1[a2[i]].first)){
            flag=0;break;
        }
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
    return 0;
}