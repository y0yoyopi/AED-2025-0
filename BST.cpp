struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Función para insertar un nodo en el BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Función para buscar un valor en el BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Función para imprimir el BST en inorden (izquierda, raíz, derecha)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


// Función para queee aa para que llene un vector con los valores inorder de un árbol
void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (!root) return; 

        inorderTraversal(root->left, result);

        result.push_back(root->val);

        inorderTraversal(root->right, result);
    }
