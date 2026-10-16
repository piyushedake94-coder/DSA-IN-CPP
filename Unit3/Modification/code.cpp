
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};

Student* head = NULL;

// Add student record
void addStudent() {
    Student* newNode = new Student;

    cout << "Enter Roll Number: ";
    cin >> newNode->rollNo;

    Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == newNode->rollNo) {
            cout << "Roll number already exists!\n";
            delete newNode;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newNode->name);

    cout << "Enter Marks: ";
    cin >> newNode->marks;

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Student added successfully!\n";
}

// Search student record
void searchStudent() {
    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    Student* temp = head;

    while (temp != NULL) {
        if (temp->rollNo == roll) {
            cout << "Student Found!\n";
            cout << "Roll Number: " << temp->rollNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Marks: " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Student not found!\n";
}

// Display all student records
void displayStudents() {
    if (head == NULL) {
        cout << "No student records available!\n";
        return;
    }

    Student* temp = head;

    while (temp != NULL) {
        cout << "\nRoll Number: " << temp->rollNo << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Marks: " << temp->marks << endl;
        temp = temp->next;
    }
}

// Delete student record
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    Student* temp = head;
    Student* prev = NULL;

    while (temp != NULL && temp->rollNo != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Student not found!\n";
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Student deleted successfully!\n";
}

// Free memory
void freeList() {
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display Students\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                freeList();
                cout << "Program terminated.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
