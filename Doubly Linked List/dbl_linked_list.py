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

    def get_size(self):
        return self.size

    #O(1) time complexity
    def extend(self, data):
        if (self.is_empty()):
            self.head = Node(None, None, data)
            self.tail = self.head
        else:
            new_entry = Node(self.tail, None, data)
            self.tail.next = new_entry
            self.tail = new_entry           #AFTER previous tail has been reformatted

        #Update size of linked list 
        self.size += 1

    #O(1) time complexity
    def remove_last(self):
        tail_to_be = self.tail.prev if self.tail.prev else None
        
        if (not tail_to_be):
            self.head = Node(None, None, None)
            self.size = 0
        else:
            tail_to_be.next = None
            self.tail = tail_to_be
            self.size -= 1

    #O(n) time complexity
    def clear(self):
        self.head = self.tail = Node(None, None, None)
        self.size = 0

    #O(n) time complexity
    def print_contents(self):
        contents = '['
        trav = self.head

        while (trav != None):
            contents += str(trav.data) if trav.data else ''
            contents += ', ' if trav.next != None else ']'
            trav = trav.next

        print(contents)

    def add_at(self, pos, data):
        new_node = Node(None, None, data)

        if (pos < 0 or pos >= self.size):
            raise IndexError
        elif (pos == 0):
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node
        else:
            trav = self.head
            current_pos = 0

            ##First we fix it from the left
            while (current_pos != pos - 1):
                trav = trav.next

            trav.next = new_node
            new_node.prev = trav

            ##Then we fix it from the right ()
            while (current_pos != pos):
                print('at node ', current_pos)
                trav = trav.next

            trav.prev = new_node
            new_node.next = trav

         ##Finally, update size to reflect change
        self.size += 1            


test = LinkedList.create_empty()
test.print_contents()

test.extend('Hello')
test.print_contents()

test.extend('Goodbye')
test.print_contents()
print("size: ", test.size)

test.remove_last()
test.print_contents()
print("size: ", test.size)

test.add_at(0, 13)
test.print_contents()
print("size: ", test.size)

test.add_at(1, 'wedge')
test.print_contents()
print("size: ", test.size)

test.clear()
test.print_contents()
print("size: ", test.size)