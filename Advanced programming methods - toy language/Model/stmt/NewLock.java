package Model.stmt;

import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.IntegerValue;

public final class NewLock implements IStmt {
    public final String var;

    public NewLock(String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        var newFreeLocation = new IntegerValue(state.getLock().getFreeAddress());
        if (state.getSymTable().lookup(var) != null && state.getSymTable().lookup(var).getType().equals(new IntegerType()))
        {
            state.getSymTable().update(var, newFreeLocation);
            state.getLock().add(newFreeLocation.value, -1);
        }


        return null;
    }

    @Override
    public String toString() {
        return "newLock(" + var + ")\n";
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        return typeEnv;
    }
}
