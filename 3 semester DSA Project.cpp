#include <iostream>
#include <string>
using namespace std;

/* =========================
   Patient Node (Linked List)
   ========================= */
struct Patient {
    int id;
    string name;
    int age;
    string disease;
    int priority;      // 1 = Critical, 2 = Serious, 3 = Normal
    Patient* next;
};

/* =========================
   Queue Class
   ========================= */
class Queue {
private:
    Patient* front;
    Patient* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(Patient* p) {
        if (rear == NULL) {
            front = rear = p;
        } else {
            rear->next = p;
            rear = p;
        }
    }

    Patient* dequeue() {
        if (isEmpty())
            return NULL;

        Patient* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        temp->next = NULL;
        return temp;
    }

    void display() {
        Patient* temp = front;
        while (temp != NULL) {
            cout << "  ID      : " << temp->id << endl;
            cout << "  Name    : " << temp->name << endl;
            cout << "  Age     : " << temp->age << endl;
            cout << "  Disease : " << temp->disease << endl;
            cout << "----------------------------------\n";
            temp = temp->next;
        }
    }

    bool search(int id) {
        Patient* temp = front;
        while (temp != NULL) {
            if (temp->id == id)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

/* =========================
   Emergency Room Class
   ========================= */
class EmergencyRoom {
private:
    Queue critical;
    Queue serious;
    Queue normal;
    int nextID;

public:
    EmergencyRoom() {
        nextID = 1;
    }

    void addPatient() {
        Patient* p = new Patient();

        p->id = nextID++;
        p->next = NULL;

        cin.ignore();
        cout << "\nEnter Patient Name   : ";
        getline(cin, p->name);

        cout << "Enter Age            : ";
        cin >> p->age;

        cin.ignore();
        cout << "Enter Disease        : ";
        getline(cin, p->disease);

        cout << "Priority (1 Critical, 2 Serious, 3 Normal): ";
        cin >> p->priority;

        if (p->priority == 1)
            critical.enqueue(p);
        else if (p->priority == 2)
            serious.enqueue(p);
        else
            normal.enqueue(p);

        cout << "\nPatient added successfully.";
        cout << "\nAssigned Patient ID  : " << p->id << endl;
    }

    void treatPatient() {
        Patient* p = NULL;

        if (!critical.isEmpty())
            p = critical.dequeue();
        else if (!serious.isEmpty())
            p = serious.dequeue();
        else if (!normal.isEmpty())
            p = normal.dequeue();

        if (p == NULL) {
            cout << "\nNo patients waiting.\n";
            return;
        }

        cout << "\n========== TREATING PATIENT ==========\n";
        cout << "ID      : " << p->id << endl;
        cout << "Name    : " << p->name << endl;
        cout << "Age     : " << p->age << endl;
        cout << "Disease : " << p->disease << endl;
        cout << "=====================================\n";

        delete p;
    }

    void displayAllPatients() {
        cout << "\n=========== WAITING PATIENTS ===========\n";

        cout << "\n--- Critical Patients ---\n";
        if (!critical.isEmpty())
            critical.display();
        else
            cout << "  None\n";

        cout << "\n--- Serious Patients ---\n";
        if (!serious.isEmpty())
            serious.display();
        else
            cout << "  None\n";

        cout << "\n--- Normal Patients ---\n";
        if (!normal.isEmpty())
            normal.display();
        else
            cout << "  None\n";

        cout << "=======================================\n";
    }

    void searchPatient() {
        int id;
        cout << "\nEnter Patient ID to search: ";
        cin >> id;

        if (critical.search(id) || serious.search(id) || normal.search(id)) {
            cout << "\nPatient record FOUND in system.\n";
        } else {
            cout << "\nPatient record NOT FOUND.\n";
        }
    }
};

/* =========================
   Main Function
   ========================= */
int main() {
    EmergencyRoom er;
    int choice;

    do {
        cout << "\n======================================\n";
        cout << "     HOSPITAL EMERGENCY ROOM SYSTEM\n";
        cout << "======================================\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Next Patient\n";
        cout << "3. Display All Patients\n";
        cout << "4. Search Patient by ID\n";
        cout << "5. Exit\n";
        cout << "--------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                er.addPatient();
                break;
            case 2:
                er.treatPatient();
                break;
            case 3:
                er.displayAllPatients();
                break;
            case 4:
                er.searchPatient();
                break;
            case 5:
                cout << "\nSystem closed successfully.\n";
                break;
            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
