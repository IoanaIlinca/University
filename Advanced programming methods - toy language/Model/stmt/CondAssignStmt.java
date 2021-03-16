package Model.stmt;

import Model.adt.IDict;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.Type;

public final class CondAssignStmt implements IStmt {
    private final String v;
    private final Exp exp1;
    private final Exp exp2;
    private final Exp exp3;

    public CondAssignStmt(String v, Exp exp1, Exp exp2, Exp exp3) {
        this.v = v;
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.exp3 = exp3;
    }


    @Override
    public PrgState execute(PrgState state) throws Exception {
        var val1 = exp1.eval(state.getSymTable(), state.getHeap());
        var val2 = exp2.eval(state.getSymTable(), state.getHeap());
        var val3 = exp3.eval(state.getSymTable(), state.getHeap());

        IStmt s = new IfStmt(exp1, new AssignStmt(v, exp2), new AssignStmt(v, exp3));

        state.getExeStack().push(s);
        return null;
    }

    @Override
    public String toString() {
        String res = "";
        res += v + " = " + exp1.toString() + " ? " + exp2.toString() + ":" + exp3.toString() + ";\n";
        return res;
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        return typeEnv;
    }
}
