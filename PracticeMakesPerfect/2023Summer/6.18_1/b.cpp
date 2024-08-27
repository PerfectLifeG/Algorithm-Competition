#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    string a,b;
    cin>>a>>b;
    int la=a.size(),lb=b.size();
    int ans=0;
    char aa=a[0],bb=b[0];
    if(la==lb){
        ans+=bb-aa;
        for(int i=1;i<la;i++){
            if(abs(bb-aa)>=1){
                if(a[i-1]!=aa&&b[i-1]!=bb){
                    if(a[i]=='0'){
                        aa='9';
                        bb='0';
                    }
                    else{
                        aa='0';
                        bb='9';
                    }
                    ans+=9;
                }else{
                    aa='9';
                    bb='0'; 
                    ans+=9;
                }
            }else{
                aa=a[i];
                bb=b[i];
                ans+=bb-aa;
            }
        }
        cout<<ans<<endl;
        return;
    }
    if(la>lb){
        int t=0;
        for(int i=0;i<la-lb;i++){
            ans+=a[i]-'0';
            t+=9;
        }
        ans=max(ans,t-9+a[0]-'0'-1);
        ans+=9*(lb);
        cout<<ans<<endl;
        return;
    }
    else if(la<lb){
        int t=0;
        for(int i=0;i<lb-la;i++){
            ans+=b[i]-'0';
            t+=9;
        }
        ans=max(ans,t-9+b[0]-'0'-1);
        ans+=9*(la);
        cout<<ans<<endl;
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}