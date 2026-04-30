#include <bits/stdc++.h>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    ~Queue() {
        while (frontNode != nullptr) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
        rearNode = nullptr;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }

        cout << value << " inserted into queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = frontNode;
        int deletedValue = temp->data;
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
        cout << deletedValue << " deleted from queue.\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element: " << frontNode->data << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        Node* current = frontNode;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Using Linked List ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
