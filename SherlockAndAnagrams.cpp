// Challenge link: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

int sherlockAndAnagrams(string s) {
    int start= 0;
    const int length= s.length();
    std::map<std::string, int> anagramsGroup;
    int pairs{0};
    
    while (start < length) {
        for (int substrLength= length - start; substrLength > 0; --substrLength) {
            std::string key= s.substr(start, substrLength);
            std::sort(key.begin(), key.end());
            if (anagramsGroup.count(key) == 0) {
                anagramsGroup.emplace(key, 1);
            }
            else ++anagramsGroup[key];
        }

        ++start;
    }

    for (auto temp : anagramsGroup) {
        int anagramsNum= temp.second;
        pairs+= (anagramsNum * (anagramsNum - 1) / 2);
    }

    return pairs;
}