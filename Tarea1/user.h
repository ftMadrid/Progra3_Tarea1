#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class User
{
public:
    User();
    User(string name, int id);

    string getName();
    int getID();
    bool isBlocked();
    void setBlocked();
    virtual void showInfo();
    virtual void genericAction() = 0;

    virtual ~User();

protected:
    string name;
    int id;
    bool blocked;
};

#endif // USER_H
