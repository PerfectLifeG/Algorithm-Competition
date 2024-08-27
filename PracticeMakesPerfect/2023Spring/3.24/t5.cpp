#include<bits/stdc++.h>
using namespace std;
const int N=410;
int n;
int d[N][N];
#define x first
#define y second
pair<int,int> dot[N];
int get(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int check(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
    float tempy1 = (a.y - b.y) ;
    float tempx1 = (a.x - b.x);
    float tempy2 = (c.y - a.y) ;
    float tempx2 = (c.x - a.x);
    float xp = tempy1 * tempx2;
    float yp = tempy2 * tempx1;
    if(fabs(xp - yp) <= 1e-6)
        return 1;
    else
        return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>dot[i].first>>dot[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            d[i][j]=get(dot[i].first,dot[i].second,dot[j].first,dot[j].second);
            d[j][i]=d[i][j];
        }
    }
    // cout<<check(dot[0],dot[2],dot[3])<<endl;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((d[i][j]==d[i][k]||d[i][j]==d[j][k]||d[j][k]==d[i][k])&&!check(dot[i],dot[j],dot[k])){
                    // cout<<i<<' '<<j<<' '<<k<<endl;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}