class LinkNode:
	def __init__(self, value):
		self.element = value
		self.next = None

def append( pHead, value ):
	node = LinkNode(value)
	if pHead is None:
		pHead = node
	else:
		cur_node = pHead
		while cur_node.next is not None:
			cur_node = cur_node.next
		cur_node.next = node
	return pHead

def print_reverse( pHead ):
	node = pHead
	nodes_list = []
	while node is not None:
		nodes_list.append(node.element)
		node = node.next
	while len(nodes_list) > 0:
		print nodes_list.pop(),
	print ''

if __name__ == '__main__':
	pHead = None
	print_reverse( pHead )

	pHead = append( pHead, 4 )
	print_reverse( pHead )

	pHead = append( pHead, 5 )
	print_reverse( pHead )

	pHead = append( pHead, 3 )
	print_reverse( pHead )