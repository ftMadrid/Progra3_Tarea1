#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "user.h"
#include <vector>

using std::vector;
using std::string;

class Student : public User
{
public:
    Student(string name, int id);

    void showInfo() override;
    void genericAction() override;

    int getCredits();
    bool isEnrolled();
    bool isGraded();
    void enrollCourse();
    void setGraded();

private:
    int credits;
    bool graded;
    bool enrolled;
};

#endif // STUDENT_H
