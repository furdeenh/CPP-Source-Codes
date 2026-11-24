#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TreeNode {
public:

    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T val): data(val) {}

    void add_child(vector<TreeNode<T>*> child_arr)
    {
        children = child_arr;
    }
};

template <typename T>
class Tree
{
    public: 
    TreeNode<T>* root {nullptr};
    Tree(TreeNode<T>* root_node): root(root_node){}

    void postorder_traversal(TreeNode<T>* node, vector<T>& traversal)
    {
        if (!node)
        {
            return;
        }

        for (const auto& child : node->children)
        {
            postorder_traversal(child, traversal);
        }

        traversal.push_back(node->data);
    }

};

int main()
{
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

    Tree<char> general_tree = Tree<char>(A);

    vector<char> traversal;

    cout << "Postorder Traversal: ";
    general_tree.postorder_traversal(general_tree.root, traversal);

    for(const auto& item: traversal) {
        cout << item << " ";
    }

    return 0;

}
