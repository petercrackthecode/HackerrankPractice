void quickSort(std::vector<int> &arr, const int &low, const int &high);
void quickSort(std::vector<int> &arr);
void swap(int &a, int &b);
int partition(std::vector<int> &arr, const int &low, const int &high);

void quickSort(std::vector<int> &arr, const int &low, const int &high) {
	if (low < high) {
		int pivotPosition= partition(arr, low, high);
		quickSort(arr, low, pivotPosition - 1);
		quickSort(arr, pivotPosition + 1, high);
	}
}

void quickSort(std::vector<int> &arr) {
	quickSort(arr, 0, arr.size() - 1);
}

int partition(std::vector<int> &arr, const int &low, const int &high) {
	int pivot= arr[high];
	int i{ low - 1};

	for (int j= low; j < high; ++j) {
		if (arr[j] < pivot) {
			++i;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);

	return i + 1;
}

void swap(int &a, int &b) {
	int temp= a;
	a= b;
	b= temp;
}