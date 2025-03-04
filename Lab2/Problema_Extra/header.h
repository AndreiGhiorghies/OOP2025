#pragma once

class Movie
{
private:
	char name[256];
	int release_year;
	double IMDB_score;
	int movie_length;
	
public:
	void set_name(const char* new_name);
	void set_year(int new_year);
	void set_score(double new_score);
	void set_length(int new_length);

	const char* get_name();
	const int& get_year();
	const double& get_score();
	const int& get_length();

	int passed_years();
};

class MovieSeries {
private:
	Movie* movies[16];
	int count;

public:
	void init();
	void add(Movie* movie_to_add);
	void print();
	void sort();
};


