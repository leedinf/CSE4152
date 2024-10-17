#include <iostream>
#include <cassert>

/**
 * @brief Query the value of the cell (r, c).
 * @param r The row number of the cell.
 * @param c The column number of the cell.
 * @return The value of the cell (r, c).
 */
int query_cell(int r, int c) {
    int result;
    std::cout << "? " << r << ' ' << c << std::endl;
    std::cin >> result;
    assert(result != -1);
    return result;
}

/**
 * @brief Verifies if the value of the cell (r, c) is equal to K.
 * @param r The row number of the cell.
 * @param c The column number of the cell.
 * @return true if the answer is correct, otherwise returns false.
 */
bool answer_with_cell(int r, int c) {
    int result;
    std::cout << "! " << r << ' ' << c << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

/**
 * @brief Verifies if there is no cell with value K in the matrix.
 * @return true if the answer is correct, otherwise returns false.
 */
 bool answer_without_cell() {
    int result;
    std::cout << "! -1" << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    // TODO: write your logic here!
    // You can use the functions `query_cell`, `answer_with_cell`, and `answer_without_cell`.
    // Any invocation of print functions rather than the given
    // functions will result in 0 points for this question.
    int a=1,b=n;
    int t=0;
    while(a<=n && b>=1){
        t=query_cell(a,b);
        if(t > k){
            b--;
        }
        else if(t < k){
            a++;
        }
        else{
            answer_with_cell(a,b);
            return 0;
        }
    }
    answer_without_cell();
    return 0;
}
