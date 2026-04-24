/*
Name: Nicolas Carigi
Student ID: 40303463
Course: COEN 243
Assignment: Final Project
 */

#include "hospital.h"
#include "patient.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

//Method to find the oldest patient and print their information
void hospital::Find_Oldest_Patient() {
    // Check if there are any patients in the hospital
    if (!patients -> empty()) {
        // Initialize variables to keep track of the oldest patient
        long int oldestPatientID=0;
        double oldestPatientAge=0;

        // Loop through the patients to find the oldest one
        for (auto & patient : *patients) {
            if (patient.calculateAge()>oldestPatientAge) {
                oldestPatientID=patient.getPatientID(); // Update the oldest patient ID
                oldestPatientAge=patient.calculateAge(); // Update the oldest patient age
            }

        }
    // Print the oldest patient's information
    cout << "Oldest patient is "<< oldestPatientAge <<" years old. See more below" << endl;
    Show_Patient_by_ID(oldestPatientID);
    }
    else {
    // If there are no patients, print a message indicating that
    cout << "No patients found" << endl;
    }
}

//Method to count the number of critical patients
int hospital::Count_Critical_Patients() {
    // Initialize a counter for critical patients
    int NumCriticalPatients=0;

    // Loop through the patients and count how many are critical
    if (!patients -> empty()) {
        for (auto & patient : *patients) {
            if (patient.Patient_Status()=="Critical") {
                NumCriticalPatients++; // Increment the counter if the patient is critical
            }
        }
    }
    return NumCriticalPatients; // Return the total number of critical patients
}

//Helper method to get a patient object by their ID
patient hospital::Get_Patient_Object_By_ID(long int ID) {
    for (auto & patient : *patients) {
        if (patient.getPatientID() == ID) {
            return patient; // Return the patient object if a match is found
        }
    }
    return {}; // Return an empty patient object if no match is found
}

//Helper method to get a doctor object by their ID
doctor hospital::Get_Doctor_Object_By_ID(long int ID) {
    for (auto & doctor : *doctors) {
        if (doctor.getDocID() == ID) {
            return doctor; // Return the doctor object if a match is found
        }
    }
    return {}; // Return an empty doctor object if no match is found
}

//Method to show doctors by specialty
void hospital::DoctorsBySpecialty(const string& specialty) {
    cout << "Here are the doctors specializing in "<<specialty<<":"<< endl;
    
    //loop through the doctors and print those whose specialty matches the requested specialty
    for (auto & doctor : *doctors) {
        if (doctor.getSpecialty()==specialty) {
            cout <<"- " << doctor.getDocFirstName()<<" "<<doctor.getDocLastName()<<" ID: "<<doctor.getDocID()<<"\n";
        }
    }
}

//Method to show patient information by their ID
void hospital::Show_Patient_by_ID(long int ID) {

        // Check if the current patient ID matches the requested ID
        // Use the helper method Get_Patient_Object_By_ID to find the patient object
        if (Get_Patient_Object_By_ID(ID).getPatientID()>0) {
            cout << "--- Patient Found ---" << endl;
            Get_Patient_Object_By_ID(ID).Print_Patient_Info(); // Print their details
        }
        else { // If no patient is found with the given ID, print an error message
            cout << "Error: No patient found with ID " << ID << "." << endl;
        }

}
//Method to show doctor information by their ID
void hospital::Show_Doctor_by_ID(long int ID) {
    // Check if the current patient ID matches the requested ID
     // Use the helper method Get_Doctor_Object_By_ID to find the doctor object
    if (Get_Doctor_Object_By_ID(ID).getDocID()>0) {
        cout << "--- Doctor Found ---" << endl;
        Get_Doctor_Object_By_ID(ID).Print_Doctor_Info(); // Print their details
    }
    else {// If no doctor is found with the given ID, print an error message
        cout << "Error: No Doctor found with ID " << ID << "." << endl;
    }
}

//Method to show the doctor assigned to a patient by the patient's ID
void hospital::Show_Assigned_Doctor(long int PatientID) {

    // Use the helper method Get_Patient_Object_By_ID to find the patient object and check if it exists
    if (Get_Patient_Object_By_ID(PatientID).getPatientID()>0) {
        //Set the patient object to the patient with the requested ID and get their assigned doctor ID
        patient patient = Get_Patient_Object_By_ID(PatientID);
        long int assignedDoctorID = patient.getAssignedDoctorID();

        // If they have an assigned doctor, use the helper method to find the doctor object
        if (assignedDoctorID>0) {
            //Assign the doctor object
            doctor assignedDoctor = Get_Doctor_Object_By_ID(assignedDoctorID);

            //Print the assigned doctor's information
            cout << "The doctor assigned to " << patient.getFirstName()<<" "<<patient.getLastName()<<" is:\n";
            assignedDoctor.Print_Doctor_Info();
        }
        else {
            // If the patient does not have an assigned doctor, print a message indicating that
            cout << "There is currently no doctor assigned to this patient" << endl;
        }

    }
    else {
        // If no patient is found with the given ID, print an error message
        cout << "Error: No Patient found with ID " << PatientID << "." << endl;
    }

}
void hospital::Show_Assigned_Patients(long int DoctorID) {

    // Use the helper method Get_Doctor_Object_By_ID to find the doctor object and check if it exists
    if (Get_Doctor_Object_By_ID(DoctorID).getDocID()>0) {
        //Set the doctor object to the doctor with the requested ID
        doctor doctor = Get_Doctor_Object_By_ID(DoctorID);

        //Loop through the patients and find those whose assigned doctor ID matches the requested doctor ID
        vector<patient> assignedPatients;
        for (auto & patient : *patients) {
            if (patient.getAssignedDoctorID()==DoctorID) {
                assignedPatients.push_back(patient);
            }
        }

        //Print the assigned patients' information
        if (!assignedPatients.empty()) { // Checks there are patients assigned to this doctor
            cout << "The following patients are assigned to doctor " << doctor.getDocFirstName() << " " << doctor.getDocLastName()<<" ID: "<<doctor.getDocID()<<endl;
            //Loop through the assigned patients and print their information
            for (int i = 0; i < assignedPatients.size(); i++) {
                cout <<"["<<i+1<<"]\n" ;
                assignedPatients[i].Print_Patient_Info();
            }
        }
        else {
            // If there are no patients assigned to this doctor, print a message indicating that
            cout << "There is currently no patients assigned to this doctor" << endl;
        }

    }
    else {
        // If no doctor is found with the given ID, print an error message
        cout << "Error: No Doctor found with ID " << DoctorID << "." << endl;
    }

}


hospital::hospital() {
    // Initialize the patients and doctors vectors
    patients = new vector<patient>();
    doctors = new vector<doctor>();

    // Load patients from the patients.txt file
    ifstream patientsFile("patients.txt");

    // Check if the file was successfully opened
    if (patientsFile.is_open()) {
        // Read the number of patients from the first line of the file
        int numPatients;
        patientsFile >> numPatients;

        // Variable to hold each line of patient information
        string patientInfoLine; 

        // Skip the next two lines (number of patients + headers)
        getline(patientsFile, patientInfoLine);
        getline(patientsFile, patientInfoLine);

        // Loop through the remaining lines of the file to read patient information
        for (int i = 0; i < numPatients; i++) {
            // Read a line of patient information
            getline(patientsFile, patientInfoLine);
            //Parse the information
            stringstream ss(patientInfoLine);

            // Variables to hold the parsed patient information
            string fName, lName, dob, bloodType, diag, admit, discharge;
            long int pID, docID;

            // Extract the patient information from the line and store it in the variables
            ss >> fName >> lName >> pID >> docID >> dob >> bloodType >> diag >> admit >> discharge;

            // Create a new patient object using the parsed information and add it to the patients vector
            patient newPatient(fName, lName, pID, docID, dob, bloodType, diag, admit, discharge);

            // Add the new patient object to the patients vector
            patients -> push_back(newPatient);
        }
        // Close the file and print a success message with the number of patients loaded
        patientsFile.close();
        cout << "Successfully loaded " << patients -> size() << " patients." << endl;
    } else {
        // If the file could not be opened, print an error message
        cout << "Unable to open patients.txt" << endl;
    }

    // Load doctors from the doctors.txt file
    ifstream doctorsFile("doctors.txt");
    // Check if the file was successfully opened
    if (doctorsFile.is_open()) 
    {
        // Read the number of doctors from the first line of the file
        int numDocs;
        doctorsFile >> numDocs;

        // Variable to hold each line of doctor information
        string doctorInfoLine;

        // Skip the next two lines (number of doctors + headers)
        getline(doctorsFile, doctorInfoLine);
        getline(doctorsFile, doctorInfoLine);

        // Loop through the remaining lines of the file to read doctor information
        for (int i = 0; i < numDocs; i++) {
            // Read a line of doctor information
            getline(doctorsFile, doctorInfoLine);
            //Parse the information
            stringstream ss(doctorInfoLine);

            // Variables to hold the parsed doctor information
            string fName, lName, specialty;
            long int dID;
            int yearExp;
            double baseSalary, performanceBonus;

            // Extract the doctor information from the line and store it in the variables
            ss >> fName >> lName >> dID >> specialty >> yearExp >> baseSalary >> performanceBonus;

            // Create a new doctor object using the parsed information and add it to the doctors vector
            doctor newDoctor(fName, lName, dID, specialty, yearExp , baseSalary, performanceBonus);

            //
            doctors -> push_back(newDoctor);
        }
        // Close the file and print a success message with the number of doctors loaded
        doctorsFile.close();
        cout << "Successfully loaded " << doctors -> size() << " doctors." << endl;
    } else {
        // If the file could not be opened, print an error message
        cout << "Unable to open doctors.txt" << endl;
    }
}

// Destructor to clean up memory allocated for patients and doctors vectors (should run automatically)
hospital::~hospital() {
    // Clean up memory allocated for patients and doctors vectors
    delete patients;
    delete doctors;
    // Print a message indicating that the hospital memory has been successfully cleaned up
    cout<<"[Shutting down] Hospital memory successfully cleaned up!"<<endl;
}