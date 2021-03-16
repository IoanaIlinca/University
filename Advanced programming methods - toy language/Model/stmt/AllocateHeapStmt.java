package Model.stmt;

import Exceptions.AssignmentTypesException;
import Exceptions.ExpectedBooleanException;
import Exceptions.NotDeclaredVariable;
import Model.adt.ClassHeap;
import Model.adt.IDict;
import Model.adt.IHeap;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.BooleanType;
import Model.types.RefType;
import Model.types.Type;
import Model.values.RefValue;
import Model.values.Value;

import java.beans.Expression;

public final class AllocateHeapStmt implements IStmt{
    private final String id;
    private final Exp expression;

    public AllocateHeapStmt(String id, Exp expression) {
        this.id = id;
        this.expression = expression;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        IDict<String, Value> symTable = state.getSymTable();
        var heap = state.getHeap();
        if (!symTable.isDefined(id))
            throw new NotDeclaredVariable("Variable " + id + " was not declared");

        Value symbol = symTable.lookup(id);

        if(!(symbol.getType() instanceof RefType))
            throw new AssignmentTypesException("The variable " + id + " is not of type reference");

        Type expType = expression.eval(symTable, heap).getType();
        Type referenceInnerType = ((RefType) symbol.getType()).getInner();

        if(!expType.equals(referenceInnerType))
            throw new AssignmentTypesException("The inner type of " + expression + " is not the same as the one of" + symbol);


        int memoryAddress = heap.getFreeAddress();
        heap.add(memoryAddress, expression.eval(symTable, heap));
        symTable.add(id, new RefValue(memoryAddress, referenceInnerType));
        //System.out.println("baldabac");
        return null;
    }

    public String toString() {
        return "new(" + id + ", " + expression + ")\n";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typevar = typeEnv.lookup(id);
        Type typexp = expression.typecheck(typeEnv);

        if (typevar.equals(new RefType(typexp)))
            return typeEnv;
        else
            throw new AssignmentTypesException("NEW stmt: right hand side and left hand side have different types ");
    }
}
