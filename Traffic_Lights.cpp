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
    int k,n; cin>>k>>n;
    vii a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vii ans;
    set<int> st;
    st.insert(0);
    st.insert(k);
    multiset<int> tmp;
    tmp.insert(k);
    for(auto x:a){
        auto it2 = st.upper_bound(x);
        auto it1=it2;
        it1--;
        int distance = *it2 - *it1;
        int dis1 = x-*it1,dis2 = *it2 - x;
        tmp.erase(tmp.find(distance));
        tmp.insert(dis1);
        tmp.insert(dis2);
        st.insert(x);
        ans.push_back(*tmp.rbegin());
    }
    for(auto x:ans) cout<<x<<" "; nl;
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