class Solution {
public:
    /*
    Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
    Output: 10

    Each interval is [start, end, coinsPerUnit].

    After sorting:
    coins = [
        [1, 3, 2],
        [5, 6, 4],
        [8, 10, 1]
    ]
    */

    long long maximumCoins(vector<vector<int>>& coins, int k) {

        sort(coins.begin(), coins.end());             

        /*
            After sorting:
    coins = [ [1, 3, 2], [5, 6, 4], [8, 10, 1]] */   // k =4

        int length = coins.size();    // 3

        long long maxCoins = 0;
        long long currentCoins = 0;


        for (int i = 0, j = 0; i < length; i++) {

            int windowEnd = coins[i][0] + k - 1;             // 1 + 4 -1 = 4

            while (j < length && coins[j][1] <= windowEnd) {          // 0< 3 && 3 <= 4

                currentCoins +=
                    1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];   // 3 - 1 + 1 * 2 = 6

                j++;
            }

            if (j < length) {      // 1 < 3

                long long partialCoins =
                    1LL * max(0, windowEnd - coins[j][0] + 1) * coins[j][2];    // 0, (4 - 1 + 1) * 2 = 8

                maxCoins = max(maxCoins, currentCoins + partialCoins);   // 0, 6 + 8 = 14
            }

            // Remove the interval at i before moving to the next start.
            currentCoins -=
                1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];  // 6 - 3 - 1 + 1 * 2 = 2
        }


        // ==========================================
        // PASS 2: Consider windows ending at coins[i][1]
        // ==========================================

        currentCoins = 0;

        for (int i = 0, j = 0; i < length; i++) {

            // Add the complete current interval.
            currentCoins +=
                1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];

            // Window starts at end - k + 1.
            int windowStart = coins[i][1] - k + 1;

            // Remove intervals that are completely outside the window.
            while (coins[j][1] < windowStart) {

                currentCoins -=
                    1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];

                j++;
            }

            // Calculate coins belonging to the partially covered
            // interval at the beginning of the window.
            long long partialCoins =
            1LL * max(0, windowStart - coins[j][0]) * coins[j][2];

            maxCoins = max(maxCoins, currentCoins - partialCoins);
        }

        return maxCoins;
    }
};