#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* right;
	node* left;

	node(int d)
	{
		data = d;
		right = NULL;
		left = NULL;
	}

	node* insertBST(node*& root, int d)
	{
		if (root == NULL)
		{
			return new node(d);
		}
		if (d < root->data)
		{
			root->left = insertBST(root->left, d);
		}
		else
		{
			root->right = insertBST(root->right, d);
		}

		return root;
	}

	node* InorderSucc(node*& root)
	{
		node* curr = root;
		while (curr && curr->left != NULL)
		{
			curr = curr->left;
		}
		return curr;
	}

	node* deleteBST(node*& root, int key)
	{
		if (key < root->data)
		{
			root->left = deleteBST(root->left, key);
		}
		else if (key > root->data)
		{
			root->right = deleteBST(root->right, key);
		}
		else
		{
			//case 1 and case 2
			if (root->left == NULL)
			{
				node* temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right = NULL)
			{
				node* temp = root->left;
				free(root);
				return temp;
			}

			//case 3
			node* temp = InorderSucc(root->right);
			root->data = temp->data;
			root->right = deleteBST(root->right, temp->data);
		}
		return root;
		
	}

	void preorder(node*& root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}

	void inorder(node*& root)
	{
		if (root == NULL)
		{
			return;
		}
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void postorder(node*& root)
	{
		if (root == NULL)
		{
			return;
		}
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
};

void main()
{
	node* root = NULL;
	root = root->insertBST(root, 1);
	root->insertBST(root, 7);
	root->insertBST(root, 4);
	root->insertBST(root, 8);
	root->insertBST(root, 9);
	root->insertBST(root, 2);

	cout << "Inorder: ";
	root->inorder(root);
	cout << endl;

	cout << "After Deletion: ";
	root->deleteBST(root, 8);
	root->inorder(root);
	cout << endl;

	/*cout << "Postorder: ";
	root->postorder(root);
	cout << endl;

	cout << "Preorder: ";
	root->preorder(root);
	cout << endl;*/

}