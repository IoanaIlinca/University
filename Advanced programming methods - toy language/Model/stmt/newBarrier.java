package Model.stmt;

import Model.adt.IDict;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.Type;
import Model.values.IntegerValue;
import org.javatuples.Pair;

import java.util.ArrayList;
import java.util.List;

public final class newBarrier implements IStmt{
    private final String var;
    private final Exp exp;

    public newBarrier(String var, Exp exp) {
        this.var = var;
        this.exp = exp;
    }


    @Override
    public PrgState execute(PrgState state) throws Exception {
        var number = exp.eval(state.getSymTable(), state.getHeap());

        Pair<Integer, java.util.List<Integer>> newFreeLocation = new Pair(((IntegerValue) number).value, new java.util.ArrayList<Integer>());
        if (state.getSymTable().lookup(var) != null)
        {
            state.getSymTable().update(var, number);
            state.getBarrierTable().add(((IntegerValue) state.getSymTable().lookup(var)).getValue(), new Pair(((IntegerValue) number).value, new ArrayList<Integer>()));
        }
        else {
            state.getSymTable().add(var, number);
            state.getBarrierTable().add(((IntegerValue) state.getSymTable().lookup(var)).getValue(), new Pair(((IntegerValue) number).value, new ArrayList<Integer>()));
        }

        return null;
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {

            return typeEnv;

    }

    public String toString()  {
        String returnValue = "";
        returnValue = "newBarrier(" + var + ", " + exp + ");\n";
        return returnValue;
    }
}
