#include <iostream>
using namespace std;
void scores(int, int, int, int);
class game
{
private:
    char arr[4][4] = {{'T', '1', '2', '3'}, {'1', '_', '_', '_'}, {'2', '_', '_', '_'}, {'3', '_', '_', '_'}};
    int row, column;

public:
    int flag = 0, checkpass = 0;
    void inidisplay();
    void win1();
    void win2();
    void setvar(char c)
    {
        while (1)
        {
            cout << "Enter Row Number (1-3) : ";
            cin >> row;
            cout << "Enter Column Number (1-3) : ";
            cin >> column;
            if ((arr[row][column] == 'X' || arr[row][column] == 'O') || row > 3 || row < 1 || column > 3 || column < 1)
            {
                if (row > 3 || row < 1)
                {
                    cout << "Invalid Input of Row" << endl;
                }
                if (column > 3 || column < 1)
                {
                    cout << "Invalid Input of Column" << endl;
                }
                if (arr[row][column] == 'X' || arr[row][column] == 'O')
                {
                    cout << "Cell Already Filled...." << endl;
                }
            }
            else
            {
                arr[row][column] = c;
                break;
            }
        }
    }
};
void game::win1()
{
    for (int i = 0; i < 4; i++)
    {

        if (arr[i][1] == 'X' && arr[i][2] == 'X' && arr[i][3] == 'X')
        {
            flag = 1;
            break;
        }
        if (arr[1][i] == 'X' && arr[2][i] == 'X' && arr[3][i] == 'X')
        {
            flag = 1;
            break;
        }
    }
    if (arr[1][3] == 'X' && arr[2][2] == 'X' && arr[3][1] == 'X')
    {
        flag = 1;
    }
    else if (arr[1][1] == 'X' && arr[2][2] == 'X' && arr[3][3] == 'X')
    {
        flag = 1;
    }
}
void game::win2()
{
    for (int i = 1; i < 4; i++)
    {

        if (arr[i][1] == 'O' && arr[i][2] == 'O' && arr[i][3] == 'O')
        {
            flag = 1;
            break;
        }
        if (arr[1][i] == 'O' && arr[2][i] == 'O' && arr[3][i] == 'O')
        {
            flag = 1;
            break;
        }
    }
    if (arr[1][3] == 'O' && arr[2][2] == 'O' && arr[3][1] == 'O')
    {
        flag = 1;
    }
    else if (arr[1][1] == 'O' && arr[2][2] == 'O' && arr[3][3] == 'O')
    {
        flag = 1;
    }
}
void game::inidisplay()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
int player1 = 0, player2 = 0, tied = 0, played = 0, l = 0;
void letsplay()
{
    game play;
    played++;
    play.inidisplay();
    while (1)
    {
        l++;
        cout << l << endl;
        cout << "Player One Turn : " << endl;
        play.setvar('X');
        play.inidisplay();
        play.win1();
        if (play.flag == 1)
        {
            cout << "Player One Won!!!..." << endl;
            player1++;
            break;
        }
        cout << "______________________________________________________________" << endl;

        if (l >= 9)
        {
            break;
        }
        l++;
        cout << l << endl;
        cout << "Player Two Turn : " << endl;
        play.setvar('O');
        play.inidisplay();
        play.win2();
        if (play.flag == 1)
        {
            cout << "Player Two Won!!!..." << endl;
            player2++;
            break;
        }
        cout << "______________________________________________________________" << endl;
    }
    if (play.flag == 0)
    {
        cout << "Match Tied Please Try Again" << endl;
        tied++;
    }
    scores(played, player1, player2, tied);
}
void scores(int played, int player1, int player2, int tied)
{
    cout << "\n\n\n______________________________________________________________" << endl;
    cout << "Your Scores Are :" << endl;
    cout << "Match Played : " << played << endl;
    cout << "Player 1 : " << player1 << endl;
    cout << "Player 2 : " << player2 << endl;
    cout << "Match Tied : " << tied << endl;
    cout << "______________________________________________________________\n\n\n"
         << endl;
}
int main()
{
    int choice = 0;
    while (1)
    {
        l = 0;
        letsplay();
        cout << "To Continue Press Any Key And To Exit Press 0 : ";
        cin >> choice;
        if (choice == 0)
        {
            if (player1 > player2)
            {
                cout << "Playe 1 Won the session" << endl;
            }
            else if (player1 < player2)
            {
                cout << "Playe 2 Won the session" << endl;
            }
            else
            {
                cout << "Session Tied....";
            }
            cout << "Thank You See You Next Time" << endl;
            break;
        }
    }
    return 0;
}