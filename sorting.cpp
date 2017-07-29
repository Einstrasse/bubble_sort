#ifndef __SORTING_H__
#define __SORTING_H__
#include "./sorting.h"
#include <vector>
#include <sys/time.h>
#include <cstdio>
using namespace std;

static double get_second (void) { //알고리즘 수행 시간 측정용
	struct timeval tp;
	struct timezone tzp;
	int i;

	i = gettimeofday(&tp, &tzp);
	(void) i;
	return ((double)tp.tv_sec + (double)tp.tv_usec * 1.e-6);
}

double bubble_sort(vector<int>::iterator arr, int len) {
	//일반 버블 정렬 구현
	double total_time = get_second();
	for (int i=0; i < len; i++) {
		for (int j=0; j < len - 1; j++) {
			if (arr[j] > arr[j+1]) {
				arr[j] ^= arr[j+1]; // arr[j]값과 arr[j+1]값을 swap
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
			}
		}
	}
	total_time = get_second() - total_time;

	fprintf(stderr, "Normal Bubble Sort - Elapsed Time: %lf\n", total_time);
	//알고리즘 수행시간 출력
	return total_time;
}

double opt_bubble_sort(vector<int>::iterator arr, int len) {
	double total_time = get_second();
	int sorted_num = 987654321; //+무한대 값
	int tmp = 987654321; //+무한대 값
	for (int i=0; i < len; i++) {
		for (int j=0; j < len - 1; j++) {
			if (j >= sorted_num) break; //이후 뒷부분이 이미 정렬된 경우 Skip
			if (arr[j] > arr[j+1]) {
				tmp = j+1;
				arr[j] ^= arr[j+1]; // arr[j]값과 arr[j+1]값을 swap
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
			}
		}
		sorted_num = tmp; //이미 정렬된 index값을 저장
	}
	total_time = get_second() - total_time;

	fprintf(stderr, "Optimized Bubble Sort - Elapsed Time: %lf\n", total_time);
	//알고리즘 수행시간 출력
	return total_time;
}

bool is_equal(vector<int>::iterator arr1, vector<int>::iterator arr2, int len) {
	//두 배열의 값이 같은지 확인
	for (int i=0; i < len; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

#endif