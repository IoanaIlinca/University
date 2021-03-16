package Model.adt;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class BarrierTable <Integer, Value> implements IBarrier<Integer, Value> {
    private HashMap<Integer, Value> barrier;

    public BarrierTable() {synchronized(this){
        barrier = new HashMap<Integer, Value>();
    }}

    @Override
    public HashMap<Integer, Value> getBarrier() {synchronized(this){
        return barrier;
    }}

    @Override
    public Map<Integer, Value> getContent() {synchronized(this){
        return barrier.entrySet().stream()
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }}

    @Override
    public void setContent(HashMap<Integer, Value> h) {synchronized(this){
        barrier = h;
    }}



    public BarrierTable(HashMap<Integer, Value> barrier) {synchronized(this){
        this.barrier = barrier;
    }}

    public int getFreeAddress() {synchronized(this) {
        return barrier.size() + 1;
    }}

    @Override
    public void add(Integer key, Value value) {synchronized(this) {
        barrier.put(key, value);
    }}

    @Override
    public void update(Integer key, Value value) {synchronized(this) {
        barrier.put(key, value);
    }}

    @Override
    public Value lookup(Integer key) {synchronized(this) {
        return barrier.get(key);
    }}

    @Override
    public boolean isDefined(Integer key) {synchronized(this) {
        return barrier.containsKey(key);
    }}

    @Override

    public String toString() {synchronized(this)  {
        String returnValue = "";
        for (Map.Entry<Integer, Value> e : barrier.entrySet()) {
            Integer key = e.getKey();
            Value v = e.getValue();
            returnValue += key.toString() + ' ' + v.toString() +"\n";
        }
        return returnValue;
    } }
}
