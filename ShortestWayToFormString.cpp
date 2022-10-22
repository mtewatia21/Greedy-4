// Time Compelxity - O(m*n), m is the length of source and n is the length of target.
// Space Comlexity - O(1)
// It runs on Leetcode!
// Problems Faced - No!

class Solution {
public:
    int shortestWay(string source, string target) {
        int s_ptr = 0;
        int t_ptr = 0;
        int sSize = source.size();
        int tSize = target.size();
        int answer = 0;
        
        while(t_ptr < tSize){
            int pos = t_ptr;
            while(s_ptr < sSize){
                if(source[s_ptr] == target[t_ptr]){
                t_ptr++;
                s_ptr++;
                }
                if(source[s_ptr] != target[t_ptr])
                    s_ptr++;
            }
            if(pos == t_ptr)
                return -1;
            s_ptr = 0;
            answer++;
        }
        return answer;
    }
};

// Time Compelxity - O(m*logn), m is the length of source and n is the length of target.
// Space Comlexity - O(1)
// It runs on Leetcode!
// Problems Faced - Binary Search in c++ is a boolean function, had to use lower_bound(Same TC as binary search).
class Solution {
public:
    int shortestWay(string source, string target) {
        int s_ptr = 0;
        int t_ptr = 0;
        int sSize = source.size();
        int tSize = target.size();
        int answer = 1;
        
        unordered_map<char, vector<int>> map;
        for(int i = 0; i < sSize; i++){
            char c = source[i];
            map[c].push_back(i);
        }
        
        while(t_ptr < tSize){
            char t = target[t_ptr];
            if(!map.count(t))
                return -1;
            vector<int> tIndex = map[t];
            vector<int>::iterator low;
            low = lower_bound (tIndex.begin(), tIndex.end(), s_ptr);
            int i = low - tIndex.begin();
            
            if(i == tIndex.size()){
                answer++;
                s_ptr = 0;
            }
            else{
                s_ptr = tIndex[i];
                s_ptr++;
                t_ptr++;
            }
        }
        return answer;
    }
};