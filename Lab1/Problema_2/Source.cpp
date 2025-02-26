#include <iostram>

using namespace std;

bool ComparaAlfabetic(const char* s1, const char* s2) {
	// true daca s1 < s2
	for (int i = 0; s1[i]; i++)
		if (s1[i] < s2[i])
			return true;
		else if (s1[i] > s2[i])
			return false;

	return true;
}

void Copie(char* destinatie, const char* sursa) {
	int i = 0;
	for (; sursa[i]; i++)
		destinatie[i] = sursa[i];
	destinatie[i] = '\0';
}

int Lungime(const char* s) {
	int i = 0;

	while (s[i])
		i++;

	return i;
}

int main() {
	char s[100] = "";

	scanf_s("%[^\n]", s, 100);

	char sortat[100][20], sir[100];
	int n = 0, j = 0;

	for (int i = 0; s[i]; i++) {
		if (s[i] != ' ')
			sir[j++] = s[i];
		else {
			sir[j] = '\0';
			int k = n - 1;
			while (k >= 0 && (Lungime(sir) > Lungime(sortat[k]) || (Lungime(sir) == Lungime(sortat[k]) && ComparaAlfabetic(sir, sortat[k])))) {
				Copie(sortat[k + 1], sortat[k]);
				k--;
			}
			Copie(sortat[k + 1], sir);
			n++;
			j = 0;
		}
	}

	if (j > 0) {
		sir[j] = '\0';
		int k = n - 1;
		while (k >= 0 && (Lungime(sir) > Lungime(sortat[k]) || (Lungime(sir) == Lungime(sortat[k]) && ComparaAlfabetic(sir, sortat[k])))) {
			Copie(sortat[k + 1], sortat[k]);
			k--;
		}
		Copie(sortat[k + 1], sir);
		n++;
	}

	printf("\n");


	for (int i = 0; i < n; i++)
		printf("%s\n", sortat[i]);

	return 0;
}