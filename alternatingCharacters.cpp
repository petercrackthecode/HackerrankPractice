// link: https://www.hackerrank.com/challenges/alternating-characters/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings&h_r=next-challenge&h_v=zen
int alternatingCharacters(string s) {
    int deletionCount{0};
    int index{0};

    while (index < s.length() - 1) {
        if (s[index] == s[index + 1]) {
            while (s[index] == s[index + 1])    {
                ++deletionCount;
                ++index;
            }
        }
        else ++index;
    }

    return deletionCount;
}