//BFS

#include<bits/stdc++.h>
using namespace std;
#define MX 110

vector<int> graph[MX];
bool vis[MX];
int dist[MX];

void Bfs(int source){
    queue<int> q;
    vis[source] = 1; // initialization
    dist[source] = 0;
    q.push(source);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0;i<graph[node].size();i++){
            int next=graph[node][i];
            if(vis[next]==0){
                vis[next]=1;
                dist[next] = dist[node]+1; //weight is 1
                q.push(next);
            }
        }
    }  
}

void displayBfs(int source,int n){
    cout<<"From node "<<source<<endl;
    for(int i=1;i<=n;i++){
        cout<<"Distance of "<<i<<" is : "<<dist[i]<<endl;
    }
}

int main(){

    int n,e,i;
    cin>>n>>e; //node and edge number
    

    for(i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        if(a==b){
            graph[a].push_back(b); //extra for self loop
            continue;
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    } 
    int source;
    cin>>source;

    Bfs(source);

    displayBfs(source,n);

    return 0;
}