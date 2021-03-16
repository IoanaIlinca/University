package Model.adt;
import java.util.Stack;

public class ClassStack<T> implements IStack<T> {
    Stack<T> stack;

    public ClassStack() {
        stack = new Stack<T>();
    }

    @Override
    public T pop() {
        return stack.pop();
    }

    @Override
    public void push(T v) {
        stack.push(v);
    }

    @Override
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    @Override
    public String toString() {
        String returnValue = "";
        String aux = "";
        for (T e : stack) {
            aux = returnValue;
            returnValue = e.toString() + aux;
        }
        return returnValue;
    }

    @Override
    public Stack<T> getStack() {
        return this.stack;
    }
}
