package Model.values;

import Model.types.*;

public class BooleanValue implements Value{
    private final boolean value;

    public BooleanValue(boolean value) {
        this.value = value;
    }

    public boolean equals(Object other)
    {
        if (other instanceof BooleanValue)
            return true;
        else
            return false;
    }

    public boolean getValue() {
        return value;
    }

    @Override
    public Type getType() {
        return new BooleanType();
    }

    @Override
    public BooleanValue toBoolean() {
        return this;
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }

}
