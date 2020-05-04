// link: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
int findNextMiddle(const std::vector<int>& count, const int& first, int& currentMedianLevel) {
    if (count[first] > currentMedianLevel) {
        ++currentMedianLevel;
        return first;
    }
    else {
        int index = first + 1;
        while (index < count.size() && count[index] == 0) {
            ++index;
        }
        currentMedianLevel = 1;
        return index;
    }
}

int getTwiceMedian(const std::vector<int>& count, const int& days, int& currentMid, int& currentMedianLevel) {
    int first{ 0 },
        second{ 0 },
        twiceMedian{ 0 };

    bool areDaysOdd = days % 2 == 1 ? true : false;

    if (currentMid < 0 || currentMedianLevel <= 0) { // the median has never been initialized
        int index = 0,
            daysTracer{ 0 };

        while (daysTracer < (days + 1) / 2) { // iterate to the median element in the real array
            if (index < count.size() && count[index] != 0) {
                if (daysTracer + count[index] >= (days + 1) / 2) {
                    currentMedianLevel = (days + 1) / 2 - daysTracer;
                    daysTracer = (days + 1) / 2;
                }
                else {
                    daysTracer += count[index];
                }

                first = index;
            }

            ++index;
        }

        if (!areDaysOdd) { // if the number of days is even, find the second middle number.
            second = findNextMiddle(count, first, currentMedianLevel);
        }
    }
    else {
        if (areDaysOdd) {
            first = findNextMiddle(count, currentMid, currentMedianLevel);
        }
        else {
            first = findNextMiddle(count, currentMid, currentMedianLevel);
            second = findNextMiddle(count, first, currentMedianLevel);
        }
    }

    currentMid = first;
    twiceMedian = (areDaysOdd) ? first * 2 : first + second;

    return twiceMedian;
}

int activityNotifications(std::vector<int> A, int days) {
    int alerts{ 0 };
    std::vector<int> count(201, 0); // stores count of last 'd' numbers
    int n = A.size(),
        currentMedian{ -1 }, currentMedianLevel{ 0 };

    for (int i = 0; i < days; ++i) {
        ++count[A[i]];
    }

    for (int i = days; i < n; ++i) {
        int twiceMedian = getTwiceMedian(count, days, currentMedian, currentMedianLevel);
        if (A[i] >= twiceMedian) ++alerts;

        // update count array
        ++count[A[i]];
        --count[A[i - days]];
    }

    return alerts;
}