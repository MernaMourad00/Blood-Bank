#include "recipient1.h"
#include "Blood.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <map>
#include <stdio.h>
using namespace std;

#pragma warning(disable : 4996)
void recipient::Request_the_blood(map <string, int>& m, vector<Blood>& blood)
{
    string blod;
    int q;
    cout << "Enter blood type : ";
    cin >> blod;
    cout << "Enter quantity : ";
    cin >> q;
    Blood b;
    if (m.count(blod) == 1 && m[blod] >= q)
    {
        b.delete_blood(blood, q, blod);
        cout << "valid go to hospital";

    }

}

void  recipient::all_valid_blood(map <string, int>& m)
{

    fstream bloodfile("blooddata.txt", fstream::in);
    string l;
    while (getline(bloodfile, l))
    {

        stringstream inputString(l);
        string blood_t;
        getline(inputString, blood_t, ',');
        m[blood_t]++;

    }

}


void recipient::recipientRegister(vector<recipient>& rec)
{
     stringstream ss, ss2;
    int id = rec[rec.size() - 1].id+1;
    cout <<"Your ID = "<< " " << id<<endl;
    string Name1, age1, Email1, password1, gender1, blood_type1, hospital1, doctor1;
    cout << "Enter your name " << endl;
    getline(cin, Name1);
    cout << "Enter your mail " << endl;
    getline(cin, Email1);
    cout << "Enter your password " << endl;
    getline(cin, password1);
    cout << "Enter your age " << endl;
    cin >> age1;
    cin.ignore();
    cout << "Enter your Gender (Male/Female)" << endl;
    getline(cin, gender1);
    cout << "Enter your blood type " << endl;
    getline(cin, blood_type1);
    cout << "Enter hospital name  " << endl;
    getline(cin, hospital1);
    cout << "Enter doctor of the case " << endl;
    getline(cin, doctor1);
    int a, a1;
    ss << age1;
    ss2 << id;
    ss >> a;
    ss2 >> a1;
    recipient R(a1, a, Name1, Email1, password1, gender1, blood_type1, hospital1, doctor1);
    rec.push_back(R);

    cout << "Your Registeration done SUCSSEFULLY" << endl;
    save_data(rec);
   
}

void recipient::login(int& index, vector<recipient>& rec) {

    //system("cls");
    bool flag = false;
    string email, password;
    cout << "Enter Your email: " << endl;
    getline(cin, email);
    cout << "Enter Your Password: " << endl;
    getline(cin, password);
    for (int i = 0; i < rec.size(); i++)
    {
        if (rec[i].Email == email && rec[i].password == password)
        {
            index = i;
            cout << "-----SIGNED IN SUCCESSFULLY-----";
            flag = true;
            break;
        }
        if (i == rec.size() - 1)
        {
            cout << "\nWrong email or password";


        }
    }


}

void  recipient::Recipient_load_data(vector<recipient>& rec)
{
    fstream file_recipient;
    file_recipient.open("rinfoo.txt", fstream::in);
    string line;
    while (getline(file_recipient, line))
    {
        stringstream inputString(line);
        stringstream ss, ss2;

        string id1, Name1, age1, Email1, password1, gender1, blood_type1, hospital1, doctor1;
        getline(inputString, id1, ',');
        getline(inputString, Name1, ',');
        getline(inputString, age1, ',');
        getline(inputString, Email1, ',');
        getline(inputString, password1, ',');
        getline(inputString, gender1, ',');
        getline(inputString, blood_type1, ',');
        getline(inputString, hospital1, ',');
        getline(inputString, doctor1, ',');
        int a, a1;
        ss << age1;
        ss2 << id1;
        ss >> a;
        ss2 >> a1;
        recipient R(a1, a, Name1, Email1, password1, gender1, blood_type1, hospital1, doctor1);
        rec.push_back(R);

     
    }
    file_recipient.close();

}

void recipient::updateRecipient(vector<recipient>& rec,int id) {
   
    for (int i = 0; i < rec.size(); i++)
    {
        if (rec[i].id == id)
        {
            cout << "what do you want to update?\n1.Hospital\n2.Password\nEnter your choice:  ";
            int num_of_choice;
            cin >> num_of_choice;
            if (num_of_choice == 1)
            {
                cout << "\nEnter the new hostpital name: ";
                string hospital;
                cin.ignore();
                getline(cin, hospital);
                rec[i].hospital = hospital;
                cout << "hospital has been updated" << endl;
            }
            else if (num_of_choice == 2)
            {
                cout << "\nEnter the new password: ";
                string password;
                cin >> password;
                rec[i].password = password;
                cout<<"password has been updated"<<endl;
            }

            break;
        }
        if (i == rec.size() - 1) {
            cout << "\nnot found";
        }
    }

    save_data(rec);

}

void recipient::deleteRecipient(vector<recipient>& rec, int id) {
    vector<recipient>::iterator it;
   
    for (it = rec.begin(); it != rec.end(); it++)
    {
        if (it-> id == id)
        {
            it = rec.erase(it);
            break;
        }
    }
    
    save_data(rec);


}
/*
void recipient::save_data(vector<recipient>& rec) {
    fstream Recipient;
    fstream temp;
    Recipient.open("rinfoo.txt", fstream::in);
    temp.open("temp.txt", fstream::out);
    for (int i = 0; i < rec.size(); i++) {

        temp << rec[i].id << "," << rec[i].name << ","
            << rec[i].age << "," << rec[i].Email
            << "," << rec[i].password << "," << rec[i].gender
            << "," << rec[i].blood_type << "," << rec[i].hospital
            << "," << rec[i].doctor << "," << endl;

    }
    temp.close();
    Recipient.close();
    remove("rinfoo.txt");
    rename("temp.txt" , "rinfoo.txt");

} */

void recipient::save_data(vector<recipient>& rec) {
    fstream Recipient;
    fstream temp;
    Recipient.open("rinfoo.txt", fstream::out | fstream::trunc); // Open file in write mode and truncate existing contents
    temp.open("temp.txt", fstream::out);
    for (int i = 0; i < rec.size(); i++) {
        temp << rec[i].id << "," << rec[i].name << ","
            << rec[i].age << "," << rec[i].Email
            << "," << rec[i].password << "," << rec[i].gender
            << "," << rec[i].blood_type << "," << rec[i].hospital
            << "," << rec[i].doctor << "," << endl;
    }
    temp.close();
    Recipient.close();
    remove("rinfoo.txt");
    rename("temp.txt", "rinfoo.txt");
}


bool recipient::search(map<string, int>& bloodnum)
{
    cout << "Enter the blood type you're looking for : ";
    string type;
    cin >> type;
    if (bloodnum.count(type) == 1){

        return true;
    }
    else{
        return false;
    }
}

void recipient::displayBloodData() {
    ifstream file("BloodData.txt", ios::in);
    vector<string>v;
    string str;
    while (file >> str) {
        //v.push_back(str);
        cout << str << endl;
    }
    
}

void recipient::Displayrecipient(vector<recipient>& rec) {
    cout << "Blood Type\t Donation day\t Expiry date\n";
    for (int i = 0; i < rec.size(); i++) {
        cout << rec[i].id << "\t \t " << rec[i].name << "\t " << rec[i].blood_type << endl;
    }
}





void recipient::recipientRequest() {
    cout << "______________" << endl;
    int rreq;
    time_t now;
    struct tm  nowloc;
    now = time(NULL);
    nowloc = *localtime(&now);
    cout << "FOR REQUIEST CLICK 1";
    cin >> rreq;
    if (rreq == 1) {
        string blood_type;
        int quantity;
        cout << "ENTER THE BLOOD TYPE YOU NEED ";
        cin >> blood_type;
        cout << "ENTER THE quantity YOU NEED ";
        cin >> quantity;
        ofstream donoreq;
        donoreq.open("rereq.txt", ios::app);
        donoreq << name << "," << age
            << "," << blood_type << "," << quantity << "," << nowloc.tm_mday << "," << nowloc.tm_mon + 1 << '\n';
        cout << "Your Donoration Request done SUCSSEFULLY" << endl;
    }
    else {
        cout << "THANKS FOR YOUR REGESTRATION";
    }
}





//void recipient::DeleteAccount(string email)
//{
//    fstream file_1, file_2;
//    file_1.open("rinfoo.txt", ios::in | ios::app);
//    file_2.open("temp_file.csv", ios::out | ios::app);
//    while (file_1.good())
//    {
//        
//        getline(file_1, line);
//        stringstream s_line(line);
//        while (getline(s_line, unit, ','))
//        {
//            Recipient_Data.push_back(unit);
//        }
//        if (Recipient_Data.size() != 0)
//        {
//            if (Recipient_Data[5] != e_mail)
//            {
//                for (int i = 0; i < Recipient_Data.size(); i++)
//                {
//                    file_2 << Recipient_Data[i] << ",";
//                }
//                file_2 << endl;
//            }
//            else
//            {
//                continue;
//            }
//        }
//    }
//    file_1.close();
//    file_2.close();
//    remove("Recipient.csv");
//    rename("temp_file.csv", "Recipient.csv");
