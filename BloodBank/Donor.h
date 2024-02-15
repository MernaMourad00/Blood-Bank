#pragma once
#include<iostream> 
#include<string> 
#include<vector>
#include "p_user.h"
#include<sstream>
using namespace std;
class Donor : public p_user
{
public:
    string any_disease, date_of_latest_donation, any_medicine;

  
public:

    Donor(int id, int age, string name, string Email, string password, string gender,
        string blood_type, string any_disease, string any_medicine, string date_of_latest_donation);


    Donor();
    //new
    //void valid_blood(Donor d, int& day, int& mon, int& year);
    //
    void donorRegister(vector<Donor>& Don);
    //void login();
    void login2(int &index, vector<Donor>& Don);

    void update(vector<Donor>& Don,int id);
    void load_data(vector<Donor>& Don);
    void delete2(vector<Donor>& Don, int id);
    void save_data(vector<Donor>& Don);
    void DonationRequest(Donor& Don);
    //void valid_donor(Donor, int age);
    void valid_donor(Donor d, int& day, int& mon, int& year);
    //void option();
  

    ////admin
    //void InsertDonor(vector<Donor>& Don);
    //void ADMIN_update(vector<Donor>& Don);
    //void ADMIN_Delete(vector<Donor>& Don);;
    void DisplayDonor(vector<Donor>& Don);

};

