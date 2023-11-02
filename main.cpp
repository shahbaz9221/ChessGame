#include "chess.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Function prototypes

// Resets the chessboard to its initial state.
void reset(string board[8][8]);

// Displays the current state of the chessboard.
void displayboard(string board[8][8], int a, int b, int c, int d);

// Checks if Player 1 has won the game.
bool player1win(string board[8][8]);

// Checks if Player 2 has won the game.
bool player2win(string board[8][8]);

// Handles user input for making a move.
void moveinput(int &a, int &b, int &c, int &d, int &p1h1, int &p1h2, int &p2h1, int &p2h2, int &p1k, int &p2k);

// Handles castling for Player 1.
bool castling1(string board[8][8], int &p1h1, int &p1h2, int &p2h1, int &p2h2, int &p1k, int &p2k);

// Handles castling for Player 2.
bool castling2(string board[8][8], int &p2h1, int &p2h2, int &p2k);

// Validates a move's legality on the chessboard.
bool validmove(string board[8][8], int a, int b, int c, int d, int mod);

// Checks the state of the board after a move to determine if the current player is in check.
void checkboard(string board[8][8], int a, int b, int c, int d);

// Undoes the board state after a move to analyze check conditions.
void checkboardundo(string board[8][8], int a, int b, int c, int d);

// Checks if Player 1's king is in check.
bool check1(string board[8][8]);

// Checks if Player 2's king is in check.
bool check2(string board[8][8]);

// Checks for stalemate conditions.
bool stalemate(int smate);

// Replays the game to display previous moves.
void replay(string board[8][8], int r1, int r2, int r3, int r4);

// Resets the replay board.
void reset1(string board[8][8]);

/**
 * The main function that simulates a two-player chess game.
 * It includes player turns, move validation, castling, and checks for game outcomes.
 * After the game concludes, it provides an option to watch a replay of the match.
 *
 * @return 0 upon successful execution.
 */
int main() {
    int a = 3, b = 3, c = 4, d = 4, x = 0, y = 0, mod = 0;
    int k = 0;
    bool check;
    bool checkking = true;
    int sx[100], tx[100], sy[100], ty[100];
    int i = 0, j = 0;
    int p1h1 = 0, p1h2 = 0, p2h1 = 0, p2h2 = 0, p1k = 0, p2k = 0;
    int r1 = 0, r2 = 0, r3 = 0, r4 = 0, smate = 0, flag = 0;
    string board1[8][8];
    string board2[8][8];

    // Initialize the chessboard and display it.
    reset(board1);
    displayboard(board1, a, b, c, d);

    // Main game loop, alternating between player turns until the game ends.
    while (x == 0 && !player1win(board1) && !player2win(board1) && flag == 0) {
        mod = y % 2;
        if (mod == 0) {
            cout << endl << "   Player 1 turn " << endl;
        } else {
            cout << endl << "   Player 2 turn " << endl;
        }

        // Get and validate the user's move input.
        moveinput(a, b, c, d, p1h1, p1h2, p2h1, p2h2, p1k, p2k);
        if (a == 111) {
            // Handle castling if "a" is a special value.
            if (mod == 0) {
                castling1(board1, p1h1, p1h2, p2h1, p2h2, p1k, p2k);
                castlingdisplayboard(board1);
            } else {
                castling2(board1, p2h1, p2h2, p2k);
                castlingdisplayboard(board1);
            }
        } else {
            // Check if the move is valid.
            check = validmove(board1, a, b, c, d, mod);

            while (!check) {
                cout << "Invalid move. Try again: ";
                moveinput(a, b, c, d, p1h1, p1h2, p2h1, p2h2, p1k, p2k);
                check = validmove(board1, a, b, c, d, mod);
            }

            // Apply the valid move to the chessboard.
            checkboard(board1, a, b, c, d);

            if (mod == 0) {
                checkking = check1(board1);
                checkboardundo(board1, a, b, c, d);
            } else {
                checkking = check2(board1);
                checkboardundo(board1, a, b, c, d);
            }

            if (checkking) {
                // Update the move history and other variables.
                sx[i] = a;
                sy[i] = b;
                tx[i] = c;
                ty[i] = d;
                displayboard(board1, a, b, c, d);
                y++;
                i++;
            } else {
                cout << "In check ";
                if (!stalemate(smate)) {
                    cout << "Game ends ";
                    flag = 1;
                }
            }
        }
    }

    // Determine and display the game result.
    if (player1win(board1)) {
        cout << "Player 1 wins";
    }
    if (player2win(board1)) {
        cout << "Player 2 wins";
    }

    cout << endl << endl;

    // Provide an option to watch the replay.
    cout << "Do you want to watch the replay? Press 1 for yes, 2 for no: ";
    int replay1;
    cin >> replay1;
    if (replay1 == 1) {
        system("cls");
        reset1(board2);
        j = 0;

        // Replay the recorded moves.
        while (j < i - 1) {
            r1 = sx[j];
            r2 = sy[j];
            r3 = tx[j];
            r4 = ty[j];
            replay(board2, r1, r2, r3, r4);
            j++;
            Sleep(1000);
            system("cls");
        }
    }

    return 0;
}
