#include<bits/stdc++.h>
using namespace std;
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
unordered_map<int,int>mp1;
unordered_map<int,int>mp2;
void solve(){
    int st,n;cin>>st>>n;
    for(int i=0;i<n;i++){
        int a,val,b;
        cin>>a>>val>>b;
        mp1[a]=val;
        mp2[a]=b;
    }
    unordered_map<int,int>book;
    vector<int>ans1;
    vector<int>ans2;
    while(st!=-1){
        if(book[abs(mp1[st])]){
            ans2.push_back(st);
            st=mp2[st];
            continue;
        }
        book[abs(mp1[st])]=1;
        ans1.push_back(st);
        st=mp2[st];
    }
    for(int i=0;i<ans1.size();i++){
        if(i==ans1.size()-1){
            printf("%05d %d -1\n",ans1[i],mp1[ans1[i]]);
        }else printf("%05d %d %05d\n",ans1[i],mp1[ans1[i]],ans1[i+1]);
    }
    for(int i=0;i<ans2.size();i++){
        if(i==ans2.size()-1){
            printf("%05d %d -1\n",ans2[i],mp1[ans2[i]]);
        }else printf("%05d %d %05d\n",ans2[i],mp1[ans2[i]],ans2[i+1]);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}