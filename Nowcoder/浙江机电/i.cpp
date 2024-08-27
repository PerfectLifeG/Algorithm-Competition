#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    map<char,string>mp;
    mp['1']="壹";mp['2']="贰";mp['3']="叁";mp['4']="肆";mp['5']="伍";
    mp['6']="陆";mp['7']="柒";mp['8']="捌";mp['9']="玖";mp['0']="零";
    while(cin>>s){
        int pos=s.find('.');
        string ans;
        if(pos==-1){ans.append("整");pos=s.size();}
        if(s.substr(0,2)!="0.")ans.insert(0,"元");
        int cnt=1;
        for(int i=pos-1;i>=0;i--){
            if(i!=pos-1&&s[i]=='0'&&s[i+1]!='0'&&cnt!=5)ans.insert(0,"零");
            if(s[i]!='0'&&cnt==2)ans.insert(0,"拾");
            if(s[i]!='0'&&cnt==3)ans.insert(0,"佰");
            if(s[i]!='0'&&cnt==4)ans.insert(0,"仟");
            if(cnt==5)ans.insert(0,"万");
            if(s[i]!='0'&&cnt==6)ans.insert(0,"拾");
            if(s[i]!='0'&&cnt==7)ans.insert(0,"佰");
            if(s[i]!='0'&&cnt==8)ans.insert(0,"仟");
            if(s[i]!='0')ans.insert(0,mp[s[i]]); 
            cnt++;
        }
        if(s.find('.')!=-1){
            s.append("00");
            if(s[pos+1]!='0')ans.append(mp[s[pos+1]]+"角");
            else if(s[pos+2]!='0')ans.append(mp[s[pos+1]]);
            else ans.append("整");
            if(s[pos+2]!='0'){
                ans.append(mp[s[pos+2]]+"分");
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}