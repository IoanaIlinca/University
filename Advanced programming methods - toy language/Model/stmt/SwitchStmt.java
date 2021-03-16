package Model.stmt;

import Model.adt.IDict;
import Model.exp.Exp;
import Model.exp.RelExp;
import Model.programState.PrgState;
import Model.types.Type;

public final class SwitchStmt implements IStmt {
    private final Exp exp;
    private final Exp exp1;
    private final Exp exp2;
    //private final Exp exp3;
    private final IStmt stmt1;
    private final IStmt stmt2;
    private final IStmt stmt3;

    public SwitchStmt(Exp exp, Exp exp1, Exp exp2, IStmt stmt1, IStmt stmt2, IStmt stmt3) {
        this.exp = exp;
        this.exp1 = exp1;
        this.exp2 = exp2;
        //this.exp3 = exp3;
        this.stmt1 = stmt1;
        this.stmt2 = stmt2;
        this.stmt3 = stmt3;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        //if(exp==exp1) then stmt1 else (if (exp==exp2) then stmt2 else stmt3)
        IStmt st = new IfStmt(new RelExp("==", exp, exp1), stmt1, new IfStmt(new RelExp("==", exp, exp2), stmt2, stmt3));
        state.getExeStack().push(st);
        return null;
    }

    @Override
    public String toString() {
        return "switch(" + exp + ") (case "+ exp1 + ":" + stmt1+ ") ( case " + exp2 +":" + stmt2 + ") (" + "default:" + stmt3 + "\n)";
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        return null;
    }
}
