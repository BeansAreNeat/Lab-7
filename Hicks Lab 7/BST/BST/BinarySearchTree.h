#pragma once
#include <iostream> 

class BinarySearchTree {
public:
	// Constructor
	BinarySearchTree() { }
	// Empties subtree
	~BinarySearchTree() {
		makeEmpty(root); 
	}
	// Finds smallest number
	const int& findMin() const {
		return findMin(root)->element;
	}
	// Finds largest number
	const int& findMax() const {
		return findMax(root)->element;
	}
	// Returns true if x is found in tree
	bool contains(const int& x) const {
		return contains(x, root);
	}
	// true if empty
	bool isEmpty() {
		if (root == NULL)
			return true;
		else
			return false;
	}
	// Add x to tree, no duplicates
	void insert(const int& x) {
		insert(x, root);
	}
	// If x is found, remove x from tree
	void remove(const int& x) {
		remove(x, root);
	}
	//Prints elements in order
	void printInOrder() {
		printInOrder(root);
	}

private:
	struct BinaryNode
	{
		int element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode(const int& el, BinaryNode* lt, BinaryNode* rt)
			:element(el), left(lt), right(rt) { }
	};

	BinaryNode* root;
	// Insert into subtree
	void insert(const int& x, BinaryNode*& t) const {
		// insert x
		// root = t
		if (t == NULL) {
			// Dynamically creates node
			t = new BinaryNode(x, NULL, NULL);
		}
		else if (x < t->element) {
			insert(x, t->left);
		}
		else if (x > t->element) {
			insert(x, t->right);
		}
	}
	// Removes from subtree
	void remove(const int& x, BinaryNode*& t) const {
		if (t == NULL) {
			return; // Nothing to delete
		}
		if (x < t->element) {
			remove(x, t->left);
		}
		else if (x > t->element) {
			remove(x, t->right);
		}
		else if (t->left != NULL && t->right != NULL) // Two children
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else {
			BinaryNode* oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
	}
	// Empties a subtree
	void makeEmpty(BinaryNode*& t) {
		if (t != NULL) {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = NULL;
	}
	//Prints elements in order
	void printInOrder(BinaryNode* t) {
		// Base Case
		if (t == NULL)
			return; // Nothing to print
		// Move left until root == min
		if (findMin() != t->element) {
			printInOrder(t->left);
		}
		std::cout << t->element << " ";
		printInOrder(t->right);
	}
	// Finds smallest item in subtree
	BinaryNode* findMin(BinaryNode* t) const {
		if (t == NULL) {
			return NULL;
		}
		if (t->left == NULL) {
			return t;
		}
		// Return node contains smallest item
		return findMin(t->left);
	}
	// Finds biggest item in subtree
	BinaryNode* findMax(BinaryNode* t) const {
		// Note, function is not recursive!
		if (t != NULL) // If the tree isn't empty
		{
			// Set root = to right node
			// until right node = NULL
			while (t->right != NULL)
				t = t->right;
			return t; // Farthest right node (biggest)
		}
	}
	// Test if item (x) is in subtree
	bool contains(const int& x, BinaryNode* t) const {
		// Search for x
		// Note: t is root
		if (t == NULL) {
			return false; //Base Case
		}
		else if (x < t->element) // If root > target
		{
			// Call function w/ search target & LEFT child
			return contains(x, t->left);
		}
		else if (x > t->element) // If root < target
		{
			// Call function w/ search target & RIGHT child
			return contains(x, t->right);
		}
		else {
			return true; // Match
		}
	}
};