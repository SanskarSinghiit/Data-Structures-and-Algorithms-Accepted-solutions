/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init)
{
    var x = init;
    return {
        increment : function(){return x = x + 1;},
        decrement : function(){return x = x - 1;},
        reset : function(){return x = init;}
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */