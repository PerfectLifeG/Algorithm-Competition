#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    vector<int>s(n+1);
    vector<int>ji(n+1);
    vector<PII>st,st2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]&1)ji[i]=1;
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+ji[i];
    }
    int lst=0;
    for(int i=1;i<=n;i++){
        if(a[i]&1&&lst){
            st.push_back({lst,i});
            lst=0;
        }else if(a[i]&1){
            lst=i;
        }
        else if(!lst&&a[i]%2==0){
            st.push_back({i,i});
        }
    }
    int lst2=1;
    while(a[lst2]%2==0&&lst2<=n){
        lst2++;
    }
    lst2++;
    lst=0;
    for(int i=lst2;i<=n;i++){
        if(a[i]&1&&lst){
            st2.push_back({lst,i});
            lst=0;
        }else if(a[i]&1){
            lst=i;
        }
        else if(!lst&&a[i]%2==0){
            st2.push_back({i,i});
        }
    }
    // for(auto i:st)cout<<i.first<<' '<<i.second<<'.'<<endl;
        
    // for(auto i:st2)cout<<i.first<<' '<<i.second<<endl;
    //     cout<<endl;
    while(q--){
        int a,b,c;cin>>a>>b>>c;
        if((s[b]-s[a-1])%2!=0){
            no;
            continue;
        }
        int l=-1,r=st.size();
        while(l+1!=r){
            int mid=l+r>>1;
            if(st[mid].first>a){
                r=mid;
            }else l=mid;
        }
        int t1=l;
        l=-1,r=st.size();
        while(l+1!=r){
            int mid=l+r>>1;
            if(st[mid].second>b){
                r=mid;
            }else l=mid;
        }
        int t2=l;

        // cout<<t1<<' '<<t2<<endl;

        if(t1>=0&&t2>=0&&t2-t1+1>=c&&st[t2].second==b&&st[t1].first==a){
            yes;
            continue;
        }


        l=-1,r=st2.size();
        while(l+1!=r){
            int mid=l+r>>1;
            if(st2[mid].first>a){
                r=mid;
            }else l=mid;
        }
        t1=l;
        l=-1,r=st2.size();
        while(l+1!=r){
            int mid=l+r>>1;
            if(st[mid].second>b){
                r=mid;
            }else l=mid;
        }
        t2=l;

        // cout<<t1<<' '<<t2<<endl;
        if(t1>=0&&t2>=0&&t2-t1+1>=c&&st2[t2].second==b&&st2[t1].first==a){
            yes;
        }else no;

        // auto t=st.upper_bound({a,a});
        // auto t2=prev(st.upper_bound({b,b}));
        // int l=distance(t,t2)+1;


        // if(t!=st.end()&&c<=l&&a==t->first&&b==t2->second){yes;continue;}
        // t=st2.lower_bound({a,a});
        // t2=prev(st2.upper_bound({b,b}));
        // l=distance(t,t2)+1;
        // if(t==st2.end()){
        //     continue;
        // }
        // if(t!=st2.end())yes;
        // else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}