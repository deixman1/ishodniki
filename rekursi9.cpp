#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const unsigned int DIM1 = 6;
const unsigned int DIM2 = 5;

int ary[DIM1][DIM2], j, i;
int b = 0, c = 0;


int main() {
	srand(time(NULL));

	for (i = 0; i < DIM1; i++) {
		for (j = 0; j < DIM2; j++) {
			ary[i][j] = (10 + rand() % (100 - 10));
			if (i == j)
				b += ary[i][j];
			if (j == i)
				c += ary[i][j];
			cout << setw(4) << ary[i][j];
		}
		if (b == c) cout << " " << b << endl;
		else cout << " " << c << endl;
	}
	return 0;
}