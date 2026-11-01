#include <iostream>
#include <vector>

using namespace std;

class BinaryTree
{
    private:
        vector<int> vec;

    public:
        int parent (int index)
        {
            return (index - 1) / 2;
        }

        int left_child(int index)
        {
            return (2*index) + 1;
        }

        int right_child(int index)
        {
            return (2 * index) + 2;
        }

        int has_parent(int index)
        {
            return parent(index) >= 0;
        }

        bool has_left_child(int index)
        {
            return left_child(index) < vec.size();
        }

        bool has_right_child(int index)
        {
            return right_child(index) < vec.size();
        }

        void insert(int value)
        {
            vec.push_back(value);
        }

        void print_tree()
        {
            for (int value : vec)
            {
                cout << value << " ";
            }
            cout << endl;
        }

        int get_value_at(int index)
        {
            return vec[index];
        }

};




int main() {

    BinaryTree bt;

    // Insert elements into the binary tree
    for (int i = 0; i < 10; i++) {
        bt.insert(i);
    }

    // Display binary tree
    bt.print_tree();
    cout << endl;

    // Check some relationships
    int index = 3;
    if (bt.has_parent(index)) {
        cout << "Parent of node at index " << index << ": " << bt.get_value_at(bt.parent(index)) << endl;
    }

    if (bt.has_left_child(index)) {
        cout << "Left child of node at index " << index << ": " << bt.get_value_at(bt.left_child(index)) << endl;
    }

    if (bt.has_right_child(index)) {
        cout << "Right child of node at index " << index << ": " << bt.get_value_at(bt.right_child(index)) << endl;
    }

    return 0;
}