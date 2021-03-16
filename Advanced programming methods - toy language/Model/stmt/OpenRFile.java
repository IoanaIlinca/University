package Model.stmt;

import Model.adt.IDict;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.StringType;
import Model.types.Type;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

public final class OpenRFile implements IStmt {
    private  final Exp fileName;
    public OpenRFile(Exp fileName) {
        this.fileName = fileName;
    }
    public Exp getFileName() {return  fileName;}

    @Override
    public PrgState execute(PrgState state) throws Exception {
        var fileTable = state.getFileTable();
        var fileName = this.fileName.eval(state.getSymTable(), state.getHeap()).toString();

        if( fileTable.isDefined(fileName))
            throw new RuntimeException("File already open\n");
        try{
            var reader = new BufferedReader( new FileReader(fileName));
            fileTable.set(fileName, reader);
        } catch ( FileNotFoundException e){
            throw new RuntimeException("Cannot create file reader",e);
        }
        return null;
    }

    @Override
    public String toString() {
        return "open(" + fileName.toString() + ");\n";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typexp=fileName.typecheck(typeEnv);
        if (typexp.equals(new StringType()))
            return typeEnv;
        else throw new RuntimeException("Expression must be of type string!");

    }
}
