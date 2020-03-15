// BFS: Shortest Reach in a Graph

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void bfs(int **graph, int *visited, int start, queue<int> _queue, int n){
    visited[start] = 0;
    _queue.push(start);
    int src;
    while(!_queue.empty()){
        int front = _queue.front();
        src = front;
        _queue.pop();
        for(int i = 0; i < n; i++){
            if(visited[i] == 0 && graph[src][i] == 1){
                visited[i] = visited[src]+6;
                _queue.push(i);
            }
        }
    }
}

int main(){
    
    int q, n, m;
    int start;
    int **graph; 
    int *visited;
    int *output;
    
     
    cin>>q;

    while(q--){
        cin>>n>>m;
        
        graph = new int*[n];

        for(int i = 0; i < n; i++){
            graph[i] = new int[n]();
        }
        visited = new int[n]();
        //output = new int[n]();

        int from, to;
        for(int i = 0; i < m; i++){
            cin>>from>>to;
            graph[from-1][to-1] = 1;
            graph[to-1][from-1] = 1;
        }
        
        cin>>start;
        start--;
        queue<int> _queue;
        //_queue.clear(); 
        bfs(graph, visited, start, _queue, n);       

        for(int i = 0; i < n; i++){
            if(i != start){
                if(visited[i] > 0){
                    cout<<visited[i]<<" "; 
                }else{
                    cout<<-1<<" "; 
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
