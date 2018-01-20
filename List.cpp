/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Cannot have more than maximum elements stated in List.h
 *
 *
 *
 * Last modified on: May 30, 2017
 * Author: Dan Tang (301256468)
 */

#include <iostream>
#include <stdlib.h>
#include "Patient.h"
#include "List.h" // Header file

//Constructors
List::List(): elementCount(0), capacity(List::MAX_ELEMENTS) //set elementCount to 0 and capacity to MAX_ELEMENTS
{

}

// Description: Returns the current number of elements in the list
int List::getElementCount() const
{
	return elementCount;
}

// Description: Insert an element.
// Precondition: - newElement must not already be in data collection.
//				 - List cannot be full.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement)
{
	bool ableToInsert = (elementCount<(capacity));
	int pos = elementCount;
	bool inserted=false;
	
	//This if statement will always be true
	if(ableToInsert)
	{
		
		for (int index = elementCount; index<=pos;index++)
		{	
			for (int i=1; i<=pos; i++)
			{	
				// This if statement is to insert a modified patient
				// Searches for the patients careCard number then replaces that patient with the modified version
				if((elements[i].getCareCard()==newElement.getCareCard())&&(newElement.getName()!="To be entered")) 
				{	
					elements[i]=newElement;
					inserted = true;
					break; break; // to break out of the inner 'for' loop

				} 

				//to check if the new patient's careCard number is unique, if not unique then it is not added
				else if(elements[i].getCareCard()==newElement.getCareCard())
				{
					cout<<"ERROR: This careCard number already exist"<<endl
						<<"Unable to add "<< newElement.getCareCard() << " to the system" << endl;

					inserted = true;//stops the next if-else statement from running
					break; break; // to break out of the inner 'for' loop
				}

			} 

			//If list is at full capacity, then a new patient will not be added
			if((inserted==false)&&(elementCount>=capacity-1))
				{
					cout<< "Error: System is full."<<endl
					<<"Unable to add "<< newElement.getCareCard() << " to the system" << endl;
				} // end if 

			//Will only occur if no previous patients were modified, list is not at full capacity and careCard number is unique
			//Finds the location of last element, then adds newElement to the list
			//Increments elementCount to increase size of List
			else if((inserted==false)&&(elementCount<capacity-1)) 
			{
				cout<< "Patient# " << newElement.getCareCard() << " has successfully entered the system." << endl;
				elements[pos+1] = newElement;
				elementCount++; //increase count of elements
			} 

		} // end outer for

	}// end if

	return ableToInsert;
} // end insert


// Description: Remove an element. 
// Precondition: List cannot be empty.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove(const Patient& toBeRemoved)
{
	bool ableToRemove = ((elementCount+1)>0);

	int index = elementCount;

	//Nothing will be removed if list is empty
	if(ableToRemove)
	{
		for (int i=0; i<=index; i++)
		{
			//This statement searches for the patient with the same careCard number entered
			if(elements[i].getCareCard()==toBeRemoved.getCareCard())
			{	
				//The patient that is to be removed is pushed to the end of the list
				//elementCount is decremented in order to decrease size of the list which will then remove the patient
				// that is to be removed
				for (int fromIndex = i, toIndex = (fromIndex+1); fromIndex<elementCount; fromIndex++, toIndex++)
					elements[fromIndex] = elements[toIndex];
				

				elementCount--; // decrease count of elements
			} 

		}

	}// end if
	return ableToRemove;

}// end remove

// Description: Remove all elements.
void List::removeAll()
{
	elementCount = 0;
} //end removeAll

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
//Precondition: List cannot be full or empty
Patient* List::search(const Patient& target)
{

	//Enforce precondition
	bool ableToGet = ((elementCount>=1)&&(elementCount<capacity));

	if(ableToGet)
	{
		bool found=false;
		
			for(int index=1;index<=elementCount;index++)
			{
				if(elements[index].getCareCard()==target.getCareCard())
				{
					cout<<"Patient Found!"<<endl;
					
					elements[index].printPatient();

					found=true;//stops the next if statement from running if patient found
					break; break; //breaks out of for loop


				}
	
			}


			if(found==false)
			{
				cout<<"Patient not found!"
					<<endl<<"-----------------------------------"<<endl;
				return NULL;
			}


	}

	
} // end of search

// Description: Prints all elements stored in List.
// Postcondition: Patients must be printed in ascending 
//				  order of careCard numbers.
void List::printList()
{
	
	//
	for(int counter=1;counter<=elementCount-1;counter++)
	{
		Patient temp = Patient(); // creates a temporary individual patient

		for(int index=1;index<=elementCount-1;index++)
		{
			//Sorts patients into ascending order of care card numbers
			if(elements[index].getCareCard()>elements[index+1].getCareCard())
			{
				temp=elements[index];
				elements[index]=elements[index+1];
				elements[index+1]=temp;
			}
		}

	}


	cout<<"---Patient List---"<<endl;

	// Prints information about each patient in the list
	for(int index=1; index<=elementCount; index++)
	{
		cout<<elements[index].getCareCard()<<", Patient: "
			<<elements[index].getName()<<", "
			<<elements[index].getAddress()<<", "
			<<elements[index].getPhone()<<", "
			<<elements[index].getEmail()<<endl;
	}

	cout<<"---End of Patient List---"<<endl;

} // end of printList

// end of List.cpp




