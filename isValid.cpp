// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
string isValid(string s) {
    std::map<char, int> charactersCount;
    std::map<int, int> frequencies;
    
    for (auto ch : s) {
        ++charactersCount[ch];
    }

    for (auto elem : charactersCount) {
        if (elem.second != 0)
            ++frequencies[elem.second];
    }

    if (frequencies.size() > 2) {
        return "NO";
    }
    else if (frequencies.size() == 2) {
        int firstFrequency{0},
            firstFrequencyCount{0},
            thirdFrequency{0},
            secondFrequency{0},
            secondFrequencyCount{0};
        for (auto elem : frequencies) {
            if (firstFrequencyCount == 0) {
                firstFrequency= elem.first;
                firstFrequencyCount= elem.second;
            }
            else if (secondFrequencyCount == 0) {
                secondFrequency= elem.first;
                secondFrequencyCount= elem.second;
            }
        }

        if (std::abs(firstFrequency - secondFrequency) >= 2) {
            return "NO";
        }
        else if (firstFrequencyCount > 1 && secondFrequencyCount > 1) {
            if (std::abs(firstFrequencyCount - secondFrequencyCount) != 2)
                return "NO";
        }
    }
    
    return "YES";
}