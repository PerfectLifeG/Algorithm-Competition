#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
using namespace std;
struct vv
{
    int t;
    int f;
    int c;
};
bool cmp(struct vv v1,struct vv v2){
    return v1.c>v2.c;
}
bool cmp2(struct vv v1,struct vv v2){
    return v1.f<v2.f;
}
int main()
{
    int n,k;int cnt=0;int s=0;
    cin>>n>>k;
    vector<struct vv>v;
    struct vv stu;
    for (int i = 0; i < n; i++)
    {
        cin>>stu.t;
        v.push_back(stu);
    }
    vector<struct vv>::iterator it=v.begin();
    for (int i = 0; i < n; i++)
    {
        cin>>it->f;
        it->c=it->t - it->f;
        if(it->c<0)cnt++;
        it++;
    }
    sort(v.begin(),v.end(),cmp); 
    if(k>cnt){
        it=v.begin();
        for (int i = 0; i < cnt; i++)
        {
            int t=it->t;
            it->t=it->f;
            it->f=t;
            it++;
        }
        k-=cnt;
        if(k%2==0);
        else{
            it=v.begin();
            sort(v.begin(),v.end(),cmp2);
            int t=it->t;
            it->t=it->f;
            it->f=t;
        }
    }
    else{
        it=v.begin();
        for (int i = 0; i < k; i++)
        {
            int t=it->t;
            it->t=it->f;
            it->f=t;
            it++;
        }
    }
    it=v.begin();
    for (int i = 0; i < n; i++)
    {
        s+=it->t;
        it++;
    }
    cout<<s;
    return 0;
}