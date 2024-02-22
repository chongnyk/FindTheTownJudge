class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> frequency(n, 0);
        int index = 0;
        int trustSize = trust.size();
        for(vector<int> entry : trust){
            index = entry[1];
            frequency[index - 1]++;
        }
        int highestFrequency = *max_element(frequency.begin(), frequency.end());
        if(highestFrequency != n - 1){
            return -1;
        }
        else {
            int highestFrequencyIdx = max_element(frequency.begin(), frequency.end()) - frequency.begin();
            highestFrequencyIdx++;
            if(all_of(trust.cbegin(), trust.cend(), [&highestFrequencyIdx](vector<int> row){return row[0] != highestFrequencyIdx;})){
                return highestFrequencyIdx;
            }
            else {
                return -1;
            }
        }
    }
};
