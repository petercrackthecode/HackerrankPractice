// link: https://leetcode.com/problems/jewels-and-stones/
int numJewelsInStones(string J, string S) {
    std::map<char, bool> jewelsType;
    int jewelsCount{0};
    for (char ch : J) {
        jewelsType[ch]= true;
    }
    
    for (char ch : S) {
        if (jewelsType[ch]) {
            ++jewelsCount;
        }
    }
        
    return jewelsCount;
}