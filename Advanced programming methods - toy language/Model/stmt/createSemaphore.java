package Model.stmt;

import Exceptions.AssignmentTypesException;
import Exceptions.ExpectedIntegerException;
import Model.adt.IDict;
import Model.adt.ISemaphore;
import Model.adt.List;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.IntegerValue;
import Model.values.Value;
import org.javatuples.Pair;

public final class createSemaphore implements IStmt {
    private final String var;
    private final Exp exp1;

    public createSemaphore(String var, Exp exp1) {
        this.var = var;
        this.exp1 = exp1;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        IDict<String, Value> symbolTable = state.getSymTable();
        ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> semaphoreTable = state.getSemaphoreTable();

        Value value1 = exp1.eval(symbolTable, state.getHeap());
        IntegerValue v1;
        if (value1.getType() instanceof IntegerType) {
            v1 = (IntegerValue) value1;
        }
        else
            throw new ExpectedIntegerException("Expected an Integer expression");


        Integer location = state.getSemaphoreTable().getFreeAddress();
        semaphoreTable.add(location, new Pair<IntegerValue, List<Integer>>(v1, new List<>()));
        if (symbolTable.isDefined(var) && (symbolTable.lookup(var).getType() instanceof IntegerType))
            symbolTable.update(var, new IntegerValue(location));
        else
            throw new ExpectedIntegerException("Expected an Integer expression");

        //state(semaphoreTable);
        //state.setSymbolTable(symbolTable);
        return null;
    }


    @Override
    public String toString() {
        return "createSemaphore( " + var + ", " + exp1.toString() + ")";
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typeVar = typeEnv.lookup(var);
        Type va = exp1.typecheck(typeEnv);
        if (typeVar instanceof IntegerType && va instanceof IntegerType)
            return typeEnv;
        else throw new AssignmentTypesException("new Semaphore: var is not a string variable or exp1 does not have type int");
    }
}
