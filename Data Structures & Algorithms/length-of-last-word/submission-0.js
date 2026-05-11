class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLastWord(s) {
        var newArr= s.trim().split(" ");

        return newArr[newArr.length-1].length;
    }
}
