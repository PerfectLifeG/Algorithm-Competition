#include<bits/stdc++.h>
using namespace std;
#define int long long
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
unordered_map<int,char>mp;
unordered_map<string,string>mp2;
int cal(string s,int l,int r){
    // cout<<s<<' '<<mp2[s]<<' '<<l<<' '<<r<<endl;
    s=mp2[s];
    int res=0;
    int a=1;
    for(int i=r;i>=l;i--){
        if(s[i]=='1')res+=a;
        a*=2;
    }
    // cout<<res<<endl;
    return res;
}
void solve(){
    unordered_map<char,int>mp01,mp00,mp10,mp0;
    for(int i=0;i<(1<<8);i++){
        if((i>>7&1)==0)mp0[mp[i/16]]++;
        if((i&1)==0&&(i>>1&1)==0)mp00[mp[i%16]]++;
        if((i&1)==1&&(i>>1&1)==0)mp01[mp[i%16]]++;
        if((i&1)==0&&(i>>1&1)==1)mp10[mp[i%16]]++;
        string t1;
        string t2;
        t2+=mp[i/16];t2+=mp[i%16];
        for(int j=7;j>=0;j--){
            if(i>>j&1)t1+='1';
            else t1+='0';
        }
        mp2[t2]=t1;
    }
    int n;cin>>n;
    int m=(n+7)/8;
    string s;
    string ans;
    while(m--){
        string t;cin>>t;
        s+=t;
    }
    int i=0;
    for(;i<s.size();i+=2){
        string t=s.substr(i,2);
        if(mp0.count(t[0])){i+=2;break;}
    }
    for(;i<s.size();){
        string t=s.substr(i,2);i+=2;
        if(mp00.count(t[1])){
            int l=cal(t,0,5);
            // cout<<i<<' '<<t<<' '<<l<<endl;
            if(l<=59){
                l+=1;
                ans+=s.substr(i,l*2);i+=l*2;
                // cout<<ans<<endl;
            }else{
                if(l==60){
                    l=cal(s.substr(i,2),0,7);i+=2;
                    l+=1;ans+=s.substr(i,l*2);i+=l*2;
                }else if(l==61){
                    l=cal(s.substr(i,2),0,7);i+=2;
                    l=l+cal(s.substr(i,2),0,7)*256;i+=2;
                    l+=1;ans+=s.substr(i,l*2);i+=l*2;
                }else if(l==62){
                    l=cal(s.substr(i,2),0,7);i+=2;
                    int e=256;
                    l=l+cal(s.substr(i,2),0,7)*e;e*=256;i+=2;
                    l=l+cal(s.substr(i,2),0,7)*e;e*=256;i+=2;
                    l+=1;ans+=s.substr(i,l*2);i+=l*2;
                }else{
                    l=cal(s.substr(i,2),0,7);i+=2;
                    int e=256;
                    l=l+cal(s.substr(i,2),0,7)*e;e*=256;i+=2;
                    l=l+cal(s.substr(i,2),0,7)*e;e*=256;i+=2;
                    l=l+cal(s.substr(i,2),0,7)*e;e*=256;i+=2;
                    l+=1;ans+=s.substr(i,l*2);i+=l*2;
                }
            }
        }else {
            int o,l;
            if(mp01.count(t[1])){
                o=cal(t,0,2);
                l=cal(t,3,5);l+=4;
                o=o*256+cal(s.substr(i,2),0,7);i+=2;
                // cout<<"01 "<<l<<' '<<o<<endl;
            }else if(mp10.count(t[1])){
                l=cal(t,0,5);l+=1;
                o=cal(s.substr(i,2),0,7);i+=2;
                o=o+cal(s.substr(i,2),0,7)*256;i+=2;
                // cout<<"10 "<<l<<' '<<o<<endl;
            }
            if(o>=l){
                ans+=ans.substr(ans.size()-o*2,l*2);
            }else{
                string t=ans.substr(ans.size()-o*2,o*2);
                string t2=ans.substr(ans.size()-o*2,l%o*2);
                int cnt=l/o;
                for(int k=0;k<cnt;k++)ans+=t;ans+=t2;
            }
        }
        // cout<<i<<' '<<t<<endl;
        // cout<<ans<<endl;
    }
    for(int i=0;i<ans.size();i++){
        if(i!=0&&i%16==0)cout<<endl;
        cout<<ans[i];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    mp[0]='0';mp[1]='1';mp[2]='2';mp[3]='3';
    mp[4]='4';mp[5]='5';mp[6]='6';mp[7]='7';
    mp[8]='8';mp[9]='9';mp[10]='a';mp[11]='b';
    mp[12]='c';mp[13]='d';mp[14]='e';mp[15]='f';
    while(_--)solve();
    return 0;
}