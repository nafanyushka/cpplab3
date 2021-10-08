#include "DominoStatic.h"

int main()
{
	using namespace DominoStatic;
	int a = 28;
	DominoSet set(a);
	for (int i = 0; i < a; i++) {
		Domino d = set.getDominos()[i];
		std::cout << d;
	}
	
	std::cout << "SORTING!" << std::endl;

	set.sort();
	
	for (int i = 0; i < a; i++) {
		Domino d = set.getDominos()[i];
		std::cout << d;
	}
}
