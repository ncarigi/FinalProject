
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
    
    //Getters
    string getFirstName();
    string getLastName();
    long int getPatientID() const;
    long int getAssignedDoctorID() const;
    string getDOB();
    string getBloodType();
    string getDiagnosis();
    string getAdmitDate();
    string getDischargeDate();
    
    //Setters
    void setFirstName(string);
    void setLastName(string);
    void setPatientID(long int);
    void setAssignedDoctorID(long int);
    void setDOB(string);
    void setBloodType(string);
    void setDiagnosis(string);
    void setAdmitDate(string);
    void setDischargeDate(string);

    

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


#endif //FINALPROJECT_patient_H