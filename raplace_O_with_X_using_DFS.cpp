//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
int N,M;
int visited[1003][1003];
vector<pair<int,int>> dir={{0,-1},{0,1},{-1,0},{1,0}};
bool isValid(int i,int j){
    return (i<N && i>=0 && j<M && j>=0);
}

void dfs(int i,int j,vector<vector<char>> &tmp,vector<vector<int>> &visited){
    visited[i][j]=1;
    for(auto d:dir){
        int ni=i+d.first;
        int nj=j+d.second;
        if(isValid(ni,nj) && !visited[ni][nj] && tmp[ni][nj]=='O'){
            dfs(ni,nj,tmp,visited);
        }
    }
}

void bfs(int i,int j,vector<vector<char>> &tmp,vector<vector<int>> &visited){
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
            if(isValid(Ni,Nj) && !visited[Ni][Nj] && tmp[Ni][Nj]=='O'){
                visited[Ni][Nj]=1;
                q.push({Ni,Nj});
            }
        }
    }
}

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        N=n,M=m;
        vector<vector<char>> tmp=mat;
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        // Using DFS 
        // for(int i=0;i<m;i++){
        //     if(!visited[0][i] && mat[0][i]=='O') dfs(0,i,tmp,visited);
        //     if(!visited[n-1][i] && mat[n-1][i]=='O') dfs(n-1,i,tmp,visited);
        // }
        // for(int i=0;i<n;i++){
        //     if(!visited[i][0] && mat[i][0]=='O') dfs(i,0,tmp,visited);
        //     if(!visited[i][m-1] && mat[i][m-1]=='O') dfs(i,m-1,tmp,visited);
        // }
        
        // Using BFS
        for(int i=0;i<m;i++){
            if(!visited[0][i] && mat[0][i]=='O') bfs(0,i,tmp,visited);
            if(!visited[n-1][i] && mat[n-1][i]=='O') bfs(n-1,i,tmp,visited);
        }
        for(int i=0;i<n;i++){
            if(!visited[i][0] && mat[i][0]=='O') bfs(i,0,tmp,visited);
            if(!visited[i][m-1] && mat[i][m-1]=='O') bfs(i,m-1,tmp,visited);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(tmp[i][j]=='O' && !visited[i][j]){
                    tmp[i][j]='X';
                }
            }
        }
        return tmp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends