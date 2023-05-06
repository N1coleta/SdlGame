#include <random>
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	default_random_engine randomGen(time(NULL));
	uniform_real_distribution<float>attackroll(0.0f, 1.0f);
	float attack;
	int snakeHealth = 100;
	int cnt = 0;
	while (snakeHealth > 0) {
		attack = attackroll(randomGen);
		if (attack <= 0.3f) {
			cout << "The snake will fall to the legendary cat!!! :)\n";
			snakeHealth -= 10;
			cnt++;
		}
		else {
			cout << "NOOOOOOOO. U missed. :(\n";
			cnt++;
		}
	}
	cout << cnt;

}
