#include <iostream>
using namespace std;


//recursively check all the adjacent value, marking them visited and adding them to the members
void dfs(int** m, int r, int c, int i, int j, bool** visited, int& members){
    int rowDirections[] = {-1, 1, 0, 0};
    int colDirections[] = {0, 0, -1, 1};

    visited[i][j] = true;
    members += m[i][j];

    for (int k=0; k<4; k++){
        int rowToCheck = i + rowDirections[k];
        int colToCheck = j + colDirections[k];

        if (rowToCheck >= 0 && rowToCheck < r && colToCheck >= 0 && colToCheck < c && m[rowToCheck][colToCheck] > 0 && !visited[rowToCheck][colToCheck]){
            dfs(m, r, c, rowToCheck, colToCheck, visited, members);
        }
    }
}



int* gRoups(int** m, int r, int c, int& totalGroupsArrayLength){

    //to store all possible groups and its length
    int* totalGroupsArray = new int[r * c];
    totalGroupsArrayLength = 0;

    //initially marking every point as not visited
    bool** visited = new bool*[r]; //row array initialization
    for (int i=0; i<r; i++) {
        visited[i] = new bool[c]; //column array initialization
        for (int j=0; j<c; j++) {
            visited[i][j] = false;
        }
    }

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (m[i][j] > 0 && !visited[i][j]){
                int members = 0;
                dfs(m, r, c, i, j, visited, members);
                totalGroupsArray[totalGroupsArrayLength++] = members;
            }
        }
    }

    //visited - garbage collection
    for (int i=0; i<r; i++){
        delete[] visited[i];
    }
    delete[] visited;

    return totalGroupsArray;
}

int main(){
    int r = 5;
    int c = 5;
    int** m = new int*[r];
    m[0] = new int[c]{0, 2, 0, 3, 1};
    m[1] = new int[c]{4, 1, 2, 0, 0};
    m[2] = new int[c]{2, 0, 0, 0, 0};
    m[3] = new int[c]{0, 1, 0, 2, 3};
    m[4] = new int[c]{0, 0, 1, 1, 0};

    int noOfGroups = 0;
    int* groups = gRoups(m, r, c, noOfGroups);

    cout << "Total possible groups from the matrix : [";
    int max = 0;
    for (int i=0; i<noOfGroups; i++){
        if(max < groups[i]){
            max = groups[i];
        }
        cout << groups[i];
        if (i < noOfGroups - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Leader Group : [" << max << "]";

    //groups and m garbage collection
    delete[] groups;
    for(int i=0; i<r; i++){
        delete[] m[i];
    }
    delete[] m;

    return 0;
}
