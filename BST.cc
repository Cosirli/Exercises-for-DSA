#include <iostream>
#include <stack>

template<typename T>
class BST {
private:
    struct Node;
    Node* root;

    Node* insert(Node* node, T value);
    bool search(const Node* node, T value) const;
    void inorder(const Node* node) const;
    void nonRecPostorder(const Node* node) const;

public:
    BST() : root(nullptr) {}

    void insert(T value);

    bool search(T value) const;

    void inorder() const;

    void NonRecPostorder() const;
};

template<typename T>
struct BST<T>::Node {
    T data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
typename BST<T>::Node* BST<T>::insert(Node* node, T value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    return node;
}

template<typename T>
bool BST<T>::search(const Node* node, T value) const{
    if (node == nullptr) {
        return false;
    }
    if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

template<typename T>
void BST<T>::inorder(const Node* node) const {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

template<typename T>
void BST<T>::nonRecPostorder(const Node* root) const 
{
    if (root == nullptr) 
    {
        return;
    }
    enum NodeTag : char
    {
        Left, Right, Done
    };

    struct StackNode 
    {
        const Node* node;
        NodeTag tag;
        StackNode(const Node* n)
            : node(n), tag(Left)
        {
        }
    };

    std::stack<StackNode*> s;
    s.push(&StackNode(root));
    StackNode* p = s.top();

    while (!s.empty() || p->node != nullptr)
    {
        StackNode pLeft(p->node->left);
        while (pLeft.node != nullptr && p.tag == Left)
        {
            s.push(pLeft);
            p = pLeft;
            pLeft = StackNode(p->node->left);
        }

        if (p->node->right != nullptr && p->tag == Left)
        {
            p->tag = Right;
            StackNode* pRight(p->node->right);
            s.push(pRight);
            p = pRight;
        }
        else
        {
            std::cout << p->node->data << " ";
            p->tag = Done;
            s.pop();
            p = (s.empty()) ? nullptr : s.top();
        }
    }
}

// Define public member functions
template<typename T>
void BST<T>::insert(T value) {
    root = insert(root, value);
}

template<typename T>
bool BST<T>::search(const T value) const {
    return search(root, value);
}

template<typename T>
void BST<T>::inorder() const {
    inorder(root);
    std::cout << std::endl;
}

template<typename T>
void BST<T>::NonRecPostorder() const {
    nonRecPostorder(root);
    std::cout << std::endl;
}

int main() {
    BST<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);

    std::cout << "Inorder Traversal: ";
    tree.inorder();

    int key = 7;
    if (tree.search(key)) {
        std::cout << key << " is found in the BST.\n";
    } else {
        std::cout << key << " is not found in the BST.\n";
    }

    key = 15;
    if (tree.search(key)) {
        std::cout << key << " is found in the BST.\n";
    } else {
        std::cout << key << " is not found in the BST.\n";
    }

    return 0;
}
