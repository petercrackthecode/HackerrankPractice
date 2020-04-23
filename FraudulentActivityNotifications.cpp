// link: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
int getTwiceMedian(vector<int> &A, vector<int> &count, int d) {
    vector<int> countFrequencies(count);

    for (int i= 1; i < countFrequencies.size(); ++i) { // O(1);
        countFrequencies[i]+= countFrequencies[i - 1];
    }

    int median,
        a{0},
        b{0};

    // d is even -> median= a + b
    if (d % 2 == 0) {
        int first= d / 2;
        int second= first + 1;
        int i{0};

        for (; i < 200; ++i) {
            if (first <= countFrequencies[i]) {
                a= i;
                break;
            }
        }

        for (; i < 201; ++i) {
            if (second <= countFrequencies[i]) {
                b= i;
                break;
            }
        }
    }
    else { // d is odd -> median = a + 0 = 2 * (middle elem)
        int first= d / 2 + 1;
        for (int i= 0; i < 201; ++i) {
            if (first <= countFrequencies[i]) {
                a= 2 * i;
                break;
            }
        }
    }
    median= a + b;
    return median;
}

int activityNotifications(vector<int> A, int d) {
    int alerts{0};
    vector<int> count(201, 0); // stores count of last 'd' numbers
    int n= A.size();

    for (int i= 0; i < d; ++i) {
        ++count[A[i]];
    }

    for (int i= d; i < n; ++i) {
        int twiceMedian= getTwiceMedian(A, count, d);
        if (A[i] >= twiceMedian) ++alerts;

        // update count array
        ++count[A[i]];
        --count[A[i - d]];
    }

    return alerts;
}