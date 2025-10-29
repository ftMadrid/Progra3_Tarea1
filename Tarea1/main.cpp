#include <QCoreApplication>
#include <iostream>
#include <string>

#include "user.h"
#include "student.h"
#include "teacher.h"
#include "administrator.h"

using std::cout;
using std::endl;
using std::cin;
using std::getline;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<User*> users;

    users.push_back(new Student("Fernando Madrid", 1));
    users.push_back(new Student("Samuel Vasquez", 2));
    users.push_back(new Teacher("Erick Amaya", 3));
    users.push_back(new Teacher("Victor Ramirez", 4));
    users.push_back(new Administrator("Aaron Cerrato", 5));
    users.push_back(new Administrator("Carolina Rivera", 6));

    int option = 0;
    int type = 0;

    string name;
    int id;

    do{

        cout << "\n === User Management Platform === \n" << endl;
        cout << "1. Add an User" << endl;
        cout << "2. User List" << endl;
        cout << "3. Specific Actions" << endl;
        cout << "4. Exit" << endl;

        cout << "\n| Choose an option: ";
        cin >> option;

        switch(option){
        case 1:
            do {
                cout << "\n === Add a User === \n" << endl;
                cout << "1. Student" << endl;
                cout << "2. Teacher" << endl;
                cout << "3. Administrator" << endl;
                cout << "4. Go back" << endl;

                cout << "\n| Choose an option: ";
                cin >> type;

                if (type >= 1 && type <= 3) {
                    cout << "\n === Add " << (type == 1 ? "a Student" : type == 2 ? "a Teacher" : "an Administrator") << " === \n" << endl;
                    cin.ignore();
                    cout << "| Set the name: ";
                    getline(cin, name);
                    cout << "\n| Set the ID: ";
                    cin >> id;

                    for(auto* u : users){
                        if(u->getID() == id){
                            cout << "\n| An user with this ID already exists!" << endl;
                            break;
                        }else{
                            User* newUser = nullptr;

                            switch (type) {
                            case 1:
                                newUser = new Student(name, id);
                                break;
                            case 2:
                                newUser = new Teacher(name, id);
                                break;
                            case 3:
                                newUser = new Administrator(name, id);
                                break;
                            }

                            if (newUser != nullptr) {
                                users.push_back(newUser);
                                cout << "\n| User "<<newUser->getName()<<" ["<<newUser->getID()<<"] added successfully!" << endl;
                            }
                            break;
                        }
                    }
                } else if (type == 4) {
                    cout << "\n| Leaving Add User menu..." <<endl;
                } else {
                    cout << "\n| Please enter a valid option!" <<endl;
                }

            } while (type != 4);
            break;
        case 2:
            cout << "\n === User List === " <<endl;
            for(auto* u : users){
                u->showInfo();
            }
            break;
        case 3: {
            cin.ignore();
            int opt;
            do {
                cout << "\n === Specific Actions === \n" << endl;
                cout << "1. Student" << endl;
                cout << "2. Teacher" << endl;
                cout << "3. Administrator" << endl;
                cout << "4. Go back" << endl;

                cout << "\n| Choose a type of user: ";
                cin >> type;

                if (type == 4) {
                    cout << "\n| Leaving Specific Actions menu..." <<endl;
                    break;
                }

                cout << "\n === Listing " << (type == 1 ? "Students" : type == 2 ? "Teachers" : "Administrators") << " ==="<<endl;

                bool found = false;
                for (User* u : users) {
                    if ((type == 1 && dynamic_cast<Student*>(u)) ||
                        (type == 2 && dynamic_cast<Teacher*>(u)) ||
                        (type == 3 && dynamic_cast<Administrator*>(u))) {
                        cout << "\n| Name: " << u->getName() <<endl;
                        cout << "| ID: " << u->getID() <<endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "\n| No users of this type were found!" <<endl;
                    continue;
                }

                int selectedID;
                cout << "\n| Enter the ID of the user you want to select: ";
                cin >> selectedID;

                User* selectedUser = nullptr;
                for (auto* u : users) {
                    if (u->getID() == selectedID) {
                        if ((type == 1 && dynamic_cast<Student*>(u)) ||
                            (type == 2 && dynamic_cast<Teacher*>(u)) ||
                            (type == 3 && dynamic_cast<Administrator*>(u))) {
                            selectedUser = u;
                            break;
                        }
                    }
                }

                if (!selectedUser) {
                    cout << "\n| No user found with that ID for this type!" <<endl;
                    continue;
                }

                cout << "\n| You selected: " << selectedUser->getName() << " [" <<selectedUser->getID() << "]" << endl;

                if (type == 1) {
                    Student* s = dynamic_cast<Student*>(selectedUser);
                    do {
                        cout << "\n === Student Actions ["<<s->getName()<<"] ===\n" <<endl;
                        cout << "1. Show Information" <<endl;
                        cout << "2. Enroll" <<endl;
                        cout << "3. Generic Action" <<endl;
                        cout << "4. Go back" <<endl;
                        cout << "\n| Choose an option: ";
                        cin >> opt;

                        switch (opt) {
                        case 1:
                            cout << "\n === Information ===" <<endl;
                            s->showInfo();
                            break;
                        case 2:
                            if(!s->isBlocked()){
                                cout << "\n === Enroll a Course ===" <<endl;
                                s->enrollCourse();
                            }else{
                                cout << "\n| You cannot do tasks while you are blocked!" <<endl;
                            }
                            break;
                        case 3:
                            cout << "\n === "<<s->getName()<<" Action ===" <<endl;
                            s->genericAction();
                            break;
                        case 4:
                            cout << "\n| Leaving Student Actions menu..." <<endl;
                            break;
                        default:
                            cout << "\n| Please enter a valid option!" <<endl;
                            break;
                        }
                    } while (opt != 4);
                }
                else if (type == 2) {
                    Teacher* t = dynamic_cast<Teacher*>(selectedUser);
                    int opt;
                    do {
                        cout << "\n === Teacher Actions ["<<t->getName()<<"] ===\n" <<endl;
                        cout << "1. Show Information" <<endl;
                        cout << "2. Grade a Student" <<endl;
                        cout << "3. Generic Action" <<endl;
                        cout << "4. Go Back" <<endl;
                        cout << "\n| Choose an option: ";
                        cin >> opt;

                        switch (opt) {
                        case 1:
                            cout << "\n === Information ===" <<endl;
                            t->showInfo(); break;
                        case 2: {
                            if(!t->isBlocked()){
                                int studID;
                                cout << "\n| Enter ID of student to grade: ";
                                cin >> studID;
                                Student* stud = nullptr;
                                for (User* u : users) {
                                    stud = dynamic_cast<Student*>(u);
                                    if (stud && stud->getID() == studID)
                                        break;
                                    stud = nullptr;
                                }
                                cout << "\n === Grading " << stud->getName() <<" ===" <<endl;
                                if (stud){
                                    t->gradeTask(stud);
                                }else{
                                    cout << "\n| No student found with that ID!" <<endl;
                                }
                            }else{
                                cout << "\n| You cannot do tasks while you are blocked!" <<endl;
                            }
                            break;
                        }
                        case 3:
                            cout << "\n === "<<t->getName()<<" Action ===" <<endl;
                            t->genericAction();
                            break;
                        case 4:
                            cout << "\n| Leaving Teacher Actions menu..." <<endl;
                            break;
                        default:
                            cout << "\n| Please enter a valid option!" <<endl;
                            break;
                        }
                    } while (opt != 4);
                }
                else if (type == 3) {
                    Administrator* a = dynamic_cast<Administrator*>(selectedUser);
                    int opt;
                    do {
                        cout << "\n === Administrator Actions ["<<a->getName()<<"] ===\n" <<endl;
                        cout << "1. Show Information"<<endl;
                        cout << "2. Block an User" <<endl;
                        cout << "3. Generic Action" <<endl;
                        cout << "4. Go Back" <<endl;
                        cout << "\n| Choose an option: ";
                        cin >> opt;

                        switch (opt) {
                        case 1:
                            cout << "\n === Information ===" <<endl;
                            a->showInfo();
                            break;
                        case 2: {
                            if(!a->isBlocked()){
                                cout << "\n| Enter ID of user to block: ";
                                cin >> id;

                                bool found = false;

                                for (auto* u : users) {
                                    if (u && u->getID() == id) {
                                        cout << "\n === Blocking " << u->getName() << " ===" << endl;
                                        a->blockUser(u);
                                        found = true;
                                        break;
                                    }
                                }

                                if (!found) {
                                    cout << "\n| No user found with that ID!" << endl;
                                }
                            }else{
                                cout << "\n| You cannot do tasks while you are blocked!" <<endl;
                            }
                            break;
                        }
                        case 3:
                            cout << "\n === "<<a->getName()<<" Action ===" <<endl;
                            a->genericAction();
                            break;
                        case 4:
                            cout << "\n| Leaving Administrator Actions menu..." <<endl;
                            break;
                        default:
                            cout << "\n| Please enter a valid option!" <<endl;
                            break;
                        }
                    } while (opt != 4);
                }

            } while (type != 4);
            break;
        }
        case 4:
            print "\n| Have a nice day!" ln;
            for(auto* u : users){
                delete u;
            }
            users.clear();
            break;
        default:
            break;
        }

    }while(option != 4);

    return a.exec();
}
