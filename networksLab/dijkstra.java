public class Shekhar_Suman_B_113{
    public static void main(String[] args){
        int[][] graph = new int[][] {
                { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
        };
        Shekhar_Suman_B_113 shortestPath = new Shekhar_Suman_B_113();
        shortestPath.dijkstra(graph);
    }
    private void dijkstra(int[][] graph){
        for(int i=0;i<graph.length;i++){
            for(int j=0;j<graph[0].length;j++){
                if(graph[i][j]==0){
                    graph[i][j]=(int)1e9;
                }
            }
        }
        boolean[] visited = new boolean[graph.length];
        int source=0;
        int curNode=-1;
        graph[source][source]=0;
        while(!allVisited(visited)){
            curNode=currentMinNode(graph,visited);
            if(curNode==-1){
                break;
            }
            setAllNodes(graph,curNode);
            visited[curNode]=true;
        }
        printAllNode(graph);
    }
    private void setAllNodes(int[][] graph,int curNode){
        for(int i=0;i<graph[curNode].length;i++){
            if(graph[curNode][curNode]+graph[curNode][i]<graph[i][i]){
                graph[i][i]=graph[curNode][curNode]+graph[curNode][i];
            }
        }
    }
    private int currentMinNode(int[][] graph,boolean[] visited){
        int val=Integer.MAX_VALUE;
        int pos=-1;
        for(int i=0;i<graph.length;i++){
            if(graph[i][i]<val && visited[i]==false){
                val=graph[i][i];
                pos=i;
            }
        }
        return pos;
    }
    private boolean allVisited(boolean[] visited){
        for(int i=0;i<visited.length;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
    private void printAllNode(int[][] graph){
        System.out.println("Node    Distance from source");
        for(int i=0;i<graph.length;i++){
            System.out.println(i+"              "+graph[i][i]);
        }
    }
}


