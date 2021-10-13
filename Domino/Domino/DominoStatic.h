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
		friend bool operator == (const Domino a, const Domino b);
		friend bool operator > (const Domino a, const Domino b);
		friend bool operator == (const int a, const Domino b);
	};

	class DominoSet {
	private:
		static const int MAX_SIZE = 28;
		int curSize = 0;
		Domino dominos[MAX_SIZE];
		void put(static int index, static Domino domino);
	public:
		//DominoSet();
		DominoSet(const int count);
		DominoSet(const int bot, const int top);
		DominoSet(Domino domino = Domino(0, 0));
		int getCurSize() const;
		int find(const Domino domino) const;
		const Domino* getDominos() const;
		bool contains(const Domino domino) const;
		void addRandom();
		void sort();
		void remove(const Domino domino);
		void put(static Domino domino);
		DominoSet getSubset(const int value) const;
		DominoSet openByNumber(const int number) const;
		friend DominoSet& operator ++ (DominoSet& set);
		friend void operator + (DominoSet& set, Domino domino);
		friend void operator - (DominoSet& set, Domino domino);
	};
}