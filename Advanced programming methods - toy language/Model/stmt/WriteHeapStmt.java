package Model.stmt;


import Exceptions.AssignmentTypesException;
import Exceptions.ExpectedReferenceException;
import Exceptions.InvalidMemoryException;
import Exceptions.NotDeclaredVariable;
import Model.adt.IDict;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.RefType;
import Model.types.Type;
import Model.values.RefValue;
import Model.values.Value;

public final class WriteHeapStmt implements IStmt {
    private final String identifier;
    private final Exp expression;

    public WriteHeapStmt(String identifier, Exp expression) {
        this.identifier = identifier;
        this.expression = expression;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        var symbolTable = state.getSymTable();
        var heapMemory = state.getHeap();

        if (!symbolTable.isDefined(identifier))
            throw new NotDeclaredVariable(String.format(
                    "variable '%s' was not declared",
                    identifier
            ));

        Value value = symbolTable.lookup(identifier);

        if (!(value.getType() instanceof RefType))
            throw new ExpectedReferenceException(String.format(
                    "variable of reference type expected, got '%s' with type %s",
                    identifier,
                    value.getType()));

        RefValue referenceValue = (RefValue)symbolTable.lookup(identifier);
        int address = referenceValue.getAddr();

        if (!heapMemory.isDefined(address))
            throw new InvalidMemoryException(String.format(
                    "referenced address %d was not found in heap memory",
                    address));

        Type referenceInnerType = ((RefType)referenceValue.getType()).getInner();
        Type expressionType = expression.eval(symbolTable, heapMemory).getType();

        if (!expressionType.equals(referenceInnerType))
            throw new AssignmentTypesException(String.format(
                    "trying to assign %s type expression to a reference with inner type %s",
                    expressionType,
                    referenceInnerType));

        heapMemory.add(address, expression.eval(symbolTable, heapMemory));

        return null;
    }

    @Override
    public String toString() {
        return "*(" + identifier + ") = " + expression.toString();
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception{
        expression.typecheck(typeEnv);
        return typeEnv;
    }
}

