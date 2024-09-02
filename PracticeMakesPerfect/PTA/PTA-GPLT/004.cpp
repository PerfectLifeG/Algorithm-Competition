#include<bits/stdc++.h>
using namespace std;
int pre[1001];
int is=0;
vector<int>post;
void getpost(int l,int r){
    if(l==r){
        post.push_back(pre[l]);
        return;
    }
    int i=l+1,j=r;
    if(!is)
    {
        while(i<=r&&pre[i]<pre[l])i++;//这里i<=r有等于     这个=太重要了！因为当l==r时我们才插入，不然就会出错
        while(j>l&&pre[j]>=pre[l])j--;//这里j>l没等于  原因在于当l==r时  都不进入
    }
    else
    {
        while(i<=r&&pre[i]>=pre[l])i++;
        while(j>l&&pre[j]<pre[l])j--;
    }
    if(i-j!=1)return;
    getpost(l+1,j);
    getpost(i,r);
    post.push_back(pre[l]);
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>pre[i];
    }
    getpost(0,n-1);
    if(post.size()<n){
        is=1;
        post.clear();
        getpost(0,n-1);
    }
    if(post.size()==n){
        cout<<"YES"<<endl<<post[0];
        for (int i = 1; i < n; i++)
        {
            cout<<" "<<post[i];
        }
    }else 
        cout<<"NO";
    return 0;
}