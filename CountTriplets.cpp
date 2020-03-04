// problem link: https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dictionaries-hashmaps&isFullScreen=true

/*
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
*/

// second Solution

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    long count{0};

    std::map<long, vector<int>> backTracker;
    std::map<long, long> counter;

    for (int index= 0; index < arr.size(); ++index) {
        if (backTracker.count(arr[index] / r) == 0 || arr[index] % r != 0) {
            backTracker[arr[index]].push_back(0);
            counter[arr[index]]= 0;
        }
        else {
            int currentNum= backTracker[arr[index] / r].size();
            if (backTracker.count(arr[index] / (r * r)) != 0 && arr[index] % (r * r) == 0) 
                count+= counter[arr[index] / r];

            backTracker[arr[index]].push_back(currentNum);
            if (counter.count(arr[index]) == 0) {
                counter[arr[index]]= 0 + currentNum;
            }
            else counter[arr[index]]+= currentNum;
        }
    }

    return count;
}

// shorter solution
long countTriplets(vector<long> arr, long r) {
    long count = 0;

    map<long, long> m1;
    map<long, long> m2;
    for (const auto &e : arr) {
        count += m2[e];
        m2[e * r] += m1[e];
        ++m1[e * r];
    }

    return count;
}