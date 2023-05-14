#include<iostream>
#include "MainGame.h"
using namespace std;
int main(int argc, char ** argv)
{
	MainGame mg;
	mg.run();
	int a;
	cout << "Enter any key if cat is fluffy ";
	cin >> a;
	return 0;
}