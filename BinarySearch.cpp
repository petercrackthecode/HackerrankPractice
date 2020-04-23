int binarySearch(const std::vector<int> &arr, const int &searchedValue) {
	int start{0},
		end= static_cast<int>(arr.size() - 1),
		mid= (end - start) / 2 + start;

	while (start <= end) {
		if (arr[mid] == searchedValue) {
			return mid;
		}
		else if (arr[mid] > searchedvalue) {
			end= mid - 1;
			mid= (end - start) / 2 + start;
		}
		else {
			start= mid + 1;
			mid= (end - start) / 2 + start;
		}
	}

	return -1;
}