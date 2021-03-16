package Controller;
import Exceptions.EmptyStackException;
import Exceptions.LogPrgStateException;
import Model.adt.IStack;

import java.util.Collection;
import java.util.List;
import Model.programState.PrgState;
import Model.stmt.IStmt;
import Model.values.Value;
import Repo.IRepo;

import java.util.HashMap;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    private final IRepo repo;
    private ExecutorService executor;

    public Controller(IRepo repo) {
        this.repo = repo;
    }



    public void addProgram(PrgState newPrg) {
        repo.addPrg(newPrg);
    }

    public List<PrgState> removeCompletedProgram(List<PrgState> inPrgList) {
        return inPrgList.stream()
                .filter(p -> p.isNotCompleted())
                .collect(Collectors.toList());
    }

    public void oneStepForAllPrg(List<PrgState> prgList) throws InterruptedException {
        //before the execution, print the PrgState List into the log file
            prgList.forEach(prg -> {
                try {
                    repo.logPrgStateExec(prg);
                } catch (LogPrgStateException e) {
                    e.printStackTrace();
                }
            });


//RUN concurrently one step for each of the existing PrgStates
        //-----------------------------------------------------------------------
        //prepare the list of callables
        List<Callable<PrgState>> callList = prgList.stream()
                .map((PrgState p) -> (Callable<PrgState>)(() -> {return p.oneStep();}))
                .collect(Collectors.toList());

        //start the execution of the callables
        //it returns the list of new created PrgStates (namely threads)
        List<PrgState> newPrgList = executor.invokeAll(callList).stream()
                .map(future -> {
                            try {
                                return future.get();
                            } catch (Exception e) {
                                //here you can treat the possible exceptions thrown by statements
                                throw new RuntimeException(e.getCause().getMessage());
                                //return null;
                            }
                        }
                )
                .filter(p -> p != null)
                .collect(Collectors.toList());
                    //add the new created threads to the list of existing threads
                    prgList.addAll(newPrgList);
                    //------------------------------------------------------------------------------

                    //after the execution, print the PrgState List into the log file
                    prgList.forEach(prg -> {
                        try {
                            repo.logPrgStateExec(prg);
                        } catch (LogPrgStateException e) {
                            throw new RuntimeException(e.getMessage());
                        }
                    });
                    //Save the current programs in the repository
                    repo.setPrgList(prgList);


    }


    public void allStep(PrgState state) throws Exception{
        executor = Executors.newFixedThreadPool(2);
        //remove the completed programs
        List<PrgState> prgList=removeCompletedProgram(repo.getPrgList());
        var garbageCollector = new GarbageCollector();
        while(prgList.size() > 0){
            repo.getPrgList().stream().forEach(program -> program.getHeap().setContent(
                    (HashMap<Integer, Value>) garbageCollector.safeGarbageCollector(
                            garbageCollector.addIndirections(garbageCollector.getAddressFromTables(repo.getPrgList()),program.getHeap()),
                            program.getHeap())));
            oneStepForAllPrg(prgList);
            //remove the completed programs
            prgList=removeCompletedProgram(repo.getPrgList());
            prgList=removeCompletedProgram(repo.getPrgList());
        }
        executor.shutdownNow();
        //HERE the repository still contains at least one Completed Prg
        // and its List<PrgState> is not empty. Note that oneStepForAllPrg calls the method
        //setPrgList of repository in order to change the repository

        // update the repository state
        repo.setPrgList(prgList);
    }

    public void allStepGUI() throws Exception{
        executor = Executors.newFixedThreadPool(2);
        //remove the completed programs
        List<PrgState> prgList=removeCompletedProgram(repo.getPrgList());


        var garbageCollector = new GarbageCollector();
        if(prgList.size() > 0){
            repo.getPrgList().stream().forEach(program -> program.getHeap().setContent(
                    (HashMap<Integer, Value>) garbageCollector.safeGarbageCollector(
                            garbageCollector.addIndirections(garbageCollector.getAddressFromTables(repo.getPrgList()),program.getHeap()),
                            program.getHeap())));
            oneStepForAllPrg(prgList);
            //remove the completed programs
            //prgList=removeCompletedProgram(repo.getPrgList());
            //prgList=removeCompletedProgram(repo.getPrgList());
        }
        if(prgList.size() > 0)
            executor.shutdownNow();
        //HERE the repository still contains at least one Completed Prg
        // and its List<PrgState> is not empty. Note that oneStepForAllPrg calls the method
        //setPrgList of repository in order to change the repository

        // update the repository state
        repo.setPrgList(prgList);
    }

    public List<PrgState> getProgramList() {
        return this.repo.getPrgList();
    }
}
