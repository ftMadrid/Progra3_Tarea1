#include "student.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Student::Student(string name, int id){
    this->name = name;
    this->id = id;
    credits = 40;
    graded = false;
    enrolled = false;
}

int Student::getCredits(){
    return credits;
}

bool Student::isEnrolled(){
    return this->enrolled;
}

bool Student::isGraded(){
    return this->graded;
}

void Student::enrollCourse(){
    if(!this->isBlocked()){
        if(!this->isEnrolled()){
            if(this->credits >= 10){
                this->enrolled = true;
                this->credits -= 10;
                cout << "\n| "<<this->getName()<<" has been successfully enrolled!" <<endl;
                cout << "| Remaining Credits: " << this->getCredits() << endl;
            }else{
                cout << "\n| You dont have enough credits to be enrolled" <<endl;
                cout << "| Current Credits: " << this->getCredits() << endl;
            }
        }else{
            cout << "\n| "<<this->getName()<<" is already enrolled!" <<endl;
        }
    }else{
        cout << "\n| You cannot enrolled an user if is blocked!" << endl;
    }
}

void Student::setGraded(){
    this->graded = true;
}

void Student::showInfo(){
    User::showInfo();
    cout << "| Type: Student" <<endl;
    cout << "| Credits: " << this->getCredits() <<endl;
    cout << "| Enrolled: " << (this->isEnrolled() ? "Yes" : "No") <<endl;
    cout << "| Graded: " << (this->isGraded() ? "Yes" : "No") <<endl;
    this->genericAction();
}

void Student::genericAction(){
    cout << "\n[*] " << this->getName() << " is studying..." <<endl;
}

