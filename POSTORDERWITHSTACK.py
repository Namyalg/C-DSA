# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#modified pre order
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        nodes = [root]
        res = []
        curr = root
        while nodes and curr != None:
            curr = nodes.pop()
            res.append(curr.val)
            if curr.left != None:
                nodes.append(curr.left)
            if curr.right != None:
                nodes.append(curr.right)
           
        return res[::-1]
