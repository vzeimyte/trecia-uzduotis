#include <iostream>
#include <fstream>
#include <array>

using namespace std;
int main()
{
    // string title;
    // string profesija;
    string photo_url;
    string nav_mygtukai[3];

    // cout << "Jusu vardas ir pavarde (Privaloma): ";
    // getline(cin, title);

    // cout << "\nJusu dabartine arba anorima profesija: ";
    // getline(cin, profesija);

    cout << "\nJusu nuotraukos URL nuoroda: ";
    cin >> photo_url;

    cout << "\n Suveskite 3 norimos navigacinius mygtukus\n";

    cin.ignore();

    for (int i = 0; i < 3; i++)
    {
        getline(cin, nav_mygtukai[i]);
    }
    cout << "\n\n vedimas baigtas\n\n";

    for (int i = 0; i < 3; i++)
    {
        cout << i << nav_mygtukai[i] << endl;
    }
}