#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
struct Hash{
    #define ll unsigned long long
    const int P=131;
    string s;
    ll h[N]={},p[N]={};
    Hash(string t){
        s=' '+t;
        init();
    }
    void init(){
        p[0]=1;
        for(int i=1;i<s.size();i++){
            p[i]=p[i-1]*P;
            h[i]=h[i-1]*P+s[i];
        }
    }
    ll get(int l,int r){
        ll res=h[r]-h[l-1]*p[r-l+1];
        return res;
    }
};
void solve(){
    int n,m,q;cin>>n>>m>>q;
    string s1,s2;cin>>s1>>s2;
    Hash hs1(s1);
    Hash hs2(s2);
    while(q--){
        int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
        int len=r1-l1+1;
        int l=0,r=len+1;
        while(l+1!=r){
            int mid=l+r>>1;
            if(hs1.get(l1,l1+mid-1)!=hs2.get(l2,l2+mid-1)){
                r=mid;
            }else l=mid;
        }
        // cout<<l<<endl;
        l1--,l2--;
        if(l==0){
            if(s1[l1]>s2[l2]){
                cout<<">\n";
            }
            if(s1[l1]==s2[l2]){
                cout<<"=\n";
            }
            if(s1[l1]<s2[l2]){
                cout<<"<\n";
            }
            continue;
        }
        if(l==len){
            cout<<"=\n";
            continue;
        }
        if(s1[l1+l]>s2[l2+l]){
            cout<<">\n";
        }
        if(s1[l1+l]==s2[l2+l]){
            cout<<"=\n";
        }
        if(s1[l1+l]<s2[l2+l]){
            cout<<"<\n";
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}