#include <iostream>

// Node struct representing an element in the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class for managing the linked list operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new element at the end of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete an element from the linked list
    void remove(int value) {
        if (!head) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Function to print the elements of the linked list
    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to deallocate memory when the LinkedList object goes out of scope
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList myList;

    // Insert elements into the linked list
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);

    // Print the linked list
    std::cout << "Linked List: ";
    myList.print();

    // Remove an element from the linked list
    myList.remove(20);

    // Print the updated linked list
    std::cout << "Linked List after removal: ";
    myList.print();

    return 0;
}
