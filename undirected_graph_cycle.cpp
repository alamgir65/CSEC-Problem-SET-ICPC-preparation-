//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool bfs(int node,vector<int> adj[],vector<int> &visited,int parent){
      queue<pair<int,int>> q;
      q.push({node,parent});
      visited[node]=1;
      while(!q.empty()){
          int u=q.front().first;
          int p=q.front().second;
          q.pop();
          for(auto v:adj[u]){
              if(visited[v] && v!=p) return true;
              if(!visited[v]){
                  visited[v]=1;
                  q.push({v,u});
              }
          }
      }
      return false;
      
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool flag=false;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                flag = bfs(i,adj,visited,-1);
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