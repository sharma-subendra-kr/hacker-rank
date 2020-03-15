// Roads and Libraries

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void dfs(int **graph, int *visited, int src, int n, long long *sum, long long cost){
    visited[src] = 1;
    for(int i = 0; i < n; i++){
        if(visited[i] != 1 && graph[src][i] == 1){
            *sum+=cost;
            dfs(graph, visited, i, n, sum, cost);
        }
    }
}

int main(){
    int q;  //queries
    int n;  //number of cities
    long long m;  //number of roads
    long long cl; //cost of building libraries 
    long long cr; //cost of building roads
    
    int inp1, inp2;

    int *visited;
    int **graph;  

    cin>>q;
    
    while(q--){
        cin>>n>>m>>cl>>cr;             
        
        visited = new int[n]();
        graph = new int*[n]();

        for(int i = 0; i < n; i++){
            graph[i] = new int[n]();
        }
        
        while(m--){
            cin>>inp1>>inp2; 
            graph[inp1 -1][inp2 - 1] = 1; 
            graph[inp2 -1][inp1 - 1] = 1;
        }
        
        long long sum = 0; 
        long long cost = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == 1){
                continue;
            }
            if(cr<=cl){
                cost = cr;
                sum+=cl;
            }else{
                cost = cl;
                sum+=cl; 
            }
            
            dfs(graph, visited, i, n, &sum, cost);
        }
        
        cout<<sum<<endl;

        for(int i = 0; i < n; i++){
            delete [] graph[i];
        }

        delete [] graph;
        delete [] visited;
    } 
     
    return 0;
}
