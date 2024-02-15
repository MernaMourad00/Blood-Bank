#pragma once
#include<string> 
#include<iostream> 
#include<vector> 
#include<fstream> 
#include <map>
#include<sstream>

using namespace std;

class Blood
{
public:
	string bloodType, donation_day, expiry_date;

	Blood(string bloodType, string donation_day, string expiry_date) {

		this->bloodType = bloodType;
		this->donation_day = donation_day;
		this->expiry_date = expiry_date;

	}
	Blood() {
		bloodType = "AAA";
	}

	void insert_blood(vector<Blood>& Bloodd);
	void delete_blood(vector<Blood>& B_v,int quantity, string blood_type);
	void Blood_loadData(vector<Blood>& B_v);
	//void update_blood(vector<Blood>& rec);
	void blood_saveData(vector<Blood>& b_v);
	void displayBloodData(vector<Blood>& b_v);
	//void ADMIN_delete_blood(vector<Blood>& B_v);

};