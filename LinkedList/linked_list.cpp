#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
class LinkedList{
    Node<T>* head;
    public:
        LinkedList() : head(nullptr) {}

    void insert_node_at_beginning(T data)
    {
        Node<T>* new_node = Node<T>({data});
        new_node->next = head;
        head = new_node;
    }

    void insert_node_at_position(T data, int position)
    {
        if (position == 1)
        {
            insert_node_at_beginning(data);
            return;
        }

        Node<T>* new_node = new Node<T>({data});

        Node<T>* current = head;
        
        int i = 1;
        while (i < position - 1)
        {
            current = current->next;
            ++i;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    void append(T data)
    {
        Node<T>* new_node = new Node<T>({data});
        if (head == nullptr) {  
            head = new_node;
            return;
        }
        Node<T>* current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    void insert_node(T data, int position = 0)
    {
        if (!position || position < 0 || position > count_elements()) {
            append(data); 
            return;
        }
        insert_at_position(data, position);
    }

    int count_elements()
    {
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void concatenate(LinkedList* list)
    {
        Node<T>* current = head;
        while(current -> next != nullptr){
            current = current -> next;
        }
        Node<T>* temp = list->head;
        current->next = temp;
    }

    void display() {
        Node<T>* current = head;
        // Traverse the list and print each node's data
        while (current != nullptr) {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "nullptr\n";  // End the list with nullptr to indicate the end
    }

};


int main(){
   LinkedList<int> my_list;

   my_list.append(2);
   my_list.append(4);
   my_list.append(6);
   my_list.append(8);

   LinkedList<int> my_another_list;
   my_another_list.append(10);
   my_another_list.append(12);
   my_another_list.append(14);
   my_another_list.append(16);

   cout << "Linked List 1:\n";
   my_list.display();

   cout << "Linked List 2:\n";
   my_another_list.display();

   my_list.concatenate(&my_another_list);
   cout << "After concatenating:\n";
   my_list.display();
}