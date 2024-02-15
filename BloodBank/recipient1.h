#pragma once
#include "p_user.h"
#include "Blood.h"
#include<string> 
#include<iostream> 
#include<vector> 
#include<fstream> 
#include <map>
#include<sstream>
using namespace std;
class recipient : public p_user
{
public:
    string hospital, doctor;

    recipient(int id, int age, string name, string Email, string password, string gender, string blood_type,
        string hospital, string doctor)
        : p_user(id, age, name, Email, password, gender, blood_type)
    {
        {
            this->hospital = hospital;
            this->doctor = doctor;
        }
    }
    recipient() {
        this->id = 0;

    }

public:
  //  void  Request_the_blood(map <string, int>& m, vector<Blood>& blood);
    void all_valid_blood(map <string, int>& m);
    void Request_the_blood(map <string, int>& m, vector<Blood>& blood);
    
    void recipientRegister(vector<recipient>& rec);
    void login(int& index, vector<recipient>& rec);
    void Recipient_load_data(vector<recipient>& d);
    void updateRecipient(vector<recipient>& rec,int id);
    void deleteRecipient(vector<recipient>& rec, int id);
    void recipientRequest();
    void save_data(vector<recipient>& rec);
    void displayBloodData();
    bool search(map<string, int>& bloodnum);
    //admin
   /* void ADMIN_insert(vector<recipient>& rec);
    void ADMIN_Delete(vector<recipient>& rec);
    void ADMIN_update(vector<recipient>& rec);*/
    void Displayrecipient(vector<recipient>& rec);


   //void DeleteAccount(string );
    
};
