// link: https://www.hackerrank.com/challenges/special-palindrome-again/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
bool checkSubStr(const std::string &s, const int &startPos, const int &checkPos, const char &commonChar) {
    int endPos = checkPos * 2 - startPos;
    
    if (endPos > s.length() - 1) {
        return false;
    }
    
    for (int index= checkPos + 1; index <= checkPos * 2 - startPos; ++index) {
        if (s[index] != commonChar)
            return false; 
    }

    return true;
}

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long specialCount{n};
    int startPos{0};

    while (startPos <= n - 2) {
        int checkPos{startPos + 1};
        bool scanNext{true};
        char commonChar{s[startPos]};

        while (scanNext && checkPos < n) {
            if (commonChar == s[checkPos]) {
                ++specialCount;
            }
            else {
                if (checkSubStr(s, startPos, checkPos, commonChar)) {
                    ++specialCount;
                }

                scanNext= false;
            }

            ++checkPos;
        }

        ++startPos;
    }

    return specialCount;
}