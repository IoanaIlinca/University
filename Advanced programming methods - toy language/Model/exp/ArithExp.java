package Model.exp;

import Model.adt.IDict;
import Model.adt.IHeap;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.*;
import Exceptions.*;

public class ArithExp extends Exp{
    char op;
    Exp e1, e2;

    public ArithExp (String op, Exp e1, Exp e2) {
        this.e1 = e1;
        this.e2 = e2;
        this.op = op.charAt(0);

    }

    public Value eval(IDict<String, Value> symTable, IHeap<Integer, Value> heap) throws Exception {
        Value leftValue = e1.eval(symTable, heap);
        Value rightValue = e2.eval(symTable, heap);

        if (!leftValue.getType().equals(new IntegerType())) {
            throw new ExpectedIntegerException("The first operand does not have the type integer!\n");
        }
        if (!rightValue.getType().equals(new IntegerType())) {
            throw new ExpectedIntegerException("The second operand does not have the type integer!\n");
        }

        IntegerValue left = (IntegerValue) leftValue;
        IntegerValue right = (IntegerValue) rightValue;


        if (op == '+') {
            return new IntegerValue(left.getValue() + right.getValue());
        }
        if (op == '-') {
            return new IntegerValue(left.getValue() - right.getValue());
        }
        if (op == '*') {
            return new IntegerValue(left.getValue() * right.getValue());
        }
        if (op == '/') {
            if (right.getValue() == 0)
                throw new DivisionBy0Exception("Cannot divide by 0");
            return new IntegerValue(left.getValue() / right.getValue());
        }

        assert false;
        return new IntegerValue(0);
    }

    public Type typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typ1, typ2;
        typ1=e1.typecheck(typeEnv);
        typ2=e2.typecheck(typeEnv);
        if (typ1 != null && typ1.equals(new IntegerType()) )
            {
                if (typ2 != null && typ2.equals(new IntegerType())) {
                        return new IntegerType();
                }
                else
                    throw new ExpectedIntegerException("second operand is not an integer");
            }
        else
            throw new ExpectedIntegerException("first operand is not an integer");
    }

    public char getOp() {return this.op;}

    public Exp getFirst() {
        return this.e1;
    }

    public Exp getSecond() {
        return this.e2;
    }

    public String toString() { return e1.toString() + " " + op + " " + e2.toString(); }
}
