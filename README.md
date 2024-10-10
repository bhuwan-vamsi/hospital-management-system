# Hospital Management System

This project implements a **command-line-based Hospital Management System** in C++, designed to streamline hospital operations such as patient registration, doctor registration, and billing management. The system persists data in text files, ensuring that information is stored across multiple sessions. With its easy-to-use menu-driven interface, the system efficiently manages patient records, doctor details, and billing processes.

---

## Features

### Patient Management:
- Register new patients with details such as name, age, gender, and contact information.
- View and update patient records.

### Doctor Management:
- Register new doctors with specialization, experience, and other details.
- View doctors by specialization or individual details.

### Billing System:
- Create new bills for patients.
- Update bills with details such as services provided, fees, and payment status.
- View bills associated with a particular patient or doctor.

### File Persistence:
- The system stores patient, doctor, and billing data in text files (`Patients.txt`, `Doctors.txt`, `Bills.txt`).
- The text file-based storage ensures data persistence even when the program is closed.

### Menu Interface:
- A simple command-line menu allows users to navigate and manage hospital operations easily.

---

## System Overview

- **Language:** C++
- **Platform:** Command-line interface
- **Data Storage:** Text files
- **Tools:** Dev C++ (recommended IDE)

---

## Functions List

- `registerPatient()`: Registers a new patient and saves their details to `Patients.txt`.
- `registerDoctor()`: Registers a new doctor and saves their details to `Doctors.txt`.
- `createBill()`: Generates a bill for a patient and stores it in `Bills.txt`.
- `viewPatients()`: Displays a list of all registered patients.
- `viewDoctors()`: Displays a list of doctors, with an option to filter by specialization.
- `viewBills()`: Shows all bills or bills related to a specific patient or doctor.
- `updatePatient()`: Updates the details of an existing patient.
- `updateDoctor()`: Updates the details of an existing doctor.
- `updateBill()`: Updates the billing details for a patient (e.g., payment status).

---

## How to Run the Program

To run this program in **Dev C++**, follow these steps:

### 1. Open Dev C++
- Launch Dev C++ on your computer.

### 2. Create a New Project
- Navigate to **File > New > Project**.
- Select **Console Application** and ensure the language is set to **C++**.
- Name your project (e.g., `HospitalManagementSystem`) and select a location to save it.
- Click **OK**.

### 3. Write or Paste the Code
- Go to **File > New > Source File** to create a new file in the project.
- Copy and paste your C++ code into the newly created source file.

### 4. Save the File
- Save the source file by going to **File > Save As**, and name it `main.cpp`.
- Ensure that it is saved inside your project folder.

### 5. Set Up I/O File Paths (Optional)
- Ensure the text files for data storage (`Patients.txt`, `Doctors.txt`, `Bills.txt`) are located in the working directory where the project files are stored.
- If these files don't exist, the program should create them automatically during execution.

### 6. Compile the Program
- Click the **Compile & Run** button (or press `F11`) to compile and execute the program.
- Dev C++ will compile the program. If there are no errors, the program will run in the console window.

### 7. Use the Menu
- Once the program runs, follow the menu prompts to perform actions like registering patients, creating bills, and viewing records.

---

## File Structure

```plaintext
HospitalManagementSystem/
├── code.cpp           # The main C++ source code file
├── Patients.txt       # Stores registered patient information
├── Doctors.txt        # Stores registered doctor information
├── Bills.txt          # Stores billing information
├── README.md          # Project documentation (this file)

```

## Future Enhancements

- **Search Functionality**: 
  - Add a search feature to quickly find patients or doctors by **ID** or **name**.

- **Graphical User Interface (GUI)**: 
  - Implement a GUI for a more **user-friendly experience**, allowing users to interact with the system more intuitively.

- **Expanded Billing System**: 
  - Enhance the billing system to support **multiple services** and **insurance processing**, providing a more comprehensive billing solution for patients.

