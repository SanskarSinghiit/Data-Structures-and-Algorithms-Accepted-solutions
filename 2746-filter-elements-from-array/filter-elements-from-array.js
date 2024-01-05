/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    // arr = arr.filter(fn);
    let arr1 = [];
    for(var i = 0; i < arr.length; i++){
        if(fn(arr[i], i)){
            arr1.push(arr[i]);
        }
    }
    return arr1;
};