#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int a;
    vector<int>v;
    while(cin>>a){
        v.push_back(a);
    }
    int b=v[v.size()-2],rr=v[v.size()-1];
    v.erase(v.end()-1);
    v.erase(v.end()-1);
    sort(all(v));
    int l=-1,r=v.size();
    while(l+1!=r){
        int mid=l+r>>1;
        if(v[mid]>b+rr){
            r=mid;
        }else l=mid;
    }   
    int ar,al;
    ar=l;
    l=-1,r=v.size();
    while(l+1!=r){
        int mid=l+r>>1;
        if(v[mid]>=b-rr){
            r=mid;
        }else l=mid;
    }
    al=r;
    if(al==-1){
        cout<<endl;
        return;
    }
    for(int i=ar;i>=al;i--){
        cout<<v[i]<<' ';
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}