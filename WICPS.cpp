/*
 * WICPS.cpp - version 1
 * 
 * Class Description: Application that stores and displays patient data for Walk-in clinics
 *
 * In this version, we use a List ADT.
 *
 * Last modified on: May 30, 2017
 * Author: Dan Tang (301256468)
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include "List.h"
#include "Patient.h"

using namespace std;

//Function to print elementCount
void printElementCount(List * thePatients)
{
	int elementCount = thePatients->getElementCount();

		if(elementCount==1)
		{
			cout<<"There is "<<elementCount<<" patient in the system" << endl
			<< "-----------------------------------"<<endl;
		}
		else
		{
			cout<<"There are "<<elementCount << " patients in the system" << endl
			<< "-----------------------------------"<<endl;
		}
}

//Function to add a new patient
void addPatient(List * thePatients)
{
	//clears terminal screen
	system("clear screen");

	string theCareCard = "";

	
	cout<<"Enter patient's care card number: ";
	getline(cin>> ws, theCareCard);
	
	//Create new patient profile
	Patient thePatient = Patient(theCareCard);

	//Add new patient to the end of list
	thePatients->insert(thePatient);

	//Prints elementCount after adding new patient
	printElementCount(thePatients);


	
	return;

} // end of addPatient

//Function to search for a unique patient
void searchPatient(List * thePatients)
{
	system("clear screen");

	string theCareCard= "";

	cout<<"Enter the care card number of the patient you wish to find: ";
	getline(cin>> ws, theCareCard);

	Patient thePatient = Patient(theCareCard);

	//Searches for patient 
	cout<<endl<<thePatients->search(thePatient);

} // end of searchPatient

//Function to remove one unique patient
void removePatient(List * thePatients)
{
	system("clear screen");
	
	string theCareCard="";

	//This if statement does not run if list is empty
	if(thePatients->getElementCount()>0)
	{
		//Prints patients to choose from
		thePatients->printList();

		cout<< "Please enter the care card number of the patient you wish to remove :";
		getline(cin>> ws, theCareCard);
	

		Patient thePatient = Patient(theCareCard);

		//Removes patient if found
		if(thePatients->remove(thePatient))
			cout<<"The patient has been removed."<<endl;
		else
			cout<<"Unable to remove patient."<<endl;
	}
	else
		cout<<"There are no patients in the system!"<<endl;

	//Prints count of elements after patient is removed or not removed
	printElementCount(thePatients);
	return;

}// end of removePatient

//Modifies the information of a patient
void modifyPatient(List * thePatients)
{
	system("clear screen");

	string theCareCard="";
	string theName="";
	string theAddress="";
	string thePhone="";
	string theEmail="";

	//This if statement does not run if list is empty
	if(thePatients->getElementCount()!=0)
	{
		//Prints patients to choose from
		thePatients->printList();

		cout<<endl<<"Please enter the care card number of the patient you wish to modify :";
		getline(cin>> ws, theCareCard);
		cout<<" Enter new name: ";
		getline(cin>> ws, theName);
		cout<<" Enter new address: ";
		getline(cin>> ws, theAddress);
		cout<<" Enter new phone number: ";
		getline(cin>> ws, thePhone);
		cout<<" Enter new email: ";
		getline(cin>> ws, theEmail);
		

		Patient thePatient = Patient(theCareCard);

		//Sets new information to chosen patient
		thePatient.setName(theName);
		thePatient.setAddress(theAddress);
		thePatient.setPhone(thePhone);
		thePatient.setEmail(theEmail);

		//Inserts modified patient into list
		thePatients->insert(thePatient);

		cout<<"Patient # "<<thePatient.getCareCard()<<" was modified"
			<<endl<<"-----------------------------------"<<endl;


	}

}// end of modifyPatient



// This function used to pause the program to give the user more time to read outputs
void pause()
{

	cout<<endl<<"Press enter to continue...";
	cin.get();
}



int main()
{
	//Variable declarations
	List* patients = new List();
	bool done = false;
	char input = 0;

	//Keep doing what the user selects until the user quits
	while(not done)
	{
		system("clear screen");

		cout<<endl<<"---Welcome to the Patient System--- "<<endl
			<<"To <A>dd a patient enter: a"<< endl
			<<"To <S>earch for a patient enter: s"<<endl
			<<"To <R>emove a patient enter: r"<< endl
			<<"To <M>odify a patient's information enter: m"<<endl
			<<"To <P>rint the list of patients enter: p"<<endl
			<<"To <C>lear all patients enter: c"<<endl
			<<"To <Q>uit enter: q"<<endl;

		cout<<"You entered: ";
		cin>>input;

		switch(input)
		{
			case 'a': addPatient(patients); break;
			case 's': searchPatient(patients); break;
			case 'r': removePatient(patients); break;
			case 'm': modifyPatient(patients); break;
			case 'p': system("clear screen"); patients->printList(); cin.ignore(); break;
			case 'c': patients->removeAll(); cout<<"All patients have been removed from the system!"<<endl; cin.ignore(); break;
			case 'q': cout<<"Closing program..."; done =true; break; 
			default: cout<<"ERROR: Invalid entry! Please, try again!" << endl; pause();
		}

		pause();
		

	}

	cin.ignore(); //ignore extra space after inputs
	system("clear screen");


	

	return 0;

} //end of main()
