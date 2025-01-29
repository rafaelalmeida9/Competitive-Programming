# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        prev = slow
        slow = slow.next
        while slow:
            temp = slow
            slow = slow.next
            temp.next = prev
            prev = temp
        
        pointer1 = head
        pointer2 = prev

        while pointer1 != pointer2:
            print(pointer1.val,pointer2.val)
            if pointer1.val != pointer2.val:
                return False
            pointer1 = pointer1.next
            if pointer1 == pointer2:
                break
            pointer2 = pointer2.next
        if pointer1.val != pointer2.val:
            return False
        return True
