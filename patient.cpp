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
string patient::getFirstName() {
    return firstName;
}
string patient::getLastName() {
    return lastName;
}
long int patient::getPatientID() const {
    return patientID;
}
long int patient::getAssignedDoctorID() const {
    return assignedDoctorID;
}
string patient::getDOB() {
    return DOB;
}
string patient::getBloodType() {
    return bloodType;
}
string patient::getDiagnosis() {
    return diagnosis;
}
string patient::getAdmitDate() {
    return admitDate;
}
string patient::getDischargeDate() {
    return dischargeDate;
}

// --- Setters ---
void patient::setFirstName(string firstName) {
    this->firstName = std::move(firstName);
}
void patient::setLastName(string lastName) {
    this->lastName = std::move(lastName);
}
void patient::setPatientID(long int patientID) {
    this->patientID = patientID;
}
void patient::setAssignedDoctorID(long int assignedDoctorID) {
    this->assignedDoctorID = assignedDoctorID;
}
void patient::setDOB(string DOB) {
    this->DOB = std::move(DOB);
}
void patient::setBloodType(string bloodType) {
    this->bloodType = std::move(bloodType);
}
void patient::setDiagnosis(string diagnosis) {
    this->diagnosis = std::move(diagnosis);
}

void patient::setAdmitDate(string admitDate) {
    this->admitDate = std::move(admitDate);
}

void patient::setDischargeDate(string dischargeDate) {
    this->dischargeDate = std::move(dischargeDate);
}
