package Model.adt;

import java.util.HashMap;
import java.util.Map;

public interface ILatch <T1, T2> {
    int getFreeAddress();
    void add(T1 key, T2 value);
    void update(T1 key, T2 value);
    T2 lookup(T1 key);
    boolean isDefined(T1 key);
    String toString();
    void setContent(HashMap<T1, T2> h);
    HashMap<T1, T2> getLatch();

    Map<T1, T2> getContent();
}
