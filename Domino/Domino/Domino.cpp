#include "DominoStatic.h"

using namespace DominoStatic;

template <class T>
bool getNum(T& a) {
	std::cin >> a;
	if (!std::cin.good()) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		return false;
	}
	return true;
}

int getInt() {
	int a;
	while (true) {
		bool k = getNum(a);
		if (k)
			break;
		std::cout << "TRY AGAIN!" << std::endl;
	}
	return a;
}

void menu() {
	int choice;
	DominoSet set, subSet;
	Domino domino;
	int value;
	std::cout << "CREATED DEFAULT DOMINO SET." << std::endl;
	while (true) {
		std::cout << std::endl << "\t1. Add random domino." << std::endl;
		std::cout << "\t2. Remove." << std::endl;
		std::cout << "\t3. Open domino (get set with 1 element)." << std::endl;
		std::cout << "\t4. Sort." << std::endl;
		std::cout << "\t5. Get subset with value." << std::endl;
		std::cout << "\t6. Show all dominos and their numbers." << std::endl;
		std::cout << "\t7. Exit." << std::endl;
		choice = getInt();
		
		switch (choice) {
		case 1:
			set.addRandom();
			break;
		case 2:
			std::cout << "Input bot and top of domino: ";
			std::cin >> domino;
			set.remove(domino);
			break;
		case 3:
			std::cout << "Input number: ";
			value = getInt();
			subSet = set.openByNumber(value);
			domino = subSet.getDominos()[0];
			std::cout << domino;
			break;
		case 4:
			set.sort();
			break;
		case 5:
			std::cout << "Input value: ";
			value = getInt();
			subSet = set.getSubset(value);
			for (int i = 0; i < subSet.getCurSize(); i++) {
				domino = subSet.getDominos()[i];
				std::cout << i << ". " << domino;
			}
			break;
		case 6:
			for (int i = 0; i < set.getCurSize(); i++) {
				domino = set.getDominos()[i];
				std::cout << i << ". " << domino;
			}
			break;
		case 7:
			return;
			break;
		default:
			break;
		}
	}
}

int main()
{
	menu();
}
