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

int findDoubledMediumExpenditure(std::vector<int> count, int days, bool areDaysEven, int &expenditureOrder, int &currentMediumInCount) {
    if (currentMediumInCount == -1) {

    }
    
}

// Complete the activityNotifications function below.
int activityNotifications(std::vector<int> expenditure, int d) {
    int notifications{0},
        currentMediumInCount{-1},
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