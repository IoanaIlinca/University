package Model.stmt;

import Model.adt.IDict;
import Model.programState.PrgState;
import Model.types.RefType;
import Model.types.Type;
import Model.values.Value;

public final class RefDeclarationStmt implements IStmt {
    private final Type type;
    private final String identifier;

    public RefDeclarationStmt(Type type, String identifier) {
        this.type = type;
        this.identifier = identifier;
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        IDict<String, Value> symbolTable = state.getSymTable();

        if (!symbolTable.isDefined(identifier)) {
            symbolTable.add(identifier, new RefType(this.type).defaultValue());
        } else {
            throw new RuntimeException("Variable " + identifier + " was already declared");
        }
        return null;
    }

    @Override
    public String toString() {
        return "Ref " + type.toString() + " " + identifier + "\n";
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception{
        typeEnv.add(identifier, new RefType(type));
        return typeEnv;
    }
}
