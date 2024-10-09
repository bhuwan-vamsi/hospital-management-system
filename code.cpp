#include <bits/stdc++.h>
#include<string>
using namespace std;

// Person base class
class Person {
public:
    int id;
    string firstName;
    string middleName;
    string lastName;
    string contactNumber;
    string address;
    int age;

    Person(int id, const string& firstName, const string& middleName, const string& lastName,
           const string& contactNumber, const string& address, int age)
        : id(id), firstName(firstName), middleName(middleName), lastName(lastName),
          contactNumber(contactNumber), address(address), age(age) {}

    virtual void display() const = 0;
};

// Patient class
class Patient : public Person {
public:
    Patient(int id, const string& firstName, const string& middleName, const string& lastName,
            const string& contactNumber, const string& address, int age)
        : Person(id, firstName, middleName, lastName, contactNumber, address, age) {}

    void display() const override {
        cout << "Patient ID: " << id << "\nName: " << firstName << " " << middleName << " " << lastName
             << "\nContact Number: " << contactNumber << "\nAddress: " << address << "\nAge: " << age << "\n";
    }
};

// Doctor class
class Doctor : public Person {
public:
    string specialization;

    Doctor(int id, const string& firstName, const string& middleName, const string& lastName,
           const string& contactNumber, const string& address, int age, const string& specialization)
        : Person(id, firstName, middleName, lastName, contactNumber, address, age), specialization(specialization) {}

    void display() const override {
        cout << "Doctor ID: " << id << "\nName: " << firstName << " " << middleName << " " << lastName
             << "\nContact Number: " << contactNumber << "\nAddress: " << address << "\nAge: " << age
             << "\nSpecialization: " << specialization << "\n";
    }
};

// Bill class
class Bill {
public:
    int billId;
    int doctorId;
    int patientId;
    double amount;
    string admissionDate;
    string billingDate;
    bool paymentStatus;

    Bill(int billId, int doctorId, int patientId, const string& admissionDate)
        : billId(billId), doctorId(doctorId), patientId(patientId),
          amount(0.0), admissionDate(admissionDate), paymentStatus(false) {}

    void display() const {
        cout << "Bill ID: " << billId << "\nDoctor ID: " << doctorId << "\nPatient ID: " << patientId
             << "\nAdmission Date: " << admissionDate << "\nBilling Date: " << billingDate
             << "\nAmount: $" << fixed << setprecision(2) << amount << "\nPayment Status: " << (paymentStatus ? "Paid" : "Unpaid") << "\n";
    }
};

// Function to register a patient
void registerPatient(vector<Patient>& patients) {
    int id, age;
    string firstName, middleName, lastName, contactNumber, address;

    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Middle Name (or leave empty): ";
    cin.ignore();
    getline(cin, middleName);
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Contact Number: ";
    cin >> contactNumber;
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter Age: ";
    cin >> age;

    patients.emplace_back(id, firstName, middleName, lastName, contactNumber, address, age);

    ofstream outFile("Patients.txt", ios::app);
    if (outFile.is_open()) {
        outFile << id << "," << firstName << "," << middleName << "," << lastName << ","
                << contactNumber << "," << address << "," << age << "\n";
        outFile.close();
    }
}

// Function to register a doctor
void registerDoctor(vector<Doctor>& doctors) {
    int id, age;
    string firstName, middleName, lastName, contactNumber, address, specialization;

    cout << "Enter Doctor ID: ";
    cin >> id;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Middle Name (or leave empty): ";
    cin.ignore();
    getline(cin, middleName);
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Contact Number: ";
    cin >> contactNumber;
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Specialization: ";
    cin.ignore();
    getline(cin, specialization);

    doctors.emplace_back(id, firstName, middleName, lastName, contactNumber, address, age, specialization);

    ofstream outFile("Doctors.txt", ios::app);
    if (outFile.is_open()) {
        outFile << id << "," << firstName << "," << middleName << "," << lastName << ","
                << contactNumber << "," << address << "," << age << "," << specialization << "\n";
        outFile.close();
    }
}

// Function to create a bill
void createBill(vector<Bill>& bills) {
    int billId, doctorId, patientId;
    string admissionDate;

    cout << "Enter Bill ID: ";
    cin >> billId;
    cout << "Enter Doctor ID: ";
    cin >> doctorId;
    cout << "Enter Patient ID: ";
    cin >> patientId;
    cout << "Enter Admission Date (YYYY-MM-DD): ";
    cin >> admissionDate;

    bills.emplace_back(billId, doctorId, patientId, admissionDate);

    ofstream outFile("Bills.txt", ios::app);
    if (outFile.is_open()) {
        outFile << billId << "," << doctorId << "," << patientId << ","
                << admissionDate << ",0.00,,false\n";
        outFile.close();
    }
}

// Function to confirm a bill amount
void confirmBillAmount(vector<Bill>& bills) {
    int billId;
    double amount;
    string billingDate;

    cout << "Enter Bill ID: ";
    cin >> billId;
    cout << "Enter Bill Amount: ";
    cin >> amount;
    cout << "Enter Billing Date (YYYY-MM-DD): ";
    cin >> billingDate;

    for (auto& bill : bills) {
        if (bill.billId == billId) {
            bill.amount = amount;
            bill.billingDate = billingDate;

            // Update the bill in the file
            fstream outFile("Bills.txt", ios::in | ios::out);
            if (outFile.is_open()) {
                string line;
                vector<string> fileLines;
                while (getline(outFile, line)) {
                    stringstream ss(line);
                    string idStr;
                    getline(ss, idStr, ',');
                    if (stoi(idStr) == billId) {
                        stringstream updatedLine;
                        updatedLine << bill.billId << "," << bill.doctorId << "," << bill.patientId << ","
                                    << bill.admissionDate << "," << fixed << setprecision(2) << bill.amount
                                    << "," << bill.billingDate << "," << (bill.paymentStatus ? "true" : "false") << "\n";
                        fileLines.push_back(updatedLine.str());
                    } else {
                        fileLines.push_back(line);
                    }
                }

                outFile.close();
                outFile.open("Bills.txt", ios::out | ios::trunc);
                for (const auto& fileLine : fileLines) {
                    outFile << fileLine;
                }
                outFile.close();
            }
            break;
        }
    }
}

// Function to confirm payment status
void confirmPaymentStatus(vector<Bill>& bills) {
    int billId;
    bool status;

    cout << "Enter Bill ID: ";
    cin >> billId;
    cout << "Enter Payment Status (1 for Paid, 0 for Unpaid): ";
    cin >> status;

    for (auto& bill : bills) {
        if (bill.billId == billId) {
            bill.paymentStatus = status;

            // Update the bill in the file
            fstream outFile("Bills.txt", ios::in | ios::out);
            if (outFile.is_open()) {
                string line;
                vector<string> fileLines;
                while (getline(outFile, line)) {
                    stringstream ss(line);
                    string idStr;
                    getline(ss, idStr, ',');
                    if (stoi(idStr) == billId) {
                        stringstream updatedLine;
                        updatedLine << bill.billId << "," << bill.doctorId << "," << bill.patientId << ","
                                    << bill.admissionDate << "," << fixed << setprecision(2) << bill.amount
                                    << "," << bill.billingDate << "," << (bill.paymentStatus ? "true" : "false") << "\n";
                        fileLines.push_back(updatedLine.str());
                    } else {
                        fileLines.push_back(line);
                    }
                }

                outFile.close();
                outFile.open("Bills.txt", ios::out | ios::trunc);
                for (const auto& fileLine : fileLines) {
                    outFile << fileLine;
                }
                outFile.close();
            }
            break;
        }
    }
}

// Function to show all patients
void showAllPatients(const vector<Patient>& patients) {
    cout << "Patient Records:\n";
    for (const auto& patient : patients) {
        patient.display();
        cout << "-----------------------\n";
    }
}

// Function to show all doctors
void showAllDoctors(const vector<Doctor>& doctors) {
    cout << "Doctor Records:\n";
    for (const auto& doctor : doctors) {
        doctor.display();
        cout << "-----------------------\n";
    }
}

// Function to show all doctors with a particular specialization
void showDoctorsBySpecialization(const vector<Doctor>& doctors, const string& specialization) {
    cout << "Doctors with Specialization: " << specialization << "\n";
    for (const auto& doctor : doctors) {
        if (doctor.specialization == specialization) {
            doctor.display();
            cout << "-----------------------\n";
        }
    }
}

// Function to show all bills
void showAllBills(const vector<Bill>& bills) {
    cout << "Billing Records:\n";
    for (const auto& bill : bills) {
        bill.display();
        cout << "-----------------------\n";
    }
}

// Function to show all bills regarding a patient
void showBillsByPatient(const vector<Bill>& bills, int patientId) {
    cout << "Bills for Patient ID: " << patientId << "\n";
    for (const auto& bill : bills) {
        if (bill.patientId == patientId) {
            bill.display();
            cout << "-----------------------\n";
        }
    }
}

// Function to show all bills regarding a doctor
void showBillsByDoctor(const vector<Bill>& bills, int doctorId) {
    cout << "Bills for Doctor ID: " << doctorId << "\n";
    for (const auto& bill : bills) {
        if (bill.doctorId == doctorId) {
            bill.display();
            cout << "-----------------------\n";
        }
    }
}

int main() {
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Bill> bills;
    int choice;

    while (true) {
        cout << "Hospital Management System Menu:\n";
        cout << "1. Register a Patient\n";
        cout << "2. Register a Doctor\n";
        cout << "3. Type a Bill\n";
        cout << "4. Confirm a Bill Amount\n";
        cout << "5. Confirm Payment Status\n";
        cout << "6. Show all patients\n";
        cout << "7. Show all doctors\n";
        cout << "8. Show all doctors with a particular specialization\n";
        cout << "9. Show all bills\n";
        cout << "10. Show all bills regarding a patient\n";
        cout << "11. Show all bills regarding a doctor\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerPatient(patients);
                break;
            case 2:
                registerDoctor(doctors);
                break;
            case 3:
                createBill(bills);
                break;
            case 4:
                confirmBillAmount(bills);
                break;
            case 5:
                confirmPaymentStatus(bills);
                break;
            case 6:
                showAllPatients(patients);
                break;
            case 7:
                showAllDoctors(doctors);
                break;
            case 8: {
                string specialization;
                cout << "Enter Specialization: ";
                cin.ignore();
                getline(cin, specialization);
                showDoctorsBySpecialization(doctors, specialization);
                break;
            }
            case 9:
                showAllBills(bills);
                break;
            case 10: {
                int patientId;
                cout << "Enter Patient ID: ";
                cin >> patientId;
                showBillsByPatient(bills, patientId);
                break;
            }
            case 11: {
                int doctorId;
                cout << "Enter Doctor ID: ";
                cin >> doctorId;
                showBillsByDoctor(bills, doctorId);
                break;
            }
            case 12:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
