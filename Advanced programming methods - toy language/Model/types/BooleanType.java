package Model.types;

import Model.values.BooleanValue;

public class BooleanType implements Type {
    public boolean equals(Object other)
    {
        if (other instanceof BooleanType)
            return true;
        else
            return false;
    }

    public BooleanValue defaultValue() {
        return new BooleanValue(false);
    }

    @Override
    public String toString() { return "Boolean"; }
}
