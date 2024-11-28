// Quiz Haris 23P-0573
#include <iostream>
using namespace std;

struct node {
    node *left, *right;
    int info;
};

class BST {
private:
    node *root;
public:
    BST();
    ~BST();
    void option();
    void insertion(node *&root, int val);
    void preorder(node *root);
    int height(node* root);    // for the height function then this heiht pass to the checkgreater subtree
    void checkGreaterSubtree(node* root);
    bool isBSTUtil(node* root, int minVal, int maxVal);   // to check the max val and min val  from the tree to check is  BST or not
    bool checkBST();
};

// Constructor
BST::BST() {
    root = NULL;
}

// Destructor
BST::~BST() {}

// Option menu
void BST::option() {
    int choice, val;
    do {
        cout << "Available Options: " << endl;
        cout << "1) Insertion" << endl;
        cout << "2) Pre-order" << endl;
        cout << "3) Check Greater Subtree" << endl;
        cout << "4) Check if Tree is BST" << endl;
        cout << "0) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the value: ";
            cin >> val;
            insertion(root, val);
        } else if (choice == 2) {
            preorder(root);
            cout << endl;
        } else if (choice == 3) {
            checkGreaterSubtree(root);
        } else if (choice == 4) {
            if (checkBST()) {
                cout << "The tree is a valid BST." << endl;
            } else {
                cout << "The tree is NOT a valid BST." << endl;
            }
        } else if (choice == 0) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 0);
}

// Insertion function   where manully  i insert the value
void BST::insertion(node *&root, int val) {
    if (root == NULL) {
        root = new node;
        root->info = val;
        root->left = NULL;
        root->right = NULL;
    } else if (val < root->info) {
        insertion(root->left, val);
    } else if (val > root->info) {
        insertion(root->right, val);
    } else {
        cout << "Duplicate value: " << val << endl;
    }
}

// Pre-order traversal    for check the min and max vlaue for teh bst or not
void BST::preorder(node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->info <<;
    preorder(root->left);
    preorder(root->right);
}

// Height of the tree
int BST::height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1+(leftHeight , rightHeight);   // here +1 bcz , we also have the current node where it is standing right now
}

// Function for the greater subtree
void BST::checkGreaterSubtree(node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (rightHeight < leftHeight) {
        cout << "Left Subtree is greater." << endl;
    } else if (rightHeight > leftHeight) {
        cout << "Right Subtree is greater." << endl;
    } else {
        cout << "Both Subtrees are of equal height." << endl;
    }
}

// Utility function to check if the tree is a BST
bool BST::isBSTUtil(node* root, int minVal, int maxVal) {
    if (root == NULL) {
        return true;
    }

    if (root->info <= minVal || root->info >= maxVal) {
        return false;
    }

    // here  check the left and right subtrees
    return isBSTUtil(root->left, minVal, root->info) &&
    isBSTUtil(root->right, root->info, maxVal);
}

// Function to check if the tree is a BST
bool BST::checkBST() {
    return isBSTUtil(root ,min,max); // Use min and max values for integers
}

int main() {
    BST obj;
    obj.option();
    return 0;
}
