#include <iostream>
using namespace std;

//definisi struktur node
struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	
	//Constructor untuk membuat node baru
	TreeNode(int value) : data{value}, left(NULL), right(NULL) {} //Mengganti nullptr dengan NULL
};

int main() {
	//Membuat simpul - simpul pohon
	int left, right;
	int arr[] = {1, 2, 3, 4, 5};
		TreeNode* root = new TreeNode(arr[0]);
		root->left =  new TreeNode(arr[1]);
		root->right = new TreeNode(arr[2]);
		root->left->left = new TreeNode(arr[3]);
		root->left->right = new TreeNode(arr[4]);
	
//	TreeNode* root =  new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
	
	//Menampilkan nilai simpul - simpul pohon
	cout<<"Nilai simpul - simpul pohon : "<<endl;
	cout<<"Akar : "<<root->data<<endl;
	cout<<"Anak kiri dari akar : "<<root->left->data<<endl;
	cout<<"Anak kanan dar akar : "<<root->right->data<<endl;
	cout<<"Anak kiri dari anak kiri dari akar : " << root->left->left->data<<endl;
	cout<<"Anak kanan dari anak kiri dari akar : " << root->left->right->data << endl;
	
	//Membersihkan memory
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;
}
