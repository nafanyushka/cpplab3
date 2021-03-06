#include "DominoStatic.h"

namespace DominoStatic {

	template <class T>
	void swap(T& a, T& b) {
		T p = a;
		a = b;
		b = p;
	}

	//?????? ????????? ????? ?????????
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

	bool operator==(int a, Domino b)
	{
		return (a == b.bot || a == b.top);
	}

	DominoSet& operator++(DominoSet& set)
	{
		set.addRandom();
		return set;
	}

	void operator+(DominoSet& set, Domino domino)
	{
		set.put(domino);
	}

	void operator-(DominoSet& set, Domino domino)
	{
		set.remove(domino);
	}

	//?????? ?????? ?????? ???
	//DominoSet::DominoSet() : curSize(1)
	//{
		//Domino domino;
		//domino.bot = 0;
		//domino.top = 0;
		//dominos[0] = domino;
	//}

	DominoSet::DominoSet(Domino domino) : curSize(1){
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

	void DominoSet::put(int index, Domino domino)
	{
		dominos[index] = domino;
	}

	bool DominoSet::contains(Domino domino) const
	{
		return find(domino) != -1;
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

	void DominoSet::remove(Domino domino)
	{
		int index = find(domino);
		if (index == -1)
			return;
		curSize--;
		dominos[index] = dominos[curSize];
	}

	void DominoSet::put(Domino domino)
	{
		if (curSize == MAX_SIZE)
			throw std::runtime_error("OVERFLOW!");
		if (contains(domino))
			return;
		dominos[curSize++] = domino;
	}

	DominoSet DominoSet::getSubset(int value) const
	{
		DominoSet newSet;
		newSet.curSize = 0;

		if (value > 6 || value < 0)
			return newSet;

		for (int i = 0; i < curSize; i++) {
			if (value == dominos[i])
				newSet.put(dominos[i]);
		}
		return newSet;
	}

	DominoSet DominoSet::openByNumber(int number) const
	{
		if (number > curSize)
			throw std::runtime_error("BAD VARIABLE!");
		DominoSet set;
		set.put(0, dominos[number]);
		set.curSize = 0;
		return set;
	}

	int DominoSet::getCurSize() const
	{
		return this->curSize;
	}

	int DominoSet::find(Domino domino) const
	{
		for (int i = 0; i < curSize; i++)
			if (domino == dominos[i])
				return i;
		return -1;
	}

	const Domino* DominoSet::getDominos() const
	{
		return dominos;
	}

	
}