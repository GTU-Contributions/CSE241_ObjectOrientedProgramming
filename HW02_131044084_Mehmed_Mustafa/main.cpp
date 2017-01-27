// HW02_131044084_Mehmed_Mustafa
// main.cpp
// Function pointer in use
//
// Created on 16/10/2015 by Mehmed Mustafa
// Last Edited on 23/10/2015 by Mehmed Mustafa

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class DayOfYear{
public:
	DayOfYear(int monthValue = 1, int dayValue = 1);
	
	void setDate(int newMonth, int newDay);
	void output() const;
	int getMonth() const { return month; }
	int getDay() const { return day; }

private:
	void testDate() const;
	int month;
	int day;
};
class Person{
public:
	Person(string name = "noName", int age = 0);

	void setPerson(string nameValue, int ageValue);
	void output() const;
	string getName() const { return name; }
	int getAge() const { return age; }

private:
	void testAge() const;
	string name;
	int age;
};
//Function to compare two integers
bool compI(const void* ele1, const void* ele2){
	int* p1 = (int*) ele1;
	int* p2 = (int*) ele2;

	if(*p1 == *p2)
		return true;
	else
		return false;
}
//Function to compare two chars
bool compC(const void* ele1, const void* ele2){
	char* p1 = (char*) ele1;
	char* p2 = (char*) ele2;

	if(*p1 == *p2)
		return true;
	else
		return false;
}
//Function to compare two doubles
bool compD(const void* ele1, const void* ele2){
	double* p1 = (double*) ele1;
	double* p2 = (double*) ele2;

	if(*p1 == *p2)
		return true;
	else
		return false;
}
//Function to compare two strings
bool compS(const void* ele1, const void* ele2){
	string* p1 = (string*) ele1;
	string* p2 = (string*) ele2;

	if(*p1 == *p2)
		return true;
	else
		return false;
}
//Function to compare two Person class objects
bool compP(const void* ele1, const void* ele2){
	Person* p1 = (Person*) ele1;
	Person* p2 = (Person*) ele2;

	if((p1->getAge() == p2->getAge()) && (p1->getName() == p2->getName()))
		return true;
	else
		return false;
}
//Function to compare two DayOfYear class objects
bool compDoY(const void* ele1, const void* ele2){
	DayOfYear* p1 = (DayOfYear*) ele1;
	DayOfYear* p2 = (DayOfYear*) ele2;

	if((p1->getDay() == p2->getDay()) && (p1->getMonth() == p2->getMonth()))
		return true;
	else
		return false;
}
//Function that returns the array index of the mode element
//If there are two or more mode elements, 
//the function returns the first mod's index
//For example in array = {1, 3, 3, 1, 1, 5, 3, 1, 7, 3}
//The number 1 and number 3 both occurs 4 times in the array
//The function will return the 1's first element index
//The returned value will be 0 in our example
int return_mode(const void* base, size_t num, size_t size, 
    bool(*equals)(const void*, const void*)){
	int index = 0; //Index of the mod element
	int counter, maxCount = 0; //Counters
    //Get's the array's starting pointer
    unsigned char *firstEl = (unsigned char*) base;
    //Get's the array's ending pointer
    unsigned char *lastEl = (unsigned char*) base + (size * num);
    //ce - currentElement, ce2 - CurrentElement2, ceM - CurrentElementMod
	unsigned char *ce, *ce2, *ceM;

    //Counts how many time each element occurs
	for(ce = firstEl; ce < lastEl; ce += size)
	{
		counter = 0;
		for(ce2 = firstEl; ce2 < lastEl; ce2 += size)
		{
            
			if(equals(ce, ce2)) //If the ce equals to the ce2
				counter++; // Increase the counter
		}
		if(counter > maxCount) //If another element occurs more times
		{
			maxCount = counter; //Save how many times new mod element occurs
			ceM = ce; //Change the pointer of the mod element
		}
	}

    //Compare all array's elements with the mod element
	for(ce = firstEl; ce < lastEl; ce += size)
	{
		if(!equals(ce, ceM)) //If the current element isn't equal to mod element
			index++; //Increase the index
		else //If the current element is equal to the mod element
			break; //Break loop
	}
    //And return the index
	return index;
}

int main(int argc, char** argv){
	int I[] = {1, 3, 3, 1, 4, 5, 3, 1, 7, 3};
	char C[] = {'p', 'a', 'b', 'b', 'c', 'h', 'g', 'c', 'i', 'c'};
	double D[] = {0.8, 0.9, 1.4, 1.4, 1.8, 1.8, 1.2, 1.0, 1.8, 1.6};
	string S[] = {"za", "oo", "qq", "zz", "yt", "ty", "aa", "tt", "tt", "pp"};
	Person P[] = { Person("ali", 17), Person("mehmed", 21), Person("ali", 5),
					Person("ali", 5), Person("mehmed", 21), Person("ali", 8)};
	DayOfYear DoY[] = { DayOfYear(7, 25), DayOfYear(5, 12), DayOfYear(8, 19),
						DayOfYear(7, 27), DayOfYear(5, 25), DayOfYear(7, 27)};

	int sizeOfArray = 10;
	int index;

	index = return_mode(I, sizeOfArray, sizeof(int), compI);
	cout << "The mode's first index is: " << index <<endl;

    return 0;
}

DayOfYear::DayOfYear(int mValue, int dValue):month(mValue), day(dValue){
	testDate();
}
void DayOfYear::testDate() const{
	if((month < 1) || (month > 12))
	{
		cout << "illegal month value!" << endl;
		exit(1);
	}
	if((day < 1) || (day > 31))
	{
		cout << "illegal day value!" << endl;
		exit(1);
	}
}
void DayOfYear::setDate(int newMonth, int newDay){
	month = newMonth;
	day = newDay;
	testDate();
}
void DayOfYear::output() const{
	cout << "The day is " << day << " and the month is " << month << endl;
}

Person::Person(string nameValue, int ageValue):name(nameValue), age(ageValue){
	testAge();
}
void Person::testAge() const{
	if((age < 0) || (age > 130))
	{
		cout << "illegal age value!" << endl;
		exit(1);
	}
}
void Person::setPerson(string nameValue, int ageValue){
	testAge();
	age = ageValue;
	name = nameValue;
}
void Person::output() const{
	cout << "My name is " << name; 
    cout << " and I am " << age << " years old!" << endl;
}