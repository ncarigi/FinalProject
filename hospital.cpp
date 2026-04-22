
#include "hospital.h"
#include "patient.h"

#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

void hospital::FindOldestPatient() {
    if (!patients.empty()) {
        long int oldestPatientID=0;
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
    else {
    cout << "No patients found" << endl;
    }
}

int hospital::CountCriticalPatients() {
    int NumCriticalPatients=0;
    if (!patients.empty()) {
        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].Patient_Status()=="Critical") {
                NumCriticalPatients++;
            }
        }
    }
    return NumCriticalPatients;
}
void hospital::DoctorsBySpecialty(string specialty){}


patient hospital::Show_Patient_by_ID(long int ID) {

    // Loop through the vector of patients
    for (int i = 0; i < patients.size(); i++) {
        // Check if the current doctor's ID matches the requested ID
        if (patients[i].getPatientID() == ID) {
            cout << "--- Patient Found ---" << endl;
            patients[i].Print_Patient_Info(); // Print their details
            cout << endl;

            return patient();
        }
    }
        cout << "Error: No doctor found with ID " << ID << "." << endl;
    return {};
}

doctor hospital::Show_Doctor_by_ID(long int ID) {
    // Loop through the vector of doctors
    for (int i = 0; i < doctors.size(); i++) {
        // Check if the current doctor's ID matches the requested ID
        if (doctors[i].getDocID() == ID) {
            cout << "\n--- Doctor Found ---" << endl;
            doctors[i].Print_Doctor_Info(); // Print their details

            return doctors[i];
        }
    }
        cout << "Error: No doctor found with ID " << ID << "." << endl;
        return doctor();
}

void hospital::Show_Assigned_Doctor(long int PatientID) {


}
void hospital::Show_Assigned_Patients(long int DoctorID) {

}

hospital::hospital() {
    ifstream patientsFile("patients.txt");


    if (patientsFile.is_open()) {
        int numPatients;
        string patientInfoLine;

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
        cout << "Successfully loaded " << patients.size() << " patients." << endl;
    } else {
        cout << "Unable to open patients.txt" << endl;
    }

    ifstream doctorsFile("doctors.txt");


    if (doctorsFile.is_open()) {
        string doctorInfoLine;
        int numDocs;
        doctorsFile >> numDocs;

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
        cout << "Successfully loaded " << doctors.size() << " doctors." << endl;
    } else {
        cout << "Unable to open doctors.txt" << endl;
    }
}