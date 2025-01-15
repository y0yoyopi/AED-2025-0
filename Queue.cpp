class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Añadir elemento al final
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Elimina y devuelve el elemento del frente de la cola
    int dequeue() {
        if (front == nullptr) {
            return -1;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        int data = temp->data;
        delete temp;
        return data;
    }

    // Devuelve el elemento del frente sin eliminarlo
    int last() {
        if (front == nullptr) {
            return -1;
        }
        return front->data;
    }

    // Verifica si la cola está vacía
    bool isEmpty() {
        return front == nullptr;
    }
};
