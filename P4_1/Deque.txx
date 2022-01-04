#include <iostream>

#include "Deque.hpp"

// TODO

template<typename T>
Deque<T>::Deque()
{
    N = 64;
    F = 0;
    B = 0;

    items = new T[N + 1];
}

template<typename T>
Deque<T>::~Deque()
{
    delete[] items;
}

template<typename T>
Deque<T>::Deque(const Deque& rhs)
{
    N = rhs.N;
    F = rhs.F;
    B = rhs.B;

    items = new T[N + 1];
    std::copy(rhs.items, rhs.items + (N + 1), items);
}
template<typename T>
const Deque<T>& Deque<T>::operator=(Deque rhs) noexcept
{
    std::swap(this->N, rhs.N);
    std::swap(this->F, rhs.F);
    std::swap(this->B, rhs.B);
    std::swap(this->items, rhs.items);

    return *this;
}

template<typename T>
bool Deque<T>::isEmpty() const noexcept
{
    return (F == B);
}

template<typename T>
void Deque<T>::pushFront(const T& item)
{
    if ((B + 1) % (N + 1) == F) //if full grow
    {
        // std::cout << "orig items, F = " << F << " B = " << B << std::endl;
        // for(int i = 0; i < N+1; i++)
        // 	std::cout << " " << items[i];

        T* orig_items = items; //original: what we delete
        std::size_t orig_size = N + 1;

        N *= 2; //new array is twice as large as previous
        items = new T[N + 1];

        //copy items in order to new array and adjust F and B
        for (int i = 0; i < orig_size; i++)
            items[i] = orig_items[(F + 1 + i) % (orig_size)];

        F = N;
        B = orig_size - 2;

        delete[] orig_items;

        // std::cout << std::endl << "new items, F = " << F << " B = " << B << std::endl;
        // for(int i = 0; i < N+1; i++)
        // 	std::cout << " " << items[i];
    }

    //figure out index for new item
    if (F == 0) //wrap around to back of array
        F = N;
    else
        F--;

    items[(F + 1) % (N + 1)] = item;
}

template<typename T>
void Deque<T>::popFront()
{
    if (isEmpty())
        throw std::runtime_error("popping an empty deque");
    else
        F = (F + 1) % (N + 1);
}

template<typename T>
const T& Deque<T>::front() const
{
    if (isEmpty())
        throw std::runtime_error("peeking an empty deque");
    else
        return items[(F + 1) % (N + 1)];
}

template<typename T>
void Deque<T>::pushBack(const T& item)
{
    if ((B + 1) % (N + 1) == F) //if full grow
    {
        // std::cout << std::endl << "orig items, F = " << F << " B = " << B << std::endl;
        // for(int i = 0; i < N+1; i++)
        // 	std::cout << " " << items[i];

        T* orig_items = items; //original: what we delete
        std::size_t orig_size = N + 1;

        N *= 2; //new array is twice as large as previous
        items = new T[N + 1];

        //copy items in order to new array and adjust F and B
        for (int i = 0; i < orig_size; i++)
            items[i] = orig_items[(F + 1 + i) % (orig_size)];

        F = N;
        B = orig_size - 2;

        delete[] orig_items;

        // std::cout << std::endl << "new items, F = " << F << " B = " << B << std::endl;
        // for(int i = 0; i < N+1; i++)
        // 	std::cout << " " << items[i];
    }

    B = (B + 1) % (N + 1);
    items[B] = item;
}

template<typename T>
void Deque<T>::popBack()
{
    if (isEmpty())
        throw std::runtime_error("popping an empty deque");
    else
    {
        if (B == 0) //wrap around to back of array
            B = N;
        else
            B--;
    }
}

template<typename T>
const T& Deque<T>::back() const
{
    if (isEmpty())
        throw std::runtime_error("peeking an empty deque");
    else
        return items[B];
}