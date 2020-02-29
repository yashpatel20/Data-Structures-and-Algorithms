#include <bits/stdc++.h>
using namespace std;

//search a 2d sorted array
//n rows m columns

//Brute force is to binary search for target in each sorted row or column
//Time : O(nlogm)

//Improve time by taking advantage of the fact that array is sorted
//[0,0] is the smallest element in the array
//implement row and column eliminations
//Time : O(n+m) total n+m-1 comparisions


bool search(vector<vector<int>>& matrix, int target){
    //start with the right corner element
    int i = 0, j = matrix[0].size();
    while( i < matrix.size() and j>=0){
        if(target == matrix[i][j]) return true;
        else if(target > matrix[i][j]) i++;
        else j--;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    int target = 20;
    cout << search(matrix, target) << endl;
}