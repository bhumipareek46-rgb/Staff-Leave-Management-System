#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct LeaveRequest {
    int id;
    string employeeName;
    string leaveType;
    string startDate;
    string endDate;
    string reason;
    string status; // Pending, Approved, Rejected
};

class LeaveManagementSystem {
private:
    vector<LeaveRequest> requests;
    int nextId;

public:
    LeaveManagementSystem() : nextId(1) {}

    void submitLeaveRequest() {
        LeaveRequest req;
        req.id = nextId++;
        cin.ignore();

        cout << "\nEnter Employee Name: ";
        getline(cin, req.employeeName);

        cout << "Enter Leave Type (Annual, Sick, Casual, etc.): ";
        getline(cin, req.leaveType);

        cout << "Enter Start Date (dd-mm-yyyy): ";
        getline(cin, req.startDate);

        cout << "Enter End Date (dd-mm-yyyy): ";
        getline(cin, req.endDate);

        cout << "Enter Reason: ";
        getline(cin, req.reason);

        req.status = "Pending";
        requests.push_back(req);

        cout << "\n Leave request submitted successfully!\n";
    }

    void viewPendingRequests() {
        cout << "\n--- Pending Leave Requests ---\n";
        bool found = false;

        for (const auto &req : requests) {
            if (req.status == "Pending") {
                cout << "ID: " << req.id << "\nEmployee: " << req.employeeName
                     << "\nType: " << req.leaveType
                     << "\nFrom: " << req.startDate << " To: " << req.endDate
                     << "\nReason: " << req.reason
                     << "\nStatus: " << req.status << endl;
                found = true;
            }
        }

        if (!found)
            cout << "No pending leave requests.\n";
    }

    void approveOrReject() {
        int id;
        cout << "\nEnter Leave Request ID to update: ";
        cin >> id;

        for (auto &req : requests) {
            if (req.id == id) {
                cout << "1. Approve\n2. Reject\nChoose: ";
                int choice;
                cin >> choice;

                if (choice == 1) req.status = "Approved";
                else if (choice == 2) req.status = "Rejected";
                else {
                    cout << "Invalid choice.\n";
                    return;
                }

                cout << "Leave request updated successfully!\n";
                return;
            }
        }

        cout << " Leave request not found.\n";
    }

    void viewAllRequests() {
        cout << "\n--- All Leave Requests ---\n";
        if (requests.empty()) {
            cout << "No leave requests available.\n";
            return;
        }

        for (const auto &req : requests) {
            cout << "ID: " << req.id << "\nEmployee: " << req.employeeName
                 << "\nType: " << req.leaveType
                 << "\nFrom: " << req.startDate << " To: " << req.endDate
                 << "\nReason: " << req.reason
                 << "\nStatus: " << req.status << endl;
        }
    }
};

int main() {
    LeaveManagementSystem system;
    int choice;

    do {
        cout << "\n====== STAFF LEAVE MANAGEMENT SYSTEM ======\n";
        cout << "1. Submit Leave Request\n";
        cout << "2. View Pending Requests\n";
        cout << "3. Approve/Reject Request\n";
        cout << "4. View All Requests\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.submitLeaveRequest(); break;
            case 2: system.viewPendingRequests(); break;
            case 3: system.approveOrReject(); break;
            case 4: system.viewAllRequests(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
