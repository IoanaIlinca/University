package Model.values;
import Model.types.*;

public interface Value {
    Type getType();
    BooleanValue toBoolean();
    public boolean equals(Object other);

    String toString();
}
