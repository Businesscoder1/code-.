// #include<bits/stdc++.h>

// using namespace std;

// class BinaryTree{
   
//    int data;
//    BinaryTree* left=NULL;
//    BinaryTree* right=NULL;

//    public:
// //    BinaryTree();
//    BinaryTree(int data){
//     this->data=data;
//     left=NULL;
//     right=NULL;

//    }
   


// };

// BinaryTree* insert(BinaryTree*root,int x){
//     if(root==NULL){
//         BinaryTree *temp=new BinaryTree (data);
//         return temp;

//     }
//     if(root->data>data){
//         root->left=insert(root->left,data)
//     }
// }

#include<bits/stdc++.h>
using namespace std;
class Tree
{
public:
  int data;
  Tree *left = NULL, *right = NULL;
  // Constructor initialised
    Tree (int x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }
};

Tree *insert_node (Tree * root, int x)
{

  if (root == NULL)
    {
      Tree *temp = new Tree (x);
      return temp;
    }

  if (root->data < x)
    {
      root->left = insert_node (root->left, x);
    }

  else
    {
      root->right = insert_node (root->right, x);
    }
  return root;

}

void inorder_traversal (Tree * root)
{
  if (root == NULL)
    return;
  inorder_traversal (root->left);

  cout << root->data << " ";

  inorder_traversal (root->right);

}

int main ()
{
  Tree *root = new Tree (15);
  root->left = new Tree (13);
  root->right = new Tree (18);
  root->left->left = new Tree (8);
  root->left->right = new Tree (14);
  root->right->left = new Tree (16);
  root->right->right = new Tree (19);
  
  cout << "Inorder Traversal of the Binary Search Tree:";
  inorder_traversal (root);
}