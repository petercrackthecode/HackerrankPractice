int findNextMiddle(const std::vector<int> &count, const int &first, int &currentMedianLevel) {
    if (count[first] > currentMedianLevel) {
        ++currentMedianLevel;
        return first;
    }
    else {
        int index= first + 1;
        while (count[index] != 0) {
            ++index;
        }
        currentMedianLevel= 1;
        return count[index];
    }
}

int getTwiceMedian(const std::vector<int> &count, const int &days, int &currentMid, int &currentMedianLevel) {
    int first{0},
        second{0},
        twiceMedian{0};

    if (currentMid < 0 || currentMedianLevel <= 0) { // the median has never been initialized
        int index= 0,
            daysTracer{0};
        while (daysTracer < days / 2) { // iterate to the median element in the real array
            if (count[index] != 0) {
                if (daysTracer + count[index] >= days / 2) {
                    first= index;
                    currentMedianLevel= days / 2 - daysTracer;
                    daysTracer= days / 2;
                }
                else {
                    daysTracer+= count[index];
                }
            }

            ++index;
        }

        if (days % 2 == 0) { // if the number of days is odd, find the second middle number.
            second= findNextMiddle(count, first, currentMedianLevel);
        }
    }
    else {
        if (days % 2 == 1) {
            first= findNextMiddle(count, currentMid, currentMedianLevel);
        }
        else {
            first= findNextMiddle(count, currentMid, currentMedianLevel);
            second= findNextMiddle(count, first, currentMedianLevel);
        }
    }

    currentMid= first;
    twiceMedian= (second == 0) ? first * 2 : first + second;

    return twiceMedian;
}

int activityNotifications(std::vector<int> A, int days) {
    int alerts{0};
    std::vector<int> count(201, 0); // stores count of last 'd' numbers
    int n= A.size(),
        currentMedian{-1}, currentMedianLevel{0};

    for (int i= 0; i < days; ++i) {
        ++count[A[i]];
    }



    for (int i= days; i < n; ++i) {
        int twiceMedian= getTwiceMedian(count, days, currentMedian, currentMedianLevel);
        if (A[i] >= twiceMedian) ++alerts;

        // update count array
        ++count[A[i]];
        --count[A[i - days]];
    }

    return alerts;
}