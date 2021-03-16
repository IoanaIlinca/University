package Model.stmt;

import Model.adt.IDict;
import Model.adt.IStack;
import Model.programState.PrgState;
import Model.types.Type;

public final class CompStmt implements IStmt{
    private final IStmt left;
    private final IStmt right;

    public CompStmt(IStmt l, IStmt r)
    {
        left = l;
        right = r;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        IStack<IStmt> stack = state.getExeStack();
        stack.push(this.right);
        stack.push(this.left);
        return null;
    }

    public String toString() {
        return this.left.toString() + this.right.toString();
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception{
        //IDict<String,Type> typEnv1 = left.typecheck(typeEnv);
        //IDict<String,Type> typEnv2 = right.typecheck(typEnv1);
        //return typEnv2;
        return right.typecheck(left.typecheck(typeEnv));
    }
}
