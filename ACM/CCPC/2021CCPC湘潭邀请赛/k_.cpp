#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int k;
  int i,j;cin>>k>>s;
  // while(cin>>k>>s)
  // {
    map<char,int>mp;
    int ans=0;
    j=0;
    for(i=0;i<s.size();i++)
    {
      j=max(j,i);
      while(j<s.size()&&mp[s[j]]<k)
      {
        mp[s[j]]++;
        j++;
      }
      ans=max(ans,j-i);
      // if(ans==15){cout<<i<<endl;ans++;}
      mp[s[i]]--;
    }
    printf("%d\n",ans);
  // }
}