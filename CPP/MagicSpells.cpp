//
//  MagicSpells.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 26/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/magic-spells

#include <iostream>
#include <vector>
using namespace std;

class Spell {
private:
    string scrollName;
public:
    Spell(): scrollName("") { }
    Spell(string name): scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private: int power;
public:
    Fireball(int power): power(power) { }
    void revealFirepower(){
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private: int power;
public:
    Frostbite(int power): power(power) { }
    void revealFrostpower(){
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private: int power;
public:
    Thunderstorm(int power): power(power) { }
    void revealThunderpower(){
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private: int power;
public:
    Waterbolt(int power): power(power) { }
    void revealWaterpower(){
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal {
public:
    static string journal;
    static string read() {
        return journal;
    }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

    if(Fireball* fireBall = dynamic_cast<Fireball*>(spell)) {
        
        fireBall->revealFirepower();
    } else if(Frostbite* frostBite = dynamic_cast<Frostbite*>(spell)) {
        
        frostBite->revealFrostpower();
    } else if(Thunderstorm* thunderstorm = dynamic_cast<Thunderstorm*>(spell)) {
        
        thunderstorm->revealThunderpower();
    } else if(Waterbolt* waterbolt = dynamic_cast<Waterbolt*>(spell)) {

        waterbolt->revealWaterpower();
    } else {
        
        string spellRevealed = spell->revealScrollName();
        string spellRead = SpellJournal::read();
        
        unsigned long m = spellRevealed.length();
        unsigned long n = spellRead.length();
        
        int L[m + 1][n + 1];
        int i, j;
        
        for (i=0; i <= m; i++) {
            for (j=0; j<=n; j++) {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (spellRevealed[i-1] == spellRead[j-1])
                    L[i][j] = L[i-1][j-1] + 1;
                else
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
        
        cout << L[m][n] << endl;
    }
}

class Wizard {
public:
    Spell *cast() {
        Spell *spell;
        string s; cin >> s;
        int power; cin >> power;
        if(s == "fire") {
            spell = new Fireball(power);
        }
        else if(s == "frost") {
            spell = new Frostbite(power);
        }
        else if(s == "water") {
            spell = new Waterbolt(power);
        }
        else if(s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}

