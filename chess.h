#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

// Function to reset the chessboard to its initial state.
// The board is represented as a 2D array of strings.
// Each piece is represented by a three-character string, e.g., " r " for a black rook.
void reset(string board[8][8])
{
	// Initialize the chessboard with the starting positions of pieces.
	// Black pieces are represented with lowercase letters, and white pieces with uppercase.
	// " " represents an empty square on the board.
	board[0][0] = " r ";
	board[0][1] = " k ";
	board[0][2] = " b ";
	board[0][3] = " Q ";
	board[0][4] = " K ";
	board[0][5] = " b ";
	board[0][6] = " k ";
	board[0][7] = " r ";
	board[1][0] = " p ";
	board[1][1] = " p ";
	board[1][2] = " p ";
	board[1][3] = " p ";
	board[1][4] = " p ";
	board[1][5] = " p ";
	board[1][6] = " p ";
	board[1][7] = " p ";
	// Initialize empty squares in the middle rows.
	for (int row = 2; row <= 5; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			board[row][col] = "   ";
		}
	}
	// Initialize white pieces in the last two rows.
	board[6][0] = "<p>";
	board[6][1] = "<p>";
	board[6][2] = "<p>";
	board[6][3] = "<p>";
	board[6][4] = "<p>";
	board[6][5] = "<p>";
	board[6][6] = "<p>";
	board[6][7] = "<p>";
	board[7][0] = "<r>";
	board[7][1] = "<k>";
	board[7][2] = "<b>";
	board[7][3] = "<Q>";
	board[7][4] = "<K>";
	board[7][5] = "<b>";
	board[7][6] = "<k>";
	board[7][7] = "<r>";
}

// Function to reset a second board (board2) with the same initial state as the main board.
void reset1(string board2[8][8])
{
	reset(board2); // Call the reset function to initialize board2.
}

/**
 * Prompt the user to input the source (sx, sy) and target (tx, ty) coordinates for a chess move.
 * Update the piece counts for both players based on specific source locations.
 *
 * @param sx - Reference to the row of the source position.
 * @param sy - Reference to the column of the source position.
 * @param tx - Reference to the row of the target position.
 * @param ty - Reference to the column of the target position.
 * @param p1h1 - Reference to the count of player 1's left rooks.
 * @param p1h2 - Reference to the count of player 1's right rooks.
 * @param p2h1 - Reference to the count of player 2's left rooks.
 * @param p2h2 - Reference to the count of player 2's right rooks.
 * @param p1k - Reference to the count of player 1's kings.
 * @param p2k - Reference to the count of player 2's kings.
 */
void moveinput(int &sx, int &sy, int &tx, int &ty, int &p1h1, int &p1h2, int &p2h1, int &p2h2, int &p1k, int &p2k)
{
	cout << "Source input: ";
	cin >> sx >> sy;
	cout << "Target input: ";
	cin >> tx >> ty;

	// Update piece counts when a move is made from specific locations.
	if (sx == 0 && sy == 0)
		p1h1++;
	if (sx == 0 && sy == 7)
		p1h2++;
	if (sx == 7 && sy == 0)
		p2h1++;
	if (sx == 7 && sy == 7)
		p2h2++;
	if (sx == 0 && sy == 4)
		p1k++;
	if (sx == 7 && sy == 4)
		p2k++;
}

/**
 * Display the current state of the chessboard after a move, with the updated source and target coordinates.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @param a - The row of the piece's source position.
 * @param b - The column of the piece's source position.
 * @param c - The row of the piece's target position.
 * @param d - The column of the piece's target position.
 */
void displayboard(string board[8][8], int a, int b, int c, int d)
{
	board[c][d] = board[a][b];
	board[a][b] = "   "; // Clear the source square.

	cout << endl;
	cout << "      0   1   2   3   4   5   6   7" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "    !---!---!---!---!---!---!---!---!" << endl;
		cout << "  " << i << " " << char(179);
		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j];
			cout << char(179);
		}
		cout << endl;
		cout << "    " << char(179);
		for (int j = 0; j < 8; j++)
		{
			cout << ' ' << ' ' << ' ';
			cout << char(179);
		}
		cout << endl;
	}
	cout << "    |---|---|---|---|---|---|---|---|" << endl;
}

// Function to display the board after castling.
void castlingdisplayboard(string board[8][8])
{
	// Set the castling flag to true to indicate that castling is being displayed.
	bool isCastling = true;

	// Call the displayboard function with the castling flag set to true.
	displayboard(board, 0, 0, 0, 0, isCastling);
}
// Function to determine the current player's turn.
// It takes 'a' as a reference to update it.
int playerturn(int &a)
{

	if (a % 2 == 0)
		return 0;
	else
		return 1;
	a = a + 1;
}

/**
 * Check if a move from the source position (sx, sy) to the target position (tx, ty) is valid.
 * @param board The chessboard represented as a 2D array of strings.
 * @param sx The source row index.
 * @param sy The source column index.
 * @param tx The target row index.
 * @param ty The target column index.
 * @param m The player's turn (0 for black, 1 for white).
 * @return True if the move is valid, false otherwise.
 */
bool validmove(std::string board[8][8], int sx, int sy, int tx, int ty, int m) {
    std::string source = board[sx][sy];
    std::string target = board[tx][ty];

    if (m == 0) { // For player 1 (black pieces)
        if (source == " p ") { // Pawn
            if (ty == sy && (tx - sx == 1 || tx - sx == -1) && target == "   ") {
                return true;
            }
            if ((ty - sy == 1 || ty - sy == -1) && (tx - sx == 1 || tx - sx == -1) && target != "   " && target != " p " &&
                target != " r " && target != " Q " && target != " k " && target != " K " && target != " b ") {
                return true;
            }
            if (sx == 1 && (sx - tx == 2 || sx - tx == -2) && target == "   ") {
                return true;
            } else {
                return false;
            }
        } else if (source == " k ") { // Knight
            int dx = abs(tx - sx);
            int dy = abs(ty - sy);
            if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
                return true;
            }
        } else if (source == " b ") { // Bishop
            int dx = abs(tx - sx);
            int dy = abs(ty - sy);
            if (dx == dy) {
                int stepX = (tx > sx) ? 1 : -1;
                int stepY = (ty > sy) ? 1 : -1;
                int i = sx + stepX;
                int j = sy + stepY;
                while (i != tx) {
                    if (board[i][j] != "   ") {
                        return false;
                    }
                    i += stepX;
                    j += stepY;
                }
                return true;
            }
        } else if (source == " Q ") { // Queen
            int dx = abs(tx - sx);
            int dy = abs(ty - sy);
            if (dx == dy) { // Diagonal movement
                int stepX = (tx > sx) ? 1 : (tx < sx) ? -1 : 0;
                int stepY = (ty > sy) ? 1 : (ty < sy) ? -1 : 0;
                int i = sx + stepX;
                int j = sy + stepY;
                while (i != tx) {
                    if (board[i][j] != "   ") {
                        return false;
                    }
                    i += stepX;
                    j += stepY;
                }
                return true;
            } else if (tx == sx || ty == sy) { // Straight movement
                int stepX = (tx > sx) ? 1 : (tx < sx) ? -1 : 0;
                int stepY = (ty > sy) ? 1 : (ty < sy) ? -1 : 0;
                int i = sx + stepX;
                int j = sy + stepY;
                while (i != tx || j != ty) {
                    if (board[i][j] != "   ") {
                        return false;
                    }
                    i += stepX;
                    j += stepY;
                }
                return true;
            }
        } else if (source == " r ") { // Rook
            if (tx == sx || ty == sy) { // Straight movement
                int stepX = (tx > sx) ? 1 : (tx < sx) ? -1 : 0;
                int stepY = (ty > sy) ? 1 : (ty < sy) ? -1 : 0;
                int i = sx + stepX;
                int j = sy + stepY;
                while (i != tx || j != ty) {
                    if (board[i][j] != "   ") {
                        return false;
                    }
                    i += stepX;
                    j += stepY;
                }
                return true;
            }
        } else if (source == " K ") { // King
            int dx = abs(tx - sx);
            int dy = abs(ty - sy);
            if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1)) {
                return true;
            }
        }
    } else { // For player 2 (white pieces)
        if (source == "<p>") { // Pawn
            int dx = tx - sx;
            int dy = ty - sy;
            if (dx == -1 && dy == 0 && target == "   ") {
                return true;
            }
            if (dx == -1 && abs(dy) == 1 && target != "  " && target != "<p>" &&
                target != "<r>" && target != "<Q>" && target != "<k>" && target != "<K>" && target != "<b>") {
                return true;
            }
            if (sx == 6 && dx == -2 && dy == 0 && target == "   ") {
                return true;
            }
        } else if (source == "<k>") { // Knight
            int dx = abs(tx - sx);
            int dy = abs(ty - sy);
            if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
                return true;
            }
        } else if (source == "<b>") { // Bishop
            int dx = abs(tx - sx);
            int dy = abs(ty - sy);
            if (dx == dy) {
                int stepX = (tx > sx) ? 1 : -1;
                int stepY = (ty > sy) ? 1 : -1;
                int i = sx + stepX;
                int j = sy + stepY;
                while (i != tx) {
                    if (board[i][j] != "   ") {
                        return false;
                    }
                    i += stepX;
                    j += stepY;
                }
                return true;
            }
        } else if (source == "<r>") { // Rook
            if (tx == sx || ty == sy) {
                int stepX = (tx > sx) ? 1 : (tx < sx) ? -1 : 0;
                int stepY = (ty > sy) ? 1 : (ty < sy) ? -1 : 0;
                int i = sx + stepX;
                int j = sy + stepY;
                while (i != tx || j != ty) {
                    if (board[i][j] != "   ") {
                        return false;
                    }
                    i += stepX;
                    j += stepY;
                }
                return true;
            }
        } else if (source == "<K>") { // King
            int dx = abs(tx - sx);
            int dy = abs(ty - sy);
            if (dx <= 1 && dy <= 1) {
                return true;
            }
        } else if (source == "<Q>") { // Queen
            int dx = abs(tx - sx);
            int dy = abs(ty - sy);
            if (dx == dy) {
                int stepX = (tx > sx) ? 1 : (tx < sx) ? -1 : 0;
                int stepY = (ty > sy) ? 1 : (ty < sy) ? -1 : 0;
                int i = sx + stepX;
                int j = sy + stepY;
                while (i != tx) {
                    if (board[i][j] != "   ") {
                        return false;
                    }
                    i += stepX;
                    j += stepY;
                }
                return true;
            } else if (tx == sx || ty == sy) {
                int stepX = (tx > sx) ? 1 : (tx < sx) ? -1 : 0;
                int stepY = (ty > sy) ? 1 : (ty < sy) ? -1 : 0;
                int i = sx + stepX;
                int j = sy + stepY;
                while (i != tx || j != ty) {
                    if (board[i][j] != "   ") {
                        return false;
                    }
                    i += stepX;
                    j += stepY;
                }
                return true;
            }
        }
    }

    return false; // Invalid move
}

/**
 * Check if Player 1 (the first player) has won the game by determining whether their king (" K ") is present on the chessboard.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @return True if Player 1 has won (king is not present), false otherwise (king is present).
 */
bool player1win(const std::string board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == "<K>") {
                return false;
            }
        }
    }
    return true;
}

/**
 * Check if Player 2 (the second player) has won the game by determining whether their king (" K ") is present on the chessboard.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @return True if Player 2 has won (king is not present), false otherwise (king is present).
 */
bool player2win(const std::string board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == " K ") {
                return false;
            }
        }
    }
    return true;
}

/**
 * Replay a chess move on the provided chessboard. This function moves a piece from a source position
 * (sx1, sy1) to a target position (tx1, ty1) on the chessboard (board2). It updates the chessboard
 * by moving the piece to the new position and clearing the source position.
 *
 * @param board2 - The chessboard represented as a 2D array of strings.
 * @param sx1 - The row of the source position.
 * @param sy1 - The column of the source position.
 * @param tx1 - The row of the target position.
 * @param ty1 - The column of the target position.
 */
void replay(std::string board2[8][8], int& sx1, int& sy1, int& tx1, int& ty1) {
    board2[tx1][ty1] = board2[sx1][sy1];
    board2[sx1][sy1] = "   ";
}

/**
 * Handle castling for player 1. Castling is a special chess move that involves the king
 * and one of the rooks. It allows the player to move the king two squares towards a rook
 * on the player's first rank, then move the rook to the square the king crossed over.
 * Castling is a legal move only under the following conditions:
 * 1. The king and the chosen rook have not previously moved.
 * 2. The squares between the king and the chosen rook are unoccupied.
 * 3. The king is not in check.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @param p1h1 - Flag indicating whether player 1's left rook has moved before.
 * @param p1h2 - Flag indicating whether player 1's right rook has moved before.
 * @param p2h1 - Flag indicating whether player 2's left rook has moved before.
 * @param p2h2 - Flag indicating whether player 2's right rook has moved before.
 * @param p1k - Flag indicating whether player 1's king has moved before.
 * @param p2k - Flag indicating whether player 2's king has moved before.
 */
void castling1(std::string board[8][8], int& p1h1, int& p1h2, int& p2h1, int& p2h2, int& p1k, int& p2k) {
    int a = 0, b = 0;
    if (p1k == 0) {
        std::cout << "Enter position of rook: ";
        std::cin >> a >> b;
        if (a == 0 && (b == 0 || b == 7)) {
            if ((b == 0 && p1h1 == 0) || (b == 7 && p1h2 == 0)) {
                if (b == 0) {
                    if (board[0][1] == "   " && board[0][2] == "   " && board[0][3] == "   ") {
                        board[0][0] = "   ";
                        board[0][3] = " r ";
                        board[0][2] = " K ";
                        board[0][4] = "   ";
                    } else {
                        std::cout << "Invalid castling move. Pieces block the path." << std::endl;
                    }
                } else if (b == 7) {
                    if (board[0][5] == "   " && board[0][6] == "   ") {
                        board[0][4] = "   ";
                        board[0][5] = " r ";
                        board[0][6] = " K ";
                        board[0][7] = "   ";
                    } else {
                        std::cout << "Invalid castling move. Pieces block the path." << std::endl;
                    }
                }
            } else {
                std::cout << "Invalid castling move. Rook or king has moved before." << std::endl;
            }
        } else {
            std::cout << "Invalid castling move. Enter 0-0 or 0-7." << std::endl;
        }
    } else {
        std::cout << "Invalid castling move. King has moved before." << std::endl;
    }
}

/**
 * Handle castling for player 2. Castling is a special chess move that involves the king
 * and one of the rooks. It allows the player to move the king two squares towards a rook
 * on the player's first rank, then move the rook to the square the king crossed over.
 * Castling is a legal move only under the following conditions:
 * 1. The king and the chosen rook have not previously moved.
 * 2. The squares between the king and the chosen rook are unoccupied.
 * 3. The king is not in check.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @param p2h1 - Flag indicating whether player 2's left rook has moved before.
 * @param p2h2 - Flag indicating whether player 2's right rook has moved before.
 * @param p2k - Flag indicating whether player 2's king has moved before.
 */
void castling2(std::string board[8][8], int& p2h1, int& p2h2, int& p2k) {
    int a = 0, b = 0;
    if (p2k == 0) {
        std::cout << "Enter position of rook: ";
        std::cin >> a >> b;
        if (a == 7 && (b == 0 || b == 7)) {
            if ((b == 0 && p2h1 == 0) || (b == 7 && p2h2 == 0)) {
                if (b == 0) {
                    if (board[7][1] == "   " && board[7][2] == "   " && board[7][3] == "   ") {
                        board[7][0] = "   ";
                        board[7][3] = "<r>";
                        board[7][2] = "<K>";
                        board[7][4] = "   ";
                    } else {
                        std::cout << "Invalid castling move. Pieces block the path." << std::endl;
                    }
                } else if (b == 7) {
                    if (board[7][5] == "   " && board[7][6] == "   ") {
                        board[7][4] = "   ";
                        board[7][5] = "<r>";
                        board[7][6] = "<K>";
                        board[7][7] = "   ";
                    } else {
                        std::cout << "Invalid castling move. Pieces block the path." << std::endl;
                    }
                }
            } else {
                std::cout << "Invalid castling move. Rook or king has moved before." << std::endl;
            }
        } else {
            std::cout << "Invalid castling move. Enter 7-0 or 7-7." << std::endl;
        }
    } else {
        std::cout << "Invalid castling move. King has moved before." << std::endl;
    }
}

/**
 * Check if the king of player 1 is in check.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @return true if the king is in check, false otherwise.
 */
bool check1(std::string board[8][8]) {
    int x1 = 0, y1 = 0; // x for row, y for column
    int flag = 0;
    int a, b, x, y;

    // Find the position of the king
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == " K ") {
                x1 = i;
                y1 = j;
            }
        }
    }

    // Check horizontally to the right
    for (a = y1 + 1; a < 8; a++) {
        if ((board[x1][a] == "<Q>") || (board[x1][a] == "<r>")) {
            for (b = y1 + 1; b < a && flag == 0; b++) {
                if (board[x1][b] == "   ")
                    flag = 0;
                else
                    flag = 1;
            }
            if (flag == 0)
                return false;
        }
    }

    // Check horizontally to the left
    for (a = y1 - 1; a >= 0; a--) {
        if ((board[x1][a] == "<Q>") || (board[x1][a] == "<r>")) {
            for (b = y1 - 1; b > a && flag == 0; b--) {
                if (board[x1][b] == "   ")
                    flag = 0;
                else
                    flag = 1;
            }
            if (flag == 0)
                return false;
        }
    }

    // Check vertically downwards
    for (a = x1 + 1; a < 8; a++) {
        if ((board[a][y1] == "<Q>") || (board[a][y1] == "<r>")) {
            for (b = x1 + 1; b < a && flag == 0; b++) {
                if (board[b][y1] == "   ")
                    flag = 0;
                else
                    flag = 1;
            }
            if (flag == 0)
                return false;
        }
    }

    // Check vertically upwards
    for (a = x1 - 1; a >= 0; a--) {
        if ((board[a][y1] == "<Q>") || (board[a][y1] == "<r>")) {
            for (b = x1 - 1; b > a && flag == 0; b--) {
                if (board[b][y1] == "   ")
                    flag = 0;
                else
                    flag = 1;
            }
            if (flag == 0)
                return false;
        }
    }

    x = x1 + 1;
    // Check diagonally down and right (forward slash)
    for (b = y1 + 1; x < 8 && b < 8; x++, b++) {
        int x2 = x + 1, y2 = b + 1;
        if ((x2 - x) == (y2 - b)) {
            if ((board[x][b] == "<Q>") || (board[x][b] == "<b>")) {
                int c = x1 + 1;
                for (int d = y1 + 1; c < x && d < b && flag == 0; c++, d++) {
                    if (board[c][d] == "   ")
                        flag = 0;
                    else
                        flag = 1;
                }
                if (flag == 0)
                    return false;
            }
        }
    }

    x = x1 + 1;
    // Check diagonally down and left (backslash)
    for (b = y1 - 1; x < 8 && b >= 0; x++, b--) {
        int x2 = x + 1, y2 = b - 1;
        if ((x2 - x) == (b - y2)) {
            if ((board[x][b] == "<Q>") || (board[x][b] == "<b>")) {
                c = x1 + 1;
                for (int d = y1 - 1; c < x && d > b && flag == 0; c++, d--) {
                    if (board[c][d] == "   ")
                        flag = 0;
                    else
                        flag = 1;
                }
                if (flag == 0)
                    return false;
            }
        }
    }

    a = x1 - 1;
    // Check diagonally up and left
    for (b = y1 - 1; a >= 0 && b >= 0; a--, b--) {
        int x2 = a - 1, y2 = b - 1;
        if ((a - x2) == (b - y2)) {
            if (board[a][b] == "<b>" || board[a][b] == "<Q>") {
                x = x1 - 1;
                for (int y = y1 - 1; x > a && y > b && flag == 0; x--, y--) {
                    if (board[x][y] == "   ")
                        flag = 0;
                    else
                        flag = 1;
                }
                if (flag == 0)
                    return false;
            }
        }
    }

    x = x1 + 1;
    y = y1 + 1;

    // Check for threats from pawns and kings (for king's 8 neighboring squares)
    if (x1 > 0 && x1 < 7 && y1 > 0 && y1 < 7) {
        if ((board[x][y] == "<p>") || (board[x][y - 2] == "<p>") ||
            (board[x][y] == "<K>") || (board[x - 2][y - 2] == "<K>") ||
            (board[x - 1][y] == "<K>") || (board[x][y - 1] == "<K>") ||
            (board[x][y - 2] == "<K>") || (board[x - 1][y - 2] == "<K>") ||
            (board[x - 2][y - 1] == "<K>") || (board[x - 2][y] == "<K>"))
            return false;
    } else if (x1 == 0 && y1 == 0) {
        if (board[x][y] == "<p>" || board[x][y - 1] == "<K>" || board[x - 1][y] == "<K>" || board[x][y] == "<K>")
            return false;
    } else if (x1 == 0 && y1 == 7) {
        if (board[x][y - 2] == "<p>" || board[x - 1][y - 2] == "<K>" || board[x][y - 2] == "<K>" || board[x][y - 1] == "<K>")
            return false;
    } else if (x1 == 7 && y1 == 0) {
        if (board[x - 2][y - 1] == "<K>" || board[x - 2][y] == "<K>" || board[x - 1][y] == "<K>")
            return false;
    } else if (x1 == 7 && y1 == 7) {
        if (board[x - 2][y - 2] == "<K>" || board[x - 1][y - 2] == "<K>" || board[x - 2][y - 1] == "<K>")
            return false;
    } else if (x1 == 0 && y1 > 0 && y1 < 7) {
        if ((board[x][y] == "<p>") || (board[x][y - 2] == "<p>") || (board[x][y] == "<K>") ||
            (board[x][y - 1] == "<K>") || (board[x - 1][y - 2] == "<K>") || (board[x][y - 1] == "<K>") ||
            (board[x - 1][y] == "<K>"))
            return false;
    } else if (x1 == 7 && y1 > 0 && y1 < 7) {
        if ((board[x - 1][y] == "<K>") || (board[x - 1][y - 2] == "<K>") || (board[x - 2][y - 2] == "<K>") ||
            (board[x - 2][y - 1] == "<K>") || (board[x - 2][y] == "<K>"))
            return false;
    } else if (y1 == 0 && x1 > 0 && x1 < 7) {
        if ((board[x - 1][y] == "<K>") || (board[x][y] == "<K>") || (board[x - 2][y] == "<K>") ||
            (board[x][y - 1] == "<K>") || (board[x - 2][y - 1] == "<K>") || (board[x][y] == "<p>"))
            return false;
    } else if (y1 == 7 && x1 > 0 && x1 < 7) {
        if ((board[x - 2][y - 1] == "<K>") || (board[x - 2][y - 2] == "<K>") || (board[x - 1][y - 2] == "<K>") ||
            (board[x][y - 2] == "<K>") || (board[x][y - 1] == "<K>") || (board[x][y - 2] == "<p>"))
            return false;
    }

    x = x1;
    y = y1;

    // Check for threats from knights in 8 possible positions
    if (x > 1 && x < 6 && y > 1 && y < 6) {
        if (board[x - 2][y - 1] == "<k>" || board[x - 2][y + 1] == "<k>" || board[x - 1][y - 2] == "<k>" ||
            board[x - 1][y + 2] == "<k>" || board[x + 1][y - 2] == "<k>" || board[x + 1][y + 2] == "<k>" ||
            board[x + 2][y - 1] == "<k>" || board[x + 2][y + 2] == "<k>")
        {
            return false;
        }
    }

    // No threats found, king is not in check
    return true;
}


/**
 * Allows a player to promote a pawn to a higher-ranked piece (queen, rook, bishop, or knight).
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @param p1 - The row of the pawn's current position.
 * @param p2 - The column of the pawn's current position.
 * @param d1 - The row to move the pawn to (promotion rank).
 * @param d2 - The column to move the pawn to.
 * @param player - The current player (1 or 2).
 */
void promotePawn(std::string board[8][8], int p1, int p2, int d1, int d2, int player) {
    if ((player == 1 && board[p1][p2] == " p " && d1 == 7) ||
        (player == 2 && board[p1][p2] == "<p>" && d1 == 0)) {
        system("cls");  // Clear the console (for Windows)
        cout << "Make your choice" << endl;
        cout << "1 for queen" << endl;
        cout << "2 for rook" << endl;
        cout << "3 for bishop" << endl;
        cout << "4 for knight" << endl;
        int choice;
        cin >> choice;

        // Promote the pawn based on the player's choice
        switch (choice) {
            case 1:
                board[p1][p2] = (player == 1) ? " Q " : "<Q>";
                break;
            case 2:
                board[p1][p2] = (player == 1) ? " R " : "<r>";
                break;
            case 3:
                board[p1][p2] = (player == 1) ? " B " : "<b>";
                break;
            case 4:
                board[p1][p2] = (player == 1) ? " N " : "<n>";
                break;
            default:
                cout << "Invalid choice. The pawn remains unpromoted." << endl;
                break;
        }
    }
}

/**
 * Updates the chessboard by moving a piece from one position to another.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @param a - The row of the source position.
 * @param b - The column of the source position.
 * @param c - The row of the destination position.
 * @param d - The column of the destination position.
 */
void checkboard(std::string board[8][8], int a, int b, int c, int d) {
    board[c][d] = board[a][b];
    board[a][b] = "   ";
}

/**
 * Reverts the chessboard to its previous state by undoing a move.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @param a - The row of the source position (before the move).
 * @param b - The column of the source position (before the move).
 * @param c - The row of the destination position (before the move).
 * @param d - The column of the destination position (before the move).
 */
void checkboardundo(std::string board[8][8], int a, int b, int c, int d) {
    board[a][b] = board[c][d];
    board[c][d] = "   ";
}

/**
 * Checks if the opponent's king is under a threat from any of the player's pieces.
 *
 * @param board - The chessboard represented as a 2D array of strings.
 * @return True if the opponent's king is not under a direct threat, false if threatened.
 */
bool check2(std::string board[8][8]) {
    int x1 = 0, y1 = 0, flag = 0;

    // Find the opponent's king's position
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == "<K>") {
                x1 = i;
                y1 = j;
            }
        }
    }

    int x, y;

    // Check for threats along the vertical (up and down) and horizontal (left and right) directions
    for (x = x1 - 1; x >= 0; x--) {
        if (board[x][y1] == " Q " || board[x][y1] == " r ") {
            for (int b = x1 - 1; b > x && flag == 0; b--) {
                if (board[b][y1] == "   ") {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) return false;
        }
    }

    flag = 0;
    for (x = x1 + 1; x <= 7; x++) {
        if (board[x][y1] == " Q " || board[x][y1] == " r ") {
            for (int b = x1 + 1; b < x && flag == 0; b++) {
                if (board[b][y1] == "   ") {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) return false;
        }
    }

    flag = 0;
    for (y = y1 + 1; y < 8; y++) {
        if (board[x1][y] == " Q " || board[x1][y] == " r ") {
            for (int b = y1 + 1; b < 8 && flag == 0; b++) {
                if (board[x1][b] == "   ") {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) return false;
        }
    }

    flag = 0;
    for (y = y1 - 1; y >= 0; y--) {
        if (board[x1][y] == " Q " || board[x1][y] == " r ") {
            for (int b = y1 - 1; b > y && flag == 0; b--) {
                if (board[x1][b] == "   ") {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) return false;
        }
    }

    // Check for threats along the diagonals ("/" and "\") directions
    flag = 0;
    for (x = x1 - 1, y = y1 + 1; x >= 0 && y < 8; x--, y++) {
        if (board[x][y] == " Q " || board[x][y] == " b ") {
            a = x1 - 1;
            for (int b = y1 + 1; a > x && flag == 0; b++, a--) {
                if (board[a][b] == "   ") {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) return false;
        }
    }

    flag = 0;
    for (x = x1 - 1, y = y1 - 1; x >= 0 && y >= 0; x--, y--) {
        if (board[x][y] == " Q " || board[x][y] == " b ") {
            a = x1 - 1;
            for (int b = y1 - 1; a > x && flag == 0; b--, a--) {
                if (board[a][b] == "   ") {
                    flag = 0;
                } else {
                    flag = 1;
                }
            }
            if (flag == 0) return false;
        }
    }

    // Check for knight threats
    x = x1 + 1;
    y = y1 + 1;
    if (x1 > 0 && x1 < 7 && y1 > 0 && y1 < 7) {
        if (board[x - 2][y] == " p " || board[x - 2][y - 2] == " K " || board[x - 2][y - 2] == " K " ||
            board[x - 1][y] == " K " || board[x][y - 1] == " K " || board[x][y - 2] == " K " ||
            board[x - 1][y - 2] == " K " || board[x - 2][y - 1] == " K " || board[x - 2][y] == " K ") {
            return false;
        }
    } else if (x1 == 0 && y1 == 0) {
        if (board[x][y - 1] == " K " || board[x - 1][y] == " K " || board[x][y] == " K ") return false;
    } else if (x1 == 0 && y1 == 7) {
        if (board[x - 1][y - 2] == " K " || board[x][y - 2] == " K " || board[x][y - 1] == " K ") return false;
    } else if (x1 == 7 && y1 == 0) {
        if (board[x - 2][y - 1] == " K " || board[x - 2][y] == " K " || board[x - 1][y] == " K ") return false;
    } else if (x1 == 7 && y1 == 7) {
        if (board[x - 2][y - 2] == " K " || board[x - 1][y - 2] == " K " || board[x - 2][y - 1] == " K ") return false;
    } else if (x1 == 0 && y1 > 0 && y1 < 7) {
        if (board[x][y] == " K " || board[x][y - 1] == " K " || board[x - 1][y - 2] == " K " ||
            board[x][y - 1] == " K " || board[x - 1][y] == " K ") return false;
    } else if (x1 == 7 && y1 > 0 && y1 < 7) {
        if (board[x - 1][y] == " K " || board[x - 1][y - 2] == " K " || board[x - 2][y - 2] == " K " ||
            board[x - 2][y - 1] == " K " || board[x - 2][y] == " K ") return false;
    } else if (y1 == 0 && x1 > 0 && x1 < 7) {
        if (board[x - 1][y] == " K " || board[x][y] == " K " || board[x - 2][y] == " K " ||
            board[x][y - 1] == " K " || board[x - 2][y - 1] == " K ") return false;
    } else if (y1 == 7 && x1 > 0 and x1 < 7)
    {
        if (board[x - 2][y - 1] == " K " || board[x - 2][y - 2] == " K " || board[x - 1][y - 2] == " K " || board[x][y - 2] == " K " || board[x][y - 1] == " K ")
            return false;
    }

    x = x1;
    y = y1;

    // Check for knight threats in the remaining positions
    if (x > 1 && x < 6 && y > 1 && y < 6) {
        if (board[x - 2][y - 1] == " k " || board[x - 2][y + 1] == " k " || board[x - 1][y - 2] == " k " ||
            board[x - 1][y + 2] == " k " || board[x + 1][y - 2] == " k " || board[x + 1][y + 2] == " k " ||
            board[x + 2][y - 1] == " k " || board[x + 2][y + 1] == " k ") {
            return false;
        }
    }

    return true;
}


/**
 * Determines if a stalemate condition is reached and increments the turn counter.
 *
 * @param i - The turn counter (updated by reference).
 * @return True if the game continues, false if a stalemate condition is met.
 */
bool stalemate(int &i) {
    i = i + 1; // Increment the turn counter.

    if (i > 2) {
        // If the turn counter exceeds 2, it's not a stalemate.
        return false;
    } else {
        // If the turn counter is 2 or less, it's a stalemate.
        // Note that the code below this point is unreachable and has no effect.
        return true;
        i = 0; // This line is unreachable code and won't be executed.
    }
}
