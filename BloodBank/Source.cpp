#pragma warning(disable : 4996)
#include <iostream> 
#include "Blood.h"
#include"donor.h"  
#include<vector>
#include<sstream>
#include "p_user.h"
#include<fstream>
#include<string> 
#include <map>
#include "recipient1.h"
using namespace std;

bool confirmation_msg() {
    //system("cls");
    cout << "ARE YOU SURE?\n1.YES       2.NO\n";
    int j;
    cin >> j;
    if (j == 1)
        return true;
    else
        return false;
}

void donor_func(vector<Donor> don) {

    Donor d;
    d.load_data(don);
    bool  flag = false;
    while (true)
    {
     
        if (flag == true)
            break;
        //system("cls");
        int index = -1;
      
        cout << "\n1.Register\n2.Log in\nEnter your choice\n";
       
        int i;
        cin >> i;
        cin.ignore();
        if (i == 1)
        {
            d.donorRegister(don);
            
            system("pause");
            //break;
        }
        else if (i == 2)
        {
            d.login2(index, don);
            //break;
        }
        if (index == -1)
            continue;

        while (true)
        {
            //system("cls");

            cout << "\n1.Donate\n2.Update my data\n3.Delete this account\n4.Exit\nEnter your choice\n";
            int i;
            cin >> i;
            cin.ignore();
            if (i == 1)
            {
                //system("cls");
                d.DonationRequest(don[index]);
                flag == true;
                break;
            }
               
            else if (i == 2)
            {
                //system("cls");
                d.update(don, don[index].id);
                break;
            }
            else if (i == 3)
            {
                //system("cls");
                bool q = confirmation_msg();
                if (q)
                {
                    d.delete2(don, don[index].id);
                }
                break;
            }
            else if (i == 4)
            {
                cout << "##########################" << endl;
                flag = true;
                break;
            }
            if (flag == true)
                break;
        }
        if (flag == true)
            break;
    }


}

void rec_func(map<string, int>& mp, vector<recipient> rec)
{

    recipient r;
    r.Recipient_load_data(rec);
    bool  flag2 = false;
    while (true)
    {
        if (flag2 == true)
        {
            break;
        }
        //system("cls");
        int index = -1;
        //recipient r;

        cout << "\n1.Register\n2.Log in\nEnter your choice\n";
     //  r.Recipient_load_data(rec);
        int i;
        cin >> i;
        cin.ignore();
        if (i == 1)
        {
            r.recipientRegister(rec);
           
        }
        else if (i == 2)
        {
            r.login(index, rec);
            //break;
        }
        //system("cls");
        if (index == -1)
            continue;
        while (true)
        {
            //system("cls");
            cout << "1.Search for availability\n2.Update my data\n3.Delete this account\n4.Display all blood data\n5.Exit\nEnter your choice\n";
            int i;
            cin >> i;
            cin.ignore();
            if (i == 1)
            {
                // system("cls");
                if (r.search(mp))
                {
                    cout << "yes found" << endl;
                }
                else
                    cout << "not found" << endl;

            }
            else if (i == 2)
            {
                //system("cls");
                cout << rec[index].id;
                r.updateRecipient(rec, rec[index].id);
            }
            else if (i == 3)
            {
                //system("cls");
                bool f = confirmation_msg();
                if (f)
                {
                    r.deleteRecipient(rec, rec[index].id);
                   
                }

            }
            else if (i == 4)
            {
                // system("cls");
                r.displayBloodData();

                system("pause");
            }
            else if (i == 5)
            {
                cout << "##########################" << endl;
                flag2 = true;
                break;
            }
            if (flag2 == true)
                break;

            
        }
    }

}
               /*system("pause");
               flag2 *//*== true;*/
               //break;
            


int main() {
    map<string, int> map;
    recipient r;
    Blood b;
    vector<Donor> don;
    vector<recipient> rec;
    vector<Blood> bld;
    Donor q;

    //r.Recipient_load_data(rec);
    r.all_valid_blood(map);
    b.Blood_loadData(bld);
   // q.load_data(don);


    int c;
    while (true) {
        //system("cls");
        cout << "1.donor\n2.recpient\n3.logout\nplease enter your choice: ";
        cin >> c;
        if (c == 1)
        {
            donor_func(don);
        }
        else if (c == 2)
        {
            rec_func(map, rec);
        }
        else if (c == 3)
        {
            
            break;
        }
    }
}





