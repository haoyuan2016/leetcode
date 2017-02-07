// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int guessMax = n;
        int guessMin = 1;
        while(guessMin <= guessMax)
        {
            int guessMid = guessMin + (guessMax - guessMin) / 2;
            if(guess(guessMid) == 0) return guessMid;
            else if(guess(gitguessMid) == 1) guessMin = guessMid + 1;
            else guessMax = guessMid - 1;
        }
        return guessMin;
    }
};
