/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = n => {
    let c = n
    return () => {
        c++
        return c - 1
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */