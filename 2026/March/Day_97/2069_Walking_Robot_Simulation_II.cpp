//Approach: Simulation
//T.C: O(width+height) , for Constructor & O(1) for other methods
//S.C: O(width+height)
class Robot {
public:
    int idx = 0;
    bool moved = false;

    vector<vector<int>> pos;

    Robot(int width, int height) {

        for (int x = 0; x < width; x++) {
            pos.push_back({x, 0, 0});
        }

        for (int y = 1; y < height; y++) {
            pos.push_back({width - 1, y, 1});
        }

        for (int x = width - 2; x >= 0; x--) {
            pos.push_back({x, height - 1, 2});
        }

        for (int y = height - 2; y > 0; y--) {
            pos.push_back({0, y, 3});
        }


        pos[0][2] = 3;
    }
    
    void step(int num) {
        moved = true;

        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0], pos[idx][1]};
    }
    
    string getDir() {

        if(!moved)
            return "East";
        
        int d = pos[idx][2];

        if(d == 0) return "East";
        else if(d == 1) return "North";
        else if(d == 2) return "West";
        
        return "South";
    }
};