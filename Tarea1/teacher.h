#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include "student.h"

using std::cout;
using std::endl;

#define print cout <<
#define ln << endl

class Teacher : public User
{
public:
    Teacher(string name, int id);

    void showInfo() override;
    void genericAction() override;

    void gradeTask(Student* us);
    int gradedTask();

private:

    int gradedCant;

};

#endif // TEACHER_H
