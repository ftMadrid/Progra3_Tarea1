#include "user.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

User::User() : name(""), id(0){}

User::User(string name, int id) {
    this->name = name;
    this->id = id;
    this->blocked = false;
}

string User::getName(){
    return this->name;
}

int User::getID(){
    return this->id;
}

bool User::isBlocked(){
    return this->blocked;
}

void User::setBlocked(){
    this->blocked = true;
}

void User::showInfo(){
    cout << "\n| Name: " << this->getName() <<endl;
    cout << "| ID: " << this->getID() <<endl;
    cout << "| Blocked: " << (this->isBlocked() ? "Yes" : "No") <<endl;
}

User::~User(){}
