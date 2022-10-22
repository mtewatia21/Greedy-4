// Time Compelxity - O(n)
// Space Comlexity - O(1)
// It runs on Leetcode!
// Problems Faced - No!
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map<int, int> map;
        int rotateMe = 0;
        for(int i = 0; i < n; i++){
            map[tops[i]]++;
            if(map[tops[i]] >= n){
                rotateMe = tops[i];
                break;
            }
            
            map[bottoms[i]]++;
            if(map[bottoms[i]] >= n){
                rotateMe = bottoms[i];
                break;
            }
        }
        
        int topR = 0;
        int bottomR = 0;
        for(int i = 0; i < n; i++){
            if(tops[i] != rotateMe && bottoms[i] != rotateMe)
                return -1;
            if(tops[i] != rotateMe)
                topR++;
            if(bottoms[i] != rotateMe)
                bottomR++;
        }
        return min(topR, bottomR);
    }
};

// Time Compelxity - O(n)
// SPace Comlexity - O(1)
// It runs on Leetcode!
// Problems Faced - No!
class Solution {
    private:
    int findRotations(vector<int>& tops, vector<int>& bottoms, int n){
        int topR = 0;
        int bottomR = 0;
        int size = tops.size();
        for(int i = 0; i < size; i++){
            if(tops[i] != n && bottoms[i] != n)
                return -1;
            if(tops[i] != n)
                topR++;
            if(bottoms[i] != n)
                bottomR++;
        }
        return min(topR, bottomR);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int answer = findRotations(tops, bottoms, tops[0]);
        if(answer != -1)
            return answer;
        return findRotations(tops, bottoms, bottoms[0]);
    }
};