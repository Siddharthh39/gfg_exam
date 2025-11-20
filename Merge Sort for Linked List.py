class Solution:
    def mergeSort(self, head):
        if not head or not head.next:
            return head
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        mid = slow.next
        slow.next = None
        left = self.mergeSort(head)
        right = self.mergeSort(mid)
        return self.merge(left, right)

    def merge(self, a, b):
        dummy = Node(0)
        t = dummy
        while a and b:
            if a.data <= b.data:
                t.next = a
                a = a.next
            else:
                t.next = b
                b = b.next
            t = t.next
        if a:
            t.next = a
        else:
            t.next = b
        return dummy.next






