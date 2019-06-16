# program for bst in python
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key
        self.parent = None

# insert function in bst


def insert(root, node):
    if root is None:
        root = node
    else:
        if root.value < node.value:
            if root.right is None:
                root.right = node
                node.parent = root
            else:
                insert(root.right, node)
        else:
            if root.left is None:
                root.left = node
                node.parent = root
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

# searching of node in bst


def search(root, key):
    if root is None or root.value == key:
        return root
    elif root.value < key:
        return search(root.right, key)
    else:
        return search(root.left, key)


#min and max in bst
def minmum(root):
    if root == None:
        return None
    while(root.left != None):
        root = root.left
    return root


def maximum(root):
    if root == None:
        return None
    while(root.right != None):
        root = root.right
    return root

#sucessor and predessor in bst


def treesucc(x):
    if(x.right != None):
        return minmum(x.right)
    # to handle the case when there is no right sub tree
    y = x.parent
    while(y != None and x == y.right):
        x = y
        y = y.p
    return y

# predecessor code for bst


def treepred(x):
    if(x.left != None):
        return maximum(x.left)
    # to handle the case when there is no left sub tree
    y = x.parent
    while(y != None and x == y.left):
        x = y
        y = y.p
    return y

# different function for pred and successor


def predsucc(root, key, pred, succ):
    if(root == None):
        return
    elif(root.value == key):
        pred = maximum(root.left)
        succ = minmum(root.right)
        return
    elif(root.value < key):
        pred = root
        predsucc(root.right, key, pred, succ)
    else:
        succ = root
        predsucc(root.left, key, pred, succ)

# transplant procedure helps to replace the subtrees with in the tree


def transplant(root, u, v):
    # this procedure replaces the sub tree rooted at node u with the subtree rooted at node v
    if u.parent == None:
        # case when u is the root
        root = v
    elif u.parent.left == u:
        u.parent.left = v
    else:
        u.parent.right = v
    if v != None:
        v.parent = u.parent

# delete case in bst
# at total we had to handle three cases for this sought of problem


def delete(root, z):
    # z is the node to delete
    if z.left == None:
        transplant(root, z, z.right)
    elif z.right == None:
        transplant(root, z, z.left)
    else:
        y = minmum(z.right)
        if y.parent != z:
            transplant(root, y, y.right)
            y.right = z.right
            y.right.parent = y
        transplant(root, z, y)
        y.left = z.left
        y.left.p = y


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
    print(search(r, 7).value)
    print(search(r, 10))
    print(minmum(r).value)
    print(maximum(r).value)
    a = search(r, 5)
    v = treesucc(a)
    print(v.value)
    delete(r, a)
    print("inorder")
    inorder(r)
