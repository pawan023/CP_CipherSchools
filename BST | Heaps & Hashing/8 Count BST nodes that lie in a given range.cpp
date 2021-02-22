// Count BST nodes that lie in a given range

int getCount(Node* root, int low, int high)
{

	// Base case
	if (!root) return 0;

	// Special Optional case for improving efficiency
	if (root->data == high && root->data == low)
		return 1;

	// If current node is in range, then include it in count and
	// recur for left and right children of it
	if (root->data <= high && root->data >= low)
		return 1 + getCount(root->left, low, high) +
		       getCount(root->right, low, high);

	// If current node is smaller than low, then recur for right
	// child
	else if (root->data < low)
		return getCount(root->right, low, high);

	// Else recur for left child
	else return getCount(root->left, low, high);
}
