package Repo;
import Exceptions.LogPrgStateException;
import java.util.List;
import Model.programState.PrgState;

public interface IRepo {
    void addPrg(PrgState newPrg);
    //PrgState getCrtPrg();
    void logPrgStateExec(PrgState prgState) throws LogPrgStateException;
    List<PrgState> getPrgList();
    void setPrgList(List<PrgState> newPrgStates);
}
