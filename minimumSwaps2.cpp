// link: https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays&h_r=next-challenge&h_v=zen

int swap(int &firstNum, int &secondNum) {
	int temp= firstNum;
	firstNum= secondNum;
	secondNum= temp;
}

int minimumSwaps(vector<int> arr) {
	int size{arr.size()};
	int minSwaps{0};

	for (int i= 0; i < size; ++i) {
		if (i + 1 != arr[i]) {
			int j{i + 1};
			while (arr[j] != i + 1)
				++j;

			swap(arr[i], arr[j]);
			++minSwaps;
		}
	}

	return minSwaps;
}