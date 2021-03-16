package Model.stmt;

import Exceptions.AssignmentTypesException;
import Model.adt.IDict;
import Model.adt.ISemaphore;
import Model.adt.IStack;
import Model.adt.List;
import Model.programState.PrgState;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.IntegerValue;
import Model.values.Value;
import org.javatuples.Pair;

public final class Release implements IStmt {

    public  final String var;

    public Release(String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        try{
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> semaphoreTable = state.getSemaphoreTable();
            IStack<IStmt> executionStack = state.getExeStack();

            Value foundIndex = state.getSymTable().lookup(var);

            if(foundIndex == null || !(foundIndex instanceof IntegerValue))
                throw new Exception("No such variable in symbolTable ot variable is not an integer");
            Pair<IntegerValue, List<Integer>> semaphoreValue = semaphoreTable.lookup(((IntegerValue) foundIndex).value);
            List<Integer> threads = semaphoreValue.getValue1();
            IntegerValue n = semaphoreValue.getValue0();

            if(threads.isDefined(state.getId()))
                threads.getList().remove(state.getId());
                //state.getSemaphoreTable().add(((IntegerValue) foundIndex).value, new Triplet<>(nMax, threads, semaphoreValue.getValue2()));

        }catch (Exception e){
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type t = typeEnv.lookup(var);
        if (t instanceof IntegerType)
            return typeEnv;
        else
            throw new AssignmentTypesException("acquire: var is not a string variable or exp1 does not have type int");
    }

    @Override
    public String toString() {
        return "release( " + var + " )";
    }
}
