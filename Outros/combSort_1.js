// Comb Sort
//
// Use the Comb Sort algorithm (http://en.wikipedia.org/wiki/Comb_sort) to sort an array of items by value.

function combSort(items) {
    var array = [],
        swapped = true,
        i,
        gap,
        shrink = 1.3;
    
    if ( items ) {
      array = items.map(function(item) { return item; });
    }
    
    gap = array.length;
    
    while ( gap !== 1 || swapped ) {
      gap = Math.floor(gap / shrink);
      if ( gap < 1 ) {
        gap = 1;
      }
      
      i = 0;
      swapped = false;
      
      while ( i + gap < array.length ) {
        if ( array[i] > array[i+gap] ) {
          swap(array, i, i+gap);
          swapped = true;
        }
        i++;
      }
    }
    
    return array;
  }
  
  // swap what is stored at position i and j in the array
  function swap(array, i, j) {
    var temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
  
  var items1 = [5,4,3,2,1],
      items2 = [6,2,5,10,13,9,1,11,8,15,7,4];
  console.log(items1 + ' -> ' + combSort(items1));
  console.log(items2 + ' -> ' + combSort(items2));