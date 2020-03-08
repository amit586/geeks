class Node(object):
	"""docstring for Node"""
	def __init__(self, arg):
		super(Node, self).__init__()
		self.data = arg
		self.left=None
		self.right=None

def inorder(root):
	if root is None:
		return 
	inorder(root.left)
	print(root.data , end=" ")
	inorder(root.right)

def deleteDeepest(root,child):
	q = []
	q.append(root)
	while(len(q)):
		temp = q.pop(0)
		if temp is child:
			temp=None
			return
		if temp.left is child:
			temp.left = None
			return 
		else :
			q.append(temp.left)

		if(temp.right is child):
			temp.rith = None
			return 
		else :
			q.append(temp.right)
	return


def delete(root , key):
	if root==None:
		return None
	if root.left==None and root.right==None:
		if root.data == key:
			return None
		else:
			return root
	q = []
	q.append(root)
	keynode=None
	while len(q):
		temp = q.pop(0)

		if(temp.data==key):
			keynode =temp

		if temp.left:
			q.append(temp.left)
		if temp.right:
			q.append(temp.right)
	if keynode :
		x = temp.data
		deleteDeepest(root,temp)
		keynode.data=x
	return root

if __name__=='__main__': 
    root = Node(10) 
    root.left = Node(11) 
    root.left.left = Node(7) 
    root.left.right = Node(12) 
    root.right = Node(9) 
    root.right.left = Node(15) 
    root.right.right = Node(8) 
    print("The tree before the deletion:") 
    inorder(root) 
    key = 11
    root = delete(root, key) 
    print() 
    print("The tree after the deletion;") 
    inorder(root) 