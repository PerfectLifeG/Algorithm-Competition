#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='5'){
            i--;
            while(i>=0&&s[i+1]>='5'){
                s[i]++;
                i--;
            }
            if(s[0]>='5'){
                cout<<1<<string((int)s.size(),'0')<<endl;
                return;
            }else{
                if(i==-1){
                    cout<<s[0]<<string((int)s.size()-1,'0')<<endl;
                    return;
                }
                int j=0;
                i++;
                while(j<=i){
                    cout<<s[j];
                    j++;
                }
                cout<<string((int)s.size()-i-1,'0')<<endl;
                return;
            }
        }
    }
    cout<<s<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}