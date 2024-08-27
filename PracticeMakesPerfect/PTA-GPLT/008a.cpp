#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	string cnt="#";
	int len=s.size();
	for(int i=0;i<len;i++)	cnt+=s[i],cnt+='#';
	len=cnt.size();
	int ans=1;
	for(int i=0;i<len;i++)
	{
		int tmp=0;
		if(cnt[i]!='#')	tmp++;
		for(int j=i-1,l=i+1;j>=0&&l<len;j--,l++)
			if(cnt[j]==cnt[l])
			{	if(cnt[j]!='#')	tmp+=2;}
			else	break;
		ans=max(ans,tmp);
	}
	cout<<ans;
}	
