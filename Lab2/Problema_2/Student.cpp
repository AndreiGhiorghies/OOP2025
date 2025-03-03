#include "Student.h"

void Student::SetName(char* newName) {
	int i = 0;
	for (; newName[i]; i++)
		name[i] = newName[i];
	name[i] = '\0';
}

char* Student::GetName() {
	return name;
}

float Student::GetMathematicsGrade()
{
	return mathematicsGrade;
}

void Student::SetMathematicsGrade(float newGrade)
{
	mathematicsGrade = newGrade;
}

float Student::GetEnglishGrade()
{
	return englishGrade;
}

void Student::SetEnglishGrade(float newGrade)
{
	englishGrade = newGrade;
}

float Student::GetHistoryGrade()
{
	return historyGrade;
}

void Student::SetHistoryGrade(float newGrade)
{
	historyGrade = newGrade;
}

float Student::AverageGrade()
{
	return (mathematicsGrade + englishGrade + historyGrade) / 3.0;
}

