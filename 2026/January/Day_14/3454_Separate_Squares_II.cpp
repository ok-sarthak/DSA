class Solution {
public:

    struct Event {
        int y; //event
        int type; //starting event +1 or ending event -1
        int x1, x2; //Range

        bool operator < (const Event& other) const{ //sorting y
            return y < other.y;
        }
    };

    double getUnionWidth(vector<pair<int, int>>& intervals) {
        if(intervals.empty()) return 0.0;

        sort(intervals.begin(), intervals.end());

        double width = 0;

        int currentL = intervals[0].first;
        int currentR = intervals[0].second;

        int length = intervals.size();

        for(int i = 1; i < length; i++) {
            if(intervals[i].first > currentR) {
                width += currentR - currentL;

                currentL = intervals[i].first;
                currentR = intervals[i].second;
            } else {
                currentR = max(currentR, intervals[i].second);
            }
        }

        return width += currentR - currentL;
    }
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events; //Creating event for every square

        for(auto &square : squares) {
            int x = square[0];
            int y = square[1];
            int l = square[2];

            events.push_back({y, +1, x, x+l});
            events.push_back({y+l, -1, x, x+l});
        }

        sort(events.begin(), events.end());

        vector<pair<int, int>> activeX;

        vector<tuple<int, int, double>> strips; //y, height, width

        double totalArea = 0;

        int prevY = events[0].y;

        for(auto &event : events) {
            if(event.y > prevY) {
                double width = getUnionWidth(activeX);

                int height = event.y - prevY;

                if(width > 0) {
                    strips.push_back({prevY, height, width});

                    totalArea += width * height;
                }
            }

            if(event.type == +1) {
                activeX.push_back({event.x1, event.x2});
            } else {
                for(auto it = activeX.begin(); it != activeX.end(); it++) {
                    if(it->first == event.x1 && it->second == event.x2) {
                        activeX.erase(it);

                        break;
                    }
                }
            }

            prevY = event.y;
        }

        double targetArea = totalArea/2.0;

        double currentArea = 0;

        for(auto &strip : strips) {
            int y, h;
            double w;

            tie(y, h, w) = strip;

            double stripArea = h * w;

            if(currentArea + stripArea >= targetArea) {
                double needArea = targetArea - currentArea;

                return y + (needArea/w);
            }

            currentArea += stripArea;
        }

        return 0.0;
    }
};