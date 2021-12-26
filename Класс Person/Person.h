#pragma warning (disable:4996)
#include <iostream>

using namespace std;

enum class Gender
{
	male = 1,
	female
};

class Person
{
private:
	const int ID;
	char* Name;
	Gender gender;
	static int NextID;
	Person* Mother;
	Person* Father;
	void Delete();
public:
	Person();
	Person(const char*, Gender, Person* = NULL, Person* = NULL);
	Person* giveBirth(const char*, Gender, Person* = NULL);
	Person operator = (const Person);
	void Print() const;
	char* getName() const;
	const char* getGender() const;
	char* getMother() const;
	char* getFather() const;
	int getID() const;
};