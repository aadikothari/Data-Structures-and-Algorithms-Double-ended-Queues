#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"

template <typename T>
class Deque : public AbstractDeque<T>
{
	//TODO
public:

	Deque();

	~Deque();

	Deque(const Deque& rhs);

	const Deque& operator=(Deque rhs) noexcept;

	bool isEmpty() const noexcept;

	void pushFront(const T& item);

	void popFront();

	const T& front() const;

	void pushBack(const T& item);

	void popBack();

	const T& back() const;

private:
	T* items;
	std::size_t N;
	std::size_t F;
	std::size_t B;
};

#include "Deque.txx"
#endif
