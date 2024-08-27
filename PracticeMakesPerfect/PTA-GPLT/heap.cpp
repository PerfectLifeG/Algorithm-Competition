#include<bits/stdc++.h>
using namespace std;
int heap[100];
void upAdjust(int i){
    if(i == 1) return ;
    while(i != 1) {
        if(heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i = i / 2;
        } else {
        break;
        }
    }
}
int main()
{
    int n;cin>>n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
        upAdjust(i);
    }

    return 0;
}
