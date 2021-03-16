package Model.exp;

import Model.adt.IDict;
import Model.adt.IHeap;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.Value;

public class ValExp extends Exp {
    private final Value val;

    public ValExp(Value val) {
        this.val = val;
    }

    @Override
    public Value eval(IDict<String, Value> symTable, IHeap<Integer, Value> heap) throws Exception {
        return val;
    }

    @Override
    public String toString() {
        return val.toString();
    }

    public Type typecheck(IDict<String,Type> typeEnv) throws Exception {
        return val.getType();
    }
}
