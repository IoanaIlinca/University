package Model.stmt;

import Model.adt.IDict;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.Type;
import Model.values.Value;

public final class PrintStmt implements IStmt {
    private final Exp expression;

    public PrintStmt(Exp expression) {
        this.expression = expression;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        Value val = expression.eval(state.getSymTable(), state.getHeap());
        state.getOutputStream().add(val.toString());
        return null;
    }

    public String toString() {
        return "print (" + expression.toString() + ");\n";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception{
        expression.typecheck(typeEnv);
        return typeEnv;
    }
}
