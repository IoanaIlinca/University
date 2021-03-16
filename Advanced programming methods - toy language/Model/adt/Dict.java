package Model.adt;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Dict<T1,T2> implements IDict<T1,T2>, Cloneable {


    HashMap<T1, T2> dictionary;

    public Dict(Object clone) {
        this.dictionary = (HashMap<T1, T2>) clone;
    }

    public Dict<T1, T2> Copy() {
        if(!(this == null))
            return new Dict<>(dictionary.clone());
        else
            return new Dict<>();
    }

    public HashMap<T1, T2> getContent() {
        return dictionary;
    }

    public Dict() {
        dictionary = new HashMap<T1,T2>();
    }

    @Override
    public Collection<T2> getValues() {
        return dictionary.values();

    }

    @Override
    public void add(T1 key, T2 value) {
        dictionary.put(key, value);
    }

    @Override
    public void update(T1 key, T2 value) {
        dictionary.put(key, value);
    }

    @Override
    public T2 lookup(T1 key) {
        return (T2) dictionary.get(key);
    }

    @Override
    public boolean isDefined(T1 key) {
        return dictionary.containsKey(key);
    }

    @Override
    public void setContent(Map<T1, T2> map) {
        dictionary = (HashMap<T1, T2>) map;
    }

    @Override
    public String toString() {
        String returnValue = "";
        for (Map.Entry<T1, T2> e : dictionary.entrySet()) {
            T1 key    = e.getKey();
            T2 value  = e.getValue();
            returnValue += key.toString() + "->" + value.toString() +"\n";
        }
        return returnValue;
    }

    public IDict<T1, T2> clone() throws
            CloneNotSupportedException
    {
        return (IDict<T1, T2>) super.clone();
    }
}
