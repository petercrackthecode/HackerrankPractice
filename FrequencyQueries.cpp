vector<int> freqQuery(vector<vector<int>> queries) {
    std::map<int, int> data,
                       queriesFrequencies;
    std::vector<int> output;

    for (auto query : queries) {
        int command= query[0],
            unit= query[1];
        
        switch (command) {
            case 1:
                --queriesFrequencies[data[unit]]; 
                ++data[unit];
                ++queriesFrequencies[data[unit]];
            break;
            case 2:
                if (data[unit] > 0) {
                    --queriesFrequencies[data[unit]]; 
                    --data[unit];
                    ++queriesFrequencies[data[unit]];
                }
            break;
            case 3:
                if (queriesFrequencies[unit] > 0)   {
                    output.push_back(1);
                }
                else output.push_back(0);
            break;
            default:
            break;
        }
    }

    return output;
}