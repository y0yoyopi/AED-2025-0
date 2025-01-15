#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int arr[100];

public:
    Stack() { top = -1; }

    void push(int x){
        if (top >= 99) {
            return;
        }
        arr[++top] = x;
    }

    int pop(){
        if (top < 0) {
            return -1;
        }
        return arr[top--];
    }

    int peek(){
        if (top < 0) {
            return 0;
        }
        return arr[top];
    }

    bool isEmpty(){
        return (top < 0);
    }
};


int main()
{
    
    Stack s;
  
    s.push(10);
    s.push(20);
    s.push(30);
  
    cout << "Top element is: " << s.peek() << endl;
    cout << "Elements present in stack : ";
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    return 0;
}
