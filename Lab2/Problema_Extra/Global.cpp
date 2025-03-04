#include "Global.h"

int movie_compare_name(Movie& a, Movie& b)
{
	int i = 0;
	const char* name_a = a.get_name(), * name_b = b.get_name();
	for (; name_a[i] && name_b[i]; i++)
		if (name_a[i] > name_b[i])
			return 1;
		else if (name_a[i] < name_b[i])
			return -1;

	if (name_a[i] == name_b[i])
		return 0;
	if (name_a[i])
		return 1;
	return -1;
}

int movie_compare_year(Movie& a, Movie& b)
{
	int year_a = a.get_year(), year_b = b.get_year();

	if (year_a > year_b)
		return 1;
	else if (year_a < year_b)
		return -1;
	return 0;
}

int movie_compare_score(Movie& a, Movie& b)
{
	double score_a = a.get_score(), score_b = b.get_score();

	if (score_a > score_b)
		return 1;
	else if (score_a < score_b)
		return -1;
	return 0;
}

int movie_compare_length(Movie& a, Movie& b)
{
	int length_a = a.get_length(), length_b = b.get_length();

	if (length_a > length_b)
		return 1;
	else if (length_a < length_b)
		return -1;
	return 0;
}

int movie_compare_passed_years(Movie& a, Movie& b)
{
	int years_a = a.passed_years(), years_b = b.passed_years();

	if (years_a > years_b)
		return 1;
	else if (years_a < years_b)
		return -1;
	return 0;
}