// Time complexity :- O(1)
// Space complexity :- O(1)
class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        if(hour == 12)
            return angleClock(0, minutes);
        double ans = 0;
        double min_deg = minutes*6;
        double hr_deg = (hour*5*6) + (min_deg * (1/12.0));
        ans = abs(min_deg - hr_deg);
        
        return min(ans, 360 - ans);
        
    }
};