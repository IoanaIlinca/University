package Model.stmt;

import Exceptions.ExpectedBooleanException;
import Model.adt.IDict;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.BooleanType;
import Model.types.StringType;
import Model.types.Type;
import Model.values.IntegerValue;

public final class ReadFile implements IStmt {
    private final String varName;
    private final Exp exp;

    public ReadFile(String varName, Exp exp) {
        this.varName = varName;
        this.exp = exp;
    }
    public String getVarName() { return varName; }

    public Exp getExp() { return exp; }


    @Override
    public PrgState execute(PrgState state) throws Exception {
        var symTable = state.getSymTable();
        var fileTable = state.getFileTable();
        var heap = state.getHeap();
        if(!(symTable.isDefined(this.varName))){
            throw new RuntimeException("Variable " + varName +" not declared\n");
        }
        var filename = this.exp.eval(symTable, heap);
        System.out.println(filename.toString());
        if(!(filename.getType().equals(new StringType()))){
            throw new RuntimeException("Expression must be of string type\n");
        }

        if(!(fileTable.isDefined(filename.toString()))){
            throw new RuntimeException("Invalid file name!\n");
        }
        int valueFromFile=0;
        var line = fileTable.lookup(filename.toString()).readLine();
        if(line == null) {
            valueFromFile = 0;
        } else{
            valueFromFile = Integer.parseInt(line);
        }

        symTable.add(varName, new IntegerValue(valueFromFile));
        return null;
    }

    @Override
    public String toString() {
        return "read(" + this.varName + ", " + exp.toString() + ");\n";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typexp=exp.typecheck(typeEnv);
        return typeEnv;

    }
}
