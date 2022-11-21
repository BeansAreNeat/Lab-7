#include "BinarySearchTree.h"

int main() {
	int capacity = 5, count = 0, num;
	BinarySearchTree bst;

	std::cout << "Type " << capacity << " numbers between 1 & 100: " << std::endl;
	// count starts at 0
	while (count < capacity) {
		std::cin >> num;
		bst.insert(num); // Adds input to tree
		count++;
	} std::cout << std::endl;
	bst.printInOrder(); // Output
	bst.~BinarySearchTree();
	return 0;
}