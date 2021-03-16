package Model.stmt;

import Model.adt.IDict;
import Model.exp.Exp;
import Model.exp.NegExp;
import Model.programState.PrgState;
import Model.types.Type;

public final class RepeatUntilStmt implements IStmt{
    private final IStmt stmt1;
    private final Exp exp2;

    public RepeatUntilStmt(Exp exp2,IStmt stmt1) {
        this.stmt1 = stmt1;
        this.exp2 = exp2;
    }


    @Override
    public PrgState execute(PrgState state) throws Exception {
        IStmt st = new CompStmt(stmt1,
                new WhileStatement(new NegExp(exp2), stmt1)
                );
        state.getExeStack().push(st);
        return null;
    }

    @Override
    public String toString() {
        return "repeat " + stmt1 + " until " + exp2;
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        return typeEnv;
    }
}
