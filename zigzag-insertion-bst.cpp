int main() {
    tree myTree;
    node* root = NULL;
    bool zigzag = true; // Start with Zig (left)

    int values[] = {10, 5, 15, 3, 7, 12, 20};
    for (int val : values) {
        myTree.insert(root, val, zigzag);
    }

    // Add a function to print the tree to verify the structure (e.g., in-order traversal)
    cout << "Tree created with Zig-Zag insertion." << endl;
    return 0;
}


void tree::insert(node*& root, int val, bool& zigzag) {
    if (root == NULL) {
        root = new node;
        root->info = val;
        root->left = NULL;
        root->right = NULL;
        return;
    }

    if (zigzag) { // Zig: Try inserting into the left subtree
        insert(root->left, val, zigzag);
    } else { // Zag: Try inserting into the right subtree
        insert(root->right, val, zigzag);
    }

    zigzag = !zigzag; // Toggle the direction for the next insertion
}
