#include "DominoStatic.h"

namespace DominoStatic {

	template <class T>
	void swap(T& a, T& b) {
		T p = a;
		a = b;
		b = p;
	}

	//ÌÅÒÎÄÛ ÑÒÐÓÊÒÓÐÛ ÎÄÍÎÉ ÄÎÌÈÍÎØÊÈ
	Domino::Domino(int bot, int top) : bot(bot), top(top) {
		if (bot > 7 || top > 7 || top < 0 || bot < 0)
			throw std::runtime_error("BAD VARIABLES!");
		if(bot > top)
			swap(this->bot, this->top);
		
	}

	Domino::~Domino()
	{
	}

	std::istream& operator>>(std::istream& stream, Domino& domino)
	{
		stream >> domino.bot >> domino.top;
		if (stream.good()) {
			if (domino.bot > 6 || domino.bot < 0 || domino.top > 6 || domino.top < 0)
				stream.setstate(std::ios::failbit);
			else {
				if (domino.bot > domino.top)
					swap(domino.bot, domino.top);
			}
		}
		return stream;
	}

	std::ostream& operator<<(std::ostream& stream, Domino& domino)
	{
		stream << "(" << domino.bot << ", " << domino.top << ")" << std::endl;
		return stream;
	}

	bool operator==(Domino a, Domino b)
	{
		return (a.bot == b.bot && a.top == b.top || a.bot == b.top && a.top == b.bot);
	}

	bool operator>(Domino a, Domino b)
	{
		return (a.bot + a.top > b.top + b.bot);
	}

	//ÌÅÒÎÄÛ ÊËÀÑÑÀ ÄÎÌÈÍÎ ÑÅÒ
	DominoSet::DominoSet() : curSize(1)
	{
		Domino domino;
		domino.bot = 0;
		domino.top = 0;
		dominos[0] = domino;
	}

	DominoSet::DominoSet(int count)
	{
		if (count > DominoSet::MAX_SIZE || count <= 0)
			throw std::runtime_error("BAD VARIABLE");
		for (int i = 0; i < count; i++) {
			addRandom();
		}
	}

	DominoSet::DominoSet(int bot, int top)
	{
		if (bot == top)
			throw std::runtime_error("BAD VARIABLES!");
		curSize = 1;
		dominos[0] = Domino(bot, top);
	}

	bool DominoSet::contains(Domino domino) const
	{
		for (int i = 0; i < curSize; i++) {
			Domino cur = dominos[i];
			if (domino == cur)
				return true;
		}
		return false;
	}

	void DominoSet::addRandom()
	{
		if (curSize == MAX_SIZE)
			throw std::runtime_error("OVERFLOW!");
		while (true) {
			Domino domino(rand() % 7, rand() % 7);
			if (contains(domino))
				continue;
			dominos[curSize] = domino;
			curSize++;
			break;
		}
	}

	void DominoSet::sort()
	{
		for (int i = 0; i < curSize; i++) {
			for (int j = i + 1; j < curSize; j++) {
				if (dominos[i] > dominos[j])
					swap(dominos[i], dominos[j]);
			}
		}
	}

	int DominoSet::getCurSize() const
	{
		return this->curSize;
	}

	const Domino* DominoSet::getDominos() const
	{
		return dominos;
	}

	
}