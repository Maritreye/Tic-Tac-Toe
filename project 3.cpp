#include <stdio.h>

char board[3][3]; // 3x3 Tic-Tac-Toe board
char Player = 'X'; 

void initialBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

int Win() {
    for (int i = 0; i < 3; i++) {
        
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1; 
        }
    }
    
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1; 
    }
    return 0; 
}

int BoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0; 
        }
    }
    return 1;
}

void switchPlayer() {
    Player = (Player == 'X') ? 'O' : 'X';
}

void Move() {
    int row, col;
    while (1) {
        printf("Player %c, enter row (1-3) and column (1-3): ",Player);
        scanf("%d %d", &row, &col);

        row--; col--;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = Player;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

int main() {
    initialBoard();
    printf("Welcome to Tic-Tac-Toe!\n");

    while (1) {
        printBoard();
        Move();
        
        if (Win()) {
            printBoard();
            printf("Player %c wins!\n", Player);
            break;
        }
        if (BoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        switchPlayer();
    }
   return 0;
}
