/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Last modified on: May 30, 2017
 * Author: Dan Tang (301256468)
 */

#include <stdlib.h> //included to be able to use system("") commands
#include "Patient.h"
#include <iostream>


// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".
Patient::Patient()
{
	careCard = "0000000000";
	name = "To be entered";
	address = "To be entered";
	email = "To be entered";
	phone = "To be entered";
}


// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard)
{

	if(aCareCard.size()!=10)
		{
			cout<<"ERROR: The care card number must contain 10 digits"<<endl;
				
			careCard = "0000000000";
		}
	else
		careCard=aCareCard;
	name = "To be entered";
	address = "To be entered";
	email = "To be entered";
	phone = "To be entered";

}

//Getters and Setters

// Description: Returns patient's name.
string Patient::getName() const
{
	return name;
}

// Description: Returns patient's address.
string Patient::getAddress() const
{
	return address;
}

// Description: Returns patient's phone number.
string Patient::getPhone() const
{
	return phone;
}

// Description: Returns patient's email.
string Patient::getEmail() const
{
	return email;
}

// Description: Returns patient's care card number.
string Patient::getCareCard() const
{
	return careCard;
}

// Description: Sets the patient's name.
void Patient::setName(const string aName)
{
	name = aName;
}

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress)
{
	address = anAddress;
}

// Description: Sets the patient's phone number.
void Patient::setPhone(const string aPhone)
{
	phone = aPhone;
}

// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail)
{
	email = anEmail;
}

// Overloaded Operators

// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator==(const Patient & rhs)
{
	if(careCard==rhs.getCareCard())
		return true;
	else
		return false;
}

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card number of "rhs" Patient object.
bool Patient::operator>(const Patient & rhs)
{
	if(careCard>rhs.getCareCard())
		return true;
	else
		return false;
}

// Description: Prints the content of "this" patient.
void Patient::printPatient()
{
	cout<<careCard<<", Patient: "
		<<name<<", "
		<<address<<", "
		<<phone<<", "
		<<email
		<<endl<<"-----------------------------------"<<endl;
}

//end of Patient.cpp






































































