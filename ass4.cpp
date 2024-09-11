#include <iostream>
using namespace std;

class Route {
public:
    int data;
    Route* next;
    Route* prev;
};

void insertEnd(Route** start, int value) {
    if (*start == NULL) {
        Route* new_route = new Route;
        new_route->data = value;
        new_route->next = new_route->prev = new_route;
        *start = new_route;
        return;
    }

    Route* last = (*start)->prev;

    Route* new_route = new Route;
    new_route->data = value;

    new_route->next = *start;
    (*start)->prev = new_route;

    new_route->prev = last;
    last->next = new_route;
}

void insertBegin(Route** start, int value) {
    if (*start == NULL) {
        insertEnd(start, value);
        return;
    }

    Route* last = (*start)->prev;

    Route* new_route = new Route;
    new_route->data = value;

    new_route->next = *start;
    new_route->prev = last;

    last->next = (*start)->prev = new_route;

    *start = new_route;
}

void insertAtIndex(Route** start, int index, int value) {
   
    Route* new_route = new Route;
    new_route->data = value;

    Route* temp = *start;
    int count = 0;

    if (index == 0) {
        insertBegin(start, value);
        return;
    }

    while (count < index - 1) {
        temp = temp->next;
        if (temp == *start) {
            cout << "Index out of bounds." << endl;
            delete new_route;
            return;
        }
        count++;
    }

    new_route->next = temp->next;
    new_route->prev = temp;

    temp->next->prev = new_route;
    temp->next = new_route;
}

void display(Route* start) {
    if (start == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Route* temp = start;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

int main() {
    Route* start = NULL;
    int choice, value1, index;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert Route" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int l;
                cout << "Enter :\n1 for inserting in start\n2 for inserting in the end\n3 for inserting at a specific index: ";
                cin >> l;
                switch (l) {
                    case 1:
                        cout << "Enter value to insert at beginning: ";
                        cin >> value1;
                        insertBegin(&start, value1);
                        break;

                    case 2:
                        cout << "Enter value to insert at end: ";
                        cin >> value1;
                        insertEnd(&start, value1);
                        break;

                    case 3:
                        cout << "Enter value to insert: ";
                        cin >> value1;
                        cout << "Enter index at which to insert: ";
                        cin >> index;
                        insertAtIndex(&start, index, value1);
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;

            case 2:
                cout << "Circular Doubly Linked List: ";
                display(start);
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}


