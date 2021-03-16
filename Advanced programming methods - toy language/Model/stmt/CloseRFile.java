package Model.stmt;

import Exceptions.ExpectedBooleanException;
import Model.adt.IDict;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.BooleanType;
import Model.types.StringType;
import Model.types.Type;

import java.io.IOException;

public final class CloseRFile implements IStmt {
    private final Exp exp;

    public CloseRFile(Exp exp) {
        this.exp = exp;
    }

    public Exp getExp() { return exp; }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        var fileTable = state.getFileTable();
        var filename = this.exp.eval(state.getSymTable(), state.getHeap());
        if(!(filename.getType().equals(new StringType()))){
            throw new RuntimeException("Expression must be of type string\n");
        }

        if(!(fileTable.isDefined(filename.toString()))){
            throw new RuntimeException("Invalid file name!\n");
        }

        var reader = fileTable.lookup(filename.toString());
        try{
            reader.close();
        }catch (IOException ignored){ }

        fileTable.remove(filename.toString());
        return null;
    }

    @Override
    public String toString() {
        return "close(" + exp.toString() + ");\n";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typexp=exp.typecheck(typeEnv);
        if (typexp.equals(new StringType()))
            return typeEnv;
        else throw new RuntimeException("Expression must be of type string!");

    }
}
