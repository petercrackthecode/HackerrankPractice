// link: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting

void putNumberIntoRightPos(vector<int> &expenditure, int startPos, int endPos) {
    int subArrayEndPos= endPos - 1,
        traversingIndex= startPos;
    bool isSorted= false;
    while (traversingIndex < endPos && !isSorted) {
        if (expenditure[traversingIndex])

        ++traversingIndex;
    }
}

double getMedium(std::vector<int> &expenditure, int startPos, int endPos) {
    int subArraySize{endPos - startPos + 1};
    if (startPos == 0)
        std::sort(expenditure.begin() + startPos, expenditure.begin() + endPos);
    else putNumberIntoRightPos(expenditure, startPos, endPos);

    double medium= (subArraySize % 2 != 0) ? expenditure[subArraySize / 2 + startPos]
                                        : (expenditure[subArraySize / 2 + startPos] + expenditure[subArraySize / 2 - 1 + startPos]) / 2.0;

    return medium;
}

// Complete the activityNotifications function below.
int activityNotifications(std::vector<int> expenditure, int d) {
    int notifications{0};
    for (int index= 0; index <= expenditure.size() - d; ++index) {
        double medium= getMedium(expenditure, index, index + d - 1);
        if (expenditure[index + d] >= medium * 2)
            ++notifications;
    }

    return notifications;
}