// Clase para representar un nodo en la lista enlazada
class Node {
public:
    std::string key;
    std::string value;
    Node* next;

    Node(const std::string& key, const std::string& value) : key(key), value(value), next(nullptr) {}
};

// Clase para representar una lista enlazada
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    void insert(const std::string& key, const std::string& value) {
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    void remove(const std::string& key) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            return; // Key not found
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    std::string search(const std::string& key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return ""; // Key not found
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "(" << current->key << ": " << current->value << ") -> ";
            current = current->next;
        }
        std::cout << "NULL";
    }
};

// Clase para representar la tabla hash
class HashTable {
private:
    int numBuckets;
    std::vector<LinkedList> table;

    int hashFunction(const std::string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += ch;
        }
        return hashValue % numBuckets;
    }

public:
    HashTable(int buckets) : numBuckets(buckets), table(buckets) {}

    void insert(const std::string& key, const std::string& value) {
        int index = hashFunction(key);
        table[index].insert(key, value);
    }

    void remove(const std::string& key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    std::string search(const std::string& key) {
        int index = hashFunction(key);
        return table[index].search(key);
    }

    void display() {
        for (int i = 0; i < numBuckets; ++i) {
            std::cout << "Bucket " << i << ": ";
            table[i].display();
            std::cout << std::endl;
        }
    }
};
