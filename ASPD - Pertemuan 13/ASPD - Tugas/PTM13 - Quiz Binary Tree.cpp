#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int value) {
			data = value;
			left = NULL;
			right = NULL;
		}
};

class Tree {
	public:
		Node* root;
		Tree() {
			root = NULL;
		}
		
		void insert(int value) {
			root = insert(root, value);
		}
		
		Node* insert (Node* node, int value) {
			if (node == NULL) {
				node = new Node(value);
			} else if (value <= node->data) {
				node -> left = insert(node->left, value);
			} else {
				node -> right = insert(node->right, value);
			}
			
			return node;
		}
		
		void preorder() {
			preorder(root);
		}
		
		void preorder(Node* node) {
			if(node == NULL) return;
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
		}
		
		void postorder() {
			postorder(root);
		}
 		
 		void postorder(Node* node) {
 			 if(node == NULL) return;
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
		}
		 
		void printTree(int mode) {
            if (mode == 1) {
            	cout<<"(NPM Gnajil) Pre-Order Traversal	: ";
                preorder(root);
                cout<<endl;
            }
            
            else if (mode == 2) {
            	cout<<"(NPM Genap) Post-Order Traversal	: ";
                postorder(root);
                cout<<endl;
            }
        }
};

int main(){
	Tree tree;
	int n;
	
	cout<<"Masukkan jumlah simpul : ";
	cin>>n;
	
	
	cout<<"Masukkan "<<n<<" nilai untuk Binary Tree: "<<endl;
	for(int i = 0; i < n; i++) {
		int data;
		cout<<"Nilai ke-"<<i+1<<": ";
		cin >> data;
		tree.insert(data);
	}
	
	cout<<endl;
	tree.printTree(1);
	tree.printTree(2);
	
	return 0;
}
