// assume that the min element in the array is greater than or equal to zero
void countingSort(std::vector<int> &expenditures, int max) {
    std::vector<int> count(max, 0);
    
    for (int expenditure : expenditures) {
        ++count[expenditure];
    }
    
    int countIndex{0},
        expenditureIndex{0};
    
    while (expenditureIndex < expenditures.size()) {
        while (count[countIndex] > 0) {
            expenditures[expenditureIndex]= countIndex;
            ++expenditureIndex;
            --count[countIndex];
        }
        ++countIndex;
    }
}