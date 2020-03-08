class node(object):
	"""docstring for node"""
	def __init__(self, arg):
		super(node, self).__init__()
		self.val = arg
		self.left = None
		self.right=None

root = node(1)
root.left = node(2)
root.right = node(3)
root.left.left = node(4)
root.left.right = node(5)