#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MaxUsers 100
#define MaxTime 60

struct user{
    char name[20];
    int id;
    int time_left;
};
using namespace std;

int main()
{
   struct user users[MaxUsers];
   int num_Users = 0;

   int option;
   do{
    cout<< "Management system"<<endl;
    cout<< "-----------------"<<endl;
    cout<< "Choose a number to perform an action" <<endl;
    cout<< "------------------------------------"<<endl;
    cout<< "1 Add User" <<endl;
    cout<< "----------"<<endl;
    cout<< "2 Remove User" <<endl;
    cout<< "-------------"<<endl;
    cout<< "3 Print User List" <<endl;
    cout<< "-----------------"<<endl;
    cout<< "4 Logout User" <<endl;
    cout<< "-------------"<<endl;
    cout<< "5 Exit" <<endl;
    cout<< "------"<<endl;
    cin>>option;

    switch(option){
        case 1:{
            if(num_Users<MaxUsers){
                struct user new_user;
                cout<< "Enter user name" <<endl;
                cin>>new_user.name;
                cout<< "Enter user ID"<<endl;
                cin>>new_user.id;
                cout<< "Enter the entry time" <<endl;
                cin>>new_user.time_left;

                users[num_Users++] = new_user;

                cout<< "User successfully added" <<endl;
            }
            else{
                cout<< "Minimum number of users reached!"<<endl;
            }
            break;
        }
        case 2:{
            int user_id;
            cout<< "Enter the user ID to remove" <<endl;
            cin >>user_id;

            int found = 0;
            for(int i=0; i<num_Users;i++){
                if(users[i].id==user_id){
                    found = 1;
                    for(int j=i;j<num_Users-1;j++){
                        users[j] = users[j+1];
                    }
                    num_Users--;
                    cout<< "User removed successfully" <<endl;
                break;
                }
                }
                if(!found){
                    cout<< "User not found" <<endl;
                }
                break;
            }
        case 3:{
            cout<< "User List" <<endl;
            cout<< "---------"<<endl;
            for(int i = 0;i<num_Users;i++){
                cout<< "User name" <<endl;
                cout<<users[i].name<<endl;
                cout<<"User ID"<<endl;
                cout<<users[i].id<<endl;
                cout<<"Time left"<<endl;
                cout<<users[i].time_left<<endl;
            }
            break;
        }
        case 4:{
            int user_id;
            cout<< "Enter the user ID to logout:" <<endl;
            cin>>user_id;

            int found = 0;

            for(int i=0;i<num_Users;i++){
                if(users[i].id == user_id){
                    found = 1;
                    cout<< "Successfully logged out" <<endl;
                    for(int j = i;j<num_Users-1;j++){
                        users[j] = users[j+1];
                    }
                    num_Users--;
                    break;
                }
                }
                if(!found){
                       cout<< "User not found" <<endl;
                       break;
            }
        }
        case 5:{
            cout<< "Exiting Program" <<endl;
            break;
        }
        default:{
            cout<< "Invalid option." <<endl;
            break;
        }

    }
   }while(option !=5);
    return 0;
}
