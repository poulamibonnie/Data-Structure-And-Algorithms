/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), [] (Interval &a, Interval &b){
            return a.start < b.start;
        });

        int nstart = intervals[0].start;
        int nend = intervals[0].end;

        for (int i = 1; i < intervals.size(); i++) {
            if (nend <= intervals[i].start) {
                nstart = intervals[i].start;
                nend = intervals[i].end;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
