// ONE ONE ONE
#include <iostream>

struct Node {
    int row, col, value;
    Node* next;
};

class SparseMatrix {
    Node* head;
    int rows, cols;

public:
    SparseMatrix(int n, int m) : rows(n), cols(m), head(nullptr) {}

    ~SparseMatrix() {
        // Destructor to clean up the dynamically allocated memory
        Node* temp = head;
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }

    void insert(int r, int c, int val) {
        if (r > rows || c > cols) { // Prevent insertions out of range.
            std::cout << "Error: Out_Of_Range insertion at direction " << head << std::endl;
            return; // Limit bounds
        }
        Node* newNode = new Node{r, c, val, nullptr}; // Memoria dinámica
        if (!head) {
            head = newNode;
            head->next = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) { // Find the last node.
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
        }
    }

    void display() {
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                bool found = false;
                Node* temp = head;
                while (temp) {
                    if (temp->row == i && temp->col == j) {
                        std::cout << temp->value << " ";
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }
                if (!found) std::cout << "0 "; // Print 0 for empty positions.
            }
            std::cout << "\n";
        }
    }
};

int main() {
    std::cout << "Display [Sample] Matrix.\n" << std::endl;
    SparseMatrix sample = SparseMatrix(9, 9);
    sample.insert(2, 1, 3);
    sample.insert(2, 2, 5);
    sample.insert(2, 7, 9);
    sample.insert(3, 7, 5);
    sample.insert(4, 5, 5);
    sample.insert(4, 9, 22);
    sample.insert(6, 5, 5);
    sample.insert(7, 8, 5);
    sample.insert(9, 9, 5);
    sample.insert(10, 10, 2); // Out of range insertion.
    sample.display();
}

//TWO 2 TOO TUBA TUNGSTENO 
//CIRCULAR

#include <iostream>
using namespace std;

struct Node {
    int row, col, value;
    Node* next;
};

class CircularSparseMatrix {
    Node* head;
    int rows, cols;

public:
    CircularSparseMatrix(int n, int m) : rows(n), cols(m), head(nullptr) {}

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    void insert(int r, int c, int val) {
        Node* newNode = new Node{r, c, val, nullptr};
        if (r > getRows() || c > getCols()) {
            cout << "insertion out of range" << endl;
            return;
        }
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    static CircularSparseMatrix add(CircularSparseMatrix& m1, CircularSparseMatrix& m2) {
        CircularSparseMatrix result(m1.rows, m1.cols);
        Node* temp1 = m1.head;
        Node* temp2 = m2.head;

        do {
            result.insert(temp1->row, temp1->col, temp1->value);
            temp1 = temp1->next;
        } while (temp1 != m1.head);

        do {
            Node* temp = result.head;
            bool added = false;
            do {
                if (temp->row == temp2->row && temp->col == temp2->col) {
                    temp->value += temp2->value;
                    added = true;
                    break;
                }
                temp = temp->next;
            } while (temp != result.head);
            if (!added) result.insert(temp2->row, temp2->col, temp2->value);
            temp2 = temp2->next;
        } while (temp2 != m2.head);

        return result;
    }

    void display() {
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                bool found = false;
                Node* temp = head;
                do {
                    if (temp->row == i && temp->col == j) {
                        cout << temp->value << " ";
                        found = true;
                        break;
                    }
                    temp = temp->next;
                } while (temp != head);
                if (!found) cout << "0 ";
            }
            cout << "\n";
        }
    }

    ~CircularSparseMatrix() {
        if (head) {
            Node* temp = head;
            do {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            } while (temp != head);
        }
    }
};

int main() {
    CircularSparseMatrix m1(9, 7), m2(9, 7);

    // M1
    m1.insert(2, 3, 3);
    m1.insert(5, 1, 3);
    m1.insert(5, 4, 1);
    m1.insert(7, 4, 5);
    m1.insert(8, 1, 1);
    m1.insert(8, 6, 4);
    m1.insert(9, 3, 2);

    // M2
    m2.insert(2, 3, 4);
    m2.insert(5, 1, 2);
    m2.insert(5, 4, 1);
    m2.insert(7, 4, 4);
    m2.insert(8, 1, 3);
    m2.insert(8, 6, 2);
    m2.insert(9, 3, 1);

    CircularSparseMatrix result = CircularSparseMatrix::add(m1, m2);
    result.display();

    return 0;
}
