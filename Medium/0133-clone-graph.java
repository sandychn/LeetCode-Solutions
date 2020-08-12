/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    private Map<Integer, Node> seen;

    public Node doClone(Node node) {
        if (node == null) {
            return null;
        }
        if (seen.containsKey(node.val)) {
            return seen.get(node.val);
        }
        ArrayList<Node> neighbors = new ArrayList<>();
        Node newNode = new Node(node.val, neighbors);
        seen.put(node.val, newNode);
        for (Node neighbor : node.neighbors) {
            neighbors.add(doClone(neighbor));
        }
        return newNode;
    }

    public Node cloneGraph(Node node) {
        seen = new HashMap<>();
        return doClone(node);
    }
}
