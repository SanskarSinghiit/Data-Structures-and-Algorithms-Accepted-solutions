/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
// var map = function(arr, fn)
// {
//     // arr = arr.map(fn);    
//     arr.forEach(fn);
// };
var map = function(arr, fn) {
  const transformedArr = [];
  arr.forEach((element, index) => {
    transformedArr[index] = fn(element, index);
  });
  return transformedArr;
};