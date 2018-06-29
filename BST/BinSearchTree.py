Python 3.7.0a2 (v3.7.0a2:f7ac4fe, Oct 17 2017, 16:23:57) [MSC v.1900 32 bit (Intel)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> def is_bintree(T):
	if type(T) is not tuple:
		return False
	if T == ():
		return True
	if len(T) != 3:
		return False
	if is_bintree(T[1]) and is_bintree(T[2]):

		return True
	return False

	
>>> def bst_min(T):
	if T == ():
		return None
	if not T[1]:
		return T[0]
	return bst_min(T[1])

>>> def bst_max(T):
	if T == ():
		return None
	if not T[2]:
		return T[0]
	return bst_max(T[2])

>>> def is_bst(T):
	if not is_bintree(T):
		return False
	if T == ():
		return True
	if not is_bst(T[1]) or not is_bst(T[2]):
		return False
	if T[1] == () and T[2] == ():
		return True
	if T[2] == ():
		return bst_max(T[1]) < T[0]
	if T[1] == ():
		return T[0] < bst_min(T[2])
	return bst_max(T[1]) < T[0] < bst_min(T[2])

>>> def bst_search(T,x):
	if T == ():
		return T
	if T[0] == x:
		return T
	if x < T[0]:
		return bst_search(T[1],x)
	return bst_search(T[2],x)

>>> def bst_insert(T,x):
	if T == ():
		return (x,(),())
	elif x < T[0]:
		return (T[0],bst_insert(T[1],x),T[2])
	else:
		return (T[0],T[1],bst_insert(T[2],x))

	
>>> def delete_min(T):
	if T == ():
		return T
	if not T[1]:
		return T[2]
	else:
		return (T[0],delete_min(T[1]),T[2])

	
>>> def bst_delete(T,x):
	assert T, "deleting value not in tree"           
	if x < T[0]:
		return (T[0],bst_delete(T[1],x),T[2])
	elif x > T[0]:
		return (T[0],T[1],bst_delete(T[2],x))
	else:
		if not T[1]:
			return T[2]
		elif not T[2]:
			return T[1]
		else:
			return (bst_min(T[2]),T[1],delete_min(T[2]))

		
>>> def print_bintree(T,indent=0):
	if not T:
		print('*')
		return
	else:
		print(T[0])
		print(' '*(indent + len(T[0])-1)+'---', end = '')
		print_bintree(T[1],indent+3)
		print(' '*(indent + len(T[0])-1)+'---', end = '')
		print_bintree(T[2],indent+3)

		
>>> def print_func_space(x):
	print(x, end=' ')

	
>>> def inorder(T,f):
	if not is_bst(T):
		return
	if not T:
		return
	inorder(T[1],f)
	f(T[0])
	inorder(T[2],f)

	
>>> def preorder(T,f):
	if not is_bst(T):
		return
	if not T:
		return
	f(T[0])
	preorder(T[1],f)
	preorder(T[2],f)

	
>>> def postorder(T,f):
	if not is_bst(T):
		return
	if not T:
		return
	postorder(T[1],f)
	postorder(T[2],f)
	f(T[0])

	
>>> def tree_height(T):
	if T is None:
		return 0;
	else:
		return max(tree_height(T[1]),tree_height(T[2])) + 1

	
>>> def balance(T):
	if T is None:
		return
	return tree_height(T[1]) - tree_height(T[2])

>>> def minBalance(T):
	if T is None:
		return
	else:
		return min(balance(T[1]),balance(T[2]))

	
>>> def maxBalance(T):
	if T is None:
		return
	else:
		return max(balance(T[1]),balance(T[2]))

	
>>> def is_avl(T):
	if (minBalance(T) < -1 and maxBalance(T) > 1):
		return False
	else:
		return True

	
>>>  def is_bintree(T):
	if type(T) is not tuple:
		return False
	if T == ():
		return True
	if len(T) != 3:
		return False
	if is_bintree(T[1]) and is_bintree(T[2]):
		return True
	return False



