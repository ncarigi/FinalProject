
#ifndef FINALPROJECT_DOCTOR_H
#define FINALPROJECT_DOCTOR_H
#include <string>
using namespace std;

class doctor {
    public:
    //Constructors
    doctor();
    doctor(string docFirstName,
    string docLastName,
    long int docID,
    string specialty,
    int yearsExp,
    double baseSalary,
    double performanceBonus);

    //Methods
    double Calculate_Salary();
    void Print_Doctor_Info();

    // Getters
    std::string getDocFirstName();
    std::string getDocLastName();
    long int getDocID();
    std::string getSpecialty();
    int getYearsExp();
    double getBaseSalary();
    double getPerformanceBonus();

    // Setters
    void setDocFirstName(std::string firstName);
    void setDocLastName(std::string lastName);
    void setDocID(long int id);
    void setSpecialty(std::string spec);
    void setYearsExp(int years);
    void setBaseSalary(double salary);
    void setPerformanceBonus(double bonus);

    private:
    //Attributes
    string docFirstName;
    string docLastName;
    long int docID;
    string specialty;
    int yearsExp;
    double baseSalary;
    double performanceBonus;
};


#endif //FINALPROJECT_DOCTOR_H