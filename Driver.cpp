#include <iostream>
#include <string>
#include <fstream>
#include "Stack.hpp"
#include "Queue.hpp"
#include "StudentInfo.hpp"
#include "SinglyLinkedList.hpp"

//Dollar sign delimiter for files
const string delimiter = "$";
//Array that holds course units
string *courseUnit = NULL;
//Grabs input from user and returns an object containing
//student information
StudentInfo getDetails();
//Outputs results on the screen
void displayStudent(StudentInfo);
//Operates on queue
void queueOperations();
//Operates on stack
void stackOperations();
//Saves list to file as plaintext
void saveToFile();
//Reads infomation to a list
void readFromFile();
//Displays main menu
void mainMenu();
int main()
{
    try
    {
        readFromFile();
    }
    catch (SinglyLinkedList::ListIsEmpty)
    {
        std::cout << "Nothing in the file" << std::endl;
    }
    mainMenu();
    delete[] courseUnit;
    return 0;
}

StudentInfo getDetails()
{
    string admno, sName, fName, cRegistered, cUnit, address, gSName, gFName;
    int numberOfUnits;
    Units cUnits = Units();
    StudentInfo student;
    std::cout << "Please key in your admission number: ";
    std::cin >> admno;
    student.setAdmissionNumber(admno);
    std::cout << "Please key in your surname: ";
    std::cin >> sName;
    student.setSurname(sName);
    std::cout << "Please key in your first name: ";
    std::cin >> fName;
    student.setFirstName(fName);
    std::cout << "Please key in your course: ";
    std::cin.ignore();
    std::getline(std::cin, cRegistered);
    student.setCourseRegistered(cRegistered);
    std::cout << "Enter number of units: ";
    std::cin >> numberOfUnits;
    cUnits.setUnitsNum(numberOfUnits);
    std::cout << "Key in a unit then press enter" << endl;
    courseUnit = new string[numberOfUnits];
    std::cin.ignore();
    for (int j = 0; j < numberOfUnits; j++)
    {
        std::getline(std::cin, cUnit);
        courseUnit[j] = cUnit;
    }
    cUnits.setUnits(courseUnit);
    student.setCourseUnits(cUnits);
    std::cout << "Please key in your address: ";
    std::cin >> address;
    student.setAddress(address);
    std::cout << "Please key in your guardian\'s surname : ";
    std::cin >> gSName;
    student.setGSurname(gSName);
    std::cout << "Please key in your guardian\'s first name: ";
    std::cin >> gFName;
    student.setGFirstName(gFName);
    return student;
}

void displayStudent(StudentInfo student)
{
    Units units;
    std::cout << "*********************************************************" << endl;
    std::cout << "\t\tRECORD OF " << student.getFirstName() << endl;
    std::cout << "*********************************************************" << endl;
    std::cout << "STUDENT NAME:\t\t" << student.getFirstName();
    std::cout << " " << student.getSurname() << endl;
    std::cout << "ADMISSION NUMBER:\t" << student.getAdmissionNumber() << endl;
    std::cout << "COURSE REGISTERED:\t" << student.getCourseRegistered() << endl;
    std::cout << "\t\tCOURSE UNITS" << endl;
    for (int i = 0; i < student.getNumberOfUnits(); i++)
    {
        cout << student.getCourseUnits()[i] << endl;
    }
    std::cout << "***********************************************************" << endl;
    std::cout << "ADDRESS: " << student.getAddress() << endl;
    std::cout << "GUARDIAN NAME: " << student.getGFirstName() << " ";
    std::cout << student.getGSurname() << endl;
    std::cout << "***********************************************************" << endl;
}

void queueOperations()
{
    Queue q;
    Units units;
    StudentInfo student;
    string options[4] = {"Enqueue", "Dequeue",
                         "Display student in the queue",
                         "Back to main menu"};
    int choice;
    while (1)
    {
        std::cout << "*********************************************************" << endl;
        std::cout << "\t\tQUEUE MENU" << endl;
        std::cout << "*********************************************************" << endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << i + 1 << ". " << options[i] << endl;
        }
        std::cout << "Your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            q.enqueue(getDetails());
            break;
        case 2:
            try
            {
                student = q.dequeue();
                displayStudent(student);
            }
            catch (SinglyLinkedList::ListIsEmpty)
            {
                cout << "No student in the system" << endl;
            }
            break;
        case 3:
            try
            {
                string admno;
                std::cout << "Please key in admission number: ";
                cin >> admno;
                student = q.seek(admno);
                displayStudent(student);
            }
            catch (SinglyLinkedList::ListIsEmpty)
            {
                cout << "No student in the system" << endl;
            }
            catch (SinglyLinkedList::ElementNotFound)
            {
                cout << "The student does not exist in the system" << endl;
            }
            break;
        case 4:
            mainMenu();
            break;
        }
    }
}
void stackOperations()
{
    Stack stk;
    StudentInfo student;
    string options[4] = {"Push", "Pop",
                         "Display student in the stack",
                         "Back to main menu"};
    int choice;
    while (1)
    {
        std::cout << "*********************************************************" << endl;
        std::cout << "\t\tSTACK MENU" << endl;
        std::cout << "*********************************************************" << endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << i + 1 << ". " << options[i] << endl;
        }
        std::cout << "Your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            stk.push(getDetails());
            break;
        case 2:
            try
            {
                student = stk.pop();
                displayStudent(student);
            }
            catch (SinglyLinkedList::ListIsEmpty)
            {
                cout << "No student in the system" << endl;
            }
            break;
        case 3:
            try
            {
                string admno;
                std::cout << "Please key in admission number: ";
                cin >> admno;
                student = stk.seek(admno);
                displayStudent(student);
            }
            catch (SinglyLinkedList::ListIsEmpty)
            {
                cout << "No student in the system" << endl;
            }
            catch (SinglyLinkedList::ElementNotFound)
            {
                cout << "The student does not exist in the system" << endl;
            }
            break;
        case 4:
            mainMenu();
            break;
        }
    }
}

void mainMenu()
{
    string options[3] = {"Stack", "Queue", "Exit"};
    int choice;
    while (1)
    {
        std::cout << "*********************************************************" << endl;
        std::cout << "\t\tMAIN MENU" << endl;
        std::cout << "*********************************************************" << endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout << i + 1 << ". " << options[i] << endl;
        }
        std::cout << "Your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            stackOperations();
            break;
        case 2:
            queueOperations();
            break;
        case 3:
            saveToFile();
            std::exit(0);
            break;
        }
    }
}

void saveToFile()
{
    ofstream outfile;
    outfile.open("data.bin", std::ios::out);
    if (!lst.isEmpty())
    {
        for (int i = 0; i < lst.getSize(); i++)
        {
            StudentInfo student;
            try
            {
                StudentInfo info = lst.removeFirst(student);
                std::cout << "Saving " << info.getFirstName() << endl;
                outfile << info.getFirstName() << delimiter;
                outfile << info.getSurname() << delimiter;
                outfile << info.getAdmissionNumber() << delimiter;
                outfile << info.getCourseRegistered() << delimiter;
                outfile << info.getNumberOfUnits() << delimiter;
                for (int i = 0; i < info.getNumberOfUnits(); i++)
                {
                    outfile << info.getCourseUnits()[i] << delimiter;
                }
                outfile << info.getAddress() << delimiter;
                outfile << info.getGSurname() << delimiter;
                outfile << info.getGFirstName() << delimiter;
            }
            catch (SinglyLinkedList::ListIsEmpty)
            {
                cout << "Finished saving" << endl;
            }
        }
        std::cout << "Linked list saved" << endl;
        outfile.close();
    }
}
void readFromFile()
{
    Units units = Units();
    ifstream infile;
    infile.open("data.bin", ios::in);
    if (!infile)
    {
        std::cout << "Could not find student\'s file" << endl;
    }
    if (infile)
    {
        StudentInfo info;
        string admno, sName, fName, cRegistered, address, gSName, gFName, unit, unitsNum;
        bool firstEntry = true;
        std::getline(infile, fName, delimiter.c_str()[0]);
        while (infile)
        {
            if (!firstEntry)
            {
                std::getline(infile, fName, delimiter.c_str()[0]);
            }
            firstEntry = false;
            info.setFirstName(fName);
            std::getline(infile, sName, delimiter.c_str()[0]);
            info.setSurname(sName);
            std::getline(infile, admno, delimiter.c_str()[0]);
            info.setAdmissionNumber(admno);
            std::getline(infile, cRegistered, delimiter.c_str()[0]);
            info.setCourseRegistered(cRegistered);
            std::getline(infile, unitsNum, delimiter.c_str()[0]);
            units.numberOfUnits = std::stoi(unitsNum);
            courseUnit = new string[std::stoi(unitsNum)];
            for (int j = 0; j < std::stoi(unitsNum); j++)
            {
                std::getline(infile, unit, delimiter.c_str()[0]);
                courseUnit[j] = unit;
            }
            units.setUnits(courseUnit);
            info.setCourseUnits(units);
            std::getline(infile, address, delimiter.c_str()[0]);
            info.setAddress(address);
            std::getline(infile, gSName, delimiter.c_str()[0]);
            info.setGSurname(gSName);
            std::getline(infile, gFName, delimiter.c_str()[0]);
            info.setGFirstName(gFName);
            lst.insertLast(lst.create(info));
        }
    }
    infile.close();
}