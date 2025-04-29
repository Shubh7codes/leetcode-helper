class Solution(object):
    def countSubarrays(self, nums, k):
        n = len(nums)
        maxE = max(nums)

        ans = 0
        count = 0
        i = 0
        j = 0

        while j < n:
            if nums[j] == maxE:
                count += 1
            while i <= j and count >= k:
                ans += (n - j)
                if nums[i] == maxE:
                    count -= 1
                i += 1
            j += 1

        return ans
