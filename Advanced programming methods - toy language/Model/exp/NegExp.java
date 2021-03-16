package Model.exp;


import Model.adt.IDict;
import Model.adt.IHeap;
import Model.types.BooleanType;
import Model.types.Type;
import Model.values.BooleanValue;
import Model.values.Value;

public class NegExp extends Exp{
    private final Exp exp;

    public NegExp(Exp exp) {
        this.exp = exp;
    }

    @Override
    public Value eval(IDict<String, Value> symTable, IHeap<Integer, Value> heap) throws Exception {
        var value = exp.eval(symTable,heap);
        if(value.getType().equals(new BooleanType())) {
            var bval = (BooleanValue) value;
            return new BooleanValue(!(((BooleanValue) value).getValue()));
        }
        else
            throw new Exception("Negation: type of exp is not bool");
    }



    @Override
    public String toString() {
        return "!(" + exp.toString() + ")";
    }



    @Override
    public Type typecheck(IDict<String, Type> typeEnv) throws Exception{
        var typ = exp.typecheck(typeEnv);
        if (typ.equals(new BooleanType()))
            return new BooleanType();
        else
            throw new RuntimeException("Negation: type check error;expression not boolean");
    }
}

