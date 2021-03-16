package Model.stmt;

import Exceptions.ExpectedIntegerException;
import Exceptions.NotDeclaredVariable;
import Model.adt.IDict;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.IntegerValue;

public class newLatch implements IStmt{
    private final String var;
    private final Exp exp;

    public newLatch(String var, Exp exp) {
        this.var = var;
        this.exp = exp;
    }


    @Override
    public PrgState execute(PrgState state) throws Exception {
        var num1 = exp.eval(state.getSymTable(), state.getHeap());
        if(!(num1 instanceof IntegerValue))
            throw new ExpectedIntegerException("The result of the expression is not an integer");
        Integer newFreeLocation = ((IntegerValue) num1).value;
        if (state.getSymTable().lookup(var) != null && state.getSymTable().lookup(var).getType().equals(new IntegerType()))
        {
            state.getSymTable().update(var, num1);
            state.getLatch().add(newFreeLocation, ((IntegerValue) state.getSymTable().lookup(var)).getValue());
        }
        else
            throw new NotDeclaredVariable("The variable was not declared or it is not an integer");

        return null;
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typ1 = exp.typecheck(typeEnv);
        Type typ2 = typeEnv.lookup(var);

        if (typ1.equals(new IntegerType()) && typ2.equals(new IntegerType()))
            return typeEnv;
        else
            throw new ExpectedIntegerException("The result of the expression is not an integer or var is not an integer");
    }

    public String toString()  {
        String returnValue = "";
        returnValue = "newLatch(" + var + ", " + exp + ");\n";
        return returnValue;
    }
}
