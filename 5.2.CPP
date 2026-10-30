
#include <iostream>
using namespace std;

// Singly Circular Linked List
struct SNode {
    int id;
    SNode* next;

    SNode(int x) {
        id = x;
        next = nullptr;
    }
};

SNode* sHead = nullptr;

void sJoin(int id) {
    SNode* node = new SNode(id);

    if (sHead == nullptr) {
        sHead = node;
        node->next = sHead;
        return;
    }

    SNode* temp = sHead;
    while (temp->next != sHead)
        temp = temp->next;

    temp->next = node;
    node->next = sHead;
}

void sLeave(int id) {
    if (sHead == nullptr)
        return;

    SNode* curr = sHead;
    SNode* prev = nullptr;

    do {
        if (curr->id == id)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != sHead);

    if (curr->id != id)
        return;

    if (curr == sHead && curr->next == sHead) {
        sHead = nullptr;
    } else {
        if (curr == sHead) {
            SNode* last = sHead;
            while (last->next != sHead)
                last = last->next;

            sHead = sHead->next;
            last->next = sHead;
        } else {
            prev->next = curr->next;
        }
    }

    delete curr;
}

void sDisplay() {
    if (sHead == nullptr) {
        cout << "Empty";
        return;
    }

    SNode* temp = sHead;
    do {
        cout << temp->id << " ";
        temp = temp->next;
    } while (temp != sHead);
}

// Doubly Circular Linked List
struct DNode {
    int id;
    DNode* next;
    DNode* prev;

    DNode(int x) {
        id = x;
        next = prev = nullptr;
    }
};

DNode* dHead = nullptr;

void dJoin(int id) {
    DNode* node = new DNode(id);

    if (dHead == nullptr) {
        dHead = node;
        node->next = node;
        node->prev = node;
        return;
    }

    DNode* last = dHead->prev;

    node->next = dHead;
    node->prev = last;
    last->next = node;
    dHead->prev = node;
}

void dLeave(int id) {
    if (dHead == nullptr)
        return;

    DNode* curr = dHead;

    do {
        if (curr->id == id)
            break;
        curr = curr->next;
    } while (curr != dHead);

    if (curr->id != id)
        return;

    if (curr->next == curr) {
        dHead = nullptr;
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        if (curr == dHead)
            dHead = curr->next;
    }

    delete curr;
}

void dDisplay() {
    if (dHead == nullptr) {
        cout << "Empty";
        return;
    }

    DNode* temp = dHead;
    do {
        cout << temp->id << " ";
        temp = temp->next;
    } while (temp != dHead);
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int type, id;
        cin >> type;

        if (type == 1) {
            cin >> id;
            sJoin(id);
            dJoin(id);
        } else if (type == 2) {
            cin >> id;
            sLeave(id);
            dLeave(id);
        } else if (type != 3) {
            cout << "Invalid operation\n";
            continue;
        }

        cout << "Singly Circular: ";
        sDisplay();
        cout << endl;

        cout << "Doubly Circular: ";
        dDisplay();
        cout << endl;
    }

    return 0;
}
