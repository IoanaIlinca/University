package Model.adt;

import java.util.Queue;

public interface IList<T> {
    void add(T v);
    T pop();
    String toString();
    T top();
    //void setContent(IList<T> newList);
    boolean isDefined(T key);

    Queue<T> getList();
}
