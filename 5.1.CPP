
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = nullptr;
        next = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;

void addFront(string song) {
    Node* newNode = new Node(song);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addEnd(string song) {
    Node* newNode = new Node(song);

    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAfter(string target, string song) {
    Node* temp = head;

    while (temp != nullptr && temp->song != target)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Song not found\n";
        return;
    }

    Node* newNode = new Node(song);

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

void removeFirst() {
    if (head == nullptr) {
        cout << "Playlist is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr;

    delete temp;
}

int countSongs() {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int operations;
    cin >> operations;

    while (operations--) {
        int type;
        string song, target;

        cin >> type;

        if (type == 1) {
            cin >> song;
            addFront(song);
        } else if (type == 2) {
            cin >> song;
            addEnd(song);
        } else if (type == 3) {
            cin >> target >> song;
            insertAfter(target, song);
        } else if (type == 4) {
            removeFirst();
        } else if (type == 5) {
            cout << "Song count: " << countSongs() << endl;
        } else {
            cout << "Invalid operation\n";
        }

        display();
    }

    return 0;
}
