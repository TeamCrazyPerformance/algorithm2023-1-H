n = int(input())
tree = {i: [0,0] for i in range(ord("A"),n+ord("A"))}

for i in range(n):
    curr, left, right = list(input().split())
    if left != ".":
        tree[ord(curr)][0] = ord(left)
    if right != ".":
        tree[ord(curr)][1] = ord(right)

def preorder(root):
    print(chr(root), end="")
    if tree[root][0] != 0:     # Left
        preorder(tree[root][0])
    if tree[root][1] != 0:      # Right
        preorder(tree[root][1])

def inorder(root):
    if tree[root][0] != 0:     # Left
        inorder(tree[root][0])
    
    print(chr(root), end="")

    if tree[root][1] != 0:      # Right
        inorder(tree[root][1])

def postorder(root):
    if tree[root][0] != 0:     # Left
        postorder(tree[root][0])
    if tree[root][1] != 0:      # Right
        postorder(tree[root][1])
    
    print(chr(root), end="")

preorder(ord("A"))
print()
inorder(ord("A"))
print()
postorder(ord("A"))
print()
