package Model.adt;

import java.util.Stack;

public interface IStack<T> {

    T pop();
    void push(T v);
    boolean isEmpty();
    String toString();

    Stack<T> getStack();
}

