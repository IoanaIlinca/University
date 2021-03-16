package Model.adt;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public interface IDict<T1,T2>{
    public Dict<T1, T2> Copy();
    void add(T1 key, T2 value);
    public HashMap<T1, T2> getContent();
    void update(T1 key, T2 value);
    T2 lookup(T1 key);
    boolean isDefined(T1 key);
    String toString();
    void setContent(Map<T1, T2> map);
    public Collection<T2> getValues();
    public IDict<T1, T2> clone() throws
            CloneNotSupportedException;
}
