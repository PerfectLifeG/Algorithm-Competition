#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
// char a[N];
string s;
// int f[N][2];
int a[8];
void jian(int &x,int y)
{
    x=((x-y)%mod+mod)%mod;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    cin>>s;
    s=' '+s+' ';
    for(int i=1;i<=n;i++){
    	if(s[i]<='Z'&&s[i]>='A'){
    		int j=i-1;
    		int cnt=0;
			while(j>=1&&s[j]-'a'+'A'==s[i]){
				cnt++;
				j--;
			}
			for(int j=i-2;j>=1&&i-j<=cnt;j-=2){
				s[j]=s[j]-'a'+'A';
			}
		}
		if(s[i]<='Z'&&s[i]>='A'){
    		int j=i+1;
    		int cnt=0;
			while(j<=n&&s[j]-'a'+'A'==s[i]){
				cnt++;
				j++;
			}
			for(int j=i+2;j<=n&&j-i<=cnt;j+=2){
				s[j]=s[j]-'a'+'A';
			}
		}
	}
//	cout<<s<<endl;
    for(int i=1;i<=7;i++) a[i]=1;
    for(int i=1;i<=n;i++)//??
    {
        if(s[i]=='?')
        {
            if(i-1>=1&&i+1<=n)
            {
                a[1]=a[1]*8%mod;
            }else{
                a[1]=a[1]*9%mod;
            }
        }else if(s[i]<='9'&&s[i]>='0'){
            continue;
        }else{
            a[1]=0;
            break;
        }
    }
    // cout<<a[1]<<'\n';
    for(int i=1;i<=n;i++)//??
    {
        if(s[i]=='?')
        {
            if(i-1>=1&&i+1<=n)
            {
            	char t1=s[i-1];
            	char t2=s[i+1];
            	if(t1>='a'&&t1<='z') t1=t1-'a'+'A';
				 if(t2>='a'&&t2<='z') t2=t2-'a'+'A';
				 if(t1==t2){
				 	a[2]=a[2]*25%mod;
				 }else 
                a[2]=a[2]*24%mod;
                
            }else{
                a[2]=a[2]*25%mod;
            }
        }else if(s[i]<='9'&&s[i]>='0'){
            a[2]=0;
            break;
        }else{
            if(s[i]-'a'+'A'==s[i-1]||s[i]-'a'+'A'==s[i+1])
            {
                a[2]=0;
                break;
            }
            continue;
        }
    }
    for(int i=1;i<=n;i++)//??
    {
        if(s[i]=='?')
        {
            if(i-1>=1&&i+1<=n)
            {
//                a[3]=a[3]*24%mod;
                char t1=s[i-1];
            	char t2=s[i+1];
//            	if(t1>='a'&&t1<='z') t1=t1-'a'+'A';
//				 if(t2>='a'&&t2<='z') t2=t2-'a'+'A';
				 if(t1==t2){
				 	a[2]=a[2]*25%mod;
				 }else 
                a[2]=a[2]*24%mod;
                
            }else{
                a[3]=a[3]*25%mod;
            }
        }else if(s[i]<='9'&&s[i]>='0'){
            a[3]=0;
            break;
        }else if(s[i]>='A'&&s[i]<='Z'){
            a[3]=0;
            break;
        }else{
            continue;
        }
    }
    for(int i=1;i<=n;i++)//??+??
    {
        if(s[i]=='?')
        {
            if(i-1>=1&&i+1<=n)
            {
            	 char t1=s[i-1];
            	char t2=s[i+1];
            	if(t1==t2){
            		a[4]=a[4]*35%mod;
				}else
                a[4]=a[4]*34%mod;
            }else{
                a[4]=a[4]*35%mod;
            }
        }else if(s[i]<='9'&&s[i]>='0'){
            continue;
        }else if(s[i]>='A'&&s[i]<='Z'){
            a[4]=0;
            break;
        }else{
            continue;
        }
    }
    for(int i=1;i<=n;i++)//??+??
    {
        if(s[i]=='?')
        {
            if(i-1>=1&&i+1<=n)
            {
            	char t1=s[i-1];
            	char t2=s[i+1];
            	if(t1>='a'&&t1<='z') t1=t1-'a'+'A';
				 if(t2>='a'&&t2<='z') t2=t2-'a'+'A';
            	if(t1==t2){
            		a[5]=a[5]*35%mod;
				}else
                a[5]=a[5]*34%mod;
            }else{
                a[5]=a[5]*35%mod;
            }
            
        }else if(s[i]<='9'&&s[i]>='0'){
            continue;
        }else if(s[i]>='A'&&s[i]<='Z'){
            continue;
        }else{
            if(s[i]-'a'+'A'==s[i-1]||s[i]-'a'+'A'==s[i+1])
            {
                a[5]=0;
                break;
            }
            continue;
        }
    }
    for(int i=1;i<=n;i++)//??+??
    {
        if(s[i]=='?')
        {
            if(i-1>=1&&i+1<=n)
            {
//                a[6]=a[6]*50%mod;
                char t1=s[i-1];
            	char t2=s[i+1];
            	if(t1==t2){
            		a[6]=a[6]*51%mod;
				}else
                a[6]=a[6]*50%mod;
                
            }else{
                a[6]=a[6]*51%mod;
            }
            
            
        }else if(s[i]<='9'&&s[i]>='0'){
            a[6]=0;
            break;
        }else if(s[i]>='A'&&s[i]<='Z'){
            continue;
        }else{
            if(s[i]-'a'+'A'==s[i-1]||s[i]-'a'+'A'==s[i+1])
            {
                continue;
            }else{
                a[6]=a[6]*2%mod;
            }
            // continue;
        }
    }
    for(int i=1;i<=n;i++)//??+??+??
    {
        if(s[i]=='?')
        {
            if(i-1>=1&&i+1<=n)
            {
//                a[7]=a[7]*60%mod;
                
                char t1=s[i-1];
            	char t2=s[i+1];
            	if(t1==t2){
            		a[7]=a[7]*61%mod;
				}else
                a[7]=a[7]*60%mod;
                
            }else{
                a[7]=a[7]*61%mod;
            }
        }else if(s[i]<='9'&&s[i]>='0'){
            continue;
        }else if(s[i]>='A'&&s[i]<='Z'){
            continue;
        }else{
            if(s[i]-'a'+'A'==s[i-1]||s[i]-'a'+'A'==s[i+1])
            {
                continue;
            }else{
                a[7]=a[7]*2%mod;
////            	s[i]=s[i]-'a'+'A';
            }
//             a[7]=a[7]*2%mod;
        }
    }
//    for(int i=1;i<=7;i++)cout<<a[i]<<endl;
    int val=a[7];
    jian(val,a[6]);jian(val,a[5]);jian(val,a[4]);
    jian(val,3*a[3]);jian(val,3*a[2]);jian(val,3*a[1]);
    cout<<val<<'\n';
}
