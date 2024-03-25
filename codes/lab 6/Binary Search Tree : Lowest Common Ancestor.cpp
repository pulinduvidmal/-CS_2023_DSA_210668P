
#include <iostream>
using namespace std;


class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }

        Node* insert(Node* root, int data) {
            if (root == NULL) {
                return new Node(data);
            }
            if (data < root->data) {
                root->left = insert(root->left, data);
            } else {
                root->right = insert(root->right, data);
            }
            return root;
        }
        
        Node* lca(Node* root, int v1, int v2) {
            if (root == NULL) {
                return NULL;
            }
            if (v1 < root->data && v2 < root->data) {
                return lca(root->left, v1, v2);
            }
            if (v1 > root->data && v2 > root->data) {
                return lca(root->right, v1, v2);
            }
            return root;
}

        
    };


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    Node* root = NULL;

    int count;
    int data;
    int v1;
    int v2;
    

    cin >> count;

    while (count > 0) {
        cin >> data;
        root = root->insert(root, data);
        count--;
    }
    
    cin >> v1 >> v2;
    
    
    
    Node* ancestor = root->lca(root, v1, v2);
    cout << ancestor->data << endl;

    

 
    return 0;
}
