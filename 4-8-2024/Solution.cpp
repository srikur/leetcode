class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        while (true) {
            for (int i = 0; i < tickets.size(); i++) {
                if (i == k && tickets[i] == 1)
                    return count + 1;
                if (tickets[i] > 0) {
                    count++;
                    tickets[i] -= 1;
                }
            }
        }
        return count;
    }
};