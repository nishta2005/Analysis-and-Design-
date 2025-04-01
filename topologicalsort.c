#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited [MAX];
int stack[MAX];
int top = -1;

void addedge(int u, int v){
adj[u][v] = 1;
}

void dfs(int v, int n){
visited[v] = 1;

for(int i=0; i<n; i++){
    if(adj[v][i] && !visited[i]){
        dfs(i,n);
    }
}
stack[++top] = v;
}

void topologicalSort(int n){
for(int i=0; i<n; i++){
    visited[i] = 0;
}
for(int i=0; i<n; i++){
    if(!visited[i]){
        dfs(i,n);
    }
}

printf("topological order");
while(top>=0){
    printf("%d", stack[top--]);
}
printf("\n");
}

int main(){
int vertices, edges, u, v;
printf("enter no. of vertices");
scanf("%d", &vertices);

printf("enter no. of edges");
scanf("%d", &edges);

for(int i=0; i<edges; i++){
    printf("enter edge(u,v):");
    scanf("%d%d", &u,&v);
    addedge(u,v);
}
topologicalSort(vertices);
return 0;
}
