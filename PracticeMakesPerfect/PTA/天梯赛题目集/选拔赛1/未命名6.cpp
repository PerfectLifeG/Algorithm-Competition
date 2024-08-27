#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int N=2e5+10;
typedef pair<int,int> PII;
char buf[1 << 21], *p1 = buf, *p2 = buf, obuf[1 << 21], *o = obuf, of[35];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
 
inline int read()
{
  int s = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) s = s * 10 + c - '0';
  return s * f;
}

void solve(){
    int n,q;
    n=read();q=read();
    vector<int>v;
    vector<pair<int,int>>p;
    vector<pair<int,int>>tmp;
    for(int i=0;i<n;i++){
        int a,b;
        a=read();b=read();
        p.push_back({a,b});
        v.push_back(a);v.push_back(b);
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    unordered_map<int,int>mp;
    for(int i=0;i<v.size();i++){
        mp[v[i]]=i;
    }

    vector<int>book((int)v.size());
    for(int i=0;i<n;i++){
        book[p[i].y]
        tmp.push_back({mp[p[i].x],mp[p[i].y]});
    }
    sort(tmp.begin(),tmp.end());
    vector<PII>p2;
    for(int i=0,j=1;i<n;){
        while(j<n&&tmp[i].x==tmp[j].x)j++;
        i=j-1;
        p2.push_back(tmp[i]);
        while(j<n&&tmp[j].y<=tmp[i].y)j++;
        i=j;
    }

    // vector<int>dp((int)v.size());
    // for(int i=0;i<dp.size();i++)dp[i]=i;
    // for(int i=0,l=0;i<p2.size();i++){
    //     l=max(l,p2[i].x);
    //     while(l<=p2[i].y)dp[l]=p2[i].x,l++;
    // }

    vector<int>s((int)v.size());
    vector<int>s2((int)v.size());
    for(auto [l,r]:tmp){
        s[r]++;
        s2[l]++,s2[r]--;
    }
    for(int i=1;i<s.size();i++)s[i]+=s[i-1],s2[i]+=s2[i-1];
    // for(int i=1;i<s.size();i++)if(dp[i]>=1)s[i]+=s[dp[i]-1];
    // for(int i=1;i<s.size();i++)s[i]=max(s[i],s[i-1]);
    // for(int i=0;i<s.size();i++)cout<<i<<' '<<s[i]<<endl;cout<<endl;
    // for(int i=0;i<s.size();i++)cout<<i<<' '<<s2[i]<<endl;

    while(q--){
        int l,r;
        l=read();r=read();
        // cin>>l>>r;
        l=lower_bound(v.begin(),v.end(),l)-v.begin();
        r=lower_bound(v.begin(),v.end(),r)-v.begin();
        // cout<<l<<' '<<r<<endl;
        if(r==v.size())r--;
        if(l==v.size()){
            cout<<0<<endl;
            continue;
        }
        if(l==0)printf("%lld\n",s[r]+s2[r]);
        else printf("%lld\n",s[r]-s[l-1]+s2[r]);
    }

}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
}
