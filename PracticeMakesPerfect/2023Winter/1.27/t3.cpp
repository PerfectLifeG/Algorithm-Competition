#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int book[105];
string ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        memset(book,0,sizeof book);
        int n;cin>>n;
        string s,str;
        getline(cin,s);
        getline(cin,s);
        book[s[0]-'0']++;
        char c='_';
        for(int i=0;i<n-1;i++){
            getline(cin,str);
            if(s[0]!=str[0])ans=str;
            if(c!='_')continue;
            book[str[0]-'0']++;
            if(book[str[0]-'0']>1)c=str[0];
        }
        cout<<c<<' ';
        if(ans[0]!=c)cout<<ans<<endl;
        else cout<<s<<endl;
    }
    return 0;
}