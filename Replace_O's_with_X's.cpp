//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
int N,M;
vector<pair<int,int>> dir={{0,-1},{0,1},{-1,0},{1,0}};
bool isValid(int i,int j){
    return (i<N && i>=0 && j<M && j>=0);
}
void bfs(int i,int j,vector<vector<char>> &tmp,vector<vector<int>> &visited){
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    q.push({i,j});
    visited[i][j]=1;
    bool flag=true;
    while(!q.empty()){
        int ni=q.front().first;
        int nj=q.front().second;
        q.pop();
        if(ni==0 || ni==N-1 || nj==0 || nj==M-1) flag=false;
        v.push_back({ni,nj});
        for(auto d:dir){
            int Ni=ni+d.first;
            int Nj=nj+d.second;
            if(isValid(Ni,Nj) && !visited[Ni][Nj] && tmp[i][j]=='O'){
                visited[Ni][Nj]=1;
                q.push({Ni,Nj});
            }
        }
    }
    if(flag){
        for(auto x:v){
            tmp[x.first][x.second]='X';
        }
    }
}
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        N=n,M=m;
        vector<vector<char>> tmp=mat;
        vector<vector<int>> visited(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mat[i][j]=='O'){
                    bfs(i,j,tmp,visited);
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