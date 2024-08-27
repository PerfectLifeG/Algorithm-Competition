#include<bits/stdc++.h>
using namespace std;
struct stu
{
    string name;
    int num;
    map<int,int>mp;
};
int cmp(stu s1,stu s2){
    if(s1.mp.size()==s2.mp.size())
    return s1.num<s2.num;
    else return s1.mp.size()>s2.mp.size();
}
int main(){
    int n;
    cin>>n;
    struct stu s[100];
    for (int i = 0; i < n; i++)
    {
        string a;cin>>a;s[i].name=a;
        int num;cin>>num;s[i].num=num;
        for (int j = 0; j < num; j++)
        {
            int a;cin>>a;
            s[i].mp[a]++;
        }
    }
    sort(s,s+n,cmp);int i = 0;
    if(s[i].mp.size()!=0)cout<<s[i].name;
        else printf("-");
    for (i=1; i < 3; i++)
    {
        if(s[i].mp.size()!=0)cout<<" "<<s[i].name;
        else printf(" -");
    }
    
    return 0;
}