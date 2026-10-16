
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};

Student* last = NULL;

// Add a new student record
void addStudent() {
    Student* newNode = new Student;

    cout << "Enter Roll Number: ";
    cin >> newNode->rollNo;

    Student* temp = (last == NULL) ? NULL : last->next;
    if (last != NULL) {
        do {
            if (temp->rollNo == newNode->rollNo) {
                cout << "Roll number already exists!\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
    }

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, newNode->name);
    cout << "Enter Marks: ";
    cin >> newNode->marks;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    cout << "Student record added successfully!\n";
}

// Display all student records
void displayStudents() {
    if (last == NULL) {
        cout << "No student records available.\n";
        return;
    }

    Student* temp = last->next;
    cout << "\n--- Student Records ---\n";

    do {
        cout << "Roll Number: " << temp->rollNo << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Marks: " << temp->marks << endl;
        cout << "----------------------\n";
        temp = temp->next;
    } while (temp != last->next);
}

// Search for a student
void searchStudent() {
    if (last == NULL) {
        cout << "No student records available.\n";
        return;
    }

    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    Student* temp = last->next;
    do {
        if (temp->rollNo == roll) {
            cout << "Student Found!\n";
            cout << "Roll Number: " << temp->rollNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Marks: " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    cout << "Student record not found.\n";
}

// Update student details
void updateStudent() {
    if (last == NULL) {
        cout << "No student records available.\n";
        return;
    }

    int roll;
    cout << "Enter Roll Number to Update: ";
    cin >> roll;

    Student* temp = last->next;
    do {
        if (temp->rollNo == roll) {
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, temp->name);
            cout << "Enter New Marks: ";
            cin >> temp->marks;
            cout << "Student record updated successfully!\n";
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    cout << "Student record not found.\n";
}

// Delete a student record
void deleteStudent() {
    if (last == NULL) {
        cout << "No student records available.\n";
        return;
    }

    int roll;
    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    Student* current = last->next;
    Student* previous = last;

    do {
        if (current->rollNo == roll) {
            if (current == last && current->next == last) {
                last = NULL;
            } else {
                previous->next = current->next;
                if (current == last) {
                    last = previous;
                }
            }

            delete current;
            cout << "Student record deleted successfully!\n";
            return;
        }

        previous = current;
        current = current->next;
    } while (current != last->next);

    cout << "Student record not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    // Free all remaining dynamically allocated nodes
    while (last != NULL) {
        Student* first = last->next;
        if (first == last) {
            delete last;
            last = NULL;
        } else {
            last->next = first->next;
            delete first;
        }
    }

    return 0;
}
