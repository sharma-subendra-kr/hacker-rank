// Trees: Is This a Binary Search Tree?

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <climits>
    bool checkBST(Node* root, int min, int max){
        if(root == NULL){
            return true;
        }
        if(root->data < min || root->data > max){
            return false;
        }
        
        return (checkBST(root->left, min, root->data - 1) && checkBST(root->right, root->data + 1, max));
    }    

	bool checkBST(Node* root) {
		return checkBST(root, INT_MIN, INT_MAX);
	}