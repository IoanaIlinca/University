package Model.stmt;

import Exceptions.NotDeclaredVariable;
import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.Type;
import Model.values.IntegerValue;

public final class AwaitBarrier implements IStmt {
    private final String var;

    public AwaitBarrier(String var) {
        this.var = var;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        var foundIndex= state.getSymTable().lookup(var);
        if (state.getSymTable().lookup(var) != null)
        {
            Integer index = ((IntegerValue) foundIndex).value;
            if(state.getBarrierTable().isDefined(index)){
                var p = state.getBarrierTable().lookup(index);
                var NL = p.getValue1().size();
                var N1 = p.getValue0();
                if (N1 > NL)
                {
                    if(p.getValue1().contains(state.getId()))
                        state.getExeStack().push(this);
                    else
                    {
                        p.getValue1().add(state.getId());
                        state.getExeStack().push(this);
                    }

                }
            }

            else
            {
                throw new RuntimeException("It is not in the barrier");
            }
        }
        else
            throw new NotDeclaredVariable("The variable was not declared");
        return null;
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {

            return typeEnv;
    }

    public String toString()  {
        String returnValue = "";
        returnValue = "await(" + var + ");\n";
        return returnValue;
    }
}