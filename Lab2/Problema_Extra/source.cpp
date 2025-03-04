#include "Header.h"
#include <stdio.h>

void Movie::set_name(const char* new_name)
{
	int i = 0;
	while (new_name[i])
		name[i] = new_name[i++];
	name[i] = '\0';
}

void Movie::set_year(int new_year)
{
	release_year = new_year;
}

void Movie::set_score(double new_score)
{
	IMDB_score = new_score;
}

void Movie::set_length(int new_length)
{
	movie_length = new_length;
}

const char* Movie::get_name()
{
	return name;
}

const int& Movie::get_year()
{
	return release_year;
}

const double& Movie::get_score()
{
	return IMDB_score;
}

const int& Movie::get_length()
{
	return movie_length;
}

int Movie::passed_years()
{
	return 2025 - release_year;
}

void MovieSeries::init()
{
	count = 0;
}

void MovieSeries::add(Movie* movie_to_add)
{
	if (count < 16)
		movies[count++] = movie_to_add;
}

void MovieSeries::print()
{
	for (int i = 0; i < count; i++)
		printf("%s %f %d %d %d \n", movies[i]->get_name(), movies[i]->get_score(), movies[i]->get_year(), movies[i]->get_length(), movies[i] -> passed_years());
}

void MovieSeries::sort()
{
	for(int i = 0; i < count - 1; i++)
		for(int j = i + 1; j < count; j++)
			if (movies[i]->passed_years() < movies[j]->passed_years()) {
				Movie* temp = movies[i];
				movies[i] = movies[j];
				movies[j] = temp;
			}
}
