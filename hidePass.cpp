#include "header.h"

// Function to disable terminal echo and set the terminal to non-canonical mode
void disableEcho() {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty);      // Get current terminal attributes

    tty.c_lflag &= ~(ECHO | ICANON);    // Disable ECHO and canonical mode (non-canonical input)
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);  // Apply the settings immediately
}

// Function to restore terminal settings (enable echo and canonical mode)
void restoreTerminal() {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty);      // Get current terminal attributes

    tty.c_lflag |= (ECHO | ICANON);     // Re-enable ECHO and canonical mode
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);  // Apply the settings immediately
}

// Function to get a hidden password from the terminal with '•' feedback
string hidePass() {
    string pass;
    char ch;

    disableEcho();  // Disable echo and set non-canonical mode

    // Read characters one-by-one
    while (true) {
        ch = getchar();  // Read a single character
        if (ch == '\n') {  // Check for Enter key (end of password input)
            break;
        } else if (ch == 127) {  // Handle backspace (ASCII code 127)
            if (!pass.empty()) {
                pass.pop_back();       // Remove the last character from the password
                cout << "\b \b";      // Move cursor back and overwrite the • character
            }
        } else {
            pass.push_back(ch);        // Add character to the password
            cout << "•";              // Output a • for each character typed
            cout.flush();             // Make sure the output is displayed immediately
        }
    }

    restoreTerminal();  // Restore terminal settings after input
    cout << endl;
    return pass;
}
