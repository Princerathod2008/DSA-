
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertFront(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void insertPosition(int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1) {
        insertFront(value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int operations;
    cin >> operations;

    while (operations--) {
        int type, value, pos;
        cin >> type >> value;

        if (type == 1) {
            insertFront(value);
        }
        else if (type == 2) {
            insertEnd(value);
        }
        else if (type == 3) {
            cin >> pos;
            insertPosition(value, pos);
        }
        else {
            cout << "Invalid operation\n";
        }

        display();
    }

    return 0;
}
