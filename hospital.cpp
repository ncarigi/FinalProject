
#include "hospital.h"
#include "patient.h"

#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

void hospital::FindOldestPatient() {
    if (!patients -> empty()) {
        long int oldestPatientID=0;
        double oldestPatientAge=0;

        for (auto & patient : *patients) {
            if (patient.calculateAge()>oldestPatientAge) {
                oldestPatientID=patient.getPatientID();
                oldestPatientAge=patient.calculateAge();
            }

        }
    cout << "Oldest patient is "<< oldestPatientAge <<" years old. See more below" << endl;
    Show_Patient_by_ID(oldestPatientID);
    }
    else {
    cout << "No patients found" << endl;
    }
}

int hospital::CountCriticalPatients() {
    int NumCriticalPatients=0;
    if (!patients -> empty()) {
        for (auto & patient : *patients) {
            if (patient.Patient_Status()=="Critical") {
                NumCriticalPatients++;
            }
        }
    }
    return NumCriticalPatients;
}

patient hospital::Get_Patient_Object_By_ID(long int ID) {
    for (auto & patient : *patients) {
        if (patient.getPatientID() == ID) {
            return patient;
        }
    }
    return patient();
}

doctor hospital::Get_Doctor_Object_By_ID(long int ID) {
    for (auto & doctor : *doctors) {
        if (doctor.getDocID() == ID) {
            return doctor;
        }
    }
    return doctor();
}


void hospital::DoctorsBySpecialty(const string& specialty) {

    cout << "Here are the doctors specializing in "<<specialty<<":"<< endl;
    for (int i = 0; i < doctors->size(); i++) {
        if (doctors->at(i).getSpecialty()==specialty) {
            cout <<"["<<i+1<<"] " << doctors->at(i).getDocFirstName()<<" "<<doctors->at(i).getDocLastName()<<" ID: "<<doctors->at(i).getDocID()<<"\n\n";

        }
    }
}


void hospital::Show_Patient_by_ID(long int ID) {

        // Check if the current patient ID matches the requested ID
        if (Get_Patient_Object_By_ID(ID).getPatientID()>0) {
            cout << "--- Patient Found ---" << endl;
            Get_Patient_Object_By_ID(ID).Print_Patient_Info(); // Print their details
        }
        else {
            cout << "Error: No patient found with ID " << ID << "." << endl;
        }

}
void hospital::Show_Doctor_by_ID(long int ID) {
    // Check if the current patient ID matches the requested ID
    if (Get_Doctor_Object_By_ID(ID).getDocID()>0) {
        cout << "--- Doctor Found ---" << endl;
        Get_Doctor_Object_By_ID(ID).Print_Doctor_Info(); // Print their details
    }
    else {
        cout << "Error: No Doctor found with ID " << ID << "." << endl;
    }
}

void hospital::Show_Assigned_Doctor(long int PatientID) {

    if (Get_Patient_Object_By_ID(PatientID).getPatientID()>0) {
        patient patient = Get_Patient_Object_By_ID(PatientID);
        long int assignedDoctorID = patient.getAssignedDoctorID();

        if (assignedDoctorID>0) {
            doctor assignedDoctor = Get_Doctor_Object_By_ID(assignedDoctorID);

            cout << "The doctor assigned to " << patient.getFirstName()<<" "<<patient.getLastName()<<" is:\n";
            assignedDoctor.Print_Doctor_Info();
        }
        else {
            cout << "There is currently no doctor assigned to this patient" << endl;
        }

    }
    else {
        cout << "Error: No Patient found with ID " << PatientID << "." << endl;
    }

}
void hospital::Show_Assigned_Patients(long int DoctorID) {
    if (Get_Doctor_Object_By_ID(DoctorID).getDocID()>0) {
        doctor doctor = Get_Doctor_Object_By_ID(DoctorID);
        vector<patient> assignedPatients;

        for (auto & patient : *patients) {
            if (patient.getAssignedDoctorID()==DoctorID) {
                assignedPatients.push_back(patient);
            }
        }

        if (!assignedPatients.empty()) {
            cout << "The following patients are assigned to doctor " << doctor.getDocFirstName() << " " << doctor.getDocLastName()<<" ID: "<<doctor.getDocID()<<endl;
            for (int i = 0; i < assignedPatients.size(); i++) {
                cout <<"["<<i+1<<"]\n" ;
                assignedPatients[i].Print_Patient_Info();
            }
        }
        else {
            cout << "There is currently no patients assigned to this doctor" << endl;
        }

    }
    else {
        cout << "Error: No Doctor found with ID " << DoctorID << "." << endl;
    }

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

            patients -> push_back(newPatient);
        }
        patientsFile.close();
        cout << "Successfully loaded " << patients -> size() << " patients." << endl;
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

            doctors -> push_back(newDoctor);
        }
        doctorsFile.close();
        cout << "Successfully loaded " << doctors -> size() << " doctors." << endl;
    } else {
        cout << "Unable to open doctors.txt" << endl;
    }
}