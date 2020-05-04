// link: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
int makeAnagram(string a, string b) {
    std::map<char, int> aCharactersMap;
    int anagramSize{0};

    for (auto ch : a) {
        ++aCharactersMap[ch];
    }

    for (auto ch : b) {
        if (aCharactersMap[ch] > 0) { 
            ++anagramSize;
            --aCharactersMap[ch];
        }
    }

    return (a.length() - anagramSize) + (b.length() - anagramSize);
}