
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (open % 2 == 1) {
                    insertions++;
                    open--;
                }
                open += 2;
            }
            else {
                open--;

                if (open < 0) {
                    insertions++;
                    open = 1;
                }
            }
        }

        return insertions + open;
    }
};
