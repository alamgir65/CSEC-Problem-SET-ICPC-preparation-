#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2==0) cout<<i<<" ";
    }
    for(int i=1;i<=n;i++){
        if(i%2==1) cout<<i<<" ";
    }
    return 0;
}
