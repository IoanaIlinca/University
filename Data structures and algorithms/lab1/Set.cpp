#include "Set.h"
#include "SetIterator.h"
#include <new>


/// best case - teta(1), worst case - teta(1), overall - teta(1))
Set::Set() {

    sir = new bool[10];
    for (int i = 0; i <= 9; i++)
        sir[i] = false;
    capacity = 10;
    length = 1;
    numberOfElems = 0;
    leftValue = 0;
    rightValue = 0;
}


/// best case - teta(1), worst case - teta(newLength), overall - O(newLength)
/// add explanation for newLength
bool Set::add(TElem elem) {
    if (elem < leftValue && elem < 0)
    {
        bool* newSir;
        if ((rightValue - elem + 1) >= capacity)
        {
            newSir = new bool[2 * (rightValue - elem + 1)];
            capacity = 2 * (rightValue - elem + 1);
        }
        else
            newSir = new bool[capacity];
        int difference = (-1) * (elem - leftValue); /// leftValue is 0 or smaller, so in this case the elem is negative,
                                                    /// and so is the difference that needs to be transformed
        for (int iter = 0; iter < difference; iter++)
            newSir[iter] = false; /// we make the newly added values 0
        for (int iter = 0; iter < length; iter++)
            {
                newSir[difference + iter] = sir[iter];
            }
        leftValue = elem;
        length = rightValue - leftValue + 1;
        delete[] sir;
        sir = newSir;
        sir[0] = true;
        ++numberOfElems;
        return true;
    }
    if (elem > rightValue && elem > 0)
    {
        bool* newSir;
        if ((elem - leftValue + 1) >= capacity)
        {
            newSir = new bool[2 * (elem - leftValue + 1)];
            capacity = 2 * (rightValue - elem);
        }
        else
            newSir = new bool[capacity];
        int difference = (elem - rightValue); /// rightValue is 0 or higher, so in this case the elem is positive,
                                                    /// and so is difference that needs to be transformed
        for (int iter = 0; iter < length; iter++)
            {
                newSir[iter] = sir[iter];
            }
        for (int iter = length; iter < length + difference; iter++)
            newSir[iter] = false; /// we make the newly added values 0
        rightValue = elem;
        length = rightValue - leftValue + 1;
        delete[] sir;
        sir = newSir;
        sir[length - 1] = true;
        numberOfElems++;
        return true;

    }
    if (sir[elem - leftValue] == true)
        return false;
    else
    {
        sir[elem - leftValue] = true;
        numberOfElems++;
        return true;
    }

    return false;
}

/// best case - teta(1), worst case - teta(newLength), overall - teta(newLength)
bool Set::remove(TElem elem) {
    if (numberOfElems == 0)
        return false;
    if (elem > rightValue)
        return false;
    if (elem < leftValue)
        return false;
    ///Implementation for when the ends need to be updated
    if (elem == leftValue && elem < 0)
    {
        sir[elem - leftValue] = 0;
        int newLeftValue = elem;

        for (int iter = 0; iter < length; iter++)
        {
            if (sir[iter] == true)
            {
                newLeftValue = iter + leftValue;
                break;
            }

        }
        if (numberOfElems == 0)
            newLeftValue = 0;
        int newLength = rightValue - newLeftValue + 1;
        bool *newSir = new bool[2 * newLength];

        for (int iter = 0; iter < newLength - (newLeftValue - leftValue); iter++)
        {
            newSir[iter] = sir[iter + (newLeftValue - leftValue)];
        }

        delete[] sir;
        sir = newSir;
        leftValue = newLeftValue;
        length = newLength;
        numberOfElems--;
        return true;
    }

    if (elem == rightValue && elem > 0)
    {
        sir[elem - leftValue] = 0;
        int newRightValue = elem;

        for (int iter = length - 1; iter >= 0; iter--)
        {
            if (sir[iter] == true)
            {
                newRightValue = iter + leftValue;
                break;
            }

        }
        if (numberOfElems == 0)
            newRightValue = 0;
        int newLength = newRightValue - leftValue + 1;
        bool *newSir = new bool[2 * newLength];

        for (int iter = 0; iter < newLength; iter++)
        {
            newSir[iter] = sir[iter];
        }

        delete[] sir;
        sir = newSir;
        rightValue = newRightValue;
        length = newLength;
        numberOfElems--;
        return true;
    }

	if (sir[elem - leftValue] == true)
    {
        sir[elem - leftValue] = false;
        numberOfElems--;
        return true;
    }
	return false;
}

/// best case - teta(1), worst case - teta(1), overall - teta(1))
bool Set::search(TElem elem) const {
    if (elem < leftValue)
        return false;
    if (elem > rightValue)
        return false;
    //if (elem - leftValue < length && )
    return sir[elem - leftValue];
    //else return false;
}

/// best case - teta(length), worst case - teta(length), overall - teta(length)
int Set::size() const {
    int cnt = 0;
    for (int i = 0; i < length; i++)
        if (sir[i] == true)
            cnt++;
    return cnt;
	//return numberOfElems;
}

/// best case - teta(1), worst case - teta(1), overall - teta(1))
bool Set::isEmpty() const {
	if (numberOfElems == 0)
        return true;
    return false;
}

/// best case - teta(1), worst case - teta(1), overall - teta(1))
Set::~Set() {
	delete[] sir;
}

/// best case - teta(1), worst case - teta(1), overall - teta(1))
SetIterator Set::iterator() const {
	return SetIterator(*this);
}


