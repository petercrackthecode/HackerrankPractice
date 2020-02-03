// link: https://www.hackerrank.com/challenges/ctci-ransom-note/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

void checkMagazine(vector<string> magazine, vector<string> note) {
    std::map<std::string, int> hashTable;
    
    // insertion
    for (std::string word : magazine) {
        if (hashTable.find(word) == hashTable.end())    {
            hashTable.insert({word, 1});
        }
        else {
            ++hashTable[word];
        }
    }

    // search
    for (std::string word : note)  {
        if (hashTable.find(word) == hashTable.end())    {
            std::cout << "No\n";
            return;
        }
        else if (hashTable[word] == 0)  {
            std::cout << "No\n";
            return;
        }
        else --hashTable[word];
    }

    std::cout << "Yes\n";
}