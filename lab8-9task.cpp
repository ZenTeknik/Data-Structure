
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
    void inorder(node *root);
    void postorder(node *root);
    node* deletion(node *root, int val);
    void search(node *root, int key);
    node* findmin(node *root);
};

// Constructor
BST::BST() {
    root = nullptr;
}

// Destructor
BST::~BST() {}

// Option menu
void BST::option() {
    int choice, val, key;
    do {
        cout << "Available Options: " << endl;
        cout << "1) Insertion" << endl;
        cout << "2) Pre-order" << endl;
        cout << "3) In-order" << endl;
        cout << "4) Post-order" << endl;
        cout << "5) Searching" << endl;
        cout << "6) Deletion" << endl;
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
            inorder(root);
            cout << endl;
        } else if (choice == 4) {
            postorder(root);
            cout << endl;
        } else if (choice == 5) {
            cout << "Enter the key: ";
            cin >> key;
            search(root, key);
        } else if (choice == 6) {
            cout << "Enter the key: ";
            cin >> key;
            root = deletion(root, key);
        } else if (choice == 0) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 0);
}

// Insertion function
void BST::insertion(node *&root, int val) {
    if (root == nullptr) {
        root = new node;
        root->info = val;
        root->left = nullptr;
        root->right = nullptr;
    } else if (val < root->info) {
        insertion(root->left, val);
    } else if (val > root->info) {
        insertion(root->right, val);
    } else {
        cout << "Duplicate value: " << val << endl;
    }
}

// Pre-order traversal
void BST::preorder(node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->info << " ";
    preorder(root->left);
    preorder(root->right);
}

// In-order traversal
void BST::inorder(node *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}

// Post-order traversal
void BST::postorder(node *root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->info << " ";
}

// Searching function
void BST::search(node *root, int key) {
    if (root == nullptr) {
        cout << "Key does not exist." << endl;
        return;
    }

    if (key < root->info) {
        search(root->left, key);
    } else if (key > root->info) {
        search(root->right, key);
    } else {
        cout << "Key exists: " << root->info << endl;
    }
}

// Find minimum node
node* BST::findmin(node *root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Deletion function
node* BST::deletion(node *root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    if (val < root->info) {
        root->left = deletion(root->left, val);
    } else if (val > root->info) {
        root->right = deletion(root->right, val);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            node *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            node *temp = root;
            root = root->left;
            delete temp;
        } else {
            node *temp = findmin(root->right);
            root->info = temp->info;
            root->right = deletion(root->right, temp->info);
        }
    }
    return root;
}

int main(){
    BST obj;
    obj.option();

    return 0;
}

