import java.util.*;

public class clinicVillage{
    public static double minLoad(int[] population,int n,int k){

        PriorityQueue<double[]> pqMax=new PriorityQueue<>((a,b) -> Double.compare(b[0],a[0]));

        for (int i=0;i<n;i++){
            pqMax.add(new double[]{population[i],population[i],1});
        }

        int extra=k-n;

        while(extra>0){

            double[] top=pqMax.poll();
            double load=top[0];
            double popul=top[1];
            double clinic=top[2];
            clinic++;

            double newLoad=popul/clinic;

            pqMax.offer(new double[]{newLoad,popul,clinic});
            extra--;
        }

        return pqMax.peek()[0];
    }

    public static void main(String[] args) {

        int[] population = {200,20,50};
        int n=3;
        int k=5;

        double answer=minLoad(population,n,k);
        System.out.println(answer);
    }
}
