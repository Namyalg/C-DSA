
#go to the utmost left, on hitting null print, 

and then set the current to the right and continue the same process till the stack is not empty same as level order, use a queue

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        curr = root
        stack = []
        res = []
        while stack or curr != None:
            while curr != None:
                stack.append(curr)
                curr = curr.left 
            curr = stack.pop()
            res.append(curr.val)
            curr = curr.right
        return res
