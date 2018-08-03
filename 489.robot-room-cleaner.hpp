/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

struct pair_hash {
    size_t operator() (const pair<int, int> &pr) const{
        return (size_t)pr.first << 32 | pr.second;
    }
};

class Solution {
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    void cleanRoom(Robot& robot) {
        unordered_set<pair<int, int>, pair_hash> vis;
        dfs(0, 0, 0, vis, robot);
    }
    void dfs(int r, int c, int dir, unordered_set<pair<int, int>, pair_hash> &vis, Robot &robot) {
        pair<int, int> key = {r, c};
        if(vis.count(key)) return;
        vis.insert(key);
        robot.clean();

        for(int i = 0; i < 4; i++, dir = (dir + 1) % 4, robot.turnRight()) {
            if(robot.move()) {
                int x = r + dirs[dir][0], y = c + dirs[dir][1];
                dfs(x, y, dir, vis, robot);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
        }
    }
};
