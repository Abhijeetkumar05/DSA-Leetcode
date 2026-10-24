class Solution {
private:
    int dayOfYear(const string& date) {
        const int daysBeforeMonth[12] = {0,   31,  59,  90,  120, 151,
                                         181, 212, 243, 273, 304, 334};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        return daysBeforeMonth[month - 1] + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));

        return max(0, end - start + 1);
    }
};