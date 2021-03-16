package Model.exp;
import Model.adt.IDict;
import Model.adt.IHeap;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.IntegerValue;
import Model.values.Value;

public class ConstExp extends Exp{
    private final int number;

    public ConstExp(int num) {
        number = num;
    }
    @Override
    public Value eval(IDict<String, Value> symTable, IHeap<Integer, Value> heap)  {
        return new IntegerValue(number);
    }

    public String toString() {
        return Integer.toString(number);
    }

    public Type typecheck(IDict<String,Type> typeEnv) throws Exception {
        return new IntegerType();
    }
}
