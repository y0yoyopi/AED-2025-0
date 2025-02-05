// Tamaño base para la tabla hash (se puede modificar según necesidad)
const int HASH_SIZE = 26;

// Implementación de una tabla hash desde cero con encadenamiento separado
class HashTable {
private:
    struct HashNode {
        char key;
        struct TrieNode* value;
        HashNode(char k, TrieNode* v) : key(k), value(v) {}
    };

    list<HashNode> table[HASH_SIZE];

    int hashFunction(char key) {
        return key - 'a'; // Función hash simple para caracteres 'a' - 'z'
    }

public:
    TrieNode* get(char key) {
        int index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) return node.value;
        }
        return nullptr;
    }

    void insert(char key, TrieNode* value) {
        int index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                node.value = value; // Actualizar si ya existe
                return;
            }
        }
        table[index].emplace_back(key, value); // Insertar nuevo nodo
    }

    void erase(char key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const HashNode& node) { return node.key == key; });
    }

    bool empty() {
        for (int i = 0; i < HASH_SIZE; i++) {
            if (!table[i].empty()) return false;
        }
        return true;
    }
};

// Nodo del Trie usando nuestra tabla hash personalizada
class TrieNode {
public:
    HashTable children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// Implementación del Trie
class Trie {
private:
    TrieNode* root;

    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return node->children.empty();
        }

        char ch = word[depth];
        TrieNode* nextNode = node->children.get(ch);
        if (!nextNode) return false;

        if (deleteHelper(nextNode, word, depth + 1)) {
            node->children.erase(ch);
            return !node->isEndOfWord && node->children.empty();
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.get(c)) {
                node->children.insert(c, new TrieNode());
            }
            node = node->children.get(c);
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            node = node->children.get(c);
            if (!node) return false;
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            node = node->children.get(c);
            if (!node) return false;
        }
        return true;
    }

    void remove(const string& word) {
        deleteHelper(root, word, 0);
    }

    ~Trie() {
        deleteTrie(root);
    }

    void deleteTrie(TrieNode* node) {
        if (!node) return;
        for (char c = 'a'; c <= 'z'; c++) {
            TrieNode* child = node->children.get(c);
            if (child) {
                deleteTrie(child);
                node->children.erase(c);
            }
        }
        delete node;
    }
};
