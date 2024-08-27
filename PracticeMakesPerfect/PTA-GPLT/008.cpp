#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int len=s.size();
    int ans=1;
    for (int i = 0; i < len-1; i++)
    {
        int pos=len-1;
        while(s.rfind(s[i],pos)!=-1&&s.rfind(s[i],pos)!=i){
            int flag=s.rfind(s[i],pos);
            if((flag-i+1)%2!=0)
            {
                string t(s,i,(flag+i+1)/2-i+1);
                string tt(s,(flag+i+1)/2,(flag+i+1)/2-i+1);
                reverse(t.begin(),t.end());
                if(t==tt)ans=max(ans,flag-i+1);
            }
            else {
                string t(s,i,(flag+i+1)/2-i);
                string tt(s,(flag+i+1)/2,(flag+i+1)/2-i);
                reverse(t.begin(),t.end());
                if(t==tt)ans=max(ans,flag-i+1);
            }
            pos=flag-1;
        }
    }
    cout<<ans;
    return 0;
}