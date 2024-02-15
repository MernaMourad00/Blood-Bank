#include "p_user.h"
#include <iostream>
#include <string>
using namespace std;
p_user::p_user(int id, int age, string name, string Email, string password, string gender, string blood_type)
{
	this->id = id;
	this->age = age;
	this->name = name;
	this->Email = Email;
	this->gender = gender;
	this->password = password;
	this->blood_type = blood_type;
}
p_user::p_user()
{
	this->age = 0;
	this->id = 0;

}