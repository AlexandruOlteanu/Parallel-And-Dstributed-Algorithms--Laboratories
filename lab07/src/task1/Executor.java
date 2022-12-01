package task1;

import java.io.File;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.atomic.AtomicInteger;

public class Executor implements Runnable {

    ExecutorService type;
    ArrayList<Integer> inQueue;
    int dest;

    public Executor(ExecutorService type, ArrayList<Integer> inQueue,int dest) {
        //this.path = path;
        this.type = type;
        this.inQueue = inQueue;
        this.dest = dest;
    }

    @Override
    public void run() {
        if (inQueue.get(inQueue.size() - 1) == dest) {
            System.out.println(inQueue);
            type.shutdown();
            return;

        }

        int lastNodeInPath = inQueue.get(inQueue.size() - 1);
        for (int[] ints : Main.graph) {
            if (ints[0] == lastNodeInPath) {
                if (inQueue.contains(ints[1]))
                    continue;
                ArrayList<Integer> newPartialPath = new ArrayList<>(inQueue);
                newPartialPath.add(ints[1]);
                type.submit(new Executor(type, newPartialPath,3));
            }
        }
    }
}