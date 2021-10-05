let BinarySearch = (list,val)=>{
    let left = 0;
    let right = list.length - 1;
    let mid = Math.floor((left + right) / 2);

    while (list[mid] !== val && left <= right) {
        if (val < list[mid]) {
            right = mid - 1
        } else {
            left = mid + 1
        }
        mid = Math.floor((left + right) / 2);
    }
    if (list[mid] === val) {
        return mid;
    } else {
        return -1
    }

}
;

let list = [1,2,3,4,5,6,7,8]
let val = 3;
// should return 2

BinarySearch(list, val);
