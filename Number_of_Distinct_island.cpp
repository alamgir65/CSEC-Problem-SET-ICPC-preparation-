//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  int n,m;
  vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
  bool isValid(int i,int j){
      return (i<n && i>=0 && j<m && j>=0);
  }
  
  void bfs(int i,int j,vector<vector<int>> &grid,vector<pair<int,int>> &v,vector<vector<int>> &visited){
      visited[i][j]=1;
      queue<pair<int,int>> q;
      q.push({i,j});
      while(!q.empty()){
          int ni=q.front().first;
          int nj=q.front().second;
          q.pop();
          v.push_back({ni-i,nj-j});
          for(auto d:dir){
              int Ni=ni+d.first;
              int Nj=nj+d.second;
              if(isValid(Ni,Nj) && !visited[Ni][Nj] && grid[Ni][Nj]==1){
                  visited[Ni][Nj]=1;
                  q.push({Ni,Nj});
              }
          }
          
      }
  }
  
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>> v;
                    bfs(i,j,grid,v,visited);
                    st.insert(v);
                }
            }
        }
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends