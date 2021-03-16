package Model.exp;

import Exceptions.ExpectedReferenceException;
import Exceptions.InvalidMemoryException;
import Model.adt.IDict;
import Model.adt.IHeap;
import Model.types.IntegerType;
import Model.types.RefType;
import Model.types.Type;
import Model.values.RefValue;
import Model.values.Value;

public class ReadHeapExp extends Exp {
    private final Exp expression;

    public ReadHeapExp(Exp expression) {
        this.expression = expression;
    }

    @Override
    public Value eval(IDict<String, Value> symTable, IHeap<Integer, Value> heap) throws Exception {
        Value value = expression.eval(symTable, heap);
        if (!(value instanceof RefValue))
            throw new ExpectedReferenceException("The expression " + expression + " is not of type reference");

        int address = ((RefValue) value).getAddr();

        if (!heap.isDefined(address))
            throw new InvalidMemoryException("Referenced address " + address + " not found in heap memory");

        return heap.lookup(address);
    }

    @Override
    public String toString() {
        return "*(" + expression + ")\n";
    }

    public Type typecheck(IDict<String,Type> typeEnv) throws Exception {
        Type typ=expression.typecheck(typeEnv);
        if (typ instanceof RefType) {
            RefType reft =(RefType) typ;
            return reft.getInner();
        }
        else
            throw new ExpectedReferenceException("the rH argument is not a Ref Type");
    }
}
