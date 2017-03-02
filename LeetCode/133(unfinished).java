/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
    	if (node == null) {
    		return null;
    	}
    	UndirectedGraphNode newNode = new UndirectedGraphNode(node.label);
    	HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<>();
    	Queue<UndirectedGraphNode> queue = new LinkedList<>();

    	queue.put(node, newNode);
    	queue.offer(node);

    	
    }
}