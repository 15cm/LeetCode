using intpair = std::pair<int, int>;

class SnakeGame {
    int m, n;
    vector<intpair> food;
    vector<intpair>::iterator fit;
    int score;

    struct intpair_hash {
        size_t operator()(const intpair& p) const {
            return (size_t(p.first) << 32) | p.second;
        }
    };

    deque<intpair> snake;
    unordered_set<intpair, intpair_hash> region;

    bool hasFood(const intpair& pos) {
        if(fit == food.end()) return false;
        if(pos == *fit) {
            fit++;
            return true;
        }
        return false;
    }

    bool isValid(const intpair& pos) {
        int r = pos.first, c = pos.second;
        return (r >= 0 && r < m && c >= 0 && c < n) && (!region.count(pos) || pos == snake.back());
    }

    intpair transDir(string s) {
        switch(s[0]) {
        case 'R': return {0, 1};
        case 'L': return {0, -1};
        case 'D': return {1, 0};
        case 'U': return {-1, 0};
        }
        return {0, 0};
    }

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        m = height;
        n = width;
        this->food = food;
        fit = this->food.begin();
        score = 0;

        snake.push_back({0, 0});
        region.insert({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(score == -1)
            return -1;
        auto head = snake.front();
        auto dir = transDir(direction);
        head.first += dir.first;
        head.second += dir.second;

        if(!isValid(head)) return score = -1;

        if(hasFood(head)) {
            score++;
        } else {
            region.erase(snake.back());
            snake.pop_back();
        }

        snake.push_front(head);
        region.insert(head);

        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
