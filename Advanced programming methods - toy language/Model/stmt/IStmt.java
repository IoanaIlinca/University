package Model.stmt;

import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.Type;

public interface IStmt {
    PrgState execute(PrgState state) throws Exception;
    public String toString();
    IDict<String, Type> typecheck(IDict<String,Type> typeEnv) throws Exception;
}
