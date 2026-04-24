
#ifndef FINALPROJECT_PATIENTS_H
#define FINALPROJECT_PATIENTS_H
#include <string>
using namespace std;


class patient {

    //Constructor
    public:
    patient(string firstName,string lastName,long int patientID,long int assignedDoctorID,
    string DOB,string bloodType,string diagnosis,string admitDate,
    string dischargeDate);

    patient();


    //Class functions
    string Patient_Status();
    void Print_Patient_Info();
    double calculateAge();
    
    // Getters
    [[nodiscard]] string getFirstName() const;
    [[nodiscard]] string getLastName() const;
    [[nodiscard]] long int getPatientID() const;
    [[nodiscard]] long int getAssignedDoctorID() const;
    [[nodiscard]] string getDOB() const;
    [[nodiscard]] string getBloodType() const;
    [[nodiscard]] string getDiagnosis() const;
    [[nodiscard]] string getAdmitDate() const;
    [[nodiscard]] string getDischargeDate() const;

    // Setters
    void setFirstName(const string& newFirstName);
    void setLastName(const string& newLastName);
    void setPatientID(long int newPatientID);
    void setAssignedDoctorID(long int newAssignedDoctorID);
    void setDOB(const string& newDOB);
    void setBloodType(const string& newBloodType);
    void setDiagnosis(const string& newDiagnosis);
    void setAdmitDate(const string& newAdmitDate);
    void setDischargeDate(const string& newDischargeDate);

    

    private:
    //Attributes
    string firstName;
    string lastName;
    long int patientID;
    long int assignedDoctorID;
    string DOB;
    string bloodType;
    string diagnosis;
    string admitDate;
    string dischargeDate;

};


#endif //FINALPROJECT_PATIENTS_H