class Node(object):

    def __init__(self, prev, next, data):
        self.prev = prev
        self.next = next
        self.data = data


class ArgumentNotNode(Exception):
    pass

class LinkedList(object):

    def __init__(self, head, tail):
        self.head = head
        self.tail = tail
        self.size = 0

        if type(head) != Node or type(tail) != Node:
            raise ArgumentNotNode
            

    @staticmethod
    def create_empty(head = Node(None, None, None), tail = Node(None, None, None)):
        return LinkedList(head, tail)
    
    def is_empty(self):
        return self.head.data == None

    def extend(self, data):
        if (self.is_empty()):
            self.head = Node(None, None, data)
            self.tail = self.head
        else:
            new_entry = Node(self.tail, None, data)
            self.tail.next = new_entry
            self.tail = new_entry           #AFTER previous tail has been reformatted

    def remove_last(self):
        tail_to_be = self.tail.prev if self.tail.prev else None
        
        if (not tail_to_be):
            self.head = Node(None, None, None)
            return
        
        tail_to_be.next = None
        del(self.tail)
        self.tail = tail_to_be

    def print_contents(self):
        contents = '['
        trav = self.head

        while (trav != None):
            contents += str(trav.data) if trav.data else ''
            contents += ', ' if trav.next != None else ']'
            trav = trav.next

        print(contents)

test = LinkedList.create_empty()
test.print_contents()

test.extend('Hello')
test.print_contents()

test.extend('Goodbye')
test.print_contents()

              
