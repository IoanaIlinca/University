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

public final class IfStmt implements IStmt{
    private final Exp expression;
    private final IStmt ifBlock;
    private final IStmt elseBlock;

    public IfStmt(Exp exp, IStmt ifBl, IStmt elseBl) {
        this.expression = exp;
        this.ifBlock = ifBl;
        this.elseBlock = elseBl;
    }


    @Override
    public PrgState execute(PrgState state) throws Exception {
        IStack<IStmt> stack = state.getExeStack();
        Value val = this.expression.eval(state.getSymTable(), state.getHeap());
        if (val.toBoolean().getType().equals(new BooleanType()))
        {
            BooleanValue boolVal = val.toBoolean();
            if(boolVal.getValue()) {
                stack.push(ifBlock);
            }
            else {
                stack.push(elseBlock);
            }

            return null;
        }
        else {
            throw  new ExpectedBooleanException("The if statement expects a boolean expression");
        }
    }

    public String toString() {
        return "If (" + this.expression.toString() + ") then {" + this.ifBlock.toString() + "} else {" + this.elseBlock.toString() + "\n}";
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typexp=expression.typecheck(typeEnv);
        //System.out.println(typexp);
        if (typexp.equals(new BooleanType()) || typexp.equals(new IntegerType()))  {
            ifBlock.typecheck(typeEnv.clone());
            elseBlock.typecheck(typeEnv.clone());
            return typeEnv;
        }
        else throw new ExpectedBooleanException("The condition of IF has not the type bool");
    }
}
