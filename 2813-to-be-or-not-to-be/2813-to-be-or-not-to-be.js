/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val)
{
    return{
        toBe : function(x)
        {
            if(val !== x) throw Error ("Not Equal");
            else return true;
        },
        notToBe: function(y)
        {
            if(val===y) throw Error ("Equal");
            else return true;
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */