
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BSTNode
{
    public: 
        T data;
        BSTNode<T>* left {nullptr};
        BSTNode<T>* right {nullptr};

    BSTNode(T val): data(val) {}
};


template <typename T>
class BST
{
    public:
        BSTNode<T>* root {nullptr};
    BST() = default;

    void insert_node(T value, BSTNode<T>* current_node)
    {
        if (!root)
        {
            root = new BSTNode<T>(value);
            return;
        }
        if(value < current_node->data)
        {
            if(!current_node->left)
            {
                current_node->left = new BSTNode<T>(value);
            } else {
                insert_node(value, current_node->left);
            }
        } else if (value > current_node->data)
        {
            if (!current_node->right)
            {
                current_node->right = new BSTNode<T>(value);
            } else {
                insert_node(value, current_node->right);
            }
        }
    }

    BSTNode<T>* search (T value, BSTNode<T>* current_node)
    {
        if (!current_node)
        {
            return nullptr;
        }
        
        if(value == current_node)
        {
            return current_node;
        } else if (value < current_node->data) {
            return search(value, current_node->left);
        } else {
            return search(value, current_node->right);
        }
    }

    BSTNode<T>* delete_node(BSTNode<T>* root, T value)
    {
        if (!root)
        {
            return root;
        }
        if (value < root->data)
        {
            root->left = delete_node(root->left, value);
        } else if (value > root->data)
        {
            root->right = delete_node(root->right, value);
        } else {
            if (!root->left)
            {
                BSTNode<T>* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right)
            {
                BSTNode<T>* temp = root->left;
                delete root;
                return temp;
            }
            BSTNode<T>* temp = root->right;
            while (temp && temp->left)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
        return root;
    }

    void inorder_traversal(BSTNode<T>* node, vector<T>& climb)
    {
        if (!node) return;
        inorder_traversal(node->left, climb);
        climb.push_back(node->data);
        inorder_traversal(node->right, climb);     
    }

};

int main() {

    // Create a BST
    BST<int> bst;

    // Insert values
    vector<int> values = {5, 6, 7, 8, 9, 10, 11};
    for (int v : values)
    {
        bst.insert_node(v, bst.root);
    }

    vector<int> in_order;
    bst.inorder_traversal(bst.root, in_order);
    for (int data : in_order) {
        cout << data << " ";
    }
    cout << '\n';

    // Delete values
    vector<int> del {5, 10};
    for (int v : del)
    {
        bst.root = bst.delete_node(bst.root, v);
    }

    in_order.clear();
    bst.inorder_traversal(bst.root, in_order);
    for (int data : in_order) {
        cout << data << " ";
    }

    return 0;
}

