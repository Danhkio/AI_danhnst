#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
void showMap( pair<int, int> A[], int N);
void search(int);
int heuristicDistance(pair<int, int> A[], pair<int, int> B[]);
bool moveChessBoard(pair<int, int> A[], int type);
void playChessBoard(pair<int, int> currentChessBoard[], pair<int, int> targetChessBoard[]);

int main()
{

    // init chessboard 
    pair<int, int> initAdjs[9] = {
        make_pair(0,2), //1 
        make_pair(0,1), //2 
        make_pair(1,2), //3
        make_pair(1,1), //4
        make_pair(0,0), //5
        make_pair(2,2), //6
        make_pair(1,0), //7
        make_pair(2,1), //8
        make_pair(2,0), //0
        
    };
    
    // target chessboard 
    pair<int, int> targetAdjs[9] = { //modify 
        make_pair(0,0), //1  
        make_pair(0,1), //2 
        make_pair(0,2), //3
        make_pair(1,0), //4
        make_pair(1,1), //5
        make_pair(1,2), //6
        make_pair(2,0), //7
        make_pair(2,1), //8
        make_pair(2,2), //0
    };
    // heuristic function 
    int first_distance  = heuristicDistance(initAdjs, targetAdjs);
    cout << "first_distance: " << first_distance;
    // showMap(adjs,2);
    playChessBoard(initAdjs, targetAdjs);
    // movtion
        // left 0 , right - 1 , up 2, down 3
        // left -> new chessboard
        // right -> new chessboard 
        // .... -> ?
        // .... -> ?
    // get min distance 
        
    return 0;

}

int heuristicDistance(pair<int, int> A[], pair<int, int> B[]){
    // A vi tri hien tai cua ban co
    // B vi tri dich cuar ban co
    int dist = 0;
    for(int i = 0; i<8; i ++){
        int temp_dist = abs(A[i].first - B[i].first) + abs(A[i].second - B[i].second);
        dist += temp_dist;
    }
    return dist;
}

bool moveChessBoard(pair<int, int> A[], int type){
    // left 0 , right - 1 , up 2, down 3 
    int first = 0;
    int second = 0;
    int quanco = -1;
    //sang trai -> tim vi tri ben phai cua 0:  x y -> ben phai: x, y +1;
    if(type == 0 ){
        first = A[8].first;
        second = A[8].second + 1;
    }
    //sang phai -> tim vi tri ben trai cua 0  x y -> ben trai: x, y -1 ;
    if(type == 1 ){
        first = A[8].first;
        second = A[8].second - 1;
    }
    //xuong duoi -> tim vi tri ben tren cua 0  x y -> ben tren: x-1, y;
    if(type == 2 ){
        first = A[8].first - 1;
        second = A[8].second ;
    }
    //len tren ->  tim vi tri ben duoi cua 0 x y -> ben duoi: x +1, y;
    if(type == 3 ){
        first = A[8].first +1;
        second = A[8].second ;
    }
    // kiem tra vi tri co ton tai hay khong => 
    if(first > 3 || second > 3){
        return 0;
    }
    else{
        // vi tri => tim quan co 
        for(int i = 0; i<8; i ++){if(A[i].first == first & A[i].second == second){
                // Swap 
                pair<int, int> temp = A[8];
                A[8] = A[i];
                A[i] = temp;
                return 1;

            }
        }
        
    }
    
}

void playChessBoard(pair<int, int> currentChessBoard[], pair<int, int> targetChessBoard[]){
    // Explore staste chessboard
    
        // Calculate COST of each action by heuristicDistance
            // Up  
            // Down 
            // Left  
            // Right 
    // Get action with COST MIN 
    // Check finished (if heuristicDistance=0 -> stop algorithms; else -> continue explore chessboard )
    
    
}
    

void showMap( pair<int, int> A[], int N){
    A[1].first = 5;
    A[1].second = 6;
}

void search(int N){
    cout << "hi";
}
