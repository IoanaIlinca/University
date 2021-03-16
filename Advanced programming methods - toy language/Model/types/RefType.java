package Model.types;

import Model.values.RefValue;
import Model.values.Value;

public class RefType implements Type {
    Type inner;

    public RefType(Type inner) {
        this.inner=inner;
    }
    public RefType() { inner = null;}

    public Type getInner() {
        return inner;
    }
    public boolean equals(Object another){
        if (another instanceof  RefType)
            return true;
        else
            return false;}

    public String toString() { return "Ref(" +inner.toString()+")";}
    public Value defaultValue() { return new RefValue(0,inner);}
}
