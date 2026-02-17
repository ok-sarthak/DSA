//T.C : O(1) //since the number of hours and minutes are fixed
//S.C : O(1)
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int HH = 0 ; HH <= 11; HH++) {

            for(int MM = 0; MM <= 59; MM++) {

                if(__builtin_popcount(HH) + __builtin_popcount(MM) == turnedOn) {

                    string hours = to_string(HH);
                    string minutes = (MM < 10 ? "0" : "") + to_string(MM);

                    result.push_back(hours + ":" + minutes);
                }
            }
        }

        return result;
    }
};