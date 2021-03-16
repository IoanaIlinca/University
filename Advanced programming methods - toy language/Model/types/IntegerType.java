package Model.types;

import Model.values.*;

public class IntegerType implements Type{
    public boolean equals(Object other)
    {
        if (other instanceof IntegerType)
            return true;
        else
            return false;
    }

    @Override
    public IntegerValue defaultValue() {
        return new IntegerValue(0);
    }

    @Override
    public String toString() { return "Integer"; }
}
