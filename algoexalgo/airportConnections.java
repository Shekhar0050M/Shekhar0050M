import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

/**
 * @author : Shekhar Suman (shekhar0050m@gmail.com)
 * @file : airportConnections
 * @created : Wednesday Sep 28, 2022 18:06:57 IST
 */

class Airport {
	int serialno = 0;
	HashMap<Integer, Integer> hm = new HashMap<>();
}

public class airportConnections {
	public static void main(String[] args) {
		int nAirports = 18, source = 5, destination = 8;
		int[][] totalAirportConnections = new int[][] { 
				{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, };
		function(totalAirportConnections, nAirports);
	}

	private static void function(int[][] totalAirportConnections, int nAirports) {
		// Initial Storage
		ArrayList<Airport> al = new ArrayList<>();
		Queue<Integer> qu = new LinkedList<>();
		HashMap<Integer, Integer> mp = new HashMap<>();
		int serialno = 0;
		// Phase 1
		for (int x = 0; x < nAirports; x++) {
			serialno = x;
			qu.add(serialno);
			mp.clear();
			while (!qu.isEmpty()) {
				int sno = qu.poll();
				for (int i = 0; i < nAirports; i++) {
					if (totalAirportConnections[sno][i] == 1 && !mp.containsKey(i)) {
						qu.add(i);
						mp.put(i, 1);
					}
				}
			}
			Airport ap = new Airport();
			ap.serialno = serialno;
			ap.hm = new HashMap<>(mp);
			al.add(ap);
		}
		// Phase 2
		Collections.sort(al, new Comparator<Airport>() {
			@Override
			public int compare(Airport a1, Airport a2) {
				int a = a1.hm.size();
				int b = a2.hm.size();
				if (a == b) {
					return 0;
				} else if (a < b) {
					return 1;
				} else {
					return -1;
				}
			}
		});
		for (int i = 0; i < al.size(); i++) {
			for (int j = i + 1; j < al.size(); j++) {
				boolean flag = true;
				for (Map.Entry<Integer, Integer> me : al.get(j).hm.entrySet()) {
					if (!al.get(i).hm.containsKey(me.getKey())) {
						flag = false;
						break;
					}
				}
				if (flag) {
					al.remove(j);
					j--;
				}
			}
		}
		System.out.println();
	}
}

//Step 1 : Put everything in a 2D matrix or Arraylist
//Step 2 : Go to each and every node and count and map the number of nodes reachable
//Step 3 : Sort the map as per the number of nodes reachable
//Step 4 : Eliminate those nodes which appear in another nodes , probably order of O(n2)
