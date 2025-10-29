#include "teacher.h"
#include "student.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

Teacher::Teacher(string name, int id) {
    this->name = name;
    this->id = id;
    this->gradedCant = 0;
}

void Teacher::gradeTask(Student* student){

    if(!student->isBlocked()){
        if(student != nullptr){
            if(student->isEnrolled()){
                if(!student->isGraded()){
                    student->setGraded();
                    cout << "\n| The student " << student->getName() << " has been graded!" << endl;
                    gradedCant++;
                }else{
                    cout << "\n| You cannot grade a student that is already graded!" << endl;
                }
            }else{
                cout << "\n| You cannot grade a student that isnt enrolled!" << endl;
            }
        }else{
            cout << "\n| This user doesnt exists!" << endl;
        }
    }else{
        cout << "\n| You cannot graded an user if is blocked!" << endl;
    }
}

int Teacher::gradedTask(){
    return this->gradedCant;
}

void Teacher::showInfo(){
    User::showInfo();
    cout << "| Type: Teacher" << endl;
    cout << "| Graded Tasks: " << this->gradedTask() << endl;
    this->genericAction();
}

void Teacher::genericAction(){
    cout << "\n[*] " << this->getName() << " is grading tasks..." << endl;
}
