/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public IList<double> AverageOfLevels(TreeNode root) {
        IList<double> res = new List<double>();
        if (root == null) return res;

        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        while (queue.Count > 0) {
            long levelsum = 0;
            int size = queue.Count;
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.Dequeue();
                levelsum += node.val;
                if (node.left != null) queue.Enqueue(node.left);
                if (node.right != null) queue.Enqueue(node.right);
            }
            res.Add(1.0 * levelsum / size);
        }

        return res;
    }
}
