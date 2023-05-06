#include <ctime>
#include <iostream>
#include <random>
using namespace std;
int main()
{
    default_random_engine randomGen(time(0));
    uniform_int_distribution<int>attackrollcat(0, 10);
    uniform_int_distribution<int>attackrollhooman(0, 11);
    cout << "====NOW THE EPIC BATLE BETWEN HOOMANS AND CATS SHALL BEGIN===== \n";
    int nrhoomans, nrcats;
    cout << "The hooman input is  ";
    cin >> nrhoomans;
    cout << "The cat input is ";
    cin >> nrcats;
    int healthcat = 900;
    int healthhooman = 100;
    int copie1 = healthcat;
    int copie2 = healthhooman;
    int attack1, attack2;
    int deadcat = 0;
    int deadhooman = 0;
    cout << "=========battle noises intensify =========\n \n";
    while (nrcats > 0 && nrhoomans > 0) {
        attack1 = attackrollcat(randomGen);
        healthhooman -= attack1;
        attack2 = attackrollhooman(randomGen);
        healthcat -= attack2;
        if (healthcat <= 0) {
            nrcats--;
            healthcat = copie1;
            deadcat++;
        }
        if (healthhooman <= 0) {
            nrhoomans--;
            healthhooman = copie2;
            deadhooman++;
        }
    }
    if (nrhoomans <= 0 && nrcats <= 0) {
        cout << "draw( i wish the cats would have won ) :( \n \n";
    }
    else if (nrhoomans <= 0) {
        cout << "CAT WON YAAAAAAAAAAAAAAY \n \n";
    }
    else {
        cout << "hoomans won :( \n \n";
    }
    cout << deadhooman << " hoomans died and " << deadcat << " loaf of bread have died \n";
}