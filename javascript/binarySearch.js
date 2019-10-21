// Refactored Version
function binarySearch( arr, elem ) {
    var start = 0;
    var end = arr.length - 1;
    var middle = Math.floor( ( start + end ) / 2 );
    while ( arr[middle] !== elem && start <= end ) {
        if ( elem < arr[middle] ) end = middle - 1;
        else start = middle + 1;
        middle = Math.floor( ( start + end ) / 2 );
    }
    return arr[middle] === elem ? middle : -1;
}
// data array
var data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 24, 152, 234, 6252];
// keyword
var search = 6252;
console.log( binarySearch( data, search ) );