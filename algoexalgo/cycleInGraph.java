/**
 * @author      : Shekhar Suman (shekhar0050m@gmail.com)
 * @file        : cycleInGraph
 * @created     : Friday Sep 30, 2022 09:53:00 IST
 */

public class cycleInGraph{
    public static void main(String[] args){
        int[][] diGraph = new int[][]{
            {0,1,0,1,0,0},
            {0,1,1,1,0,0},
            {1,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,1,0,0,1,0},
            {0,0,0,0,0,0},
        };
        myMethod(diGraph);
    }

    private static void myMethod(int[][] diGraph){
        for(int i=0;i<diGraph.length;i++){
            if(isCyclicDFS(diGraph,new boolean[diGraph.length],i)){
                System.out.println("Graph is cyclic in nature.");
                return;
            }
        }
        System.out.println("Graph is non-cyclic in nature.");
    }
    private static boolean isCyclicDFS(int[][] diGraph,boolean[] check,int node){
        boolean res = false;
        for(int i=0;i<diGraph.length;i++){
            if(diGraph[node][i]==1){
                if(check[i]){
                    return true;
                }
                check[i]=true;
                res = res || isCyclicDFS(diGraph,check,i);
                check[i]=false;
            }
        }
        return res;
    }
}

//To count the number of loops we can put the nodes in DFS order in an dynamic array and then further operate of each array in list of arrays to eliminate repetive loops and then the size of our array will be the number of loops in a graph.
