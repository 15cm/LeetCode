typedef vector<int>::iterator vit;
typedef vector<vector<int>>::iterator vvit;
class Vector2D {
public:
    vit col;
    vvit row;
    vvit rowEnd;
    Vector2D(vector<vector<int>>& vec2d) {
        row = vec2d.begin();
        rowEnd = vec2d.end();
        if(row != rowEnd) {
            col = row->begin();
        }
    }

    int next() {
        if(hasNext()) {
            return *(col++);
        }
        return -1;
    }

    bool hasNext() {
        if(row == rowEnd) return false;
        while(col == row->end()) {
            row++;
            col = row->begin();
            if(row == rowEnd) return false;
        }
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
