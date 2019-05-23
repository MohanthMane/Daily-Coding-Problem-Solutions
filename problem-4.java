/*
 
 Question :
 
 This problem was asked by Google.
 
 Given the root to a binary tree, implement serialize(root),
 which serializes the tree into a string, and deserialize(s),
 which deserializes the string back into the tree.
 
*/


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/*
 
 I solved this problem in LeetCode.
 So, we just need to implement serialize and deserialize
 
*/

public class Codec {
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) return "X,";
        
        String leftTree = serialize(root.left);
        String rightTree = serialize(root.right);
        
        return root.val + "," + leftTree + rightTree;
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        
        Queue<String> q = new LinkedList<>();
        q.addAll(Arrays.asList(data.split(",")));
        return utilDeserialize(q);
        
    }
    
    public TreeNode utilDeserialize(Queue<String> q) {
        
        String newNode = q.poll();
        
        if(newNode.equals("X")) return null;
        
        TreeNode node = new TreeNode(Integer.valueOf(newNode));
        
        node.left = utilDeserialize(q);
        node.right = utilDeserialize(q);
        
        return node;
        
    }
    
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
