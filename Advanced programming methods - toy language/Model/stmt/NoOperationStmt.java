package Model.stmt;

import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.Type;

public final class NoOperationStmt implements IStmt{


    public NoOperationStmt() {
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        return null;
    }

    @Override
    public String toString() {
        return "Nop;";
    }


    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        return typeEnv;

    }
}
