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
    int n;cin>>n;
    vector<int>a(n);
    multiset<int>st,st2;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    auto del=[&](int x){
        auto it=st.find(x);
        auto l=prev(it);
        auto r=next(it);
        if(it!=st.begin()){
            st2.extract(x-*l);
        }
        if(r!=st.end()){
            st2.extract(*r-x);
        }
        if(it!=st.begin()&&r!=st.end()){
            st2.insert(*r-*l);
        }
        st.erase(it);
    };
    auto add=[&](int x){
        auto it=st.insert(x);
        auto l=prev(it);
        auto r=next(it);
        if(it!=st.begin()){
            st2.insert(x-*l);
        }
        if(r!=st.end()){
            st2.insert(*r-x);
        }
        if(it!=st.begin()&&r!=st.end()){
            st2.extract(*r-*l);
        }
    };
    for(int i=0;i<n;i++)add(a[i]);
    int q;cin>>q;
    while(q--){
        int c,d;cin>>c>>d;
        c--;
        del(a[c]);
        a[c]=d;
        add(d);
        if(!st2.size())cout<<*st.rbegin()<<' ';
        else cout<<*st.rbegin()+*st2.rbegin()<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}