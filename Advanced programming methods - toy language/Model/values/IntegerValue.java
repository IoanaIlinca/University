package Model.values;
import Model.types.*;
public class IntegerValue implements Value {
    public final Integer value;

    public IntegerValue(int value) { this.value = value; }
    public int getValue() {

        return value;
    }

    public boolean equals(Object other)
    {
        if (other instanceof IntegerValue)
            return true;
        else
            return false;
    }

    @Override
    public Type getType() {
        return new IntegerType();
    }


    @Override
    public String toString() {

        return String.valueOf(value);
    }

    @Override
    public BooleanValue toBoolean(){
        if (value != 0) {
            return new BooleanValue(true);
        }
        return new BooleanValue(false);
    }
}
