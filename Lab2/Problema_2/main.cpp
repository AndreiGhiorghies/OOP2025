#include "Student.h"
#include "Global.h"
#include <iostream>

using namespace std;

int main() {
	Student s1, s2, s3;
	s1.SetName((char*)"Andrei");
	s2.SetName((char*)"Ionut");
	s3.SetName((char*)"Razvan");

	s1.SetMathematicsGrade(5);
	s2.SetMathematicsGrade(5);
	s3.SetMathematicsGrade(10);

	s1.SetEnglishGrade(5);
	s2.SetEnglishGrade(8);
	s3.SetEnglishGrade(9);

	s1.SetHistoryGrade(8);
	s2.SetHistoryGrade(5);
	s3.SetHistoryGrade(7);

	printf("%s %f %f %f\n", s1.GetName(), s1.GetMathematicsGrade(), s1.GetEnglishGrade(), s1.GetHistoryGrade());
	printf("%s %f %f %f\n", s2.GetName(), s2.GetMathematicsGrade(), s2.GetEnglishGrade(), s2.GetHistoryGrade());
	printf("%s %f %f %f\n", s3.GetName(), s3.GetMathematicsGrade(), s3.GetEnglishGrade(), s3.GetHistoryGrade());

	printf("%f %f %f \n", s1.AverageGrade(), s2.AverageGrade(), s3.AverageGrade());

	printf("%d %d %d", CompareName(s3, s2), CompareMathematicsGrade(s2, s1), CompareAverage(s1, s3));

	
	return 0;
}