// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
bool checkIsValid(int currentFreq, const int &highFreq, const int &lowFreq, int &charactersWithLowFreq, int &charactersWithHighFreq) {
    if (currentFreq != highFreq && currentFreq != lowFreq) {
        return false;
    }
    else if (lowFreq == currentFreq) {
        ++charactersWithLowFreq;
    }
    else {
        ++charactersWithHighFreq;
    }

    if (charactersWithLowFreq >= charactersWithHighFreq) { // second case
        if (highFreq - lowFreq > 1 || charactersWithHighFreq > 1) {
            return false;
        }
    }
    else if (!(lowFreq == 1 && charactersWithLowFreq == 1)) { // charactersWithLowFreq < charactersWithHighFreq // third case
        return false;
    }

    return true;
}

// Complete the isValid function below.
string isValid(string s) {
    int highFreq{0},
        lowFreq{0},
        charactersWithLowFreq{0},
        charactersWithHighFreq{0};

    std::vector<int> allFrequencies(26, 0);

    for (char ch : s) {
        ++allFrequencies[ch - 'a'];
    }

    for (int index= 0; index < allFrequencies.size(); ++index) {
        if (allFrequencies[index] != 0) {
            int currentFreq= allFrequencies[index];
            if (!lowFreq) { // initialize the lowFreq
                lowFreq= currentFreq;
                ++charactersWithLowFreq;
            }
            else if (!highFreq) {
                if (lowFreq < currentFreq) {
                    highFreq= currentFreq;
                }
                else if (lowFreq == currentFreq) {
                    ++charactersWithLowFreq;
                }
                else { // lowFreq > currentFreq
                    highFreq= lowFreq;
                    charactersWithHighFreq= charactersWithLowFreq;
                    lowFreq= currentFreq;
                    charactersWithLowFreq= 1;
                }
            }
            else { // both low and high Freq are initialized
                if (!checkIsValid(currentFreq, highFreq, lowFreq, charactersWithLowFreq, charactersWithHighFreq)) {
                    return "NO";
                }
            }
        }
    }

    return "YES";
}
