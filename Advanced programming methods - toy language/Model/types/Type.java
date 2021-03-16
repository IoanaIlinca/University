package Model.types;

import Model.values.Value;

public interface Type {
    public boolean equals(Object other);
    public Value defaultValue();
    public String toString();
}
