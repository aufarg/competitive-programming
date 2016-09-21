#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<pair<string, string>, int> d;
    d[make_pair("cs", "Kamen")] = 0;
    d[make_pair("cs", "Nuzky")] = 1;
    d[make_pair("cs", "Papir")] = 2;
    d[make_pair("en", "Rock")] = 0;
    d[make_pair("en", "Scissors")] = 1;
    d[make_pair("en", "Paper")] = 2;
    d[make_pair("fr", "Pierre")] = 0;
    d[make_pair("fr", "Ciseaux")] = 1;
    d[make_pair("fr", "Feuille")] = 2;
    d[make_pair("de", "Stein")] = 0;
    d[make_pair("de", "Schere")] = 1;
    d[make_pair("de", "Papier")] = 2;
    d[make_pair("hu", "Ko")] = 0;
    d[make_pair("hu", "Koe")] = 0;
    d[make_pair("hu", "Ollo")] = 1;
    d[make_pair("hu", "Olloo")] = 1;
    d[make_pair("hu", "Papir")] = 2;
    d[make_pair("it", "Sasso")] = 0;
    d[make_pair("it", "Roccia")] = 0;
    d[make_pair("it", "Forbice")] = 1;
    d[make_pair("it", "Carta")] = 2;
    d[make_pair("it", "Rete")] = 2;
    d[make_pair("jp", "Guu")] = 0;
    d[make_pair("jp", "Choki")] = 1;
    d[make_pair("jp", "Paa")] = 2;
    d[make_pair("pl", "Kamien")] = 0;
    d[make_pair("pl", "Nozyce")] = 1;
    d[make_pair("pl", "Papier")] = 2;
    d[make_pair("es", "Piedra")] = 0;
    d[make_pair("es", "Tijera")] = 1;
    d[make_pair("es", "Papel")] = 2;

    int ta[3][3] = {
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 1, 0, 0 },
    };

    int tb[3][3] = {
        { 0, 0, 1 },
        { 1, 0, 0 },
        { 0, 1, 0 },
    };
    int a = 0, b = 0;
    string s, t;
    string ls, lt;
    int game = 0;
    int n_game = 0;
    while (true) {
        string in;
        getline(cin, in);
        if (in[0] == '-' || in[0] == '.') {
            printf("Game #%d:\n", ++n_game);
            cout << s << ": " << a << ((a == 1) ? " point" : " points") << endl;
            cout << t << ": " << b << ((b == 1) ? " point" : " points") << endl;
            if (a < b) cout << "WINNER: " << t << endl;
            if (a > b) cout << "WINNER: " << s << endl;
            if (a == b) puts("TIED GAME");
            puts("");
            a = 0; b = 0;
            game = 0;
            if (in[0] == '.') return 0;
        }
        else {
            stringstream ss(in);
            if (game == 0) ss >> ls >> s;
            else if (game == 1) ss >> lt >> t;
            else {
                string n, m;
                ss >> n >> m;
                int l = d[make_pair(ls, n)], r = d[make_pair(lt, m)];
                a += ta[l][r];
                b += tb[l][r];
            }
            ++game;
        }
    }
    return 0;
}
