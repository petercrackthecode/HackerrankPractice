// problem link: https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dictionaries-hashmaps&isFullScreen=true

long countTriplets(vector<long> arr, long r) {
    long count{0};

    std::map<long, vector<int>> tripletsCollection;

    for (int index= 0; index < arr.size(); ++index) {
        if (tripletsCollection.count(arr[index]) == 0) {
            tripletsCollection.emplace(arr[index], 1);
        }
        else ++tripletsCollection[arr[index]];
    }

    for (auto aTriplet : tripletsCollection) {
        long firstNumCounter= aTriplet.second;

        if (tripletsCollection.count(aTriplet.first * r) != 0) {
            long secondNumCounter= tripletsCollection[aTriplet.first * r];

            if (tripletsCollection.count(aTriplet.first * r * r) != 0) {
                long thirdNumCounter{tripletsCollection[aTriplet.first * r * r]};

                if (r != 1) count+= (firstNumCounter * secondNumCounter * thirdNumCounter);
                else count+= (firstNumCounter * (secondNumCounter - 1) * (thirdNumCounter - 2) / 6);
            }
        }
    }

    return count;
}

// second Solution
int findClosestGreaterIndex(int index; vector<int> arr) {
    for (int id= 0; id < vector.size(); ++id) {
        if (index < vector[id])
            return id;
    }

    return -1;
}

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    long count{0};

    std::map<long, vector<int>> tripletsCollection;

    for (int index= 0; index < arr.size(); ++index) {
        tripletsCollection[arr[index]].push_back(index);
    }

    for (auto aTriplet : tripletsCollection) { // aTriplet.second will be a vector
        int firstNum= aTriplet.first;
        for (int firstIndex : aTriplet.second) {
            
        }
    }

    return count;
}