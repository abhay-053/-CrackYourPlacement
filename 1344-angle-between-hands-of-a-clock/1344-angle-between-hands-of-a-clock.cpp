class Solution {
public:
    double angleClock(int hour, int minutes) {
        double theta = abs(30 * hour - 5.5 * minutes);
        if(theta > 180){
            theta = 360 - theta;
        }

        return theta;
    }
};