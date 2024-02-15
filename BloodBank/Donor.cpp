#pragma warning(disable : 4996)
#include<iostream> 
#include "donor.h" 
#include "p_user.h"
#include "Blood.h"
#include <fstream> 
#include<sstream>
#include<string> 
#include <stdio.h>
using namespace std;
Donor::Donor(int id, int age, string name, string Email, string password, string gender,
    string blood_type, string any_disease, string any_medicine, string date_of_latest_donation)
    : p_user(id, age, name, Email, password, gender, blood_type)
{
    {
        this->any_disease = any_disease;
        this->date_of_latest_donation = date_of_latest_donation;
        this->any_medicine = any_medicine;
    }
}

//void doner::option() {
//    int x;
//    cout << "\t\t\t" << "PLEASE PRESS " << endl;
//    cout << "1:\n2:FO DELETE YOUR ACCOUNT\n3:TO MAKE A DONATION REQUEST\n4:TO REQUEST FOR BEING ADMIN\n5:LOGOUT\n";
//    cin >> x;

void reqdate(string date, int& mon, int& year)
{
    string w = "";
    int num = 0;
    for (auto x : date)
    {
        if (x == '/')
        {
            stringstream g(w);
            int x = 0;
            g >> x;
            w = "";

            if (num == 1)
                mon = x;
            num++;
        }
        else {
            w = w + x;
        }
    }
    stringstream k(w);
    int x = 0;
    k >> x;
    year = x;
}

void Donor::valid_donor(Donor d, int& day, int& mon, int& year)
{
    stringstream ss;
    int n, m;
    reqdate(d.date_of_latest_donation, n, m);
    ss << d.age;
    int a;
    ss >> a;
    if (a >= 17 && a < 60 && d.any_medicine.compare("no") == 0 && d.any_disease.compare("no") == 0 && ((year > m) && mon - 3 >= (n)))
    {
        cout << "valid request" << endl;
    }
    else 
    {
        cout << "invalid request" << endl;
    }
    
}
/*void  Donor::valid_blood(Donor d, int& day, int& mon, int& year)
{
    int n, m;
    reqdate(d.date_of_latest_donation, n, m);
    stringstream ss;
    ss << d.age;
    int a;
    ss >> a;
    if (a >= 17 && a < 60 && ((year > m) || mon - 3 >= (n)) && d.any_medicine.compare("no") == 0 && d.any_disease.compare("no") == 0)
    {
        ofstream valid_blood;
        valid_blood.open("validblood.txt", ios::app);
        valid_blood << blood_type << "," << day << "/" << mon << "/" << year << "," << day << "/" << (mon + 1) % 12 << "/" << year + (mon / 12) << '\n';
        valid_blood.close();
    }
    else
    {
        return ;
    }
}*/
Donor::Donor() {
    id = 0;

}
//tmam
void Donor::donorRegister(vector<Donor>& Don)
{
    ofstream donorf;
 
    int id = Don[Don.size() - 1].id + 1;
    stringstream ss, ss2;


    cout << "Enter your name" << endl;
    getline(cin, name);
    cout << "Enter your mail" << endl;
    getline(cin, Email);
    cout << "Enter your password" << endl;
    getline(cin, password);
    cout << "Enter your age" << endl;
    cin >> age;
    cout << "Enter your Gender (Male/Female) " << endl;
    cin >> gender;
    cout << "Enter your blood type " << endl;
    cin >> blood_type;
    cin.ignore();
    cout << "do you suffer from blood pressure disorders,thyroid,diabetes,cancer,heart disorders,hepatitis " << endl;
    getline(cin, any_disease);
    cout << "do you suffer from any other disease  " << endl;
    getline(cin, any_medicine);
    cout << "Enter date of last donation" << endl;
    getline(cin, date_of_latest_donation);
    int a, a1;
    ss << age;
    ss2 << id;
    ss >> a;
    ss2 >> a1;
    Donor d(a1, a, name, Email, password, gender, blood_type, any_disease, any_medicine, date_of_latest_donation);
    Don.push_back(d);
    save_data(Don);
    Blood b;
   
   
    cout << "Your Registeration done SUCSSEFULLY" << endl;

}
//tmam
void Donor::login2(int &index, vector<Donor>& Don) {
 
        //system("cls");
        bool flag = false;
        string email, password;
        cout << "Enter Your email: " << endl;
        getline(cin, email);
        cout << "Enter Your Password: " << endl;
        getline(cin, password);
        for (int i = 0; i < Don.size(); i++)
        {
            if (Don[i].Email == email && Don[i].password == password)
            {
                index = i;
                cout << "-----SIGNED IN SUCCESSFULLY-----";
                flag = true;
                break;
            }
            if (i == Don.size() - 1)
            {
                cout << "\nWrong username or password";


            }
        }
       

}
//tmam
void Donor::load_data(vector<Donor>& Don)
{
    fstream file_donor;
    file_donor.open("donor.txt", fstream::in);

    string line;
    while (getline(file_donor, line))
    {
        stringstream inputString(line);
        string id2, Name, age22, Email, password, gender, blood_type, disease, medicine,last ;
        stringstream ss,ss2;
        getline(inputString, id2, ',');
        getline(inputString, Name, ',');
        getline(inputString, age22, ',');
        getline(inputString, Email, ',');
        getline(inputString, password, ',');
        getline(inputString, gender, ',');
        getline(inputString, blood_type, ',');
        getline(inputString, disease, ',');
        getline(inputString, medicine, ',');
        getline(inputString, last,',');
        int a,a1;
        ss << age22;
        ss2 << id2;
        ss >> a;
        ss2 >> a1;
        Donor d(a1 ,a, Name, Email, password, gender, blood_type, disease, medicine, last);
        Don.push_back(d);

    }
    file_donor.close();

}
//tmam
void Donor::update(vector<Donor>& Don,int id) {

    for (int i = 0; i < Don.size(); i++)
    {
        if (Don[i].id == id)
        {
            cout << "what do you want to update?\n1.Name\n2.Password\nEnter your choice:  ";
            int num_of_choice;
            cin >> num_of_choice;
            if (num_of_choice == 1)
            {
                cout << "\nEnter the new name: ";
                string name;
                cin.ignore();
                getline(cin, name);
                Don[i].name = name;
            }
            else if (num_of_choice == 2)
            {
                cout << "\nEnter the new password: ";
                string password;
                getline(cin, password);
                Don[i].password = password;
            }

            break;
        }
        if(i==Don.size()-1)
            cout << "\nnot found";
    }

    save_data(Don);
}
//tmam
void Donor::delete2(vector<Donor>& Don, int id) {
    vector<Donor>::iterator it;

    for (it = Don.begin(); it != Don.end(); it++)
    {
        if (it->id == id)
        {
            it = Don.erase(it);
            break;
        }
    }
    save_data(Don);
}
//tmam
void Donor::save_data(vector<Donor>& Don) {
    fstream donor;
    fstream temp;
    donor.open("donor.txt", fstream::in);
    temp.open("temp.txt", fstream::out);
    for (int i = 0; i < Don.size(); i++) {

        temp << Don[i].id << "," << Don[i].name << ","
            << Don[i].age << "," << Don[i].Email
            << "," << Don[i].password << "," << Don[i].gender
            << "," << Don[i].blood_type << "," << Don[i].any_disease
            << "," << Don[i].any_medicine << ","
            << Don[i].date_of_latest_donation << "," << endl;

    }
    temp.close();
    donor.close();
    remove("donor.txt");
    rename("temp.txt" , "donor.txt");

}
//tmam
void Donor::DonationRequest(Donor& Don)
{
    bool flag = true;
    if (flag == false)
    { return; }
    int donreq;
    time_t now;
    struct tm  nowloc;
    now = time(NULL);
    nowloc = *localtime(&now);
    int mon1, year1;
    mon1 = (nowloc.tm_mon + 1);
    year1 = (nowloc.tm_year + 1900);
  valid_donor(Don, nowloc.tm_mday, mon1, year1);
  {
      flag = false;
          return;
  }
  
    cout << "______________" << endl;
    /*int donreq;
    time_t now;
    struct tm  nowloc;
    now = time(NULL);
    nowloc = *localtime(&now);*/

    ofstream donoreq;
    donoreq.open("dreq.txt", ios::app);
    cout << "Your Donoration Request done SUCSSEFULLY" << endl;//wait
    donoreq << Don.name << "," << Don.age
        << "," << Don.blood_type << "," << Don.any_disease << "," << Don.any_medicine << "," << Don.date_of_latest_donation << "," << nowloc.tm_mday << "," << nowloc.tm_mon + 1 << " " << nowloc.tm_year + 1900 << '\n';
    donoreq.close();
    /*int mon1, year1;*/
    /*mon1 = (nowloc.tm_mon + 1);
    year1 = (nowloc.tm_year + 1900);*/
   // valid_blood(Don, nowloc.tm_mday, mon1, year1);
  
}




void Donor::DisplayDonor(vector<Donor>& Don) {
    cout << "Blood Type\t Donation day\t Expiry date\n";
    for (int i = 0; i < Don.size(); i++) {
        cout << Don[i].id << "\t \t " << Don[i].name << "\t " << Don[i].blood_type << endl;
    }
}

