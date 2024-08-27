#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1000010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int tr[N][26],cnt[N];int idx;
void insert(string &s){
    int t=0;
    for(int i=0;i<s.size();i++){
        int j=s[i]-'a';
        if(!tr[t][j])tr[t][j]=++idx;
        cnt[tr[t][j]]++;
        // cout<<t<<' '<<j<<' '<<idx<<' '<<cnt[idx]<<endl;
        t=tr[t][j];
    }
}
void query(){
    int t=0;
    string ans="";
    while(1){
        int flag=1;
        for(int j=25;j>=0;j--){
            // cout<<t<<' '<<j<<' '<<tr[t][j]<<' '<<cnt[tr[t][j]]<<endl;
            if(tr[t][j]&&cnt[tr[t][j]]>=2){
                t=tr[t][j];
                ans+='a'+j;
                flag=0;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    // if(ans=="")cout<<"EMPTY"<<endl;
    // else cout<<ans<<endl;
}
void solve(){
    int n,k;cin>>n>>k;
    vector<string>v;
    vector<int>book(26);
    for(int i=0;i<n;i++){
        string a;cin>>a;
        book[a[0]-'a']++;
        v.push_back(a);
    }
    sort(all(v));
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    for(int i=0;i<=idx;i++){
        cnt[i]=0;
        for(int j=0;j<26;j++)
        tr[i][j]=0;
    }
    idx=0;
    int t=0;
    for(int i=0;i<n;){
        int j=i+1;
        while(j<n&&v[i][0]==v[j][0]){
            j++;
        }
        insert(v[i]);
        book[v[i][0]-'a']--;
        t++;
        if(t==k)break;
        i=j;
    }
    for(int i=0;i<n;i++){
        if(t==k)break;
        if(book[v[i][0]-'a']&&v[i].size()&&v[i][0]){
            lt
            ltw
            ltaf
            ltaff
            ltax
            ltaxxx
            ltaz
            insert(v[i]);
            t++;
        }
    }
    query();
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}