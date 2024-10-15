//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  int n,m;
//   int visited[1003][1003];
  vector<pair<int,int>> dir={{0,-1},{0,1},{-1,0},{1,0}};
  bool isValid(int i,int j){
      return (i<n && i>=0 && j<m && j>=0);
  }
  int bfs(queue<pair<pair<int,int>,int>> q,vector<vector<int>> adj,vector<vector<int>> &visited,vector<vector<int>> &ans){
      while(!q.empty()){
          int i=q.front().first.first;
          int j=q.front().first.second;
          int cost=q.front().second;
          q.pop();
          ans[i][j]=cost;
          for(auto d:dir){
              int ni=i+d.first;
              int nj=j+d.second;
              if(isValid(ni,nj) && !visited[ni][nj]){
                  visited[ni][nj]=1;
                  q.push({{ni,nj},cost+1});
              }
          }
      }
  }
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> tmp=grid;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1){
                   q.push({{i,j},0});
                   visited[i][j]=1;
               }
            }
        }
        bfs(q,tmp,visited,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends