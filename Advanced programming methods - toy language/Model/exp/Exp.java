package Model.exp;
import Model.adt.IDict;
import Model.adt.IHeap;
import Model.types.Type;
import Model.values.Value;

public abstract class Exp {

    public abstract Value eval(IDict<String, Value> symTable, IHeap<Integer, Value> heap) throws Exception;
    public abstract String toString();
    public abstract Type typecheck(IDict<String,Type> typeEnv) throws Exception;
}
