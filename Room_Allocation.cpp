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
    int n; cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        v.push_back({b,a});
    }
    sort(all(v));
    set<int> st;
    st.insert(v[0].first);
    int room=1;
    v[0].second=1;
    for(int i=1;i<n;i++){
        int a=v[i].second;
        int b=v[i].first;
        auto it=lower_bound(all(st),a);
        if(it!=st.end() && (*it)!=a){
            st.erase(it);
            st.insert(b);
            
        } else st.insert(b);
    }
    out(st.size())
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