class linkedlist:
    class __node:
        def __init__(self,item,next = None):
            self.item = item
            self.next = next
        def getitem(self):
            return self.item
        def getnext(self):
            return self.next
        def setitem(self,item):
            self.item = item
        def setnext(self,next):
            self.next = next
    
    def __init__(self,contents = []):
        self.first = linkedlist.__node(None,None)
        self.last = self.first
        self.numitems = 0

        for e in contents:
            self.append(e)

    def append(self,item):
        node = linkedlist.__node(item)
        self.last.setnext(node)
        self.last = node
        self.numitems += 1
node  = linkedlist([1,2,3,4,5])
node.append(10)
print(node.numitems)

    