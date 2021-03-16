package Model.values;

import Model.types.StringType;
import Model.types.Type;

public class StringValue implements Value {
    public final String str;

    public StringValue(String str) {
        this.str = str;
    }


    public boolean equals(Object other)
    {
        if (other instanceof StringValue)
            return true;
        else
            return false;
    }

    @Override
    public Type getType() {
        return new StringType();
    }


    @Override
    public BooleanValue toBoolean() {
        if (str != "") {
            return new BooleanValue(true);
        }
        return new BooleanValue(false);
    }

    public String getValue() {
        return str;
    }
    @Override
    public String toString() { return str; }
}
