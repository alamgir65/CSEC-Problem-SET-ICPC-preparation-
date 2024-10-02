#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define cyes cout<<"Yes"<<endl;
#define cno cout<<"No"<<endl;
#define print(flag) (flag)? cout<<"YES\n" : cout<<"NO\n";
#define all(x) x.begin(), x.end()
#define nl cout<<endl;
#define endl '\n'
#define love int main()
#define vtr vector
#define pii pair<int,int>
#define out(x) cout << x << '\n';
#define out2(x,y) cout << x << " " << y << '\n';
#define vii vector<int> 
#define vll vector<ll>
#define dqii deque<int> 
#define dqll deque<ll> 
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define Alamgir ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(){
    int n,x; cin>>n>>x;
    vector<pii> v;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        v.push_back({a,i+1});
    }
    sort(all(v));
    int l,r;
    bool flag=false;
    int i=0,j=n-1;
    while(i<j){
        if(v[i].first + v[j].first == x){
            l=v[i].second;
            r=v[j].second;
            flag=true;
            if(l>r) swap(l,r);
            break;
        }else if(v[i].first + v[j].first > x) j--;
        else i++;
    }
    if(!flag)  cout<<"IMPOSSIBLE\n";
    else out2(l,r)
}
love{
    Alamgir
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;    
}