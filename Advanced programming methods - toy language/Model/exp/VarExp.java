package Model.exp;
import Model.adt.IDict;
import Model.adt.IHeap;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.Value;

public class VarExp extends Exp{
    public final String id;

    public VarExp(String identifier) {
        id = identifier;
    }

    @Override
    public Value eval(IDict<String,Value> symTable, IHeap<Integer, Value> heap) {

        return symTable.lookup(id);
    }

    public String toString() {return id;}

    public Type typecheck(IDict<String,Type> typeEnv) throws Exception {
        return typeEnv.lookup(id);
    }

}
