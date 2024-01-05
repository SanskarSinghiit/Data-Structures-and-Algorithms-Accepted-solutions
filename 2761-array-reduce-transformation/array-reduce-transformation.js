/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var tillvalue = init;
    for(var i = 0; i < nums.length; i++){
        tillvalue = fn(tillvalue, nums[i]);
    }
    return tillvalue;
};