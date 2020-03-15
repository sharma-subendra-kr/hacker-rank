#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    
    Node(){}

    Node(int i){
        data = i;
        left = NULL;
        right = NULL;
    }
};

struct Item{
    Node *arr; 
};

void dfs(Node *node, Item* depthArr, int* depthIndex, int depth){
    if(node == NULL) return; 
    depthArr[depth].arr[++depthIndex[depth]] = *node;
    dfs(node->left, depthArr, depthIndex, depth+1);
    dfs(node->right, depthArr, depthIndex, depth+1);
}

void inorder(Node *node){
    if(node == NULL){
        return; 
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int main(){
    int n, *depthIndex;
    Node *nodesArr;
    Item *depthArr;
     
    cin>>n;
    
    nodesArr = new struct Node[n];
    depthArr = new struct Item[n];
    depthIndex = new int[n]();
    
    for(int i = 0; i < n; i++){
        //Node node;
        //node.data = i;
        nodesArr[i] = *(new Node(i));
        depthArr[i] = *(new struct Item);
        depthArr[i].arr = new struct Node[n]; 
        depthIndex[i] = -1;
    }  

    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l;
        cin>>r;
        if(l != -1){
            nodesArr[i].left = &nodesArr[l]; 
        }   
        
        if(r != -1){
            nodesArr[i].right = &nodesArr[r]; 
        } 
    }
    
    dfs(&nodesArr[0], depthArr, depthIndex, 1);
    
    int t, k; 
    cin>>k;

    while(t != 0){
        cin>>k;
        for(int i = 0; i <= depthIndex[k]; i++){
            Node temp = *(depthArr[k].arr[i].left);
            depthArr[k].arr[i].left = depthArr[k].arr[i].right;
            depthArr[k].arr[i].right = &temp;
        }
        inorder(&nodesArr[0]);
        cout<<endl;
        t--;
    }
    
    return 1;
}
