#include <iostream>

using namespace std;
void printBoard(int A[][3]);
int checkEnd(int A[][3]);
void playBoard(int A[][3]);
pair<int, int> findBestMove(int A[][3]);
int calMinimax(int, pair<int, int> curIndex);

int main() {
  int board[3][3] = {0}; // X=1, O=2, _ = 0
  printBoard(board);
  // checkEnd -> 1 -1 0 5(fighting)
  cout << "Init status: " << checkEnd(board) << endl;
  playBoard(board);
  return 0;
}

void printBoard(int A[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

int checkEnd(int a[][3]) {
  // 1 1 1 => 1
  // 1;1;1
  // 2 2 2 => -1
  // => 0
  // row = 1
  for (int i = 0; i < 3; i++) {
    if (a[i][0] == 1 && a[i][1] == 1 && a[i][2] == 1) {
      return 1;
    }
  }
  // column = 1
  for (int i = 0; i < 3; i++) {
    if (a[0][i] == 1 && a[1][i] == 1 && a[2][i] == 1) {
      return 1;
    }
  }
  // diagonal
  if ((a[0][0] == 1 && a[1][1] == 1 && a[2][2] == 1) ||
      (a[0][2] == 1 && a[1][1] == 1 && a[2][0] == 1)) {
    return 1;
  }

  for (int i = 0; i < 3; i++) {
    if (a[i][0] == 2 && a[i][1] == 2 && a[i][2] == 2) {
      return -1;
    }
  }
  // column = 1
  for (int i = 0; i < 3; i++) {
    if (a[0][i] == 2 && a[1][i] == 2 && a[2][i] == 2) {
      return -1;
    }
  }
  // diagonal
  if ((a[0][0] == 2 && a[1][1] == 2 && a[2][2] == 2) ||
      (a[0][2] == 2 && a[1][1] == 2 && a[2][0] == 2)) {
    return -1;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (a[i][j] == 0) {
        return 5;
      }
    }
  }
  return 0;
}

void playBoard(int board[][3]) {
  while (checkEnd(board) == 5) {
    // check x,y da co hay chua
    // CODE HERE
    while (true) {
      // nguoi danh
      cout << "Nhap vi tri danh: ";
      int x, y;
      cin >> x >> y;
      if (board[x][y] != 0) {
        board[x][y] = 2; // O
        break;
      }
      else {
        cout << "Vi tri da bi danh";
      }
    }
    // COM danh
    // find best move
    pair<int, int> bestMove = findBestMove(board);
    int x_may = bestMove.first;
    int y_may = bestMove.second;
    board[x_may][y_may] = 1;
    printBoard(board);
  }
  if (checkEnd(board) == 1) {
    cout << "You lose -__- ";
  } else if (checkEnd(board) == -1) {
    cout << "You win ^ ^";
  } else {
    cout << "#####";
  }
}

pair<int, int> findBestMove(int A[][3]) {
  int bestScore = -10000000;
  int score;
  pair<int, int> bestMove = make_pair(0, 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (A[i][j] == 0) {
        score = i + j; // find Minimax Function =>
        if (score > bestScore) {
          bestMove.first = i;
          bestMove.second = j;
        }
      }
    }
  }
  return bestMove;
}

int calMinimax(int board[][3], pair<int, int> curIndex) {
  if (checkEnd(board) != 5) {
  }
}
