// Linked Lists: Detect a Cycle
// https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    struct Node* currFast = head->next;
    struct Node* currSlow = head;
    
    if(head == NULL){
        return 0;
    }
    
    while(currSlow != NULL && currFast != NULL && currFast->next != NULL){
        if(currFast == currSlow){
            // cout<<1;
            return 1;
        }
        currFast = currFast->next->next;    
        currSlow = currSlow->next;
    }
    // cout<<0;
    return 0;
}
