package Model.values;

import Model.types.RefType;
import Model.types.Type;

public class RefValue implements Value {
    int address;
    Type locationType;
    public RefValue(int addr, Type typ) {
        address = addr;
        locationType = typ;
    }
    public int getAddr() {return address;}
    public Type getType() { return new RefType(locationType);}
    public Type getLocationType() {return locationType; }

    public boolean equals(Object other) {
        if(other instanceof RefValue) {
            return ((RefValue)other).getAddr() == address;
        }
        else
            return false;
    }

    @Override
    public BooleanValue toBoolean() {
        if (address != 0)
            return new BooleanValue(true);
        return new BooleanValue(false);
    }
    
    @Override
    public String toString() {
        return String.valueOf(address) + " " + locationType.toString();
    }
}
