#include <iostream>

namespace DominoStatic {

	template <class T>
	void swap(T& a, T& b);

	struct Domino {
		int top;
		int bot;

		Domino(int top = 0, int bot = 0);
		~Domino();
		friend std::istream& operator >> (std::istream& stream, Domino& domino);
		friend std::ostream& operator << (std::ostream& stream, Domino& domino);
		friend bool operator == (Domino a, Domino b);
		friend bool operator > (Domino a, Domino b);
		friend bool operator == (int a, Domino b);
	};

	class DominoSet {
	private:
		static const int MAX_SIZE = 28;
		int curSize = 0;
		Domino dominos[MAX_SIZE];
		void put(static int index, static Domino domino);
	public:
		DominoSet();
		DominoSet(int count);
		DominoSet(int bot, int top);
		int getCurSize() const;
		int find(Domino domino) const;
		const Domino* getDominos() const;
		bool contains(Domino domino) const;
		void addRandom();
		void sort();
		void remove(Domino domino);
		void put(static Domino domino);
		DominoSet getSubset(int value);
		DominoSet openByNumber(const int number) const;
	};
}