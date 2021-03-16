package Model.exp;

import Exceptions.ExpectedBooleanException;
import Exceptions.ExpectedIntegerException;
import Model.adt.IDict;
import Model.adt.IHeap;
import Model.types.BooleanType;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.BooleanValue;
import Model.values.Value;

public class LogicExp extends Exp {
    private final Exp e1;
    private final Exp e2;
    private final char op;

    public LogicExp(String op, Exp e1, Exp e2) {
        this.e1 = e1;
        this.e2 = e2;
        this.op = op.charAt(0);
    }

    @Override
    public Value eval(IDict<String, Value> symTable, IHeap<Integer, Value> heap) throws Exception {
        Value leftValue = e1.eval(symTable, heap);
        Value rightValue = e2.eval(symTable, heap);

        if(!leftValue.getType().equals(new BooleanType())) {
            throw new ExpectedBooleanException("The left operand needs to be a boolean");
        }

        if(!rightValue.getType().equals(new BooleanType())) {
            throw new ExpectedBooleanException("The right operand needs to be a boolean");
        }

        boolean result = true;
        BooleanValue left = (BooleanValue) leftValue;
        BooleanValue right = (BooleanValue) rightValue;

        if (op == '&') {
            result = left.getValue() & right.getValue();
            return new BooleanValue(result);
        }

        if (op == '|') {
            result = left.getValue() | right.getValue();
            return new BooleanValue(result);
        }

        assert false;
        return new BooleanValue(false);
    }

    @Override
    public String toString() {
        return e1.toString() + " " + op + " " + e2.toString();
    }

    public Type typecheck(IDict<String,Type> typeEnv) throws Exception {
        Type typ1, typ2;
        typ1=e1.typecheck(typeEnv);
        typ2=e2.typecheck(typeEnv);
        if (typ1 != null && typ1.equals(new BooleanType()) )
        {
            if (typ2 != null && typ2.equals(new BooleanType())) {
                return new BooleanType();
            }
            else
                throw new ExpectedBooleanException("second operand is not a boolean");
        }
        else
            throw new ExpectedBooleanException("first operand is not a boolean");
    }
}
