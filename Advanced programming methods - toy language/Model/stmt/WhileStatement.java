package Model.stmt;

import Exceptions.ExpectedBooleanException;
import Model.adt.IDict;
import Model.adt.IStack;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.BooleanType;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.BooleanValue;
import Model.values.Value;

public final class WhileStatement implements IStmt {
    private final Exp Expression;
    private final IStmt Statement;

    public WhileStatement (Exp Expr, IStmt St) {
        Expression = Expr;
        Statement = St;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        IStack<IStmt> stack = state.getExeStack();
        Value val = this.Expression.eval(state.getSymTable(), state.getHeap());
        if (val.toBoolean().getType().equals(new BooleanType()))
        {
            BooleanValue boolVal = val.toBoolean();
            if(boolVal.getValue()) {
                stack.push(this);
                stack.push(Statement);
            }

            return null;
        }
        else {
            throw  new ExpectedBooleanException("The if statement expects a boolean expression");
        }
    }

    @Override
    public String toString() {
        return "While (" + this.Expression.toString() + ")\n{" + this.Statement.toString() + "}";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typexp=Expression.typecheck(typeEnv);
        //System.out.println(typexp);
        if (typexp.equals(new BooleanType()) || typexp.equals(new IntegerType())) {
            Statement.typecheck(typeEnv.clone());
            return typeEnv;
        }
        else throw new ExpectedBooleanException("The condition of While does not the type bool");
    }
}
