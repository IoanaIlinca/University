package Model.stmt;

import Exceptions.ExpectedIntegerException;
import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.IntegerValue;
import Model.values.Value;

public final class Unlock implements IStmt {
    private final String var;

    public Unlock(String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        Value foundIndex = state.getSymTable().lookup(var);
        if (foundIndex == null || !(foundIndex.getType().equals(new IntegerType())))
            throw new RuntimeException("The variable is not in the symbol table or it is not of Integer Type");
        else
        {
            Integer index = ((IntegerValue) foundIndex).value;
            if(state.getLock().isDefined(index))
                if (state.getLock().lookup(index) == state.getId())
                    state.getLock().update(index, -1);
            else
            {
                throw new RuntimeException("It is not in the lock now");
            }
        }
        return null;
    }

    @Override
    public String toString() {
        return "Unlock(" + var + ")\n";
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typ = typeEnv.lookup(var);

        if (typ.equals(new IntegerType()))
            return typeEnv;
        else
            throw new ExpectedIntegerException("Var is not an integer");
    }
}
