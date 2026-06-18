class Solution {
public:
    double angleClock(int hour, int minutes) {
        double total_hour = double(hour) + double(minutes)/60;
        
        double angle_hour_hand = total_hour*30;
        
        double angle_minute_hand = minutes*6;
        
        double result = abs(angle_minute_hand - angle_hour_hand);
        
        if(result > 180)
            return 360-result;

        return result;
    }
};