#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII>>q;
const int N=1000010;
int a[N];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        q.push({a[i],i});
        if(i>=k-1){
            cout<<q.top().first<<' ';
            while(q.top().second<i-k+1){
                q.pop();
            }
        }
    }
    return 0;
}