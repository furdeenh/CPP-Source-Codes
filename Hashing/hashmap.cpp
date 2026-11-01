// HashMap
#include <iostream>
#include <list>
#include <optional>
using namespace std;

template <typename K, typename V>
struct KeyPair {
    K key;
    V value;
};

template <typename K, typename V>
class HashMap {
    private:
        static const int tableSize = 128;
        list<KeyPair<K, V>>* hashtable;

    public:
        HashMap()
        {
            hashtable = new std::list<KeyPair<K, V>>[tableSize];
        }
        ~HashMap()
        {
            delete[] hashtable;
        }

        int hash(const K& key)
        {
            return key % tableSize;
        }

        void insert(const K key, const V value)
        {
            int index = hash(key);
            for (KeyPair<K, V>& pair : hashtable[index])
            {
                if(pair.key == key)
                {
                    pair.value == value;
                    return;
                }
            }
            hashtable[index].push_back(KeyPair<K, V>{key, value});
        }

        optional<V> get(const K& key)
        {
            int index = hash(key);
            for (const KeyPair<K, V>& pair : hashtable[index])
            {
                if (pair.key == key)
                {
                    return pair.value;
                }
            }
            return {};
        }

        void remove(const K& key)
        {
            int index = hash(key);
            for (auto i = hashtable[index].begin(); i != hashtable[index].end(); ++i)
            {
                if (i->key == key)
                {
                    hashtable[index].erase(i);
                    return;
                }
            }
        }

};

int main() {
    HashMap<int, string> Student;

    // Insert values into map
    Student.insert(1, "James");
    Student.insert(2, "Paul");
    Student.insert(3, "Mira");

    cout << "Student with ID 1 is " << Student.get(1).value() << endl;
    cout << "Student with ID 2 is " << Student.get(2).value() << endl;

    // Remove student with id 2
    Student.remove(2);

    // Throws a runtime error because we're trying
    // to access a value that doesn't exist
    // cout << "Student with ID 3 is " << Student.get(2).value();

    return 0;
}