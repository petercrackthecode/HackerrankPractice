// Problem link: https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

void minimumBribes(vector<int> q) {
	int minBribes{0};
	const int MAX_BRIBES{2};

	for (int i= q.size() - 1; i >= 0; --i) {
		if (q[i] - (i + 1) > MAX_BRIBES)	{
			std::cout << "Too chaotic\n";
			return;
		}

		for (int j= std::max(0, q[i] - 2); j < i; ++j)
			if (q[j] > q[i]) ++minBribes;
	}

	std::cout << minBribes << "\n";
}