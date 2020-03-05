// link: https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if (a.score > b.score)
            return 1;
        else if (a.score < b.score)
            return -1;
        else { // a.score == b.score, then we compare their name;
            if (a.name < b.name)
                return 1;
            else if (a.name > b.name)
                return -1;
            else return 0;
        }
    }
};