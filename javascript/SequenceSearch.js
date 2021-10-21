var items = [1, 2, 3, 4, 5, 6];
var found = false;

items.forEach(function(itemValue, index, array){
    if(itemValue === 4) {
        console.log("Found item " + itemValue + " at index " + index);
        found = true;
        return;
    } 
});

if(!found) {
    console.log('Item does not exist!');
}
