
#include "hospital.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "patient.h"
using namespace std;


void hospital::importPatients() {
    std::string line;
    /*
    ifstream patientsFile("patients.txt");

    if (patientsFile.is_open()) {
        while (std::getline(patientsFile, line)) {
            std::cout << line << std::endl;

        }
        patientsFile.close();
    } else {
        std::cout << "Unable to open patients.txt" << std::endl;
    }
    */
}

void hospital::FindOldestPatient(){}
int hospital::CountCriticalPatients(){}
void hospital::DoctorsBySpecialty(string specialty){}
void hospital::Show_Patient_by_ID(long int ID){}
void hospital::Show_Doctor_by_ID(long int ID){}
void hospital::Show_Assigned_Doctor(long int PatientID){}
void hospital::Show_Assigned_Patients(long int DoctorID){}

hospital::hospital() {
    ifstream patientsFile("patients.txt");
    string line;

    if (patientsFile.is_open()) {
        int numPatients;
        patientsFile >> numPatients;

        getline(patientsFile, line);

        getline(patientsFile, line);

        for (int i = 0; i < numPatients; i++) {
            getline(patientsFile, line);
            stringstream ss(line);

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
}