// Roads and Libraries

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int bfs(int **graph, int *visited, int src, int n){
    int nodes = 0;
    queue<int> _queue;
    _queue.push(src);
    visited[src] = 1;

    while(_queue.empty()){
        int src = _queue.front();  
        _queue.pop();
        for(int i = 0; i < n; i++){
            if(visited[i] != 1 && graph[src][i] == 1){
                visited[i] = 1;
                nodes++;
                _queue.push(i);
            }
        }
    }

    return nodes;
}

int main(){
    int q;  //queries
    int n;  //number of cities
    long long m;  //number of roads
    int cl; //cost of building libraries 
    int cr; //cost of building roads
    
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
        int cost = 0;

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
            
            int nodes = bfs(graph, visited, i, n);
            sum = sum + nodes*cost;
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
