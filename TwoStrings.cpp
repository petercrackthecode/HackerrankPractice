// link: https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps&h_r=next-challenge&h_v=zen

string twoStrings(string s1, string s2) {
    std::unordered_set<char> tableLookup;

    for (int index= 0; index < s1.length(); ++index) {
        tableLookup.insert(s1[index]);
    }

    for (int index= 0; index < s2.length(); ++ index) {
        if (tableLookup.find(s2[index]) != tableLookup.end()) {
            return "YES";
        }
    }

    return "NO";
}