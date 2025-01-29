class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        size = len(nums)
        for i in range(size):
            slow = i
            fast = i
            while True:
                slow = (nums[slow] + slow) % size
                fast = (nums[fast] + fast) % size
                fast = (nums[fast] + fast) % size
                if slow == fast:
                    break
            signal = nums[slow]
            allSignal = True
            node = (nums[slow] + slow) % size
            if signal > 0 and nums[node] < 0:
                allSignal = False
            if signal < 0 and nums[node] > 0:
                allSignal = False
            sz = 1
            while node != slow:
                node = (nums[node] + node) % size
                sz += 1
                if signal > 0 and nums[node] < 0:
                    allSignal = False
                if signal < 0 and nums[node] > 0:
                    allSignal = False
            if sz > 1 and allSignal:
                return True
        return False
