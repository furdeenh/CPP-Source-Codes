#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// A class to create and add nodes
template <typename T>
class TreeNode {

    public:
        TreeNode(T val): data(val) {}
        
        void add_child(vector<TreeNode<T>*> child_arr) {
            children = child_arr;
        }

        T data;
        vector<TreeNode<T>*> children;
};

// A class to create tree and perform tree operations
template <typename T>
class Tree {

    public:
        Tree(TreeNode<T>* root_node): root(root_node) {}

        void preorder_traversal(TreeNode<T>* node, vector<T>& traversal) {
            // If no nodes are left,
            // end the recursion
            if(!node) {
                return;
            }
      
            // Append node data
            traversal.push_back(node->data);

            for(const auto& child: node->children) {
                // Recursively traverse child nodes
                preorder_traversal(child, traversal);
            }
        }

        void postorder_traversal(TreeNode<T>* node, vector<T>& traversal) {
            // If no nodes are left,
            // end the recursion
            if(!node) {
                return;
            }

            for(const auto& child: node->children) {
                // Recursively traverse child nodes
                postorder_traversal(child, traversal);
            }

            // Append node data
            traversal.push_back(node->data);
        }

        void breadth_first_traversal(vector<T>& traversal) {
            // If no nodes are left,
            // end the recursion
            if(!root) {
                return;
            }

            queue<TreeNode<T>*> q;
            q.push(root);

            while(!q.empty()) {
                auto current_node = q.front();
                q.pop();
                traversal.push_back(current_node->data);

                for(const auto& child: current_node->children) {
                    q.push(child);
                }
            }    
        }

        TreeNode<T>* root {nullptr};
};

int main() {

    TreeNode<char>* A = new TreeNode<char>('A');
    TreeNode<char>* B = new TreeNode<char>('B');
    TreeNode<char>* C = new TreeNode<char>('C');
    TreeNode<char>* D = new TreeNode<char>('D');
    TreeNode<char>* E = new TreeNode<char>('E');
    TreeNode<char>* F = new TreeNode<char>('F');
    TreeNode<char>* G = new TreeNode<char>('G');

    A->add_child({B, C, D});
    B->add_child({E, F});
    E->add_child({G});

    // Create the tree
    Tree<char> general_tree = Tree<char>(A);

    vector<char> traversal1;
    cout << "Preorder Traversal: ";
    general_tree.preorder_traversal(general_tree.root, traversal1);

    for(const auto& item: traversal1) {
        cout << item << " ";
    }
    cout << "\n";

    vector<char> traversal2;
    cout << "Postorder Traversal: ";
    general_tree.postorder_traversal(general_tree.root, traversal2);

    for(const auto& item: traversal2) {
        cout << item << " ";
    }
    cout << "\n";

    vector<char> traversal3;
    cout << "Breadth-First Traversal: ";
    general_tree.breadth_first_traversal(traversal3);
    for(const auto& item: traversal3) {
        cout << item << " ";
    }
    
    return 0;
}