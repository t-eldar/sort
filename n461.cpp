#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int k;
	fin >> k;

	vector<int> groups(k);

	for (int i = 0; i < k; i++)
		fin >> groups[i];

	sort(groups.begin(), groups.end());

	int min_voices = 0;

	int temp;
	if (k % 2 != 0)
		temp = k - k / 2;
	else
		temp = k / 2 + 1;
	
	for (int i = 0; i < temp; i++)
	{
		if (groups[i] % 2 != 0)
			min_voices += groups[i] - groups[i] / 2;
		else
			min_voices += groups[i] / 2 + 1;
	}
	fout << min_voices;
}