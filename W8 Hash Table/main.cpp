#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

// HashTable using chaining to resolve collisions
class ChainingHashTable {
    // https://www.geeksforgeeks.org/c-program-hashing-chaining/
private:
    vector<vector<pair<string, int>>> table;
    int capacity;

public:
    ChainingHashTable(int size) : capacity(size) {
        // takes in int w size
        table.resize(capacity);
    }

    int hash(const string& key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue += c;
        }
        return hashValue % capacity;
    }

    void insert(const string& key, int value) {
        // onset key value pair in hash 
        int index = hash(key);
        table[index].push_back(make_pair(key, value));
    }

    bool contains(const string& key) {
        // test for exist
        int index = hash(key);
        for (const auto& entry : table[index]) { // table [index] 
            if (entry.first == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Create a ChainingHashTable
    ChainingHashTable chainingTable(10);
    chainingTable.insert("BTC", 4500);
    chainingTable.insert("ETH", 2500);
    chainingTable.insert("XRP", 1);

    // Check if certain keys exist in the ChainingHashTable
    cout << "Contains 'BTC': " << (chainingTable.contains("BTC") ? "Yes" : "No") << endl;
    cout << "Contains 'ETH': " << (chainingTable.contains("ETH") ? "Yes" : "No") << endl;
    cout << "Contains 'XRP': " << (chainingTable.contains("XRP") ? "Yes" : "No") << endl;

    return 0;
}
