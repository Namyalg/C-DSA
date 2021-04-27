class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        nodes = [root]
        res = []
        curr = root
        while nodes and curr != None:
            curr = nodes.pop()
            
            #push the current node
            
            res.append(curr.val)
            
            #add its right subtree
            if curr.right != None:
                nodes.append(curr.right)
                
             #then add right subtree as the order u need is Root Left Right
             
             #so u want left to be popped out first so u need to add right and then left as u want to pop left first
            if curr.left != None:
                nodes.append(curr.left)
          
        return res
