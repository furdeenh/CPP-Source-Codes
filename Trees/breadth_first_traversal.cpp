#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

template <typename T>
class Tree {

    public:
        Tree(TreeNode<T>* root_node): root(root_node) {}
        TreeNode<T>* root {nullptr};

        void breadth_first_traversal(vector<T>& traversal)
        {
            if(!root)
            {
                return;
            }
            queue<TreeNode<T>*> q;
            q.push(root);
            while(!q.empty())
            {
                auto current_node = q.front();
                q.pop();
                traversal.push_back(current_node->data);

                for (const auto& child : current_node->children)
                {
                    q.push(child);
                }
            }
        }



};

int main() {

    // Create the nodes
    TreeNode<char>* A = new TreeNode<char>('A');
    TreeNode<char>* B = new TreeNode<char>('B');
    TreeNode<char>* C = new TreeNode<char>('C');
    TreeNode<char>* D = new TreeNode<char>('D');
    TreeNode<char>* E = new TreeNode<char>('E');
    TreeNode<char>* F = new TreeNode<char>('F');
    TreeNode<char>* G = new TreeNode<char>('G');

    // Define the relationships
    A->add_child({B, C, D});
    B->add_child({E, F});
    E->add_child({G});

    // Create the tree
    Tree<char> general_tree = Tree<char>(A);

    vector<char> traversal;
    cout << "Breadth-First Traversal: ";
    general_tree.breadth_first_traversal(traversal);
    for(const auto& item: traversal) {
        cout << item << " ";
    }
    return 0;
}