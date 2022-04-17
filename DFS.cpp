//DFS

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

vector<int> graph[MAX];

bool visited[MAX];

void dfs(int source){
    visited[source] = 1;
    for(int i=0;i<graph[source].size();i++){
        int next = graph[source][i];
        if(visited[next]==0){
            dfs(next);
        }
    }
}

int main(){

    int n,e,i;
    cin>>n>>e; 
    
    for(i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    } 
    int source;
    cin>>source;
    dfs(source);
    for(int i=0;i<n;i++){
         if(visited[i]==1){
             cout<<"Node "<<i<<" is visited."<<" Boolean Value : "<<visited[i]<<endl;
         }
         else{
             cout<<"Node "<<i<<" is not visited."<<" Boolean Value : "<<visited[i]<<endl;
         }
    }

    return 0;
}