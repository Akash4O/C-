#include <iostream>
#include <cstdlib> // For system()

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Clear screen on Windows
#else
    system("clear"); // Clear screen on Linux/macOS
#endif
}

int main() {
    cout << "This is the old screen content." << endl;
    cout << "Press Enter to clear the screen and show new content...";
    cin.get(); // Wait for the user to press Enter

    clearScreen(); // Clear the screen

    // Display new content
    cout << "This is the new screen content!" << endl;

    return 0;
}
