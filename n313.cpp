#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	vector<int> bus(n);
	for (int i = 0; i < n; i++)
		fin >> bus[i];

	int max = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (bus[i] == bus[j])
			{
				if (abs(i - j) > max)
					max = abs(i - j);
				break;
			}
	fout << max;
}