void countingSort(std::vector<int> &expenditures, int startPos, int endPos) {
    std::vector<int> count(201, 0);
    
    for (int index= startPos; index <= endPos; ++index) {
        ++count[expenditures[index]];
    }
    
    int countIndex{0},
        expenditureIndex{startPos};
    
    while (expenditureIndex <= endPos) {
        while (count[countIndex] > 0) {
            expenditures[expenditureIndex]= countIndex;
            ++expenditureIndex;
            --count[countIndex];
        }
        ++countIndex;
    }
}

double getMedium(std::vector<int> &expenditure, int startPos, int endPos) {
    int subArraySize{endPos - startPos + 1};
    if (startPos == 0)  {
        countingSort(expenditure, startPos, endPos);
    }
    else putNumberIntoRightPos(expenditure, startPos, endPos);

    double medium= (subArraySize % 2 != 0) ? expenditure[subArraySize / 2 + startPos]
                                        : (expenditure[subArraySize / 2 + startPos] + expenditure[subArraySize / 2 - 1 + startPos]) / 2.0;

    return medium;
}

int findSmallestExpenditure(std::vector<int> count) {
    for (int index= 0; index <= 200; ++index) {
        if (count[index] > 0) {
            return index;
        }
    }

    return 200;
}

int findClosestLargerIndex(std::vector<int> count, int index) {
    for (int traversal= index + 1; traversal <= 200; ++traversal) {
        if (count[traversal] > 0) {
            return traversal;
        }
    }

    return 200;
}

int findClosestSmallerIndex(std::vector<int> count; int index) {
    for (int traversal= index - 1; traversal >= 0; --traversal) {
        if (count[traversal] > 0) {
            return traversal;
        }
    }
}

int findDoubledMediumExpenditure(std::vector<int> count, int days, bool areDaysEven) {
    int daysTracker{0};
    int index{0};

    while (daysTracker < days / 2) {
        if (count[index] != 0) {
            --count[index];
            ++daysTracker;
        }
        else ++index;
    }

    
}

// Complete the activityNotifications function below.
int activityNotifications(std::vector<int> expenditure, int d) {
    int notifications{0},
        currentMediumIndex= 0,
        expenditureOrder{0};
    std::vector<int> count(201, 0);
    bool areDaysEven= d % 2 == 0 ? true : false;

    for (int index= 0; index <= expenditure.size() - d; ++index) {
        if (index == 0) {
            for (int i= index; i < index + d) {
                ++count[expenditure[i]];
            }
        }
        else ++count[expenditure[index + d - 1]];

        if (expenditure[index + d] >= medium * 2)
            ++notifications;
    }

    return notifications;
}