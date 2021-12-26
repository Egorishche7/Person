#pragma once

#include "Person.h"
#include <iostream>

using namespace std;

int Person::NextID = 0;

Person::Person() :
	ID(++NextID)
{
	Name = new char;
}

Person::Person(const char* name, Gender gen, Person* mother, Person* father) :
	ID(++NextID)
{
	Name = new char[strlen(name) + 1];
	strcpy(Name, name);
	if (name == NULL)
		throw  "\nPerson must have a name\n";
	gender = gen;
	if (father != NULL)
		Father = father;
	Mother = mother;
	Father = father;
	if (ID > 2 && mother == NULL)
		throw "\nYou can't create new person this way\n";
	if (mother != NULL && mother->gender == Gender::male)
		throw  "\nMother's gender must be female\n";
	if (father != NULL && father->gender == Gender::female)
		throw  "\nFather's gender must be male\n";
}

Person* Person::giveBirth(const char* name, Gender gen, Person* father)
{
	if (gender == Gender::male)
		throw  "\nGiveBirth: gender error\n";
	const char* NewName = " ";
	if (name != NULL)
		NewName = name;
	else
		throw  "\nBaby must have a name\n";
	auto child = new Person(NewName, gen, this, father);
	return child;
}

Person Person::operator = (const Person person)
{
	return Person(Name, gender, Mother, Father);
}

void Person::Print() const
{
	cout << "Name: " << getName() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Gender: " << getGender() << endl;
	if (Mother != NULL)
		cout << "Mother Name: " << getMother() << endl;
	else
		cout << "This Person has no mother" << endl;
	if (Father != NULL)
		cout << "Father Name: " << getFather() << endl;
	else
		cout << "This Person has no father" << endl;
}

char* Person::getName() const
{
	return Name;
}

const char* Person::getGender() const
{
	return this->gender == Gender::male ? "Male" : "Female";
}

char* Person::getMother() const
{
	return Mother->getName();
}

char* Person::getFather() const
{
	return Father->getName();
}

int Person::getID() const
{
	return ID;
}

void Person::Delete()
{
	delete[] Name;
}