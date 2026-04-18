//
// Created by Nicolas Carigi on 2026-04-17.
//

#include "patients.h"
#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

string patients::importPatients() {
    std::string line;
    ifstream patientsFile("patients.txt");

    if (patientsFile.is_open()) {
        while (std::getline(patientsFile, line)) {
            std::cout << line << std::endl;
            return line;
        }
        patientsFile.close();
    } else {
        std::cout << "Unable to open patients.txt" << std::endl;
        return "0";
    }
}

string patients::Patient_Status() {
    if (diagnosis.find("critical") != std::string::npos) {
        return "Critical";
    }
    if (diagnosis.find("moderate") != std::string::npos) {
        return "Moderate";
    }
    else {
        return "Stable";
    }
}

void patients::Print_Patient_Info() {
    cout<<"Patient Name: "<<firstName << lastName << endl;
    cout<<"ID: "<<patientID<< endl;
    cout<<"Assigned doctor: {DOCTOR NAME} ["<<assignedDoctorID<<"]"<< endl;
    cout<<"Date of birth: "<<DOB<< endl;
    cout<<"Blood type: "<<bloodType<< endl;
    cout<<"Diagnosis: "<<diagnosis<< endl;
    cout<<"Date of Admission: "<<admitDate<< endl;
    cout<<"Discharge date: "<<dischargeDate<< endl;
}

patients::patients(std::string buildFirstName,std::string buildLastName,long int buildPatientID,long int buildAssignedDoctorID,
    std::string buildDOB,std::string buildBloodType,std::string buildDiagnosis,std::string buildAdmitDate,
    std::string buildDischargeDate) {
    firstName = buildFirstName;
    lastName = buildLastName;
    patientID = buildPatientID;
    assignedDoctorID = buildAssignedDoctorID;
    DOB = buildDOB;
    bloodType = buildBloodType;
    diagnosis = buildDiagnosis;
    admitDate = buildAdmitDate;
    dischargeDate = buildDischargeDate;
}

patients::patients() {
    firstName = "";
    lastName = "";
    patientID = 0;
    assignedDoctorID = 0;
    DOB = "";
    bloodType = "";
    diagnosis = "";
    admitDate = "";
    dischargeDate = "";
}


string patients::getFirstName() {
    return firstName;
}
string patients::getLastName() {
    return lastName;
}
long int patients::getPatientID() {
    return patientID;
}
long int patients::getAssignedDoctorID() {
    return assignedDoctorID;
}
string patients::getDOB() {
    return DOB;
}
string patients::getBloodType() {
    return bloodType;
}
string patients::getDiagnosis() {
    return diagnosis;
}
string patients::getAdmitDate() {
    return admitDate;
}
string patients::getDischargeDate() {
    return dischargeDate;
}

void patients::setFirstName(string firstName) {
    this->firstName = firstName;
}
void patients::setLastName(string lastName) {
    this->lastName = lastName;
}
void patients::setPatientID(long int patientID) {
    this->patientID = patientID;
}
void patients::setAssignedDoctorID(long int assignedDoctorID) {
    this->assignedDoctorID = assignedDoctorID;
}
void patients::setDOB(string DOB) {
    this->DOB = DOB;
}
void patients::setBloodType(string bloodType) {
    this->bloodType = bloodType;
}
void patients::setDiagnosis(string diagnosis) {
    this->diagnosis = diagnosis;
}

void patients::setAdmitDate(string admitDate) {
    this->admitDate = admitDate;
}

void patients::setDischargeDate(string dischargeDate) {
    this->dischargeDate = dischargeDate;
}
