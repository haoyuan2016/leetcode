class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int cover = 0;
        int a = max(A, E);
        int b = min(C, G);
        int c = max(B, F);
        int d = min(D, H);
        if(b > a && d > c)
            cover = (b - a) * (d - c);
        return abs(G - E) * abs(H - F) + abs(A - C) * abs(B - D) - cover;
    }
};
