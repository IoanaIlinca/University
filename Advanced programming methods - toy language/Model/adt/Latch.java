package Model.adt;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class Latch<Integer, Value> implements ILatch<Integer, Value> {
    private HashMap<Integer, Value> latch;

    public Latch() {synchronized(this){
        latch = new HashMap<Integer, Value>();
    }}

    @Override
    public HashMap<Integer, Value> getLatch() {synchronized(this){
        return latch;
    }}

    @Override
    public Map<Integer, Value> getContent() {synchronized(this){
        return latch.entrySet().stream()
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }}

    @Override
    public void setContent(HashMap<Integer, Value> h) {synchronized(this){
        latch = h;
    }}



    public Latch(HashMap<Integer, Value> latch) {synchronized(this){
        this.latch = latch;
    }}

    public int getFreeAddress() {synchronized(this) {
        return latch.size() + 1;
    }}

    @Override
    public void add(Integer key, Value value) {synchronized(this) {
        latch.put(key, value);
    }}

    @Override
    public void update(Integer key, Value value) {synchronized(this) {
        latch.put(key, value);
    }}

    @Override
    public Value lookup(Integer key) {synchronized(this) {
        return latch.get(key);
    }}

    @Override
    public boolean isDefined(Integer key) {synchronized(this) {
        return latch.containsKey(key);
    }}

    @Override

    public String toString() {synchronized(this)  {
        String returnValue = "";
        for (Map.Entry<Integer, Value> e : latch.entrySet()) {
            Integer key = e.getKey();
            Value v = e.getValue();
            returnValue += key.toString() + ' ' + v.toString() +"\n";
        }
        return returnValue;
    } }
}
