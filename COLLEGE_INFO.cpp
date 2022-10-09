#include <iostream>
#include <stdlib.h>
using namespace std;
class CET
{
private:
    string name;
    int aadhar;
    float ptile;
public:
    void getdata()
    {
        cout << "Enter Your Name : ";
        cin >> name;
        cout << "Enter Last 4 digit of AADHAR NO : ";
        cin >> aadhar;
        cout << "Enter Your CET Percentile : ";
        cin >> ptile;
    }
    void display()
    {
        cout << "Your Name : " << name << endl;
        cout << "Last 4 digit of AADHAR NO : " << aadhar << endl;
        cout << "Enter Your CET Percentile : " << ptile << endl;
    }
};
class college : public CET // 1st DERIVED CLASS
{
private:
public:
    int PRN = 12153 + rand() % 100000;
    string branch;
};
class PCCOE : public college // 2nd DERIVED CLASS
{
private:
    int FEE = 151000;

public:
    void sbranch()
    {
        getdata();
        display();
        cout << "Enter Your Branch : ";
        cin >> branch;
    }
    void dis()
    {
        cout << "You Have Selected " << branch << " in PCCOE & it has " << FEE << " Rs as FEE" << endl;
        cout << "YOUR PRN IN COLLEGE IS " << PRN << endl;
    }
};
class VIT : public college // PARALLEL DERIVED CLASS TO THAT O 2ND
{
    int FEE = 181000;

public:
    void sbranch()
    {
        getdata();
        display();
        cout << "Enter Your Branch : ";
        cin >> branch;
    }
    void dis()
    {
        cout << "You Have Selected " << branch << " in VIT it has " << FEE << " FEE in INR" << endl;
        cout << "YOUR PRN IN COLLEGE IS " << PRN << endl;
    }
};
int main()
{
    int opt;
    PCCOE student1;
    VIT student2;
    while (1)
    {
        cout << "Enter   \n\t1 For PCCOE \n\t2 For VIT\n:";
        cin >> opt;
        switch (opt)
        {
        case 1:
            student1.sbranch();
            student1.dis();
            break;
        case 2:
            student2.sbranch();
            student2.dis();
        default:
            cout << "You Have Entered Wrong Number" << endl;
            break;
        }
        cout << "__________________________________________________________________________________" << endl;
    }
    return 0;
}