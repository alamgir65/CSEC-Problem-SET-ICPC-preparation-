//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  int n,m;
//   int visited[1003][1003];
  vector<pair<int,int>> dir={{0,-1},{0,1},{-1,0},{1,0}};
  bool isValid(int i,int j){
      return (i<n && i>=0 && j<m && j>=0);
  }
  void bfs(int i,int j,vector<vector<int>> &tmp,vector<vector<int>> &visited){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=1;
    while(!q.empty()){
        int ni=q.front().first;
        int nj=q.front().second;
        q.pop();
        for(auto d:dir){
            int Ni=ni+d.first;
            int Nj=nj+d.second;
            if(isValid(Ni,Nj) && !visited[Ni][Nj] && tmp[Ni][Nj]==1){
                visited[Ni][Nj]=1;
                q.push({Ni,Nj});
            }
        }
    }
  }
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> tmp=mat;
        for(int i=0;i<m;i++){
            if(!visited[0][i] && mat[0][i]==1) bfs(0,i,tmp,visited);
            if(!visited[n-1][i] && mat[n-1][i]==1) bfs(n-1,i,tmp,visited);
        }
        for(int i=0;i<n;i++){
            if(!visited[i][0] && mat[i][0]==1) bfs(i,0,tmp,visited);
            if(!visited[i][m-1] && mat[i][m-1]==1) bfs(i,m-1,tmp,visited);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(tmp[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends