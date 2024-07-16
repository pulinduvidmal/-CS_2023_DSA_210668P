#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Append to the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Remove first occurrence of a specific value
    void remove(int data) {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != data) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            std::cout << "Element not found" << std::endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Insert at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int data) {
        append(data); // Reusing append method
    }

    // Insert at a specific position
    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cout << "Position out of range" << std::endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete from a specific position
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* temp = head;
        if (position == 0) {
            head = temp->next;
            delete temp;
            return;
        }
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            std::cout << "Position out of range" << std::endl;
            return;
        }
        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }

    // Search for a specific value
    bool search(int data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display all elements in the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.insertAtBeginning(0);
    list.insertAtPosition(5, 2);

    std::cout << "Linked List: ";
    list.display();

    list.remove(5);
    std::cout << "After removing 5: ";
    list.display();

    list.deleteFromBeginning();
    std::cout << "After deleting from beginning: ";
    list.display();

    list.deleteFromEnd();
    std::cout << "After deleting from end: ";
    list.display();

    list.deleteFromPosition(1);
    std::cout << "After deleting from position 1: ";
    list.display();

    std::cout << "Search for 2: " << (list.search(2) ? "Found" : "Not Found") << std::endl;

    list.reverse();
    std::cout << "Reversed Linked List: ";
    list.display();

    return 0;
}
