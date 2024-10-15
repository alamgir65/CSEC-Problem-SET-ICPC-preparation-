//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool dfs(int node,int parent,vector<int> adj[],vector<int> &visited){
      visited[node]=1;
      for(auto u:adj[node]){
          if(visited[u] && parent != u) return true;
          if(!visited[u]){
               if(dfs(u,node,adj,visited)==true) return true;
          }
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        bool flag=false;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                flag=dfs(i,-1,adj,visited);
                if(flag) break;
            }
        }
        return flag;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends