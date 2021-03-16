package Model.adt;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class ClassHeap<Integer, Value> implements IHeap<Integer, Value> {
    private HashMap<Integer, Value> heap;

    public ClassHeap() {
        heap = new HashMap<Integer, Value>();
    }

    @Override
    public HashMap<Integer, Value> getHeap() {
        return heap;
    }

    @Override
    public Map<Integer, Value> getContent() {
        return heap.entrySet().stream()
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    @Override
    public void setContent(HashMap<Integer, Value> h) {
        heap = h;
    }



    public ClassHeap(HashMap<Integer, Value> heap) {
        this.heap = heap;
    }

    public int getFreeAddress() {
        return heap.size() + 1;
    }

    @Override
    public void add(Integer key, Value value) {
        heap.put(key, value);
    }

    @Override
    public void update(Integer key, Value value) {
        heap.put(key, value);
    }

    @Override
    public Model.values.Value lookup(Integer key) {
        return (Model.values.Value) heap.get(key);
    }

    @Override
    public boolean isDefined(Integer key) {
        return heap.containsKey(key);
    }

    @Override
    public String toString() {
        String returnValue = "";
        for (Map.Entry<Integer, Value> e : heap.entrySet()) {
            Integer key = e.getKey();
            Value v = e.getValue();
            returnValue += key.toString() + ' ' + v.toString() +"\n";
        }
        return returnValue;
    }
}
