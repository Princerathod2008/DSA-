
#include <iostream>
using namespace std;

class Queue {
    int *a;
    int front, rear, count, capacity;

public:
    Queue(int n) {
        capacity = n;
        a = new int[n];
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int token) {
        if (count == capacity) {
            cout << "Error: Queue is full\n";
            return;
        }

        rear = (rear + 1) % capacity;
        a[rear] = token;
        count++;

        displayFront();
    }

    void serve() {
        if (count == 0) {
            cout << "Error: Queue is empty\n";
            return;
        }

        cout << "Served token: " << a[front] << endl;
        front = (front + 1) % capacity;
        count--;

        displayFront();
    }

    void displayFront() {
        if (count == 0)
            cout << "Front token: None\n";
        else
            cout << "Front token: " << a[front] << endl;
    }

    ~Queue() {
        delete[] a;
    }
};

int main() {
    int n, operations;
    cin >> n >> operations;

    Queue q(n);

    while (operations--) {
        int type;
        cin >> type;

        if (type == 1) {
            int token;
            cin >> token;
            q.join(token);
        }
        else if (type == 2) {
            q.serve();
        }
        else {
            cout << "Invalid operation\n";
        }
    }

    return 0;
}
