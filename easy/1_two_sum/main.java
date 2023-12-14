import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

class Solution {
    
    static class IndexedInteger {
        int value;
        int index;

        IndexedInteger(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    public int[] twoSum(int[] nums, int target) {
        List<IndexedInteger> indexedIntegers = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            indexedIntegers.add(new IndexedInteger(nums[i], i));
        }

        Optional<IndexedInteger[]> result = indexedIntegers.stream()
            .flatMap(x -> indexedIntegers.stream()
                .filter(y -> y.index != x.index && y.value + x.value == target)
                .map(y -> new IndexedInteger[]{x, y}))
            .findFirst();

        if (result.isPresent()) {
            IndexedInteger[] pair = result.get();
            return new int[]{pair[0].index, pair[1].index};
        } else {
            throw new IllegalArgumentException("No two sum solution");
        }
    }
}
