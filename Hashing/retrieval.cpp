#include <iostream>
#include <vector>

using namespace std;

class HashData {
public:
    // initialize a vector of 10 items
    HashData(): table(10, -1) {
     }

    // compute hash
    int hash_function(int key) {
        return key % 10;
    }

    // insert data to hash table
    void put(int key) {
        int hash_value = hash_function(key);
        table[hash_value] = key;
    }

    // display hash table
    void display() {
        for(int i = 0; i < 10; ++i)
            cout << i << " : " << table[i] << '\n';
    }

    // retrieve key from hash table
    pair<int, int> retrieve(int item) {

        int hash_value = hash_function(item);
 
        // return key from the hash table
        return {hash_value, table[hash_value]};
    }
 
private:   
    vector<int> table;
};
            
int main() {
    // keys
    vector<int> keys {1, 300, 209, 117, 12};

    HashData hash1;

    // apply hash function to each key
    for(auto key: keys)
        hash1.put(key);

    // retrieve values
    pair<int, int> retrieve_117 = hash1.retrieve(117);
    cout << "hash_value : " << retrieve_117.first << ", key: " << retrieve_117.second << '\n';
    pair<int, int> retrieve_13 = hash1.retrieve(13);
    cout << "hash_value : " << retrieve_13.first << ", key: " << retrieve_13.second << '\n';
    return 0;
}