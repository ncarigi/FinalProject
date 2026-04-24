/*
Name: Nicolas Carigi
Student ID: 40303463
Course: COEN 243
Assignment: Final Project
 */

#include <fstream>
#include <iostream>
#include <ostream>
#include <format>
#include <chrono>
#include <utility>
#include "patient.h"

using namespace std;

string patient::Patient_Status() {
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

void patient::Print_Patient_Info() {
    cout<<"Patient Name: "<<firstName <<" "<< lastName << endl;
    cout<<"ID: "<<patientID<< endl;
    if (assignedDoctorID <= 0) {
        cout<<"Assigned doctor: No doctor assigned"<< endl;
    }
    else {
        cout<<"Assigned doctor: ["<<assignedDoctorID<<"]"<< endl;
    }
    cout<<"Date of birth: "<<DOB<< endl;
    cout<<"Blood type: "<<bloodType<< endl;
    cout<<"Diagnosis: "<<diagnosis<< endl;
    cout<<"Date of Admission: "<<admitDate<< endl;
    cout<<"Discharge date: "<<dischargeDate<< endl;
}

double patient::calculateAge() {
    // Get the current date in YYYYMMDD format
    auto now = chrono::system_clock::now();
    double currentDateYYYYMMDD=stoi(format("{:%Y%m%d}", now));

    // Convert the DOB string to an integer
    double dobInt = std::stoi(DOB);

    // Calculate and return the age
    return ((currentDateYYYYMMDD - dobInt) / 10000);
}

//Constructor with parameters
patient::patient(std::string buildFirstName,std::string buildLastName,long int buildPatientID,long int buildAssignedDoctorID,
    std::string buildDOB,std::string buildBloodType,std::string buildDiagnosis,std::string buildAdmitDate,
    std::string buildDischargeDate) {
    firstName = std::move(buildFirstName);
    lastName = std::move(buildLastName);
    patientID = buildPatientID;
    assignedDoctorID = buildAssignedDoctorID;
    DOB = std::move(buildDOB);
    bloodType = std::move(buildBloodType);
    diagnosis = std::move(buildDiagnosis);
    admitDate = std::move(buildAdmitDate);
    dischargeDate = std::move(buildDischargeDate);
}

//Default constructor
patient::patient() {
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

// --- Getters ---
string patient::getFirstName() const {
    return firstName;
}
string patient::getLastName() const {
    return lastName;
}
long int patient::getPatientID() const {
    return patientID;
}
long int patient::getAssignedDoctorID() const {
    return assignedDoctorID;
}
string patient::getDOB() const {
    return DOB;
}
string patient::getBloodType() const {
    return bloodType;
}
string patient::getDiagnosis() const {
    return diagnosis;
}
string patient::getAdmitDate() const {
    return admitDate;
}
string patient::getDischargeDate() const {
    return dischargeDate;
}

// --- Setters ---
void patient::setFirstName(const string& newFirstName) {
    firstName = newFirstName;
}
void patient::setLastName(const string& newLastName) {
    lastName = newLastName;
}
void patient::setPatientID(long int newPatientID) {
    patientID = newPatientID;
}
void patient::setAssignedDoctorID(long int newAssignedDoctorID) {
    assignedDoctorID = newAssignedDoctorID;
}
void patient::setDOB(const string& newDOB) {
    DOB = newDOB;
}
void patient::setBloodType(const string& newBloodType) {
    bloodType = newBloodType;
}
void patient::setDiagnosis(const string& newDiagnosis) {
    diagnosis = newDiagnosis;
}
void patient::setAdmitDate(const string& newAdmitDate) {
    admitDate = newAdmitDate;
}
void patient::setDischargeDate(const string& newDischargeDate) {
    dischargeDate = newDischargeDate;
}