
#include "hospital.h"
#include "patient.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "patient.h"
using namespace std;

void hospital::FindOldestPatient() {
    if (patients.empty()) {
        long int oldestPatientID;
        double oldestPatientAge=0;

        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].calculateAge()>oldestPatientAge) {
                oldestPatientID=patients[i].getPatientID();
                oldestPatientAge=patients[i].calculateAge();
            }

        }
    cout << "Oldest patient is: " << endl;
    Show_Patient_by_ID(oldestPatientID);
    }
}

int hospital::CountCriticalPatients(){}
void hospital::DoctorsBySpecialty(string specialty){}
void hospital::Show_Patient_by_ID(long int ID) {
    bool found = false;

    // Loop through the vector of patients
    for (int i = 0; i < patients.size(); i++) {
        // Check if the current doctor's ID matches the requested ID
        if (patients[i].getPatientID() == ID) {
            cout << "\n--- Patient Found ---" << endl;
            patients[i].Print_Patient_Info(); // Print their details
            found = true;
            break; // Stop searching since we found them
        }
    }
}
void hospital::Show_Doctor_by_ID(long int ID) {
    bool found = false;

    // Loop through the vector of doctors
    for (int i = 0; i < doctors.size(); i++) {
        // Check if the current doctor's ID matches the requested ID
        if (doctors[i].getDocID() == ID) {
            cout << "\n--- Doctor Found ---" << endl;
            doctors[i].Print_Doctor_Info(); // Print their details
            found = true;
            break; // Stop searching since we found them
        }
    }

    // If the loop finishes and we never changed 'found' to true
    if (!found) {
        cout << "Error: No doctor found with ID " << ID << "." << endl;
    }
}
void hospital::Show_Assigned_Doctor(long int PatientID){}
void hospital::Show_Assigned_Patients(long int DoctorID){}

hospital::hospital() {
    ifstream patientsFile("patients.txt");
    string patientInfoLine;

    if (patientsFile.is_open()) {
        int numPatients;
        patientsFile >> numPatients;

        getline(patientsFile, patientInfoLine);

        getline(patientsFile, patientInfoLine);

        for (int i = 0; i < numPatients; i++) {
            getline(patientsFile, patientInfoLine);
            stringstream ss(patientInfoLine);

            string fName, lName, dob, bloodType, diag, admit, discharge;
            long int pID, docID;

            ss >> fName >> lName >> pID >> docID >> dob >> bloodType >> diag >> admit >> discharge;

            patient newPatient(fName, lName, pID, docID, dob, bloodType, diag, admit, discharge);

            patients.push_back(newPatient);
        }
        patientsFile.close();
        cout << "Successfully loaded " << numPatients << " patients." << endl;
    } else {
        cout << "Unable to open patients.txt" << endl;
    }

    ifstream doctorsFile("doctors.txt");
    string doctorInfoLine;

    if (doctorsFile.is_open()) {
        int numDocs;
        patientsFile >> numDocs;

        getline(doctorsFile, doctorInfoLine);

        getline(doctorsFile, doctorInfoLine);

        for (int i = 0; i < numDocs; i++) {
            getline(doctorsFile, doctorInfoLine);
            stringstream ss(doctorInfoLine);

            string fName, lName, specialty;
            long int dID;
            int yearExp;
            double baseSalary, performanceBonus;

            ss >> fName >> lName >> dID >> specialty >> yearExp >> baseSalary >> performanceBonus;

            doctor newDoctor(fName, lName, dID, specialty, yearExp , baseSalary, performanceBonus);

            doctors.push_back(newDoctor);
        }
        doctorsFile.close();
        cout << "Successfully loaded " << numDocs << " patients." << endl;
    } else {
        cout << "Unable to open doctors.txt" << endl;
    }
}