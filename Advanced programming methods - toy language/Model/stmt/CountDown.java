package Model.stmt;

import Exceptions.ExpectedIntegerException;
import Exceptions.NotDeclaredVariable;
import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.IntegerType;
import Model.types.Type;
import Model.values.IntegerValue;

public final class CountDown implements IStmt {
    private final String var;

    public CountDown(String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        var foundIndex= state.getSymTable().lookup(var);
        if (state.getSymTable().lookup(var) != null && state.getSymTable().lookup(var).getType().equals(new IntegerType()))
        {
            Integer index = ((IntegerValue) foundIndex).value;
            if(state.getLatch().isDefined(index)) {
                Integer val = state.getLatch().lookup(index);
                if (val > 0)
                    state.getLatch().update(index, val - 1);
                state.getOutputStream().add(((Integer) state.getId()).toString());
            }

            else
                {
                    throw new RuntimeException("It is not in the latch");
                }
        }
        else
            throw new NotDeclaredVariable("The variable was not declared or it is not an integer");
        return null;
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typ1 = typeEnv.lookup(var);

        if (typ1.equals(new IntegerType()))
            return typeEnv;
        else
            throw new ExpectedIntegerException("Var is not an integer");
    }

    public String toString()  {
        String returnValue = "";
        returnValue = "countDown(" + var + ");\n";
        return returnValue;
    }
}
