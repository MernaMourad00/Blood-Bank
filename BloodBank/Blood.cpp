#include "Blood.h"
#include<string> 
#include<iostream> 
#include<vector> 
#include<fstream> 
#include <map>
#include<sstream>
#include<stdio.h>
#pragma warning(disable : 4996)

using namespace std;

void Blood::insert_blood(vector<Blood>& Bloodd) {


    ofstream blood_file;
    blood_file.open("BloodData.txt", ios::app);
    //cin.ignore();
    int donreq;
    time_t now;
    struct tm  nowloc;
    now = time(NULL);
    nowloc = *localtime(&now);

    cout << "Enter blood type :" << endl;
    getline(cin, bloodType);
    cout << "Enter blood quantity" << endl;
    int quantity;
    cin >> quantity;
    cin.ignore();


    for (int i = 0; i < quantity; i++) {
        blood_file << bloodType << ',' << nowloc.tm_mday << "/" << nowloc.tm_mon + 1 << "/ " << nowloc.tm_year + 1900 << ',' << (nowloc.tm_mday + 1) % 12 << '/' << (nowloc.tm_mon + 1 / 12) << '/' << nowloc.tm_year + 1900 << '\n';

    }

    Blood b;
    b.Blood_loadData(Bloodd);
    blood_file.close();

}

void  Blood::Blood_loadData(vector<Blood>& B_v)
{
    fstream bloodd_file;
    bloodd_file.open("blooddata.txt", fstream::in);

    string line;
    while (getline(bloodd_file, line))
    {
        stringstream inputString(line);

        string bloodT, BloodD, BloodE;

        getline(inputString, bloodT, ',');
        getline(inputString, BloodD, ',');
        getline(inputString, BloodE, ',');

        Blood b(bloodT, BloodD, BloodE);
        B_v.push_back(b);

    }
    bloodd_file.close();

}
void Blood::delete_blood(vector<Blood>& B_v, int quantity, string blood_type) {

    vector<Blood>::iterator it;
    int i = 0;
    for (it = B_v.begin(); it != B_v.end(); it++)
    {
        // cout << "loopp";
        if (it->bloodType == blood_type)
        {
            it = B_v.erase(it);
            i++;
            if (i == quantity)
                break;
        }
    }
    Blood b;
    b.blood_saveData(B_v);


}

void Blood::blood_saveData(vector<Blood>& b_v) {
    fstream Bloodd;
    fstream temp;
    Bloodd.open("blooddata.txt", fstream::in);//hnrg3lha
    temp.open("temp.txt", fstream::out);
    for (int i = 0; i < b_v.size(); i++) {

        temp << b_v[i].bloodType << "," << b_v[i].donation_day << ","
            << b_v[i].expiry_date << endl;

    }
    temp.close();
    Bloodd.close();
    remove("blooddata.txt");
    rename("temp.txt" , "blooddata.txt");

}

void Blood::displayBloodData(vector<Blood>& b_v) {
    cout << "Blood Type\t Donation day\t Expiry date\n";
    for (int i = 0; i < b_v.size(); i++) {
        cout << b_v[i].bloodType << "\t \t " << b_v[i].donation_day << "\t " << b_v[i].expiry_date << endl;
    }
}
