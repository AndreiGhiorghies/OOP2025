#pragma once

class Student {
private:
	char name[50];
	float mathematicsGrade, englishGrade, historyGrade;

public:
	char* GetName();
	void SetName(char* newName);

	float GetMathematicsGrade();
	void SetMathematicsGrade(float newGrade);

	float GetEnglishGrade();
	void SetEnglishGrade(float newGrade);

	float GetHistoryGrade();
	void SetHistoryGrade(float newGrade);

	float AverageGrade();
};
