#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "user.h"

using std::string;

class Administrator : public User
{
public:
    Administrator(string name, int id);

    void showInfo() override;
    void genericAction() override;

    void blockUser(User* u);

};

#endif // ADMINISTRATOR_H
