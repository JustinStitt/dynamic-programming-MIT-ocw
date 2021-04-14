#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> vec){
    for(auto&& e : vec){
        os << e << " ";
    } os << "\n";
    return os;
}

int levenDist(string& s, string& t){
    const int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1);
    for(auto& r : dp) r.resize(m + 1);

    for(int x{}; x <= n; ++x) dp[x][0] = x;
    for(int x{}; x <= m; ++x) dp[0][x] = x;
    
    for(int r{1}; r <= n; ++r){
        for(int c{1}; c <= m; ++c){
            if(s[r-1] == t[c-1]){
                dp[r][c] = dp[r-1][c-1];
                continue;
            }
            dp[r][c] = 1 + min({
                            dp[r-1][c],
                            dp[r][c-1],
                            dp[r-1][c-1]
                           });
        }
    }

    /* overloaded '<<' operator to display 2D vector  */
    cout << " " <<  dp << "\n";

    /* Return result (bottom-right) */
    return dp[n][m];
}


int main(){
    string w1 = "Monday", w2 = "Tuesday";
    auto d = levenDist(w1, w2);
    cout << "distance: " << d << "\n";
    return 0;
}
