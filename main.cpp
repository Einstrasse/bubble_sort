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
	FILE* fp;
	int num_elem;
	int seed;
	double normal_time, opt_time;
	vector<int> unsort1, unsort2, sorted;
	if (argc < 3) {
		fprintf(stderr, "usage: %s [NUM OF SORT ELEM] [RANDOM SEED]\n", argv[0]);
		return 0;
	}
	fp = fopen("time_log.csv", "a+");
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
	normal_time = bubble_sort(unsort1.begin(), num_elem);
	opt_time = opt_bubble_sort(unsort2.begin(), num_elem);
	
	cout << "< Correctness Check >" << endl;
	bool is_norm_success = is_equal(sorted.begin(), unsort1.begin(), num_elem);
	bool is_opt_success = is_equal(sorted.begin(), unsort2.begin(), num_elem);
	cout << "Bubble Sort - " << (is_norm_success ? "Success" : "Failed") << endl;
	cout << "Optimized Bubble Sort - " << (is_opt_success ? "Success" : "Failed") << endl;
	if (is_norm_success && is_opt_success) {
		fprintf(fp, "%lf, %lf\n", normal_time, opt_time);
	}
	fclose(fp);
}