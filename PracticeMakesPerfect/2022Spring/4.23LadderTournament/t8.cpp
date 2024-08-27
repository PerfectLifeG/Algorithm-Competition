#include<bits/stdc++.h>
using namespace std;
struct peo
{
    int score;
    int pta;
    int book;
    peo(){
        book=0;
    }
};
int cmp(peo a,peo b){
    if(a.score==b.score)return a.pta<b.pta;
    return a.score<b.score;

}
int main(){
    int n,k,s;
    cin>>n>>k>>s;
    peo p[n];
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        int a,b;cin>>a>>b;
        p[i].score=a;p[i].pta=b;
    }
    sort(p,p+n,cmp);int flag=0;
    for (int j = 0; j < k; j++)
    {   flag=0;
        for (int i = 0; i < n; i++)
        {
            if(i>0&&p[i].score!=p[i-1].score)flag=0;
            if(p[i].score>=175&&p[i].book==0&&flag==0&&p[i].pta<90){flag=1;p[i].book=1;ans++;}
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(p[i].score>=175&&p[i].book==0&&p[i].pta>=90){p[i].book=1;ans++;}
    }
    cout<<ans;
    
    return 0;
}