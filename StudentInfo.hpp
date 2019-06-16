#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include <iostream>
#include <string>
using namespace std;
//ADT for units
struct Units
{
    int numberOfUnits;
    string *courseUnits = NULL;

    void setUnits(string *unit)
    {
        courseUnits = unit;
    }

    void setUnitsNum(int num)
    {
        numberOfUnits = num;
    }
    int getUnitsNum()
    {
        return numberOfUnits;
    }

    string *getUnits()
    {
        return courseUnits;
    }
};
//ADT for student information
struct StudentInfo
{
    StudentInfo(){};

  private:
    string admissionNumber;
    string surname;
    string firstName;
    string courseRegistered;
    Units courseUnits;
    string address;
    string gSurname;
    string gFirstName;

  public:
    string getAdmissionNumber()
    {
        return admissionNumber;
    }
    void setAdmissionNumber(string val)
    {
        admissionNumber = val;
    }
    string getSurname()
    {
        return surname;
    }
    void setSurname(string val)
    {
        surname = val;
    }
    string getFirstName()
    {
        return firstName;
    }
    void setFirstName(string val)
    {
        firstName = val;
    }
    string getCourseRegistered()
    {
        return courseRegistered;
    }
    void setCourseRegistered(string val)
    {
        courseRegistered = val;
    }
    string *getCourseUnits()
    {
        return courseUnits.getUnits();
    }
    int getNumberOfUnits()
    {
        return courseUnits.getUnitsNum();
    }

    void setCourseUnits(Units obj)
    {
        courseUnits = obj;
    }
    string getAddress()
    {
        return address;
    }
    void setAddress(string val)
    {
        address = val;
    }
    string getGSurname()
    {
        return gSurname;
    }
    void setGSurname(string val)
    {
        gSurname = val;
    }
    string getGFirstName()
    {
        return gFirstName;
    }
    void setGFirstName(string val)
    {
        gFirstName = val;
    }
};

#endif // STUDENTINFO_H
