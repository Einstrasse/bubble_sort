#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "./lcgrand.h"
#include "./sorting.h"

using namespace std;

#define LOWER_BOUND 0
#define UPPER_BOUND 1000000
int main(int argc, char* argv[]) {
	int num_elem;
	int seed;
	vector<int> unsort1, unsort2, sorted;
	if (argc < 3) {
		fprintf(stderr, "usage: %s [NUM OF SORT ELEM] [RANDOM SEED]\n", argv[0]);
		return 0;
	}
	num_elem = atoi(argv[1]);
	unsort1.reserve(num_elem);
	unsort2.reserve(num_elem);
	sorted.reserve(num_elem);
	seed = atoi(argv[2]) % 100;
	fprintf(stderr, "%d %d\n", num_elem, seed);
	for (int i=0; i < num_elem; i++) {
		int val = uniform(LOWER_BOUND, UPPER_BOUND, seed);
		unsort1.push_back(val);
		unsort2.push_back(val);
		sorted.push_back(val);
	}
	sort(sorted.begin(), sorted.end());
	bubble_sort(unsort1.begin(), num_elem);
	opt_bubble_sort(unsort2.begin(), num_elem);
	// for (int i=0; i < num_elem; i++) {
	// 	cout << sorted[i] << ' ' << unsort1[i] << " " << unsort2[i] << endl;
	// }
	cout << "< Correctness Check >" << endl;
	cout << "Bubble Sort - " << (is_equal(sorted.begin(), unsort1.begin(), num_elem) ? "Success" : "Failed") << endl;
	cout << "Optimized Bubble Sort - " << (is_equal(sorted.begin(), unsort2.begin(), num_elem) ? "Success" : "Failed") << endl;
}