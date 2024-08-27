#include<bits/stdc++.h>
using namespace std;
const int N=100010;
// string get(int a){
//     int cnt=0;
//     string s="";
//     while(a){
//         cnt++;
//         a/=10;
//     }
//     return cnt;
// }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int cnt=0;
    set<string>st;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        // cout<<s<<endl;
        if(s=="0"||s[0]=='-'||s.size()%2!=0){
            continue;
        }
        int flag=1;
        int a=0;int b=0;
        for(int i=1;i<s.size()/2;i++){
            // if(!(s.size()&1)&&i==s.size()/2)break;
            if(s[i]>s[i-1]){
                flag=0;
                break;
            }
            a+=s[i-1]-'0';
        }
        a+=s[s.size()/2-1]-'0';
        if(!flag)continue;
        for(int i=s.size()/2;i+1<s.size();i++){
            if(s[i]>s[i+1]){
                flag=0;
                break;
            }
            b+=s[i]-'0';
        }
        b+=s[s.size()-1]-'0';
        // cout<<a<<' '<<b<<endl;
        if(flag&&((a&1)^(b&1))){
            cnt++;
            st.insert(s);
        }
    }
    cout<<cnt<<endl;
    cout<<(*(--st.end()))<<endl;
    return 0;
}