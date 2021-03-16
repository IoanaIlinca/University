package Model.stmt;

import Model.adt.ClassStack;
import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.Type;

public final class ForkStmt implements IStmt{
    private final IStmt statement;

    public ForkStmt(IStmt statement) {
        this.statement = statement;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {

        //IDict<String, Type> typeEnv2 = new Dict<String, Type>();
        //this.typecheck(typeEnv2);
        var symTableDeepCopy = state.getSymTable().Copy();
        var forkedState = new PrgState(
                new ClassStack<IStmt>(),
                symTableDeepCopy,
                state.getOutputStream(),
                state.getFileTable(),
                state.getBarrierTable(), state.getHeap(),
                this.statement,
                state.getSemaphoreTable(), state.getLock(), state.getLatch());

        return forkedState;
    }

    @Override
    public String toString() {
        return "fork(" + statement.toString() + ")\n";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        statement.typecheck(typeEnv);
        return typeEnv;
    }
}
