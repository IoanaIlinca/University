package Model.adt;

import java.util.LinkedList;
import java.util.Queue;

public class List<T> implements IList<T> {
    private Queue<T> list;

    public List() {
        list = new LinkedList<>();;
    }
    @Override
    public boolean isDefined(T key) {
        return list.contains(key);
    }

    @Override
    public Queue<T> getList() {
        return list;
    }

    @Override
    public void add(T v) {
        list.add(v);
    }

    @Override
    public T pop() {
        return list.poll();
    }

    public T top() {
        if (list.isEmpty())
            return null;
        return list.element();
    }

    @Override
    public String toString() {
        String returnValue = "[";
        for (T e : list) {
            returnValue += e.toString() + " ";
        }
        returnValue += "]\n";
        return returnValue;
    }

}
