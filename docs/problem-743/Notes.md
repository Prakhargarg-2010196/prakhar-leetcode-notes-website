# 703. Kth Largest Element in a Stream

Question : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
## First approach using brute force : sorting and lower_bound(insertion-sort alternative)

```cpp
class KthLargest {
private:
    vector<int> nums2;
    int k2;

public:
    KthLargest(int k, vector<int>& nums)
        : k2{k},
          nums2{nums} { // Method for initialisation in C++ in Constructors
        sort(nums2.begin(), nums2.end());// Sort the array each time while creating a object
    }

    int add(int val) {
        // !TODO This method is an alternative to insertion sort but insertion sort can be also utilized here
        auto positionToInsert=lower_bound(nums2.begin(),nums2.end(),val);// Find the position of the min number largest or equal than the given value 
        nums2.insert(positionToInsert,val);// Insert it in correct position 
        return nums2[nums2.size()-k2]; // return the value from reversed direction 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

## Second Approach
Using Priority queue and pushing and popping as required.