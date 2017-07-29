#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "./lcgrand.h" //랜덤넘버 제너레이터
#include "./sorting.h" //버블정렬, 개선된 버블정렬

using namespace std;

#define LOWER_BOUND 0
#define UPPER_BOUND 1000000
int main(int argc, char* argv[]) {
	FILE* fp;
	int num_elem; //정렬할 숫자 개수
	int seed; //랜덤넘버 생성 시드
	double normal_time, opt_time; //일반 버블정렬렬 실행시간, 개선된 버블정렬 실행시간
	vector<int> unsort1, unsort2, sorted; // 버블정렬 배열, 개선된 버블정렬 배열, C++ STL 라이브러리 활용한 정렬 배열
	if (argc < 3) {
		fprintf(stderr, "usage: %s [NUM OF SORT ELEM] [RANDOM SEED]\n", argv[0]);
		return 0;
	}
	fp = fopen("time_log.csv", "a+");
	num_elem = atoi(argv[1]);
	unsort1.reserve(num_elem);
	unsort2.reserve(num_elem);
	sorted.reserve(num_elem); // 벡터 메모리 할당
	seed = atoi(argv[2]) % 100;
	fprintf(stderr, "%d %d\n", num_elem, seed);
	for (int i=0; i < num_elem; i++) { //숫자 개수 만큼 랜덤 넘버 생성
		int val = uniform(LOWER_BOUND, UPPER_BOUND, seed); //LowerBound ~ UpperBound 내의 값을 SEED 기반으로 랜덤생성
		unsort1.push_back(val);
		unsort2.push_back(val);
		sorted.push_back(val);
	}
	sort(sorted.begin(), sorted.end()); //C++ STL 라이브러리 활용한 정렬
	normal_time = bubble_sort(unsort1.begin(), num_elem); //일반 버블정렬
	opt_time = opt_bubble_sort(unsort2.begin(), num_elem);//개선된 버블정렬
	
	cout << "< Correctness Check >" << endl;
	bool is_norm_success = is_equal(sorted.begin(), unsort1.begin(), num_elem); //버블정렬 구현 정확성 확인
	bool is_opt_success = is_equal(sorted.begin(), unsort2.begin(), num_elem); //개선된 버블정렬 구현 정확성 확인
	cout << "Bubble Sort - " << (is_norm_success ? "Success" : "Failed") << endl; //결과 출력
	cout << "Optimized Bubble Sort - " << (is_opt_success ? "Success" : "Failed") << endl;
	if (is_norm_success && is_opt_success) {
		fprintf(fp, "%lf, %lf\n", normal_time, opt_time); //csv파일에 실행시간 출력
	}
	fclose(fp);
}