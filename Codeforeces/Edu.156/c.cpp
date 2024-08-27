#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    string s;cin>>s;
    s=' '+s;
    int n=s.size()-1;
    stack<pair<char,int>>st;
    vector<int>v;
    int now=1;
    int l=2;
    st.push({s[1],1});
    while(st.size()){
        while(l<=n&&s[l-1]<=s[l]){
            st.push({s[l],l});
            l++;
        }
        while(st.size()&&(l==n+1||st.top().x>s[l])){v.push_back(st.top().y);st.pop();}
        if(l<=n){
            st.push({s[l],l});
            l++;
        }
    }
    int q;cin>>q;
    l=0;int r=n+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if((n+mid)*(n-mid+1)/2>=q){
            l=mid;
        }else r=mid;
    }
    vector<int>book(n+1);
    for(int i=0;i<n-l;i++){
        book[v[i]]=1;
    }
    int t=1;
    q=q-(n-l)*(n+l+1)/2;
    for(int i=1;i<=n;i++){
        if(book[i])continue;
        if(t==q){cout<<s[i];return;}
        else t++;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}