#define MAX_N (10000)
#define MAX_M (10)

#include <string>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int myN, myM;
bitset<100> images[10000];

#include <iostream>

void init(int N, int M, char mImageList[MAX_N][MAX_M][MAX_M]) {
	// N : 이미지의 갯수, M : 이미지의 크기
	// mImageList : N개의 이미지 정보, ID는 1부터 시작, index값이 작은 순으로 id부여
	// e.g : mImageList[0]에는 id가 1인 이미지가 저장됨
	myN = N;
	myM = M;

	for (int i = 0; i < myN; i++) {
		images[i].reset();
		for (int j = 0; j < myM; j++) {
			for (int k = 0; k < myM; k++) {
				images[i][j * myM + k] = mImageList[i][j][k];
			}
		}
	}
}


int findImage(char mImage[MAX_M][MAX_M]) {
	// mImage : 검색할 이미지 정보, 가장 유사한 이미지의 ID값을 반환
	bitset<100> compareImage;
	for (int i = 0; i < myM; i++) {
		for (int j = 0; j < myM; j++) {
			compareImage[i * myM + j] = mImage[i][j];
		}
	}

	int ansId = 0;
	int minCnt = 100;
	int cnt;
	bitset<100> temp;
	for (int i = 0; i < myN; i++) {
		temp = compareImage ^ images[i];
		cnt = temp.count();
		if (minCnt > cnt) {
			minCnt = cnt;
			ansId = i + 1;
		}
	}

	//cout << ansId << endl;
	return ansId;
}