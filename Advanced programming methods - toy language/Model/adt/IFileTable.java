package Model.adt;

import java.io.BufferedReader;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public interface IFileTable<T1, T2> {
    void set(T1 v1, T2 v2);
    void update(T1 v1, T2 v2);
    void remove(T1 v1);
    T2 lookup(T1 id);
    String toString();
    boolean isDefined(T1 id);

    HashMap<T1, T2> getDictionary();
}
