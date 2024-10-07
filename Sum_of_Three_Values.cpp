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
    int n,k; cin>>n>>k;
    vii a(n);
    map<int,vii> mp;
    for(int i=0;i<n;i++) cin>>a[i],mp[a[i]].pb(i+1);
    set<int> ans;
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=i+1;j<n;j++){
            int need = k-a[i]-a[j];
            if(k<=0) continue;
            if(mp.find(need) != mp.end()){
                if(a[i]==a[j] && a[j]==need && mp[need].size()>=3){
                    ans.insert(mp[need][0]);
                    ans.insert(mp[need][1]);
                    ans.insert(mp[need][2]);
                    flag=true;
                }else if(a[i]==need && mp[need].size()>=2){
                    ans.insert(mp[need][0]);
                    ans.insert(mp[need][1]);
                    ans.insert(j+1);
                    flag=true;
                }else if(a[j]==need && mp[need].size()>=2){
                    ans.insert(mp[need][0]);
                    ans.insert(mp[need][1]);
                    ans.insert(i+1);
                    flag=true;
                }else{
                    ans.insert(mp[need][0]);
                    ans.insert(j+1);
                    ans.insert(i+1);
                    flag=true;
                }
            }
            if(flag) break;

        }
        if(flag) break;
    }
    // sort(all(ans));
    if(ans.size()!=3) cout<<"IMPOSSIBLE\n";
    else{
        for(auto x:ans) cout<<x<<" "; nl
    }
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