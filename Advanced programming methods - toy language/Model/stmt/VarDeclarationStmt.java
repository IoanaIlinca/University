package Model.stmt;

import Exceptions.AlreadyDeclaredVariableException;
import Exceptions.AssignmentTypesException;
import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.BooleanType;
import Model.types.IntegerType;
import Model.types.*;
import Model.values.Value;

public final class VarDeclarationStmt implements IStmt{
    private final Type type;
    public final String id;

    public VarDeclarationStmt (Type type, String id) {
        this.type = type;
        this.id = id;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        IDict<String, Value> symtable = state.getSymTable();

        if(!symtable.isDefined(id)) {
            if (type.equals(new IntegerType())) {
                symtable.add(id, new IntegerType().defaultValue());
            }
            if (type.equals(new BooleanType())) {
                symtable.add(id, new BooleanType().defaultValue());
            }
            if (type.equals(new StringType())) {
                symtable.add(id, new StringType().defaultValue());
            }
            if (type.equals(new RefType(new IntegerType()))) {
                symtable.add(id, new RefType(new IntegerType()).defaultValue());
            }
            if (type.equals(new RefType(new StringType()))) {
                symtable.add(id, new RefType(new StringType()).defaultValue());
            }
            if (type.equals(new RefType(new BooleanType()))) {
                symtable.add(id, new RefType(new BooleanType()).defaultValue());
            }

        }
        else
            throw new AlreadyDeclaredVariableException("The variable " + id + " was already declared \n");
        return null;
    }

    public String toString() {
        return type.toString() + ": " + id +";\n";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception{
        typeEnv.add(id, type);

        return typeEnv;
    }
}
