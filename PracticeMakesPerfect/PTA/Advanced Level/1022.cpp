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
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    unordered_map<string,set<int>>mp[6];
    for(int i=0;i<n;i++){
        int id;cin>>id;
        string name;string author;
        getline(cin,name);
        getline(cin,name);
        getline(cin,author);
        mp[1][name].insert(id);
        mp[2][author].insert(id);
        string key;
        while(cin>>key){
            mp[3][key].insert(id);
            char c=getchar();
            if(c=='\n')break;
        }
        string pub;
        getline(cin,pub);
        mp[4][pub].insert(id);
        string y;
        getline(cin,y);
        mp[5][y].insert(id);
    }
    int m;cin>>m;
    while(m--){
        int id;
        scanf("%d: ",&id);
        string t;
        getline(cin,t);
        cout<<id<<": "<<t<<endl;
        if(!mp[id].count(t)){
            cout<<"Not Found\n";
            continue;
        }
        for(auto i:mp[id][t]){
            printf("%07d\n",i);
        }
    }
}
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}