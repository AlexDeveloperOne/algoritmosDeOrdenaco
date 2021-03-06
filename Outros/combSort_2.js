//algoritmo comb sort implementado em JavaScript

var combSort = function (array) {
    var interval = Math.floor(array.length/1.3);
    while (interval > 0) {
      for(var i=0; i+interval<array.length; i+=1) {
        if (array[i] > array[i+interval]) {
          var small = array[i+interval];
          array[i+interval] = array[i];
          array[i] = small;
        }
      }
      interval = Math.floor(interval/1.3);
    }
    return array;
  };
  
  console.log(combSort([8,4,3,7,6,5,2,1]));