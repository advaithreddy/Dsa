#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// Function to find the maximum element in a column along with its row index
pair<int, int> findMaxInColumn(vector<vector<int>>& matrix, int col) {
    int maxVal = INT_MIN;
    int rowIndex = -1;
    int numRows = matrix.size();

    for (int i = 0; i < numRows; i++) {
        if (matrix[i][col] > maxVal) {
            maxVal = matrix[i][col];
            rowIndex = i;
        }
    }

    return make_pair(maxVal, rowIndex);
}

// Function to find a peak element in a 2D matrix along with its indices
pair<int, pair<int, int>> findPeakElement(vector<vector<int>>& matrix, int startCol, int endCol) {
    int numRows = matrix.size();
    int midCol = (startCol + endCol) / 2;
    
    // Find the maximum element in the middle column
    pair<int, int> maxInMidCol = findMaxInColumn(matrix, midCol);
    int maxVal = maxInMidCol.first;
    int maxRowIndex = maxInMidCol.second;
    
    // Check if maxVal is a peak element
    if ((midCol == 0 || maxVal >= matrix[maxRowIndex][midCol - 1]) &&
        (midCol == numRows - 1 || maxVal >= matrix[maxRowIndex][midCol + 1])) {
        return make_pair(maxVal, make_pair(maxRowIndex, midCol));
    }
    
    // If not, recursively search in the left or right submatrix
    if (midCol > 0 && maxVal < matrix[maxRowIndex][midCol - 1]) {
        return findPeakElement(matrix, startCol, midCol - 1);
    } else {
        return findPeakElement(matrix, midCol + 1, endCol);
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 3},
        {3, 2, 6},
        {5, 8, 9}
    };

    int numRows = matrix.size();
    int numCols = matrix[0].size();

    pair<int, pair<int, int>> peak = findPeakElement(matrix, 0, numCols - 1);

    cout << "Peak Element: " << peak.first << endl;
    cout << "Row Index: " << peak.second.first << endl;
    cout << "Column Index: " << peak.second.second << endl;

    return 0;
}
