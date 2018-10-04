class TreeNode
{
    public int val;
    public TreeNode left = null;
    public TreeNode right = null;
    TreeNode(int x)
    {
        this.val = x;

    }
}

class TreePrint
{
    public  void postOrderPrint(TreeNode root)
    {
        if(root == null)
            return;
        System.out.println("后序遍历：");
        Stack<TreeNode> s1 = new Stack<TreeNode>();
        Stack<TreeNode> s2 = new Stack<TreeNode>();
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode tmp = s1.pop();
            s2.push(tmp) ;
            if(tmp.left != null)
                s1.push(tmp.left);
            if(tmp.right != null)
                s1.push(tmp.right);

        }
        while(!s2.empty())
            System.out.print(s2.pop().val+" ");
        System.out.println();

    }

    public void inOrderPrint(TreeNode root)
    {
        if(root == null)
            return;
        System.out.println("中序遍历：");
        Stack<TreeNode> s = new Stack<TreeNode>();
        while(!s.empty() || root != null)
        {
            if(root != null)
            {
                s.push(root);
                root = root.left;

            }
            else
            {
                System.out.print(s.peek().val+" ");
                root = s.pop().right;

            }

        }
        System.out.println();

    }

    public void preOrderPrint(TreeNode root)
    {
        if(root == null)
            return;
        System.out.println("先序遍历：");
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        while(!s.empty())
        {
            TreeNode tmp = s.pop();
            System.out.print(tmp.val+" ");
            if(tmp.left != null)
                s.push(tmp.right);
            if(tmp.right != null)
                s.push(tmp.left);

        }
        System.out.println();

    }

}

public class Main{
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode node1 = new TreeNode(2);
        TreeNode node2 = new TreeNode(3);
        TreeNode node3 = new TreeNode(4);
        TreeNode node4 = new TreeNode(5);
        TreeNode node5 = new TreeNode(6);
        TreeNode node6 = new TreeNode(7);
        root.left = node1;
        root.right = node2;
        node1.left = node3;
        node1.right = node4;
        node2.left = node5;
        node2.right = node6;
        TreePrint p = new TreePrint();
        p.postOrderPrint(root);
        p.inOrderPrint(root);
        p.preOrderPrint(root);
    }
}
