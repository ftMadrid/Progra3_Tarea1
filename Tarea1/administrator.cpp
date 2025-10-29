#include "administrator.h"
#include <iostream>

#include <string>

using std::cout;
using std::endl;

Administrator::Administrator(string name, int id) {
    this->name = name;
    this->id = id;
}

void Administrator::showInfo(){
    User::showInfo();
    cout << "| Type: Administrator" <<endl;
    this->genericAction();
}

void Administrator::genericAction(){
    cout << "\n[*] " << this->getName() << " is managing things..." <<endl;
}

void Administrator::blockUser(User* user){

    if(!user->isBlocked()){
        if(user != nullptr){
            if(!user->isBlocked()){
                user->setBlocked();
                cout << "\n| The user " << user->getName() << " [" << user->getID() << "] has been successfully blocked!" <<endl;
            }else{
                cout << "\n| The user " << user->getName() << " [" << user->getID() << "] is already blocked!" <<endl;
            }
        }else{
            cout << "\n| This user doesnt exists!" <<endl;
        }
    }else{
        cout << "\n| You cannot block an user that is already blocked!" <<endl;
    }

}
