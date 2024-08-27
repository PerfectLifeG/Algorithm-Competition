#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,flag=1;
int a[N],b[N],c[N];
void down(int k,int idx){
    int mn=k;
    if(2*k+1<=idx && b[2*k+1]>b[mn])mn=2*k+1;
    if(2*k+2<=idx && b[2*k+2]>b[mn])mn=2*k+2;
    if(mn!=k)
    {   
        swap(b[mn],b[k]);
        down(mn,idx);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    sort(c,c+n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int idx=0;
    int fir=1;
    for(int i=n-1;i>0;i--){
        while(i>=0&&b[i]==a[i]&&fir){
            idx=i;
            i--;
        }
        if(i==0)break;
        fir=0;
        if(b[i]<b[i-1]){flag=0;break;}
    }
    if(flag){
        puts("Insertion Sort");
        if(idx==0){idx=1;while(a[idx]>a[idx-1])idx++;}
        int t=b[idx];idx--;
        while(idx>=0){
            if(idx>=0&&b[idx]>t){
                b[idx+1]=b[idx];
                idx--;
            }else break;
        }
        b[idx+1]=t;
        printf("%d",b[0]);
        for(int i=1;i<n;i++){
            printf(" %d",b[i]);
        }
    }else{
        puts("Heap Sort");
        int i=n-1;
        while(b[i]==c[i]){
            i--;
        }
        swap(b[0],b[i]);
        down(0,i-1);
        printf("%d",b[0]);
        for(int i=1;i<n;i++){
            printf(" %d",b[i]);
        }
    }
    return 0;
}