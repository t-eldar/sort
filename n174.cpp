#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	vector<unsigned long> man_capital(n);
	for (int i = 0; i < n; i++)
		fin >> man_capital[i];

	double current_capital;
	fin >> current_capital;

	sort(man_capital.begin(), man_capital.end());

	for (int i = 0; i < n; i++)
		if (man_capital[i] >= current_capital)
			current_capital = (double)(current_capital + man_capital[i]) / 2;

	fout << fixed << setprecision(6) << current_capital;
}