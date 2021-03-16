#include <iostream>
using namespace std;

template <class T>

class Array {
private:
    int m_size;
    int m_capacity;
    T* m_data = nullptr;
    int m_index;

public:

    /* Constructor without parameters */
    Array();

    /* Destructor */
    ~Array();

    /*Copy constructor*/
    Array(const Array& Vect)
    {
        this->m_capacity = Vect.m_capacity;
        this->m_size = Vect.m_size;
        this->m_index = Vect.m_index;
        this->m_data = new T[Vect.m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            this->m_data[i] = Vect.m_data[i];
        }
    }



    /* Adds a value at the end of the vector*/
    void push(T value) {
        if (m_size >= m_capacity)
            resize();
        *(m_data + m_size++) = value;
    }

    /* Returns the value at the end of the vector*/
    T pop() {
        return *(m_data + --m_size);
        //delete m_data[m_size];
    }

    /* Changes a value with a new one, given its index */
    void set(int index, T value) 
    {
        *(m_data + index) = value;
    }

    /* Returns a value, given its index */
    const T get(int index) {
        return *(m_data + index);
    }

    /* Deletes a value */
    void del(T element, int index) {
        T* newData = new T[m_capacity];
        for (int iterator = 0; iterator < m_size - 1; iterator++)
        {
            //cout << iterator;
            if (*(m_data + iterator) == element)
            {
                
                index = iterator;
                break;
            }
                
            *(newData + iterator) = *(m_data + iterator);
               

        }

        for (int iterator = index; iterator < m_size - 1; iterator++)
        {

            *(newData + iterator) = *(m_data + iterator + 1);


        }
            
        delete[] m_data;
        m_data = newData;
        m_size--;
    }

    /* Resizes the array's capacity */
    void resize() {
        int capacity = m_capacity * 2 + 1;
        T* tmp = new T[capacity];
        for (int i = 0; i < m_size; i++)
            *(tmp + i) = *(m_data + i);
        delete[] m_data;
        m_data = tmp;
        m_capacity = capacity;
    }

    /* Getter - returns the size */
    const int size()
    {
        return m_size;
    }

    /* Getter - returns the capacity */
    const int capacity()
    {
        return m_capacity;
    }

    /* Prints the vector */
    void print()
    {
        for (int iterator = 0; iterator < m_size; iterator++)
            cout << *(m_data + iterator);
    }

    /* Overwirites the << operator */
    friend ostream& operator<<(ostream& output, const Array& Arr)
    {

        for (int iterator = 0; iterator < Arr.m_size; iterator++)
            output << *(Arr.m_data + iterator);
        return output;
    }

    /* Overwirites the [] operator */
    T& operator [](int position)
    {
        return this->m_data[position];
    }
    
    /* Checks if the vector is empty 
        returns true if it is, false otherwise */
    bool is_empty()
    {
        if (m_size == 0)
            return true;
        else
            return false;
    }

    /*Overwrites the = operator */
    Array& operator= (const Array& Arr)
    {
        if (this == &Arr)
            return *this;

        this->m_capacity = Arr.m_capacity;
        this->m_size = Arr.m_size;
        this->m_index = Arr.m_index;
        delete[] this->m_data;
        this->m_data = new T[Arr.m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            this->m_data[i] = Arr.m_data[i];
        }
    }

    /*The iterator class for the vector*/
    class Iterator { // it might need to inherit the c++ iterator
    private: 
        T* ptr;

    public:
        /*Constructor */
        Iterator(T* pointer) : ptr{ pointer } {}

        /*Overwrites the * operator */
        T operator*()
        {
            return *this->ptr;
        }

        /*Overwrites the != operator */
        bool operator!= (const Iterator& it)
        {
            return this->ptr != it.ptr;
        }

        /*Overwrites the ++ operator */
        Iterator operator++ () // pre-incrementing
        {
            this->ptr++;
            return *this;
        }

        /*Overwrites the ++ operator */
        Iterator operator++ (int x) // post-incrementing - with dummy integer
        {
            Iterator aux{ *this };
            this->ptr++;
            return *(aux);
        }
    };

    /*Gets the iterator with the current element*/
    typename Iterator current()
    {
        //Iterator au
        if (this->m_index == -1)
            ++this->m_index;
        return Iterator{ (this->m_data + this->m_index) };
    }

    /*Gets the iterator with the next element*/
    typename Iterator next()
    {
        ++this->m_index;
        if (this->m_index == this->m_size)
            this->m_index = 0;
        return Iterator{ (this->m_data + this->m_index) };
    }

    /*Gets the iterator with the first element*/
    typename Iterator begin() // points to the first element
    {
        return Iterator{ this->m_data };
    }

    /*Gets the iterator after the last element*/
    typename Iterator end() // points to the element after the last element
    {
        return Iterator{ (this->m_data + this->m_size) };
    }

};

/*Constructor definition */
template <class T>
inline Array<T>::Array() {
    this->m_capacity = 10;
    this->m_size= 0;
    this->m_index = -1;
    this->m_data = new T[10];
}

/*Destructor definition*/
template <class T>
inline Array<T>::~Array() {
    delete[] this->m_data;
}