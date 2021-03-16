package Model.types;

import Model.values.StringValue;

public class StringType implements Type{
    public boolean equals(Object other)
    {
        if (other instanceof StringType)
            return true;
        else
            return false;
    }

    @Override
    public StringValue defaultValue() {
        return new StringValue("");
    }

    @Override
    public String toString() { return "String"; }
}
