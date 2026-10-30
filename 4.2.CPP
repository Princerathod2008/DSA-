
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

void deleteValue(int value) {
    if (head == nullptr) {
        cout << "Queue is empty\n";
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr &&
           temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Token not found\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void forwardPrint(Node* temp) {
    if (temp == nullptr)
        return;

    cout << temp->data << " ";
    forwardPrint(temp->next);
}

void reversePrint(Node* temp) {
    if (temp == nullptr)
        return;

    reversePrint(temp->next);
    cout << temp->data << " ";
}

int main() {
    int n, value;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(value);
    }

    cout << "Forward: ";
    forwardPrint(head);
    cout << endl;

    cout << "Reverse: ";
    reversePrint(head);
    cout << endl;

    cin >> value;
    deleteValue(value);

    cout << "After deletion: ";
    forwardPrint(head);
    cout << endl;

    return 0;
}
