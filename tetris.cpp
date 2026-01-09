#include <iostream>
using namespace std;
#include <windows.h>

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

int nScreenWidth = 80; // Console Screen Size X (columns)
int nScreenHeight = 30; // Console Screen Size Y (rows)

int Rotate(int px, int py, int r) {
    switch (r % 4) {
        case 0: return py * 4 + px;             // 0 deg
        case 1: return 12 + py - (4 * px);      // 90 deg
        case 2: return 15 - (4 * py);           // 180 deg
        case 3: return 3 + py + (4 * px);       // 270 deg
    }
    return 0;
}

int main() {
    //creating assets
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");

    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");

    tetromino[5].append(L"....");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"....");
    tetromino[6].append(L"..XX");
    tetromino[6].append(L"..X.");
    tetromino[6].append(L"..X.");

    pField = new unsigned char[nFieldWidth*nFieldHeight]; // Create play area
    for (int x = 0; x < nFieldWidth; x++)// Board Boundary
        for (int y = 0; y < nFieldHeight; y++)
            pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;

    wchar_t * screen = new wchar_t[nScreenWidth*nScreenHeight];
    for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    LPDWORD dwBytesWritten = 0;


    // Display Frame
    WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, dwBytesWritten);

    return 0;

    //commentrgjoljdsfghjjfgh

}