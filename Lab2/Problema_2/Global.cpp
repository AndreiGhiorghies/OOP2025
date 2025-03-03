#include "Global.h"

int CompareName(Student a, Student b) {
	int i = 0;
	char* numeStudent1 = a.GetName(), * numeStudent2 = b.GetName();

	for (; numeStudent1[i] && numeStudent2[i]; i++)
		if (numeStudent1[i] > numeStudent2[i])
			return 1;
		else if (numeStudent1[i] < numeStudent2[i])
			return -1;

	if (numeStudent1[i] == numeStudent2[i])
		return 0;
	if (numeStudent1[i])
		return 1;
	return -1;
}

int CompareMathematicsGrade(Student a, Student b)
{
	int gradeA = a.GetMathematicsGrade(), gradeB = b.GetMathematicsGrade();
	if (gradeA > gradeA)
		return 1;
	else if (gradeA < gradeB)
		return -1;
	return 0;
}

int CompareEnglishGrade(Student a, Student b)
{
	int gradeA = a.GetEnglishGrade(), gradeB = b.GetEnglishGrade();
	if (gradeA > gradeA)
		return 1;
	else if (gradeA < gradeB)
		return -1;
	return 0;
}

int CompareHistoryGrade(Student a, Student b)
{
	int gradeA = a.GetHistoryGrade(), gradeB = b.GetHistoryGrade();
	if (gradeA > gradeA)
		return 1;
	else if (gradeA < gradeB)
		return -1;
	return 0;
}

int CompareAverage(Student a, Student b)
{
	float averageA = a.AverageGrade(), averageB = b.AverageGrade();
	if (averageA > averageB)
		return 1;
	else if (averageA < averageB)
		return -1;
	return 0;
	
}

