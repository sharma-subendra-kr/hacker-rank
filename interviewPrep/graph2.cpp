// Find the nearest clone

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int dfs(int **graph, int *visited, int *id, int src, int n, int color){
    if(id[src] == color && visited[src] != 1){
        return 1; 
    }
    visited[src] = 1;
    
    int min = -1, temp;
    for(int i = 0; i < n; i++){
        if(visited[i] != 1 && graph[src][i] == 1){
            temp = dfs(graph, visited, id, i, n, color);
            if((temp < min && temp > 0) || (min < 0)){
                min = temp; 
            }
        }
    }
    if(min > 0){
        return min + 1;
    }else{
        return -1;
    }
}

int main(){
    
    int n, m;
    //int *from, *to;
    int *id; 
    int val;
    int **graph; 
    int *visited;
    cin>>n>>m;
    
    //from = new int[n];
    //to = new int[n];
    id = new int[n]; 
    graph = new int*[n];

    for(int i = 0; i < n; i++){
        graph[i] = new int[n]();
    }
    visited = new int[n];

    int from, to;
    for(int i = 0; i < m; i++){
        cin>>from>>to;
        graph[from-1][to-1] = 1;
        graph[to-1][from-1] = 1;
    }
    
    for(int i = 0; i < n; i++){
        cin>>id[i]; 
    }
    
    cin>>val;
    
    int min = -1;
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(id[i] != val){
            continue;
        }
    
        for(int j = 0; j < n; j++){
            visited[j] = 0;
        }
        
        visited[i] = 1;
        temp = dfs(graph, visited, id, i, n, val);
        if((temp < min && temp > 0) || (min < 0)){ 
            min = temp;
        }
    }
    
    if(min > 0){
        cout<<min - 1;
    }else{
        cout<<-1;
    }

    return 0;
}
