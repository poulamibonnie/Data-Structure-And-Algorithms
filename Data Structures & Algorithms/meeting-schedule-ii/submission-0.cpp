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

#define PII pair<int,int>
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int mnRoom = 0;
        vector<PII> meetingList;

        for (Interval meeting : intervals) {
            meetingList.push_back({meeting.start, 1});
            meetingList.push_back({meeting.end, 0});
        }
        sort(meetingList.begin(), meetingList.end(), [] (PII &a, PII &b) {
            return (a.first == b.first) ? a.second == 0 : a.first < b.first ;});

        int cnt = 0;
        for (PII meeting : meetingList) {
            if (meeting.second == 1) {
                cnt++;
            }
            else {
                cnt--;
            }
            mnRoom = max(mnRoom, cnt);
        }
        return mnRoom;
    }
};
