# program for bst in python
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key

# insert function in bst


def insert(root, node):
    if root is None:
        root = node
    else:
        if root.value < node.value:
            if root.right is None:
                root.right = node
            else:
                insert(root.right, node)
        else:
            if root.left is None:
                root.left = node
            else:
                insert(root.left, node)

#traversal in bst


def inorder(root):
    if root:
        inorder(root.left)
        print(root.value)
        inorder(root.right)


def preorder(root):
    if root:
        print(root.value)
        preorder(root.left)
        preorder(root.right)


def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.value)


if __name__ == "__main__":
    r = Node(6)
    insert(r, Node(7))
    insert(r, Node(5))
    insert(r, Node(2))
    insert(r, Node(5))
    insert(r, Node(8))
    print("inorder")
    inorder(r)
    print("preorder")
    preorder(r)
    print("postorder")
    postorder(r)
