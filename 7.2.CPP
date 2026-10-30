
#include <iostream>
using namespace std;

struct Node {
    int patient;
    Node* next;

    Node(int p) {
        patient = p;
        next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void arrive(int patient) {
        Node* newNode = new Node(patient);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        displayFront();
    }

    void attend() {
        if (front == nullptr) {
            cout << "Error: No patients waiting\n";
            displayFront();
            return;
        }

        Node* temp = front;
        cout << "Attended patient: " << front->patient << endl;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        displayFront();
    }

    void displayFront() {
        if (front == nullptr)
            cout << "Front patient: None\n";
        else
            cout << "Front patient: " << front->patient << endl;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    int operations;
    cin >> operations;

    Queue q;

    while (operations--) {
        int type;
        cin >> type;

        if (type == 1) {
            int patient;
            cin >> patient;
            q.arrive(patient);
        } else if (type == 2) {
            q.attend();
        } else {
            cout << "Invalid operation\n";
        }
    }

    return 0;
}
