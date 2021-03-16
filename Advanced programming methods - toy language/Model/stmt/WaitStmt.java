package Model.stmt;


import Model.adt.IDict;
import Model.exp.ValExp;
import Model.programState.PrgState;
import Model.types.Type;
import Model.values.IntegerValue;

public final class WaitStmt implements IStmt {
    private final IntegerValue val;

    public WaitStmt(IntegerValue val) {
        this.val = val;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        if(val.getValue() == 0)
            return null;
        else
            state.getExeStack().push(new CompStmt(new PrintStmt(new ValExp(val)), new WaitStmt(new IntegerValue(val.getValue() - 1))));
        return null;
    }

    @Override
    public String toString () {
        return "wait(" + val.toString() + ")\n";
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        return typeEnv;
    }
}

