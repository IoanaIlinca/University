package Model.stmt;

import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.Type;
import Model.values.IntegerValue;

public final class SleepStmt implements IStmt {
    private final IntegerValue val;

    public SleepStmt(IntegerValue val) {
        this.val = val;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        if(val.getValue() == 0)
            return null;
        else
            state.getExeStack().push(new SleepStmt(new IntegerValue(val.getValue() - 1)));
        return null;
    }

    @Override
    public String toString () {
        return "sleep(" + val.toString() + ")\n";
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        return typeEnv;
    }
}
